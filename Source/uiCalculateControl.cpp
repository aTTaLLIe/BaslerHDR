#include "uiCalculateControl.h"

uiCalculateControl::uiCalculateControl(Ui::MainWindow *ui_window, ImageProcessing *ptr_img_filter, QImage *ptr_image) : m_ptr_ui_window(ui_window), m_ptr_img_filter(ptr_img_filter), m_ptr_image(ptr_image)
{
	processing_img = false;
	ButtonControl();
	SignalSlotControl();
}

uiCalculateControl::~uiCalculateControl()
{
}



void uiCalculateControl::ButtonControl()
{
	//connect(m_ptr_ui_window->btn_start_convol, &QPushButton::clicked, m_ptr_img_filter, &ImageProcessing::getImageFromCamera);
	connect(m_ptr_ui_window->btn_start_filter, &QPushButton::clicked, [=]() {
		processing_img = true;
	});
	connect(m_ptr_ui_window->btn_stop_filter, &QPushButton::clicked, [=]() {
		processing_img = false;
	});
}

void uiCalculateControl::SignalSlotControl()
{
	connect(m_ptr_img_filter, &ImageProcessing::sigCalulateImage, [=](const QImage &img)
	{
		if (!img.isNull())
		{
			QPixmap pix = QPixmap::fromImage(img);
			m_ptr_ui_window->lbl_calculate_img->setPixmap(pix.scaled(m_ptr_ui_window->lbl_calculate_img->width(), m_ptr_ui_window->lbl_calculate_img->height(), Qt::IgnoreAspectRatio));
		}
	});

	connect(m_ptr_img_filter, &ImageProcessing::sigCalulateFPS, [=](const unsigned int fps) {
		m_ptr_ui_window->lbl_fps_filter->setText(QString::number(fps));
	});
}

bool uiCalculateControl::getFlagStartCalculate() 
{
	return processing_img;
}

