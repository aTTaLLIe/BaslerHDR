#include "uiCameraControl.h"

uiCameraControl::uiCameraControl(Ui::MainWindow *ptr_ui_window, Camera *ptr_camera) : m_ui_window(ptr_ui_window), m_camera(ptr_camera)
{
	ButtonControl();
	SignalSlotControl();
}


uiCameraControl::~uiCameraControl()
{
}

void uiCameraControl::ButtonControl() 
{
	connect(m_ui_window->btn_start, &QPushButton::clicked, [=]() {
		m_ui_window->lbl_exposure->setText(QString::number(m_camera->getExposureTime()));
		m_camera->StartAcquire();
		m_ui_window->btn_height->setEnabled(false);
		m_ui_window->btn_width->setEnabled(false);
	});
	connect(m_ui_window->btn_stop, &QPushButton::clicked, [=]() {
		m_camera->StopAcquire();
		m_ui_window->btn_height->setEnabled(true);
		m_ui_window->btn_width->setEnabled(true);
	});

	connect(m_ui_window->btn_exposure, &QPushButton::clicked, [=]() {
		auto exposure = m_ui_window->lbl_exposure->text();
		m_ui_window->lbl_exposure_start->setText(exposure);
		m_camera->setExposureTime(exposure.toDouble());
	});

	connect(m_ui_window->comb_trigger_mode, &QComboBox::currentTextChanged, [=](QString trigger_mode) {
		m_camera->setFeatureTriggerSourceType(trigger_mode);
	});

	connect(m_ui_window->btn_trigger, &QPushButton::clicked, [=]() {
		bool station_trigger = m_camera->getFeatureTriggerModeType();
		if (station_trigger)
			m_camera->setFeatureTriggerModeType(false);
		else
			m_camera->setFeatureTriggerModeType(true);
		setButtonTriggerState(!station_trigger);
	});

	connect(m_ui_window->btn_height, &QPushButton::clicked, [=]() {
		QString str_height = m_ui_window->lbl_height->text();
		m_camera->setHeight(str_height.toUInt());
	});

	connect(m_ui_window->btn_width, &QPushButton::clicked, [=]() {
		QString str_width = m_ui_window->lbl_width->text();
		m_camera->setWidth(str_width.toUInt());
	});
}

void uiCameraControl::SignalSlotControl() 
{
	setButtonTriggerState(m_camera->getFeatureTriggerModeType());

	connect(m_ui_window->lbl_offset_x, &QLineEdit::textChanged, [=]()
	{
		QString str_offset_x = m_ui_window->lbl_offset_x->text();
		m_camera->setOffsetX(str_offset_x.toULong());
	});

	connect(m_ui_window->lbl_offset_y, &QLineEdit::textChanged, [=]()
	{
		QString str_offset_y = m_ui_window->lbl_offset_y->text();
		m_camera->setOffsetY(str_offset_y.toULong());
	});

	connect(m_camera, &Camera::sigCurrentImage, [=](QImage img) {
		QPixmap pix = QPixmap::fromImage(img);
		m_ui_window->lbl_camera_img->setPixmap(pix.scaled(m_ui_window->lbl_camera_img->width(), m_ui_window->lbl_camera_img->height(), Qt::IgnoreAspectRatio));
	});
	connect(m_camera, &Camera::sigCameraFPS, [=](unsigned int fps) {
		m_ui_window->lbl_fps_camera->setText(QString::number(fps));
	});
}

void uiCameraControl::setButtonTriggerState(bool state_trg)
{
	if (!state_trg)
	{
		m_ui_window->btn_trigger->setStyleSheet("QPushButton{background:#e3e3e3; border: 2px solid black; border-radius:5px;}");
		m_ui_window->btn_trigger->setText("Trigger Off");
	}
	else
	{
		m_ui_window->btn_trigger->setStyleSheet("QPushButton{background:#009900; border: 2px solid black; border-radius:5px;}");
		m_ui_window->btn_trigger->setText("Trigger On");
	}
}