#pragma once

#include "uiGUIObject.h"
#include "imageprocessing.h"
#include "QImage"

class uiCalculateControl : public uiGUIObject
{
	Q_OBJECT
	Q_INTERFACES(uiGUIObject)

public:
	uiCalculateControl(Ui::MainWindow *ptr_ui_window, ImageProcessing *ptr_img_filter, QImage *ptr_image);
	~uiCalculateControl();

	void ButtonControl() override;
	void SignalSlotControl() override;

	bool getFlagStartCalculate() override;

private:
	Ui::MainWindow *m_ptr_ui_window;
	ImageProcessing *m_ptr_img_filter;
	QImage *m_ptr_image;
	bool processing_img;
};

