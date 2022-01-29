#ifndef IMAGEPROCESSING_H
#define IMAGEPROCESSING_H

#include <QObject>
#include <QImage>
#include <QDebug>

class ImageProcessing : public QObject
{
    Q_OBJECT
public:
    ImageProcessing(QObject *parent = nullptr);
    virtual ~ImageProcessing();

    virtual void calculateImage(const QImage &, const int&) = 0;

public slots:
    virtual void getImageFromCamera(const QImage &) = 0;

signals:
    void sigCalulateImage(const QImage &);
	void sigCalulateFPS(const unsigned int);
};
Q_DECLARE_INTERFACE(ImageProcessing, "ImageProcessing")
#endif // IMAGEPROCESSING_H
