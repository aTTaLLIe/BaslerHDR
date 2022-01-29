#-------------------------------------------------
#
# Project created by QtCreator 2021-11-22T14:20:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Main_Camera_Basler
TEMPLATE = app

CONFIG   += c++17


#--------------------------------------------Basler-------------------------------------------
INCLUDEPATH += $$PWD/include
LIBS += -L$$PWD/lib/x64 -lGCBase_MD_VC120_v3_0_Basler_pylon_v5_0 -lGenApi_MD_VC120_v3_0_Basler_pylon_v5_0 -lPylonBase_MD_VC120_v5_0 -lPylonC_MD_VC120 -lPylonGUI_MD_VC120_v5_0 -lPylonUtility_MD_VC120_v5_0
#----------------------------------------------------------------------------------------------

CONFIG(debug, debug|release) {
    DESTDIR = $$PWD/bin_debug
    LIBS += -L$$PWD/bin_debug
}
CONFIG(release, debug|release) { # Конфигурация драйвера????????????
    DESTDIR = $$PWD/bin_release
    LIBS += -L$$PWD/bin_release
}


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    camera.cpp \
    camera_basler.cpp \
    imageprocessing.cpp \
    wavelet.cpp \
    processinghdr.cpp

HEADERS += \
        mainwindow.h \
    camera.h \
    camera_basler.h \
    imageprocessing.h \
    wavelet.h \
    processinghdr.h

FORMS += \
        mainwindow.ui
