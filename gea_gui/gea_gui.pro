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
    qextserialport.cpp

HEADERS  += gea.h \
    qextserialenumerator.h \
    qextserialbase.h \
    posix_qextserialport.h \
    qextserialport.h

FORMS    += gea.ui
DEFINES  += _TTY_POSIX_
