#include "processinghdr.h"

ProcessingHDR::ProcessingHDR(QObject * parent) : QObject(parent)
{

}

ProcessingHDR::~ProcessingHDR()
{

}


void ProcessingHDR::sltStartCalculate(const QString &method_hdr, const vector<float>& param_tonemap)
{
	Mat buffer_img = imread(m_path_direct.string() + "Image_HDR.hdr");
	emit sigProgressBarValue(10);
	if(buffer_img.empty() || m_hdrDebevec_img.empty())
	{
		std::vector<float> vector_exposure;
		std::vector<std::string> vector_name_img;

		std::ifstream file_exposure{ m_path_direct.string() + "time.data", ios::in };
		std::ifstream file_name{ m_path_direct.string() + "name.data", ios::in };

		if (!file_exposure.is_open() || !file_name.is_open())
		{
			return;
		}

		while (!file_exposure.eof() && !file_name.eof())
		{
			float exposure;
			std::string name;
			file_exposure >> exposure;
			getline(file_name, name);
			if (!name.empty())
			{
				vector_exposure.push_back(exposure);
				vector_name_img.push_back(name);
			}
		}
		emit sigProgressBarValue(30);
		vector<Mat> vector_image(vector_exposure.size());
		for (int i = 0; i < vector_exposure.size(); i++)
		{
			Mat img = imread(m_path_direct.string() + vector_name_img[i]);
			if (img.empty())
				return;
			img.convertTo(img, CV_8UC1, 1.0, 0.0);
			vector_image[i] = img;
		}
		emit sigProgressBarValue(40);
		//Ptr<AlignMTB> alignMTB = createAlignMTB();
		//emit sigProgressBarValue(50);
		//alignMTB->process(images, images);

		Mat responseDebevec;
		Ptr<CalibrateDebevec> calibrateDebevec = createCalibrateDebevec();
		calibrateDebevec->process(vector_image, responseDebevec, vector_exposure);

		emit sigProgressBarValue(60);
		Ptr<MergeDebevec> mergeDebevec = createMergeDebevec();
		mergeDebevec->process(vector_image, m_hdrDebevec_img, vector_exposure, responseDebevec);
		// Save HDR image.
		imwrite(m_path_direct.string() + "Image_HDR.hdr", m_hdrDebevec_img);
	}
	
	emit sigProgressBarValue(70);
	Mat tonemap_img;
	if(method_hdr == "Drago Tonemap")
	{
		Ptr<TonemapDrago> tonemapDrago = createTonemapDrago(param_tonemap[0], param_tonemap[1], param_tonemap[2]);
		tonemapDrago->process(m_hdrDebevec_img, tonemap_img);
		tonemap_img = 3 * tonemap_img;
		imwrite(m_path_direct.string() + "Basler-Drago.jpg", tonemap_img * 255);
	}

	if (method_hdr == "Reinhard Tonemap")
	{
		Ptr<TonemapReinhard> tonemapReinhard = createTonemapReinhard(param_tonemap[0], param_tonemap[1], param_tonemap[2], param_tonemap[3]);
		tonemapReinhard->process(m_hdrDebevec_img, tonemap_img);
		imwrite(m_path_direct.string() + "Basler-Reinhard.bmp", tonemap_img * 255);
	}
	
	if (method_hdr == "Mantiuk Tonemap")
	{
		Ptr<TonemapMantiuk> tonemapMantiuk = createTonemapMantiuk(param_tonemap[0], param_tonemap[1], param_tonemap[2]);
		tonemapMantiuk->process(m_hdrDebevec_img, tonemap_img);
		tonemap_img = 3 * tonemap_img;
		imwrite(m_path_direct.string() + "Basler-Mantiuk.bmp", tonemap_img * 255);
	}

	tonemap_img *= 255;
	tonemap_img.convertTo(tonemap_img, CV_8UC3, 1.0, 0.0);

	const uchar *qImageBuffer = (const uchar*)tonemap_img.data;
	QImage img(qImageBuffer, tonemap_img.cols, tonemap_img.rows, tonemap_img.step, QImage::Format_RGB888);

	emit sigProgressBarValue(100);
    emit sigImageHDR(img.rgbSwapped());
}

void ProcessingHDR::setPathDirectory(std::filesystem::path path)
{
	m_path_direct = path;
}
