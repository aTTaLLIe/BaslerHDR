#pragma once

#include "camera_basler.h"
#include "uiGUIObject.h"

class uiCameraControl : public	uiGUIObject
{
	Q_OBJECT
	Q_INTERFACES(uiGUIObject)

public:
	uiCameraControl(Ui::MainWindow *ptr_ui_window, Camera *ptr_camera);
	~uiCameraControl();

	void ButtonControl() override;
	void SignalSlotControl() override;
	void setButtonTriggerState(bool);

	bool getFlagStartCalculate() override { return true; };

private:
	Ui::MainWindow *m_ui_window;
	Camera *m_camera;
};

