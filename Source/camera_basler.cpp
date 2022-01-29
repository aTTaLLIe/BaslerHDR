#include "camera_basler.h"

Camera_Basler::Camera_Basler()
{
    m_timer = std::unique_ptr<QBasicTimer> { new QBasicTimer() };
}

Camera_Basler::~Camera_Basler()
{
	deleteAll();
}

//------------------------Control Camera-------------------------------------
void Camera_Basler::Init()
{
    qDebug() << "Camera_Basler_Control: PylonInitialize initSome" ;
    PylonInitialize();
    CTlFactory &TlFactory = CTlFactory::GetInstance();
    TlInfoList_t lstInfo;
    int n = TlFactory.EnumerateTls(lstInfo);

    TlInfoList_t::const_iterator it;
    for ( it = lstInfo.begin(); it != lstInfo.end(); ++it ) {
        qDebug() << "FriendlyName: " << it->GetFriendlyName() << "FullName: " << it->GetFullName();
        qDebug() << "VendorName: " << it->GetVendorName() << "DeviceClass: " << it->GetDeviceClass() ;
    }
    UpdateCameraList();
    qDebug() << "Basler Camera Count: " << n;
}

void Camera_Basler::deleteAll()
{
    if(m_isOpenAcquire) {
        StopAcquire();
    }
    CloseCamera();
    PylonTerminate();
}

QStringList Camera_Basler::cameras()
{
    return m_cameralist;
}

void Camera_Basler::UpdateCameraList()
{
    CTlFactory& TLFactory = CTlFactory::GetInstance();
    ITransportLayer * pTl = TLFactory.CreateTl("BaslerGigE");
    DeviceInfoList_t devices;
    int n = pTl->EnumerateDevices(devices);
    CInstantCameraArray cameraArray(devices.size());
    if(n == 0) {
        qDebug() << "Cannot find Any camera!";
        return;
    }
    for (int i=0 ; i<cameraArray.GetSize() ; i++) {
        cameraArray[i].Attach(TLFactory.CreateDevice(devices[i]));
        string sn = cameraArray[i].GetDeviceInfo().GetSerialNumber();
        m_cameralist << QString::fromStdString(sn);
    }
}

int Camera_Basler::OpenCamera(QString cameraSN)
{
    try {
        CDeviceInfo cInfo;
        String_t str = String_t(cameraSN.toStdString().c_str());
        cInfo.SetSerialNumber(str);
        m_basler.Attach(CTlFactory::GetInstance().CreateDevice(cInfo));
        registerHandler(&m_basler);

        m_basler.Open();
        m_isOpen = true;
        qDebug("Connect camera");
    } catch (GenICam::GenericException &e) {
        qDebug() << "OpenCamera Error" << QString(e.GetDescription());
        m_isOpen = false;
        return -2;
    }
    return 0;
}

int Camera_Basler::CloseCamera()
{
    if(!m_isOpen) {
        return -1;
    }
    try {
        if(m_basler.IsOpen()) {
            m_basler.DetachDevice();
            m_basler.Close();
        }
    } catch (GenICam::GenericException &e) {
        qDebug() << "CloseCamera Error:" << QString(e.GetDescription());
        return -2;
    }
    return 0;
}

void Camera_Basler::setExposureTime(double time)
{
    auto &cameraNodeMap = m_basler.GetNodeMap();
    const CFloatPtr exposureTime = cameraNodeMap.GetNode("ExposureTimeAbs");
    exposureTime->SetValue(time);
}

void Camera_Basler::setHeight(qint64 height)
{
	auto &cameraNodeMap = m_basler.GetNodeMap();
	const CIntegerPtr heightPic = cameraNodeMap.GetNode("Height");
	if (IsWritable(heightPic)) {
		qint64 newHeight = adjust(height, heightPic->GetMin(), heightPic->GetMax(), heightPic->GetInc());
		heightPic->SetValue(newHeight);
	}
}

void Camera_Basler::setWidth(qint64 width)
{
	auto &cameraNodeMap = m_basler.GetNodeMap();
	const CIntegerPtr widthPic = cameraNodeMap.GetNode("Width");
	if (IsWritable(widthPic)) {
		qint64 newWidth = adjust(width, widthPic->GetMin(), widthPic->GetMax(), widthPic->GetInc());
		widthPic->SetValue(newWidth);
	}
}

unsigned int Camera_Basler::getHeight()
{
	auto &cameraNodeMap = m_basler.GetNodeMap();
	const CIntegerPtr heightPic = cameraNodeMap.GetNode("Height");
	return heightPic->GetValue();
}

unsigned int Camera_Basler::getWidth()
{
	auto &cameraNodeMap = m_basler.GetNodeMap();
	const CIntegerPtr widthPic = cameraNodeMap.GetNode("Width");
	return widthPic->GetValue();
}

