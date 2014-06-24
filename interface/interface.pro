#-------------------------------------------------
#
# Project created by QtCreator 2014-06-05T18:26:17
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = interface
TEMPLATE = app


SOURCES += main.cpp\
        interface.cpp \
    dial_meter.cpp \
    dial_display.cpp

HEADERS  += interface.h \
    dial_meter.h \
    dial_display.h

FORMS    += interface.ui

CONFIG += qwt
INCLUDEPATH += /usr/local/qwt-6.1.0/include
LIBS += -L/usr/local/qwt-6.1.0/lib -lqwt

RESOURCES += \
    gambar.qrc
