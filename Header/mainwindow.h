#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <memory>
#include <QTimer>
#include <QPainter>
#include <sstream>
#include <QFileDialog>


#include "camera_basler.h"
#include "ImgFilter.h"
#include "LogFiles.h"
#include "processinghdr.h"
#include "uiCameraControl.h"
#include "uiHDRControl.h"
#include "uiCalculateControl.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void ConnectButtons();
    void ConnectLabelsSlots();
private:
    Ui::MainWindow *ui;

	std::unique_ptr<Camera> m_camera;
	std::unique_ptr<ImageProcessing> m_img_filter;
	std::unique_ptr<ProcessingHDR> m_HDR_image;

	std::unique_ptr<LogFiles> m_loger;
	std::unique_ptr<uiGUIObject> m_camera_control;
	std::unique_ptr<uiGUIObject> m_HDR_control;
	std::unique_ptr<uiGUIObject> m_ñalculate_control;

    QImage m_input_img;
};

#endif // MAINWINDOW_H
