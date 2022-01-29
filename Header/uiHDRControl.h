#pragma once

#include <vector>

#include "uiGUIObject.h"
#include "LogFiles.h"
#include "processinghdr.h"

using namespace std;

class uiHDRControl : public uiGUIObject
{
	Q_OBJECT
	Q_INTERFACES(uiGUIObject)

public:
	uiHDRControl(Ui::MainWindow *ui_window, ProcessingHDR *HDR_image, LogFiles *loger);
	~uiHDRControl();

	void ButtonControl() override;
	void SignalSlotControl() override;

	bool getFlagStartCalculate() override { return true; };
	std::vector<float> getTonemapParam(const std::string & method);

private:
	Ui::MainWindow *m_ui_window;
	ProcessingHDR *m_HDR_image;
	LogFiles *m_loger;

	unsigned int m_curent_exposure;
	unsigned int m_step_exposure;
	unsigned int m_target_exposure;
};

