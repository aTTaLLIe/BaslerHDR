#include "ImgFilter.h"

ImgFilter::ImgFilter()
{
	m_atm_stop = false;
	m_count_fps = 0;
	m_count_rows = 0;
	m_timer = std::unique_ptr<QBasicTimer>{ new QBasicTimer{} };
	m_thread1 = std::thread(&ImgFilter::ThreadFunction, this);
	m_thread2 = std::thread(&ImgFilter::ThreadFunction, this);
	m_thread3 = std::thread(&ImgFilter::ThreadFunction, this);
	m_thread4 = std::thread(&ImgFilter::ThreadFunction, this);
	m_thread5 = std::thread(&ImgFilter::ThreadFunction, this);
	m_timer->start(1000, this);
}

ImgFilter::~ImgFilter()
{
	m_atm_stop = true;
	m_cv.notify_all();
	if (m_thread1.joinable())
		m_thread1.join();
	if (m_thread2.joinable())
		m_thread2.join();
	if (m_thread3.joinable())
		m_thread3.join();
	if (m_thread4.joinable())
		m_thread4.join();
	if (m_thread5.joinable())
		m_thread5.join();
}


void ImgFilter::getImageFromCamera(const QImage & input_img)
{
	if (!m_result_image)
	{
		m_result_image = std::unique_ptr<QImage>{ new QImage{input_img.size(), QImage::Format_RGB32} };
	}

	if(m_ptr_img.isNull())
	{
		m_ptr_img = input_img.copy();
		m_cv.notify_all();
	}

	if(input_img.size() != m_result_image->size())
	{
		m_result_image.reset();
		m_result_image = std::unique_ptr<QImage>{ new QImage{input_img.size(), QImage::Format_RGB32} };
	}

	std::lock_guard<std::mutex> lk(m_mtx);
	if (m_count_rows >= input_img.height() || m_ptr_img.size() != input_img.size())
	{
		m_count_rows = 0;
		m_ptr_img = input_img.copy();
		m_cv.notify_all();
	}
}

void ImgFilter::calculateImage(const QImage & input_img, const int& number_row = 0)
{
	auto ptr_input_pixel = input_img.bits();
	auto ptr_result_pixel = m_result_image->bits();
	int other_color = 0;
	if( number_row > 0  && number_row < input_img.height() - 2 && m_result_image)
	{
		for (int count_col = 1; count_col < input_img.width() - 2; ++count_col)
		{
			int new_pixel = ptr_input_pixel[count_col - 1 + (number_row - 1) * (input_img.width())] * m_kernel[0][0] + 
							ptr_input_pixel[count_col + (number_row - 1) * (input_img.width())] * m_kernel[0][1] +
							ptr_input_pixel[count_col + 1 + (number_row - 1) * (input_img.width())] * m_kernel[0][2] +
							ptr_input_pixel[count_col - 1 + number_row * (input_img.width())] * m_kernel[1][0] +
							ptr_input_pixel[count_col + number_row * (input_img.width())] * m_kernel[1][1] + 
							ptr_input_pixel[count_col + 1 + number_row * (input_img.width())] * m_kernel[1][2] + 
							ptr_input_pixel[count_col - 1 + (number_row + 1) * (input_img.width())] * m_kernel[2][0] +
							ptr_input_pixel[count_col + (number_row + 1) * (input_img.width())] * m_kernel[2][1] +
							ptr_input_pixel[count_col + 1 + (number_row + 1) * (input_img.width())] * m_kernel[2][2];
			//Create pixel color
			new_pixel *= 5;
			if (new_pixel > 0)
			{
				new_pixel = new_pixel > 255? 255:new_pixel;
				other_color = 255 - new_pixel;
				new_pixel <<= 16;
				new_pixel |= other_color;
				other_color <<= 8;
				new_pixel |= other_color;
			}

			if (new_pixel < 0)
			{
				new_pixel *= -1;
				new_pixel = new_pixel > 255 ? 255 : new_pixel;
				other_color = 255 - new_pixel;
				other_color <<= 8;
				new_pixel |= other_color;
				other_color <<= 8;
				new_pixel |= other_color;
			}
			if (new_pixel == 0)
			{
				new_pixel |= 0x00AAAAAA;
			}

			memcpy(&ptr_result_pixel[(count_col + number_row * (input_img.width())) * 4], &new_pixel, sizeof(int));
		}
	}
}

void ImgFilter::ThreadFunction()
{
	int current_count = 0;
	while (!m_atm_stop)
	{
		std::unique_lock<std::mutex> lk(m_mtx);
		m_cv.wait(lk, [=]() {return m_count_rows < m_ptr_img.height() || m_atm_stop; });
		if (m_count_rows < m_ptr_img.height())
		{
			++m_count_rows;
			current_count = m_count_rows;
			lk.unlock();
			calculateImage(m_ptr_img, current_count);
			if (current_count >= m_ptr_img.height())
			{
				std::lock_guard<std::mutex> lk(m_mtx);
				//qDebug() << "Count= " + QString::number(m_count_rows) + " Thread ID = " + std::hash<std::thread::id>{}(std::this_thread::get_id());
				++m_count_fps;
				emit sigCalulateImage(*m_result_image.get());
			}
		}
	}
}

void ImgFilter::timerEvent(QTimerEvent *)
{
	emit sigCalulateFPS(m_count_fps);
	m_count_fps = 0;
}
