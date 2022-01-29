#ifndef CAMERA_H
#define CAMERA_H

#include <QObject>
#include <qDebug>
#include <QImage>
#include <tuple>

using tuple_AOI = std::tuple<quint64, qint64, qint64, qint64>; //(Width, Height, Offset X, Offset Y)

class Camera : public QObject
{
    Q_OBJECT
public:
    explicit Camera();

    virtual ~Camera();

    virtual void Init() = 0;
    virtual int OpenCamera(QString) = 0;
    virtual int CloseCamera() = 0;

    virtual void setExposureTime(double) = 0;
    virtual int getExposureTime() = 0;

	virtual void setHeight(qint64) = 0;
	virtual void setWidth(qint64) = 0;
	virtual void setOffsetX(qint64) = 0;
	virtual void setOffsetY(qint64) = 0;
	
	virtual tuple_AOI getGeometryAOI() = 0;
	virtual unsigned int getHeight() = 0;
	virtual unsigned int getWidth() = 0;

    virtual void setFeatureTriggerSourceType(QString) = 0;

    virtual void setFeatureTriggerModeType(bool) = 0;
    virtual bool getFeatureTriggerModeType() = 0;

    virtual void GetOneImage() = 0;
    virtual long StartAcquire() = 0;
    virtual int StopAcquire() = 0;
    virtual QStringList cameras() = 0;
//*************************************************
signals:
    void sigCurrentImage(QImage);
    void sigCameraFPS(unsigned int);
};
Q_DECLARE_INTERFACE(Camera, "Camera")

#endif // CAMERA_H
