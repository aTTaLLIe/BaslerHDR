#pragma once


#include "ui_mainwindow.h"

class uiGUIObject : public QObject
{
	Q_OBJECT

public:
	uiGUIObject();
	virtual ~uiGUIObject();

	virtual void ButtonControl() = 0;
	virtual void SignalSlotControl() = 0;

	virtual bool getFlagStartCalculate() = 0;
};
Q_DECLARE_INTERFACE(uiGUIObject, "GUIObject")
