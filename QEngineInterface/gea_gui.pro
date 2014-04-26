#-------------------------------------------------
#
# Project created by QtCreator 2014-03-09T06:36:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gea_gui
TEMPLATE = app


SOURCES += main.cpp\
        gea.cpp \
    posix_qextserialport.cpp \
    qextserialenumerator.cpp \
    qextserialbase.cpp \
    qextserialport.cpp \
    frmrpm.cpp \
    dial_meter.cpp \
    frmtps.cpp \
    frmclk.cpp \
    frmign.cpp \
    frminj.cpp

HEADERS  += gea.h \
    qextserialenumerator.h \
    qextserialbase.h \
    posix_qextserialport.h \
    qextserialport.h \
    frmrpm.h \
    dial_meter.h \
    frmtps.h \
    frmclk.h \
    frmign.h \
    frminj.h

FORMS    += gea.ui \
    frmrpm.ui \
    frmtps.ui \
    frmclk.ui \
    frmign.ui \
    frminj.ui
DEFINES  += _TTY_POSIX_

CONFIG += qwt

INCLUDEPATH += /usr/local/qwt-6.1.0/include
LIBS += -L/usr/local/qwt-6.1.0/lib -lqwt

