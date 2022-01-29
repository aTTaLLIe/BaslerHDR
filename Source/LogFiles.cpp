#include "LogFiles.h"

LogFiles::LogFiles(QImage *image, Camera *camera) : m_input_img(image), m_camera(camera)
{
}

LogFiles::~LogFiles()
{
}


void LogFiles::SaveImage(const QString &path)
{
	QPixmap pix = QPixmap::fromImage(*m_input_img);
	pix.save(path, "JPG", 100);
	return;
}

void LogFiles::CollectImage(unsigned int& m_curent_exposure, const unsigned int& m_target_exposure, const unsigned int& m_step_exposure)
{
	m_camera->setExposureTime(m_curent_exposure);
	m_camera->GetOneImage();
	SaveImage(QString::fromStdString(m_path_direct.string()) + "Img_" + QString::number(m_curent_exposure) + ".jpg");
	*(m_file_name.get()) << "Img_" << m_curent_exposure << ".jpg" << endl;
	*(m_file_exposure.get()) << static_cast<float>(m_curent_exposure) / 1000000 << endl;
	if (m_curent_exposure < m_target_exposure)
	{
		m_curent_exposure += m_step_exposure;
		CollectImage(m_curent_exposure, m_target_exposure, m_step_exposure);
	}
	return;
}

void LogFiles::MakeDirectory(const std::string & name_dir)
{
	m_path_direct = std::filesystem::current_path();
	m_path_direct.append(name_dir + "//");
	std::filesystem::remove_all(m_path_direct);
	std::filesystem::create_directory(m_path_direct);

	if (m_file_exposure != nullptr)
		m_file_exposure.reset();

	if (m_file_name != nullptr)
		m_file_name.reset();

	m_file_exposure = std::unique_ptr <std::ofstream>{ new std::ofstream{m_path_direct.string() + "time.data", ios::out | ios::app} };
	m_file_name = std::unique_ptr<std::ofstream>{ new std::ofstream{m_path_direct.string() + "name.data", ios::out | ios::app} };
}

std::filesystem::path LogFiles::GetPathDir() 
{
	return m_path_direct;
}