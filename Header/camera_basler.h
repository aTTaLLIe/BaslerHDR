#ifndef CAMERA_BASLER_H
#define CAMERA_BASLER_H

#include"camera.h"
#include <pylon/PylonIncludes.h>
#include <QTimer>

#define DOUBLE_MAX 100000
#define DOUBLE_MIN 0

using namespace std;
using namespace Pylon;
using namespace GenApi;

class Camera_Basler : public Camera,
        public CImageEventHandler,
        public CConfigurationEventHandler
{
    Q_OBJECT
    Q_INTERFACES(Camera)

private:
//    enum BaslerCameraControl_Type{
//        Type_Basler_Freerun,
//        Type_Basler_Line1,
//        Type_Basler_ExposureTimeAbs,
//        Type_Basler_GainRaw,
//        Type_Basler_AcquisitionFrameRateAbs,
//        Type_Basler_Width,
//        Type_Basler_Height,
//        Type_Basler_LineSource,
//    };

    CInstantCamera m_basler;
    QStringList m_cameralist;
    QString m_currentMode = "Freerun";
    unique_ptr<QBasicTimer> m_timer;
    unsigned int m_camera_fps = 0;
    bool m_isOpenAcquire = false;
    bool m_isOpen = false;

public:
    explicit Camera_Basler();
    ~Camera_Basler();
//-----------------------------------------------------------
    void Init() override;
    int OpenCamera(QString) override;
    int CloseCamera() override;

    void setExposureTime(double) override;
    int getExposureTime() override;

	tuple_AOI getGeometryAOI() override;

	void setHeight(qint64) override;
	void setWidth(qint64) override;
	void setOffsetX(qint64) override;
	void setOffsetY(qint64) override;

    unsigned int getHeight() override;
    unsigned int getWidth() override;

    void setFeatureTriggerSourceType(QString) override;

    void setFeatureTriggerModeType(bool) override;
    bool getFeatureTriggerModeType() override;

    void GetOneImage() override;
    long StartAcquire() override;
    int StopAcquire() override;
    QStringList cameras() override;
//-----------------------------------------------------------

    void UpdateCameraList();
    void deleteAll();

    void CopyToImage(CGrabResultPtr pInBuffer, QImage &OutImage);
	qint64 adjust(qint64, qint64, qint64, qint64);
//-----------------------------------------------------------
    void OnImageGrabbed(CInstantCamera &, const CGrabResultPtr &) override;
    bool registerHandler(CInstantCamera *);
    void timerEvent(QTimerEvent *) override;
};

#endif // CAMERA_BASLER_H
