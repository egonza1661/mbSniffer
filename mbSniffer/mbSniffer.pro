TARGET = mbSniffer
TEMPLATE = app
VERSION = 1.0.0


QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    3rdparty/qextserialport/qextserialport.cpp \
    3rdparty/qextserialport/qextserialenumerator.h \
    aboutdialog.cpp \
    crc16.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    3rdparty/qextserialport/qextserialenumerator.h \
    3rdparty/qextserialport/qextserialport.h \
    aboutdialog.h \
    crc16.h \
    mainwindow.h



INCLUDEPATH +=  3rdparty/qextserialport

unix {
    SOURCES += 3rdparty/qextserialport/posix_qextserialport.cpp	\
           3rdparty/qextserialport/qextserialenumerator_unix.cpp
    DEFINES += _TTY_POSIX_
}

win32 {
    SOURCES += 3rdparty/qextserialport/win_qextserialport.cpp \
           3rdparty/qextserialport/qextserialenumerator_win.cpp
    DEFINES += _TTY_WIN_  WINVER=0x0501
    LIBS += -lsetupapi -lws2_32
}

linux*{
    !qesp_linux_udev:DEFINES += QESP_NO_UDEV
    qesp_linux_udev: LIBS += -ludev
}
linux*:DEFINES += __linux__

FORMS += \
    aboutdialog.ui \
    mainwindow.ui

RESOURCES += \
    sniffer_res.qrc


DEFINES += APP_VERSION=\"\\\"$${VERSION}\\\"\"

include(deployment.pri)
