/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tab_images;
    QWidget *camera;
    QLabel *lbl_camera_img;
    QWidget *calculate;
    QLabel *lbl_calculate_img;
    QWidget *HDR;
    QLabel *lbl_hdr_img;
    QTabWidget *tabWidget;
    QWidget *tab_camera;
    QPushButton *btn_trigger;
    QPushButton *btn_close;
    QLineEdit *lbl_height;
    QPushButton *btn_stop;
    QPushButton *btn_start;
    QComboBox *comb_trigger_mode;
    QLineEdit *lbl_width;
    QLineEdit *lbl_exposure;
    QLabel *lbl_fps_camera;
    QLabel *const_lbl_fps_camera;
    QLineEdit *lbl_offset_y;
    QLineEdit *lbl_offset_x;
    QPushButton *btn_exposure;
    QLabel *const_offset_y;
    QPushButton *btn_width;
    QPushButton *btn_height;
    QLabel *const_offset_x;
    QWidget *tab_convol;
    QLabel *lbl_fps_filter;
    QLabel *const_lbl_fps_filter;
    QPushButton *btn_start_filter;
    QPushButton *btn_stop_filter;
    QWidget *tab_hdr;
    QPushButton *btn_save_img;
    QLineEdit *lbl_exposure_start;
    QLineEdit *lbl_exposure_step;
    QLineEdit *lbl_quantity_img;
    QLabel *const_lbl_start_exp;
    QLabel *const_lbl_step_exp;
    QLabel *const_lbl_quantity;
    QComboBox *comb_method_tonemap;
    QPushButton *btn_calculate_hdr;
    QStackedWidget *tab_param_tonemap;
    QWidget *param_mantiuk;
    QLabel *const_lbl_gamma_mant;
    QLabel *const_lbl_scale_mant;
    QLabel *const_lbl_saturation_mant;
    QDoubleSpinBox *lbl_gamma_mant;
    QDoubleSpinBox *lbl_scale_mant;
    QDoubleSpinBox *lbl_saturation_mant;
    QWidget *param_drago;
    QLabel *const_lbl_gamma_drago;
    QLabel *const_lbl_bias_drago;
    QLabel *const_lbl_saturation_drago;
    QDoubleSpinBox *lbl_gamma_drago;
    QDoubleSpinBox *lbl_saturation_drago;
    QDoubleSpinBox *lbl_bias_drago;
    QWidget *param_reinhard;
    QLabel *const_lbl_light_adapt_reinhard;
    QLabel *const_lbl_gamma_reinhard;
    QLabel *const_lbl_intensity_reinhard;
    QLabel *const_lbl_color_adapt_reinhard;
    QDoubleSpinBox *lbl_gamma_reinhard;
    QDoubleSpinBox *lbl_intensity_reinhard;
    QDoubleSpinBox *lbl_light_adapt_reinhard;
    QDoubleSpinBox *lbl_color_adapt_reinhard;
    QProgressBar *lbl_progressBar;
    QLineEdit *lbl_dir_name;
    QPushButton *btn_make_dir;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1000, 700);
        MainWindow->setMinimumSize(QSize(1000, 700));
        MainWindow->setMaximumSize(QSize(1000, 700));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tab_images = new QTabWidget(centralWidget);
        tab_images->setObjectName(QStringLiteral("tab_images"));
        tab_images->setGeometry(QRect(20, 10, 721, 621));
        camera = new QWidget();
        camera->setObjectName(QStringLiteral("camera"));
        lbl_camera_img = new QLabel(camera);
        lbl_camera_img->setObjectName(QStringLiteral("lbl_camera_img"));
        lbl_camera_img->setGeometry(QRect(20, 10, 680, 560));
        tab_images->addTab(camera, QString());
        calculate = new QWidget();
        calculate->setObjectName(QStringLiteral("calculate"));
        lbl_calculate_img = new QLabel(calculate);
        lbl_calculate_img->setObjectName(QStringLiteral("lbl_calculate_img"));
        lbl_calculate_img->setGeometry(QRect(20, 10, 680, 560));
        tab_images->addTab(calculate, QString());
        HDR = new QWidget();
        HDR->setObjectName(QStringLiteral("HDR"));
        lbl_hdr_img = new QLabel(HDR);
        lbl_hdr_img->setObjectName(QStringLiteral("lbl_hdr_img"));
        lbl_hdr_img->setGeometry(QRect(20, 10, 680, 560));
        tab_images->addTab(HDR, QString());
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(750, 10, 241, 621));
        tab_camera = new QWidget();
        tab_camera->setObjectName(QStringLiteral("tab_camera"));
        btn_trigger = new QPushButton(tab_camera);
        btn_trigger->setObjectName(QStringLiteral("btn_trigger"));
        btn_trigger->setGeometry(QRect(30, 270, 180, 40));
        QFont font;
        font.setPointSize(15);
        btn_trigger->setFont(font);
        btn_close = new QPushButton(tab_camera);
        btn_close->setObjectName(QStringLiteral("btn_close"));
        btn_close->setGeometry(QRect(30, 110, 180, 40));
        btn_close->setFont(font);
        lbl_height = new QLineEdit(tab_camera);
        lbl_height->setObjectName(QStringLiteral("lbl_height"));
        lbl_height->setGeometry(QRect(130, 370, 80, 40));
        lbl_height->setFont(font);
        btn_stop = new QPushButton(tab_camera);
        btn_stop->setObjectName(QStringLiteral("btn_stop"));
        btn_stop->setGeometry(QRect(30, 60, 180, 40));
        btn_stop->setFont(font);
        btn_start = new QPushButton(tab_camera);
        btn_start->setObjectName(QStringLiteral("btn_start"));
        btn_start->setGeometry(QRect(30, 10, 180, 40));
        btn_start->setFont(font);
        comb_trigger_mode = new QComboBox(tab_camera);
        comb_trigger_mode->addItem(QString());
        comb_trigger_mode->addItem(QString());
        comb_trigger_mode->setObjectName(QStringLiteral("comb_trigger_mode"));
        comb_trigger_mode->setGeometry(QRect(30, 220, 180, 40));
        comb_trigger_mode->setFont(font);
        comb_trigger_mode->setLayoutDirection(Qt::LeftToRight);
        lbl_width = new QLineEdit(tab_camera);
        lbl_width->setObjectName(QStringLiteral("lbl_width"));
        lbl_width->setGeometry(QRect(130, 320, 80, 40));
        lbl_width->setFont(font);
        lbl_exposure = new QLineEdit(tab_camera);
        lbl_exposure->setObjectName(QStringLiteral("lbl_exposure"));
        lbl_exposure->setGeometry(QRect(130, 160, 80, 40));
        lbl_exposure->setFont(font);
        lbl_fps_camera = new QLabel(tab_camera);
        lbl_fps_camera->setObjectName(QStringLiteral("lbl_fps_camera"));
        lbl_fps_camera->setGeometry(QRect(140, 520, 81, 40));
        lbl_fps_camera->setFont(font);
        const_lbl_fps_camera = new QLabel(tab_camera);
        const_lbl_fps_camera->setObjectName(QStringLiteral("const_lbl_fps_camera"));
        const_lbl_fps_camera->setGeometry(QRect(10, 520, 111, 40));
        const_lbl_fps_camera->setFont(font);
        lbl_offset_y = new QLineEdit(tab_camera);
        lbl_offset_y->setObjectName(QStringLiteral("lbl_offset_y"));
        lbl_offset_y->setGeometry(QRect(130, 470, 80, 40));
        lbl_offset_y->setFont(font);
        lbl_offset_x = new QLineEdit(tab_camera);
        lbl_offset_x->setObjectName(QStringLiteral("lbl_offset_x"));
        lbl_offset_x->setGeometry(QRect(130, 420, 80, 40));
        lbl_offset_x->setFont(font);
        btn_exposure = new QPushButton(tab_camera);
        btn_exposure->setObjectName(QStringLiteral("btn_exposure"));
        btn_exposure->setGeometry(QRect(30, 160, 90, 40));
        btn_exposure->setFont(font);
        const_offset_y = new QLabel(tab_camera);
        const_offset_y->setObjectName(QStringLiteral("const_offset_y"));
        const_offset_y->setGeometry(QRect(30, 470, 81, 40));
        const_offset_y->setFont(font);
        btn_width = new QPushButton(tab_camera);
        btn_width->setObjectName(QStringLiteral("btn_width"));
        btn_width->setGeometry(QRect(30, 320, 90, 40));
        btn_width->setFont(font);
        btn_height = new QPushButton(tab_camera);
        btn_height->setObjectName(QStringLiteral("btn_height"));
        btn_height->setGeometry(QRect(30, 370, 90, 40));
        btn_height->setFont(font);
        const_offset_x = new QLabel(tab_camera);
        const_offset_x->setObjectName(QStringLiteral("const_offset_x"));
        const_offset_x->setGeometry(QRect(30, 420, 81, 40));
        const_offset_x->setFont(font);
        tabWidget->addTab(tab_camera, QString());
        tab_convol = new QWidget();
        tab_convol->setObjectName(QStringLiteral("tab_convol"));
        lbl_fps_filter = new QLabel(tab_convol);
        lbl_fps_filter->setObjectName(QStringLiteral("lbl_fps_filter"));
        lbl_fps_filter->setGeometry(QRect(140, 110, 81, 40));
        lbl_fps_filter->setFont(font);
        const_lbl_fps_filter = new QLabel(tab_convol);
        const_lbl_fps_filter->setObjectName(QStringLiteral("const_lbl_fps_filter"));
        const_lbl_fps_filter->setGeometry(QRect(10, 110, 111, 40));
        const_lbl_fps_filter->setFont(font);
        btn_start_filter = new QPushButton(tab_convol);
        btn_start_filter->setObjectName(QStringLiteral("btn_start_filter"));
        btn_start_filter->setGeometry(QRect(30, 10, 180, 40));
        btn_start_filter->setFont(font);
        btn_stop_filter = new QPushButton(tab_convol);
        btn_stop_filter->setObjectName(QStringLiteral("btn_stop_filter"));
        btn_stop_filter->setGeometry(QRect(30, 60, 180, 40));
        btn_stop_filter->setFont(font);
        tabWidget->addTab(tab_convol, QString());
        tab_hdr = new QWidget();
        tab_hdr->setObjectName(QStringLiteral("tab_hdr"));
        btn_save_img = new QPushButton(tab_hdr);
        btn_save_img->setObjectName(QStringLiteral("btn_save_img"));
        btn_save_img->setGeometry(QRect(30, 210, 180, 40));
        btn_save_img->setFont(font);
        lbl_exposure_start = new QLineEdit(tab_hdr);
        lbl_exposure_start->setObjectName(QStringLiteral("lbl_exposure_start"));
        lbl_exposure_start->setGeometry(QRect(130, 10, 80, 40));
        lbl_exposure_start->setFont(font);
        lbl_exposure_step = new QLineEdit(tab_hdr);
        lbl_exposure_step->setObjectName(QStringLiteral("lbl_exposure_step"));
        lbl_exposure_step->setGeometry(QRect(130, 60, 80, 40));
        lbl_exposure_step->setFont(font);
        lbl_quantity_img = new QLineEdit(tab_hdr);
        lbl_quantity_img->setObjectName(QStringLiteral("lbl_quantity_img"));
        lbl_quantity_img->setGeometry(QRect(130, 110, 80, 40));
        lbl_quantity_img->setFont(font);
        const_lbl_start_exp = new QLabel(tab_hdr);
        const_lbl_start_exp->setObjectName(QStringLiteral("const_lbl_start_exp"));
        const_lbl_start_exp->setGeometry(QRect(30, 10, 91, 40));
        const_lbl_start_exp->setFont(font);
        const_lbl_step_exp = new QLabel(tab_hdr);
        const_lbl_step_exp->setObjectName(QStringLiteral("const_lbl_step_exp"));
        const_lbl_step_exp->setGeometry(QRect(30, 60, 91, 40));
        const_lbl_step_exp->setFont(font);
        const_lbl_quantity = new QLabel(tab_hdr);
        const_lbl_quantity->setObjectName(QStringLiteral("const_lbl_quantity"));
        const_lbl_quantity->setGeometry(QRect(30, 110, 91, 40));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(false);
        font1.setWeight(50);
        const_lbl_quantity->setFont(font1);
        comb_method_tonemap = new QComboBox(tab_hdr);
        comb_method_tonemap->addItem(QString());
        comb_method_tonemap->addItem(QString());
        comb_method_tonemap->addItem(QString());
        comb_method_tonemap->setObjectName(QStringLiteral("comb_method_tonemap"));
        comb_method_tonemap->setGeometry(QRect(30, 260, 180, 40));
        comb_method_tonemap->setFont(font);
        comb_method_tonemap->setLayoutDirection(Qt::LeftToRight);
        btn_calculate_hdr = new QPushButton(tab_hdr);
        btn_calculate_hdr->setObjectName(QStringLiteral("btn_calculate_hdr"));
        btn_calculate_hdr->setGeometry(QRect(30, 310, 180, 40));
        btn_calculate_hdr->setFont(font);
        tab_param_tonemap = new QStackedWidget(tab_hdr);
        tab_param_tonemap->setObjectName(QStringLiteral("tab_param_tonemap"));
        tab_param_tonemap->setGeometry(QRect(30, 350, 181, 161));
        param_mantiuk = new QWidget();
        param_mantiuk->setObjectName(QStringLiteral("param_mantiuk"));
        const_lbl_gamma_mant = new QLabel(param_mantiuk);
        const_lbl_gamma_mant->setObjectName(QStringLiteral("const_lbl_gamma_mant"));
        const_lbl_gamma_mant->setGeometry(QRect(0, 20, 81, 21));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        const_lbl_gamma_mant->setFont(font2);
        const_lbl_scale_mant = new QLabel(param_mantiuk);
        const_lbl_scale_mant->setObjectName(QStringLiteral("const_lbl_scale_mant"));
        const_lbl_scale_mant->setGeometry(QRect(0, 60, 81, 21));
        const_lbl_scale_mant->setFont(font2);
        const_lbl_saturation_mant = new QLabel(param_mantiuk);
        const_lbl_saturation_mant->setObjectName(QStringLiteral("const_lbl_saturation_mant"));
        const_lbl_saturation_mant->setGeometry(QRect(0, 100, 81, 21));
        const_lbl_saturation_mant->setFont(font2);
        lbl_gamma_mant = new QDoubleSpinBox(param_mantiuk);
        lbl_gamma_mant->setObjectName(QStringLiteral("lbl_gamma_mant"));
        lbl_gamma_mant->setGeometry(QRect(100, 20, 81, 22));
        lbl_gamma_mant->setMaximum(10);
        lbl_gamma_mant->setSingleStep(0.01);
        lbl_gamma_mant->setValue(1);
        lbl_scale_mant = new QDoubleSpinBox(param_mantiuk);
        lbl_scale_mant->setObjectName(QStringLiteral("lbl_scale_mant"));
        lbl_scale_mant->setGeometry(QRect(100, 60, 81, 22));
        lbl_scale_mant->setMaximum(2);
        lbl_scale_mant->setSingleStep(0.01);
        lbl_scale_mant->setValue(0.7);
        lbl_saturation_mant = new QDoubleSpinBox(param_mantiuk);
        lbl_saturation_mant->setObjectName(QStringLiteral("lbl_saturation_mant"));
        lbl_saturation_mant->setGeometry(QRect(100, 100, 81, 22));
        lbl_saturation_mant->setMaximum(10);
        lbl_saturation_mant->setSingleStep(0.01);
        lbl_saturation_mant->setValue(1);
        tab_param_tonemap->addWidget(param_mantiuk);
        param_drago = new QWidget();
        param_drago->setObjectName(QStringLiteral("param_drago"));
        const_lbl_gamma_drago = new QLabel(param_drago);
        const_lbl_gamma_drago->setObjectName(QStringLiteral("const_lbl_gamma_drago"));
        const_lbl_gamma_drago->setGeometry(QRect(0, 20, 81, 21));
        const_lbl_gamma_drago->setFont(font2);
        const_lbl_bias_drago = new QLabel(param_drago);
        const_lbl_bias_drago->setObjectName(QStringLiteral("const_lbl_bias_drago"));
        const_lbl_bias_drago->setGeometry(QRect(0, 100, 81, 21));
        const_lbl_bias_drago->setFont(font2);
        const_lbl_saturation_drago = new QLabel(param_drago);
        const_lbl_saturation_drago->setObjectName(QStringLiteral("const_lbl_saturation_drago"));
        const_lbl_saturation_drago->setGeometry(QRect(0, 60, 81, 21));
        const_lbl_saturation_drago->setFont(font2);
        lbl_gamma_drago = new QDoubleSpinBox(param_drago);
        lbl_gamma_drago->setObjectName(QStringLiteral("lbl_gamma_drago"));
        lbl_gamma_drago->setGeometry(QRect(100, 20, 81, 22));
        lbl_gamma_drago->setMaximum(10);
        lbl_gamma_drago->setSingleStep(0.01);
        lbl_gamma_drago->setValue(1);
        lbl_saturation_drago = new QDoubleSpinBox(param_drago);
        lbl_saturation_drago->setObjectName(QStringLiteral("lbl_saturation_drago"));
        lbl_saturation_drago->setGeometry(QRect(100, 60, 81, 22));
        lbl_saturation_drago->setMaximum(10);
        lbl_saturation_drago->setSingleStep(0.01);
        lbl_saturation_drago->setValue(1);
        lbl_bias_drago = new QDoubleSpinBox(param_drago);
        lbl_bias_drago->setObjectName(QStringLiteral("lbl_bias_drago"));
        lbl_bias_drago->setGeometry(QRect(100, 100, 81, 22));
        lbl_bias_drago->setMaximum(1);
        lbl_bias_drago->setSingleStep(0.01);
        lbl_bias_drago->setValue(0.85);
        tab_param_tonemap->addWidget(param_drago);
        param_reinhard = new QWidget();
        param_reinhard->setObjectName(QStringLiteral("param_reinhard"));
        const_lbl_light_adapt_reinhard = new QLabel(param_reinhard);
        const_lbl_light_adapt_reinhard->setObjectName(QStringLiteral("const_lbl_light_adapt_reinhard"));
        const_lbl_light_adapt_reinhard->setGeometry(QRect(0, 100, 81, 21));
        const_lbl_light_adapt_reinhard->setFont(font2);
        const_lbl_gamma_reinhard = new QLabel(param_reinhard);
        const_lbl_gamma_reinhard->setObjectName(QStringLiteral("const_lbl_gamma_reinhard"));
        const_lbl_gamma_reinhard->setGeometry(QRect(0, 20, 81, 21));
        const_lbl_gamma_reinhard->setFont(font2);
        const_lbl_intensity_reinhard = new QLabel(param_reinhard);
        const_lbl_intensity_reinhard->setObjectName(QStringLiteral("const_lbl_intensity_reinhard"));
        const_lbl_intensity_reinhard->setGeometry(QRect(0, 60, 81, 21));
        const_lbl_intensity_reinhard->setFont(font2);
        const_lbl_color_adapt_reinhard = new QLabel(param_reinhard);
        const_lbl_color_adapt_reinhard->setObjectName(QStringLiteral("const_lbl_color_adapt_reinhard"));
        const_lbl_color_adapt_reinhard->setGeometry(QRect(0, 140, 81, 21));
        const_lbl_color_adapt_reinhard->setFont(font2);
        lbl_gamma_reinhard = new QDoubleSpinBox(param_reinhard);
        lbl_gamma_reinhard->setObjectName(QStringLiteral("lbl_gamma_reinhard"));
        lbl_gamma_reinhard->setGeometry(QRect(100, 20, 81, 22));
        lbl_gamma_reinhard->setSingleStep(0.01);
        lbl_gamma_reinhard->setValue(1);
        lbl_intensity_reinhard = new QDoubleSpinBox(param_reinhard);
        lbl_intensity_reinhard->setObjectName(QStringLiteral("lbl_intensity_reinhard"));
        lbl_intensity_reinhard->setGeometry(QRect(100, 60, 81, 22));
        lbl_intensity_reinhard->setMinimum(-8);
        lbl_intensity_reinhard->setMaximum(8);
        lbl_intensity_reinhard->setSingleStep(0.01);
        lbl_light_adapt_reinhard = new QDoubleSpinBox(param_reinhard);
        lbl_light_adapt_reinhard->setObjectName(QStringLiteral("lbl_light_adapt_reinhard"));
        lbl_light_adapt_reinhard->setGeometry(QRect(100, 100, 81, 22));
        lbl_light_adapt_reinhard->setMaximum(1);
        lbl_light_adapt_reinhard->setSingleStep(0.01);
        lbl_light_adapt_reinhard->setValue(1);
        lbl_color_adapt_reinhard = new QDoubleSpinBox(param_reinhard);
        lbl_color_adapt_reinhard->setObjectName(QStringLiteral("lbl_color_adapt_reinhard"));
        lbl_color_adapt_reinhard->setGeometry(QRect(100, 140, 81, 22));
        lbl_color_adapt_reinhard->setMaximum(1);
        lbl_color_adapt_reinhard->setSingleStep(0.01);
        tab_param_tonemap->addWidget(param_reinhard);
        lbl_progressBar = new QProgressBar(tab_hdr);
        lbl_progressBar->setObjectName(QStringLiteral("lbl_progressBar"));
        lbl_progressBar->setGeometry(QRect(30, 540, 181, 23));
        lbl_progressBar->setValue(0);
        lbl_progressBar->setAlignment(Qt::AlignCenter);
        lbl_dir_name = new QLineEdit(tab_hdr);
        lbl_dir_name->setObjectName(QStringLiteral("lbl_dir_name"));
        lbl_dir_name->setGeometry(QRect(130, 160, 80, 40));
        lbl_dir_name->setFont(font);
        btn_make_dir = new QPushButton(tab_hdr);
        btn_make_dir->setObjectName(QStringLiteral("btn_make_dir"));
        btn_make_dir->setGeometry(QRect(30, 160, 91, 40));
        btn_make_dir->setFont(font);
        tabWidget->addTab(tab_hdr, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tab_images->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);
        tab_param_tonemap->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "CameraView", nullptr));
        lbl_camera_img->setText(QString());
        tab_images->setTabText(tab_images->indexOf(camera), QApplication::translate("MainWindow", "Camera", nullptr));
        lbl_calculate_img->setText(QString());
        tab_images->setTabText(tab_images->indexOf(calculate), QApplication::translate("MainWindow", "Filter", nullptr));
        lbl_hdr_img->setText(QString());
        tab_images->setTabText(tab_images->indexOf(HDR), QApplication::translate("MainWindow", "HDR", nullptr));
        btn_trigger->setText(QApplication::translate("MainWindow", "Trigger Off", nullptr));
        btn_close->setText(QApplication::translate("MainWindow", "Close", nullptr));
        lbl_height->setText(QString());
        btn_stop->setText(QApplication::translate("MainWindow", "Stop", nullptr));
        btn_start->setText(QApplication::translate("MainWindow", "Start", nullptr));
        comb_trigger_mode->setItemText(0, QApplication::translate("MainWindow", "Freerun", nullptr));
        comb_trigger_mode->setItemText(1, QApplication::translate("MainWindow", "Line1", nullptr));

        lbl_width->setText(QString());
        lbl_exposure->setText(QString());
        lbl_fps_camera->setText(QApplication::translate("MainWindow", "0", nullptr));
        const_lbl_fps_camera->setText(QApplication::translate("MainWindow", " FPS Cam. = ", nullptr));
        lbl_offset_y->setText(QString());
        lbl_offset_x->setText(QString());
        btn_exposure->setText(QApplication::translate("MainWindow", "Exposure", nullptr));
        const_offset_y->setText(QApplication::translate("MainWindow", "Offset Y", nullptr));
        btn_width->setText(QApplication::translate("MainWindow", "Width", nullptr));
        btn_height->setText(QApplication::translate("MainWindow", "Height", nullptr));
        const_offset_x->setText(QApplication::translate("MainWindow", "Offset X", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_camera), QApplication::translate("MainWindow", "Camera", nullptr));
        lbl_fps_filter->setText(QApplication::translate("MainWindow", "0", nullptr));
        const_lbl_fps_filter->setText(QApplication::translate("MainWindow", " FPS Conv. = ", nullptr));
        btn_start_filter->setText(QApplication::translate("MainWindow", "Start", nullptr));
        btn_stop_filter->setText(QApplication::translate("MainWindow", "Stop", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_convol), QApplication::translate("MainWindow", "Filter Opt.", nullptr));
        btn_save_img->setText(QApplication::translate("MainWindow", "Save Img.", nullptr));
        lbl_exposure_start->setText(QString());
        lbl_exposure_step->setText(QString());
        lbl_quantity_img->setText(QString());
        const_lbl_start_exp->setText(QApplication::translate("MainWindow", "Start Exp.", nullptr));
        const_lbl_step_exp->setText(QApplication::translate("MainWindow", "Stept Exp.", nullptr));
        const_lbl_quantity->setText(QApplication::translate("MainWindow", "Quantity", nullptr));
        comb_method_tonemap->setItemText(0, QApplication::translate("MainWindow", "Drago Tonemap", nullptr));
        comb_method_tonemap->setItemText(1, QApplication::translate("MainWindow", "Reinhard Tonemap", nullptr));
        comb_method_tonemap->setItemText(2, QApplication::translate("MainWindow", "Mantiuk Tonemap", nullptr));

        btn_calculate_hdr->setText(QApplication::translate("MainWindow", "Calculate HDR", nullptr));
        const_lbl_gamma_mant->setText(QApplication::translate("MainWindow", "Gamma", nullptr));
        const_lbl_scale_mant->setText(QApplication::translate("MainWindow", "Scale", nullptr));
        const_lbl_saturation_mant->setText(QApplication::translate("MainWindow", "Saturation", nullptr));
        const_lbl_gamma_drago->setText(QApplication::translate("MainWindow", "Gamma", nullptr));
        const_lbl_bias_drago->setText(QApplication::translate("MainWindow", "Bias", nullptr));
        const_lbl_saturation_drago->setText(QApplication::translate("MainWindow", "Saturation", nullptr));
        const_lbl_light_adapt_reinhard->setText(QApplication::translate("MainWindow", "Light adapt", nullptr));
        const_lbl_gamma_reinhard->setText(QApplication::translate("MainWindow", "Gamma", nullptr));
        const_lbl_intensity_reinhard->setText(QApplication::translate("MainWindow", "Intensity", nullptr));
        const_lbl_color_adapt_reinhard->setText(QApplication::translate("MainWindow", "Color adapt", nullptr));
        lbl_dir_name->setText(QString());
        btn_make_dir->setText(QApplication::translate("MainWindow", "Make Dir.", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_hdr), QApplication::translate("MainWindow", "HDR Opt.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
