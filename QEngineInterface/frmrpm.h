#ifndef FRMRPM_H
#define FRMRPM_H

#include <QWidget>
#include <QMainWindow>
#include <QPalette>
#include <QFrame>
#include <QLayout>
#include <QTimer>
#include <QTabWidget>
#include <QString>
#include <QPainter>
#include <qwt_dial.h>
#include <qwt_round_scale_draw.h>
#include "dial_meter.h"
#include "gea.h"

class QwtDial;
class dial_Meter;

class frmrpm : public QFrame
{
    Q_OBJECT

public:
    frmrpm(QWidget *parent = NULL);

private slots:
    void changeRPM(void);

private:
    QPalette colorTheme( const QColor & ) const;
    QwtDial *createDial( void );

    dial_Meter *d_tacho;
};

#endif // FRMRPM_H
