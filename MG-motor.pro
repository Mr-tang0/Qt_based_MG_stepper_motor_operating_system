#-------------------------------------------------
#
# Project created by QtCreator 2024-01-10T10:03:01
#
#-------------------------------------------------

QT       += core gui
QT       += serialport
QT       += charts
# QT       += webengine


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MG-motor
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#MATERIAL-SDK

LIBS+=$$PWD/libs/libcomponents.a
INCLUDEPATH+=$$PWD/libs/Include

CONFIG += c++11

SOURCES += \
    chart.cpp \
    decodethread.cpp \
    formfill.cpp \
    helper.cpp \
        main.cpp \
    mainwindow.cpp \
    weigh.cpp \
    motor.cpp \
    worker.cpp \
    testfunction.cpp \
    login_window.cpp \
    about_window.cpp \
    signup_window.cpp \
    systemset_window.cpp \
    test_window.cpp

HEADERS += \
    chart.h \
    command.h \
    decodethread.h \
    formfill.h \
    headers.h \
    helper.h \
    mainwindow.h \
    weigh.h \
    motor.h \
    worker.h \
    about_window.h \
    login_window.h \
    signup_window.h \
    systemset_window.h \
    test_window.h

FORMS += \
    formfill.ui \
    helper.ui \
    mainwindow.ui \
    login_window.ui \
    about_window.ui \
    signup_window.ui \
    systemset_window.ui \
    test_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resousefile.qrc

win32-msvc*: {
    QMAKE_CFLAGS *= /utf-8
    QMAKE_CXXFLAGS *= /utf-8
}
