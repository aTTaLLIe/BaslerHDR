#include "wavelet.h"

WaveletImage::WaveletImage()
{
    m_ptr_queue_img = std::make_shared<std::queue<QImage>>();
    m_quit = false;
    m_thread1 = std::thread(&WaveletImage::ThreadFunction, this);
    m_thread2 = std::thread(&WaveletImage::ThreadFunction, this);
    m_thread3 = std::thread(&WaveletImage::ThreadFunction, this);
}

WaveletImage::~WaveletImage()
{
    m_quit = true;
    m_cond_var.notify_all();
    if(m_thread1.joinable())
        m_thread1.join();
    if(m_thread2.joinable())
        m_thread2.join();
    if(m_thread3.joinable())
        m_thread3.join();
}

void WaveletImage::calculateImage(const QImage &img, const int& num = 0)
{
//    QPixmap test_pixmap = QPixmap::fromImage(img);
    emit sigCalulateImage(img);
}

void WaveletImage::ThreadFunction()
{
    while(!m_quit)
    {
        std::unique_lock<std::mutex> lk(m_cv_mutex);
        m_cond_var.wait(lk, [&](){return !m_ptr_queue_img->empty() || m_quit;});
        if(!m_ptr_queue_img->empty())
        {
//            qDebug() << "Size of queue= " + QString::number(m_ptr_queue_img->size()) + " Thread ID = " + std::hash<std::thread::id>{}(std::this_thread::get_id());
            QImage buffer_image = std::move(m_ptr_queue_img->front());
            calculateImage(buffer_image);
            m_ptr_queue_img->pop();
            lk.unlock();
        }
    }
}

// SLOTS
void WaveletImage::getImageFromCamera(const QImage &img)
{
    std::lock_guard<std::mutex> lk(m_cv_mutex);
    if(m_ptr_queue_img->size() <= 3)
    {
        m_ptr_queue_img->push(img);
    }
    else
    {
        while(!m_ptr_queue_img->empty())
        {
            m_ptr_queue_img->pop();
        }
    }
    m_cond_var.notify_one();
}
