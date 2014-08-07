#ifndef DIAL_DISPLAY_H
#define DIAL_DISPLAY_H

#include <qframe.h>
#include <qpalette.h>
#include <qlabel.h>

#include <qtimer.h>

class QwtDial;
class QwtAnalogClock;
class dial_meter;

class dial_display: public QFrame
{
    Q_OBJECT

public:
    dial_display(QWidget *parent = NULL);

private:
    QwtDial *createDial( int pos );


    dial_meter* d_tps;
    dial_meter* d_rpm;
    dial_meter* d_inj;
    dial_meter* d_ign;
    dial_meter* d_temp;
    dial_meter* d_map;
//    QwtAnalogClock* d_clock;
//    dial_meter* d_o2;

    QTimer* tmrUpdateValue;

private slots:
    void updateValue();

};

#endif // DIAL_DISPLAY_H
