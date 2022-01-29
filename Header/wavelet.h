#ifndef DERIVATIVEIMAGE_H
#define DERIVATIVEIMAGE_H

#include <imageprocessing.h>
#include <thread>
#include <queue>
#include <condition_variable>
#include <mutex>
#include <memory>
#include <iostream>
#include <QPixmap>

using shared_ptr_img = std::shared_ptr<std::queue<QImage>>;

class WaveletImage : public ImageProcessing
{
    Q_OBJECT
    Q_INTERFACES(ImageProcessing)

private:
    std::condition_variable m_cond_var;
    std::mutex m_cv_mutex;
    std::atomic_bool m_quit;
    shared_ptr_img m_ptr_queue_img;
    std::thread m_thread1;
    std::thread m_thread2;
    std::thread m_thread3;
    void ThreadFunction();

//-----------------------Wavelet---------------------------

public:
    WaveletImage();
    ~WaveletImage();
    void calculateImage(const QImage &, const int&) override;

public slots:
    void getImageFromCamera(const QImage &) override;
};

#endif // DERIVATIVEIMAGE_H
