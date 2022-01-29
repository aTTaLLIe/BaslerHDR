#include "uiHDRControl.h"

uiHDRControl::uiHDRControl(Ui::MainWindow *ui_window, ProcessingHDR *HDR_image, LogFiles *loger) : m_ui_window(ui_window), m_HDR_image(HDR_image), m_loger(loger)
{
	ButtonControl();
	SignalSlotControl();
}

uiHDRControl::~uiHDRControl()
{
}


void uiHDRControl::ButtonControl() 
{
	connect(m_ui_window->comb_method_tonemap, &QComboBox::currentTextChanged, [=]() {
		if (m_ui_window->comb_method_tonemap->currentText() == "Drago Tonemap")
			m_ui_window->tab_param_tonemap->setCurrentIndex(1);

		if (m_ui_window->comb_method_tonemap->currentText() == "Reinhard Tonemap")
			m_ui_window->tab_param_tonemap->setCurrentIndex(2);

		if (m_ui_window->comb_method_tonemap->currentText() == "Mantiuk Tonemap")
			m_ui_window->tab_param_tonemap->setCurrentIndex(0);
	});


	connect(m_ui_window->btn_save_img, &QPushButton::clicked, [=]() {
		m_ui_window->btn_stop->click();
		m_curent_exposure = m_ui_window->lbl_exposure_start->text().toUInt();
		m_step_exposure = m_ui_window->lbl_exposure_step->text().toUInt();
		m_target_exposure = m_curent_exposure + m_step_exposure * m_ui_window->lbl_quantity_img->text().toUInt();

		m_ui_window->btn_height->setEnabled(false);
		m_ui_window->btn_width->setEnabled(false);
		m_ui_window->btn_start->setEnabled(false);
		m_ui_window->btn_exposure->setEnabled(false);
		m_ui_window->btn_trigger->setEnabled(false);
		m_ui_window->btn_stop->setEnabled(false);
		m_loger->CollectImage(m_curent_exposure, m_target_exposure, m_step_exposure);
		m_ui_window->btn_height->setEnabled(true);
		m_ui_window->btn_width->setEnabled(true);
		m_ui_window->btn_start->setEnabled(true);
		m_ui_window->btn_exposure->setEnabled(true);
		m_ui_window->btn_trigger->setEnabled(true);
		m_ui_window->btn_stop->setEnabled(true);

		m_ui_window->lbl_exposure->setText(QString::number(m_curent_exposure));
		m_ui_window->lbl_exposure_start->setText(QString::number(m_curent_exposure));

	});

	connect(m_ui_window->btn_make_dir, &QPushButton::clicked, [=]() {
		m_loger->MakeDirectory(m_ui_window->lbl_dir_name->text().toStdString());
		m_ui_window->btn_make_dir->setEnabled(false);
	});

	connect(m_ui_window->btn_calculate_hdr, &QPushButton::clicked, [=]() {
		std::vector<float> param_tonemap = getTonemapParam(m_ui_window->comb_method_tonemap->currentText().toStdString());
		m_HDR_image->setPathDirectory(m_loger->GetPathDir());
		m_HDR_image->sltStartCalculate(m_ui_window->comb_method_tonemap->currentText(), param_tonemap);
	});
}

void uiHDRControl::SignalSlotControl() 
{
	connect(m_ui_window->lbl_dir_name, &QLineEdit::textChanged, [=]()
	{
		m_ui_window->btn_make_dir->setEnabled(true);
	});

	connect(m_HDR_image, &ProcessingHDR::sigImageHDR, [=](QImage img) {
		QPixmap pix = QPixmap::fromImage(img);
		m_ui_window->lbl_hdr_img->setPixmap(pix.scaled(m_ui_window->lbl_hdr_img->width(), m_ui_window->lbl_hdr_img->height(), Qt::IgnoreAspectRatio));
	});

	connect(m_HDR_image, &ProcessingHDR::sigProgressBarValue, [=](unsigned int value) {
		m_ui_window->lbl_progressBar->setValue(value);
	});
}

vector<float> uiHDRControl::getTonemapParam(const std::string & method)
{
	vector<float> tonemap_param(4, 0);
	if (method == "Drago Tonemap")
	{
		tonemap_param[0] = m_ui_window->lbl_gamma_drago->value();
		tonemap_param[1] = m_ui_window->lbl_saturation_drago->value();
		tonemap_param[2] = m_ui_window->lbl_bias_drago->value();
	}

	if (method == "Mantiuk Tonemap")
	{
		tonemap_param[0] = m_ui_window->lbl_gamma_mant->value();
		tonemap_param[1] = m_ui_window->lbl_saturation_mant->value();
		tonemap_param[2] = m_ui_window->lbl_scale_mant->value();
	}

	if (method == "Reinhard Tonemap")
	{
		tonemap_param[0] = m_ui_window->lbl_gamma_reinhard->value();
		tonemap_param[1] = m_ui_window->lbl_intensity_reinhard->value();
		tonemap_param[2] = m_ui_window->lbl_light_adapt_reinhard->value();
		tonemap_param[3] = m_ui_window->lbl_color_adapt_reinhard->value();
	}
	return tonemap_param;
}
