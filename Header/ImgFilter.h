#pragma once

#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <memory>
#include <iostream>
#include "imageprocessing.h"

#include <QImage>
#include <QTimer>
#include <QRgb>


class ImgFilter : public  ImageProcessing
{
	Q_OBJECT
		Q_INTERFACES(ImageProcessing)

public:
	ImgFilter();
	~ImgFilter();

	void calculateImage(const QImage &, const int&) override;
	void timerEvent(QTimerEvent *) override;

public slots:
	void getImageFromCamera(const QImage &) override;

private:
	QImage m_ptr_img;
	int m_count_rows;
	int m_count_fps;
	double m_kernel[3][3] = { {1, 0, -1}, {2, 0, -2}, {1, 0, -1} };
	std::unique_ptr<QBasicTimer> m_timer;
	std::unique_ptr<QImage> m_result_image;

	std::condition_variable m_cv;
	std::mutex m_mtx;
	std::atomic_bool m_atm_stop;
	std::thread m_thread1;
	std::thread m_thread2;
	std::thread m_thread3;
	std::thread m_thread4;
	std::thread m_thread5;
	void ThreadFunction();
};