void Camera_Basler::setOffsetX(qint64 offset_x)
{
	CIntegerPtr ptr_offset_x(m_basler.GetNodeMap().GetNode("OffsetX"));
	if (IsWritable(ptr_offset_x)) {
		qint64 new_offset_x = adjust(offset_x, ptr_offset_x->GetMin(), ptr_offset_x->GetMax(), ptr_offset_x->GetInc());
		ptr_offset_x->SetValue(new_offset_x);
	}
}

void Camera_Basler::setOffsetY(qint64 offset_y)
{
	CIntegerPtr ptr_offset_y(m_basler.GetNodeMap().GetNode("OffsetY"));
	if (IsWritable(ptr_offset_y)) {
		qint64 new_offset_y = adjust(offset_y, ptr_offset_y->GetMin(), ptr_offset_y->GetMax(), ptr_offset_y->GetInc());
		ptr_offset_y->SetValue(new_offset_y);
	}
}

qint64 Camera_Basler::adjust(qint64 val, qint64 minimum, qint64 maximum, qint64 inc)
{
	if (inc <= 0) {
		throw LOGICAL_ERROR_EXCEPTION("Unexpected increment %d", inc);
	}
	if (minimum > maximum) {
		throw LOGICAL_ERROR_EXCEPTION("minimum bigger than maximum.");
	}

	if (val < minimum) {
		return minimum;
	}

	if (val > maximum) {
		return maximum;
	}

	if (inc == 1) {
		return val;
	}
	else {
		return minimum + (((val - minimum) / inc) * inc);
	}
}

tuple_AOI Camera_Basler::getGeometryAOI() 
{
	auto &cameraNodeMap = m_basler.GetNodeMap();
	const CIntegerPtr height = cameraNodeMap.GetNode("Height");
	const CIntegerPtr width = cameraNodeMap.GetNode("Width");
	const CIntegerPtr offset_x = cameraNodeMap.GetNode("OffsetX");
	const CIntegerPtr offset_y = cameraNodeMap.GetNode("OffsetY");
	tuple_AOI param_AOI;
	try 
	{
		param_AOI = {height->GetValue(), width->GetValue(), offset_x->GetValue(), offset_y->GetValue() };
		return param_AOI;
	}
	catch (const std::exception& exp)
	{
		return param_AOI;
	}
}


int Camera_Basler::getExposureTime()
{
    auto &cameraNodeMap = m_basler.GetNodeMap();
    const CFloatPtr exposureTime = cameraNodeMap.GetNode("ExposureTimeAbs");
    return static_cast<int>(exposureTime->GetValue());
}


void Camera_Basler::setFeatureTriggerSourceType(QString type)
{
    if(m_isOpenAcquire) {
        StopAcquire();
    }
    qDebug() << "Set trigger mode: " + type;
    m_currentMode = type;
    auto &cameraNodeMap = m_basler.GetNodeMap();
    CEnumerationPtr  ptrTriggerSel = cameraNodeMap.GetNode ("TriggerSelector");
    ptrTriggerSel->FromString("FrameStart");
    if(type == "Freerun") {
        CEnumerationPtr  ptrTrigger  = cameraNodeMap.GetNode ("TriggerMode");
        ptrTrigger->SetIntValue(0);
    } else if(type == "Line1"){
        CEnumerationPtr  ptrTriggerSource = cameraNodeMap.GetNode ("TriggerSource");
        ptrTriggerSource->FromString("Line1");
    }
}


void Camera_Basler::setFeatureTriggerModeType(bool on)
{
    auto &cameraNodeMap = m_basler.GetNodeMap();
    CEnumerationPtr  ptrTriggerSel = cameraNodeMap.GetNode ("TriggerSelector");
    ptrTriggerSel->FromString("FrameStart");
    CEnumerationPtr  ptrTrigger  = cameraNodeMap.GetNode ("TriggerMode");
    ptrTrigger->SetIntValue(on?1:0);
}

bool Camera_Basler::getFeatureTriggerModeType()
{
    auto &cameraNodeMap = m_basler.GetNodeMap();
    CEnumerationPtr  ptrTriggerSel = cameraNodeMap.GetNode ("TriggerSelector");
    ptrTriggerSel->FromString("FrameStart");
    CEnumerationPtr  ptrTrigger  = cameraNodeMap.GetNode ("TriggerMode");
    return ptrTrigger->GetIntValue() == 1;
}

