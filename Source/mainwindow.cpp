#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	ui->lbl_dir_name->setText("Images");
	m_camera = std::unique_ptr<Camera>(new Camera_Basler{});
	m_HDR_image = std::unique_ptr<ProcessingHDR>(new ProcessingHDR{});
	m_loger = std::unique_ptr<LogFiles>{ new LogFiles{&m_input_img, m_camera.get()} };
	m_img_filter = std::unique_ptr<ImageProcessing>(new ImgFilter{});

	m_loger->MakeDirectory("Images");
	ui->btn_make_dir->setEnabled(false);

	try
	{
		m_camera->Init();
		m_camera->OpenCamera(m_camera->cameras().first());
		ConnectButtons();
		ConnectLabelsSlots();
	}
	catch (const std::exception& exp)
	{
		ui->btn_close->click();
	}

	m_camera_control = std::unique_ptr<uiGUIObject>{ new uiCameraControl{ui, m_camera.get()} };
	m_HDR_control = std::unique_ptr<uiGUIObject>{ new uiHDRControl{ui, m_HDR_image.get(), m_loger.get()} };
	m_ñalculate_control = std::unique_ptr<uiGUIObject>{ new uiCalculateControl {ui, m_img_filter.get(), &m_input_img}}; 
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::ConnectButtons()
{
    connect(ui->btn_close, &QPushButton::clicked, [=](){
        this->close();
    });
}

void MainWindow::ConnectLabelsSlots()
{
	auto param_AOI = m_camera->getGeometryAOI();
	if (std::get<0>(param_AOI) == 0)
		ui->btn_close->click();
    ui->lbl_exposure->setText("2000");
    ui->lbl_camera_img->setStyleSheet("QLabel{background-color: white}");
    ui->lbl_calculate_img->setStyleSheet("QLabel{background-color: white}");

    ui->lbl_exposure->setText(QString::number(m_camera->getExposureTime()));
    ui->lbl_exposure_start->setText( ui->lbl_exposure->text());
    ui->lbl_exposure_step->setText("0");
    ui->lbl_quantity_img->setText("1");
    ui->lbl_height->setText(QString::number(std::get<0>(param_AOI)));
    ui->lbl_width->setText(QString::number(std::get<1>(param_AOI)));
	ui->lbl_offset_x->setText(QString::number(std::get<2>(param_AOI)));
	ui->lbl_offset_y->setText(QString::number(std::get<3>(param_AOI)));

	connect(m_camera.get(), &Camera::sigCurrentImage, [=](QImage img) {
		m_input_img = img;
		if(m_ñalculate_control->getFlagStartCalculate())
			m_img_filter->getImageFromCamera(img);
	});
}