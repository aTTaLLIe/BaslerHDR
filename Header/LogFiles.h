#pragma once

#include <QString>
#include <QPixmap>
#include <QImage>
#include <filesystem>
#include <memory>
#include <fstream>

#include "camera_basler.h"

class LogFiles
{
public:
	LogFiles(QImage *, Camera *);
	~LogFiles();

	void SaveImage(const QString &);
	void CollectImage(unsigned int& m_curent_exposure, const unsigned int& m_target_exposure, const unsigned int& m_step_exposure);
	void MakeDirectory(const std::string &);

	std::filesystem::path GetPathDir();

private:
	std::filesystem::path m_path_direct;
	std::unique_ptr<std::ofstream> m_file_exposure;
	std::unique_ptr<std::ofstream> m_file_name;

	QImage *m_input_img;
	Camera *m_camera;
};

