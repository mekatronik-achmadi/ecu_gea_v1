#ifndef FRMTPS_H
#define FRMTPS_H

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

class frmtps : public QFrame
{
    Q_OBJECT

public:
    frmtps(QWidget *parent = NULL);

private slots:
    void changeTPS(void);

private:
    QPalette colorTheme( const QColor & ) const;
    QwtDial *createDial( void );

    dial_Meter *d_tps;
};

#endif // FRMTPS_H
