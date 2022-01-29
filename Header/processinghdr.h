#ifndef PROCESSINGHDR_H
#define PROCESSINGHDR_H

#include <QObject>
#include <QImage>

#include <iostream>
#include <fstream>
#include <cmath>
#include <conio.h>
#include <vector>
#include <string>
#include <memory>

#include <filesystem>

#include <opencv2/core/mat.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/photo.hpp>

using namespace cv;
using namespace std;

class ProcessingHDR : public QObject
{
	Q_OBJECT

private:
	Mat m_hdrDebevec_img;
	std::filesystem::path m_path_direct;

public:
    ProcessingHDR(QObject * parent = nullptr);
    ~ProcessingHDR();

	void setPathDirectory(std::filesystem::path);

public slots:
    void sltStartCalculate(const QString&, const vector<float>&);

signals:
    void sigImageHDR(QImage);
	void sigProgressBarValue(unsigned int);
};

#endif // PROCESSINGHDR_H