long Camera_Basler::StartAcquire()
{
    m_isOpenAcquire = true;
    try {
        if(getFeatureTriggerModeType())
            qDebug() << "Trigger is On ";

         qDebug() << "Camera_Basler StartAcquire" << m_currentMode;
         if(m_currentMode == "Freerun")  {
             m_basler.StartGrabbing(GrabStrategy_LatestImageOnly,GrabLoop_ProvidedByInstantCamera);
         } else if(m_currentMode == "Software") {
             m_basler.StartGrabbing(GrabStrategy_LatestImageOnly);
         } else if(m_currentMode == "Line1") {
             m_basler.StartGrabbing(GrabStrategy_LatestImages, GrabLoop_ProvidedByInstantCamera);
         } else if(m_currentMode == "Line2") {
             m_basler.StartGrabbing(GrabStrategy_OneByOne);
         }
         m_timer->start(1000, this);
    } catch (GenICam::GenericException &e) {
        qDebug() << "StartAcquire Error:" << QString(e.GetDescription());
        return -2;
    }
    return 0;
}

int Camera_Basler::StopAcquire()
{
    m_isOpenAcquire = false;
    qDebug() << "Camera_Basler StopAcquire";
    try {
        if (m_basler.IsGrabbing()) {
            m_basler.StopGrabbing();
        }
        m_timer->stop();
        emit(sigCameraFPS(0));
    } catch (GenICam::GenericException &e) {
        qDebug() << "StopAcquire Error:" << QString(e.GetDescription());
        return -2;
    }
    return 0;
}


//------------------------Grab Image-------------------------------------
void Camera_Basler::CopyToImage(CGrabResultPtr pInBuffer, QImage &OutImage)
{
    try {
        uchar* buff = (uchar*)pInBuffer->GetBuffer();
        int nHeight = pInBuffer->GetHeight();
        int nWidth = pInBuffer->GetWidth();
        QImage imgBuff(buff, nWidth, nHeight, QImage::Format_Indexed8);
        OutImage = imgBuff;
        if(pInBuffer->GetPixelType() == PixelType_Mono8) {
            uchar* pCursor = OutImage.bits();
            if ( OutImage.bytesPerLine() != nWidth ) {
                for ( int y=0; y<nHeight; ++y ) {
                    pCursor = OutImage.scanLine( y );
                    for ( int x=0; x<nWidth; ++x ) {
                        *pCursor =* buff;
                        ++pCursor;
                        ++buff;
                    }
                }
            } else {
                memcpy(OutImage.bits(), buff, nWidth * nHeight );
            }
        }
    } catch (GenICam::GenericException &e) {
        qDebug() << "CopyToImage Error:" << QString(e.GetDescription());
    }
}

void Camera_Basler::GetOneImage()
{
    CGrabResultPtr grabResult;
    QImage image;
    if(m_basler.GrabOne(1000, grabResult))
    {
        if (grabResult->GrabSucceeded())
        {
            CopyToImage(grabResult, image);
        }
        if(!image.isNull()) {
            emit sigCurrentImage(image);
        }
    }
}

//*********************Event Heandle********************************************************

void Camera_Basler::OnImageGrabbed(CInstantCamera &camera, const CGrabResultPtr &grabResult)
{
    ++m_camera_fps;
    if(m_isOpenAcquire) {
        QImage image;
        try
        {
            if (!camera.IsGrabbing()) {
                StartAcquire();
            }
            if (grabResult->GrabSucceeded()) {
                if (!grabResult.IsValid()) { OutputDebugString(L"GrabResult not Valid Error\n"); return; }
                EPixelType pixelType = grabResult->GetPixelType();
                switch (pixelType) {
                case PixelType_Mono8: {
                    CopyToImage(grabResult, image);
                } break;
                case PixelType_BayerRG8: { qDebug() << "what: PixelType_BayerRG8"; }  break;
                default:  qDebug() << "what: default"; break;
                }
            } else {
                qDebug() << "Grab Error!!!";
                return;
            }
        } catch (GenICam::GenericException &e) {
            qDebug() << "GrabImage Error:" << QString(e.GetDescription());
            return;
        }
        if(!image.isNull()) {
            emit sigCurrentImage(image);
        }
    }
}

bool Camera_Basler::registerHandler(CInstantCamera *camera)
{
    try {
        // Register this object as an image event handler, so we will be notified of new new images
        // See Pylon::CImageEventHandler for details
        camera->RegisterImageEventHandler(this, Pylon::RegistrationMode_ReplaceAll, Pylon::Ownership_ExternalOwnership);
        // Register this object as a configuration event handler, so we will be notified of camera state changes.
        // See Pylon::CConfigurationEventHandler for details
        camera->RegisterConfiguration(this, Pylon::RegistrationMode_ReplaceAll, Pylon::Ownership_ExternalOwnership);
    } catch (const Pylon::GenericException& e) {
        qDebug() << QString(e.what());
        return false;
    }
    return true;
}

void Camera_Basler::timerEvent(QTimerEvent* )
{
//    qDebug("Send FPS");
    emit(sigCameraFPS(m_camera_fps));
    m_camera_fps = 0;
}
