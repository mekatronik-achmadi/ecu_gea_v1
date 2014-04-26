#ifndef FRMCLK_H
#define FRMCLK_H

#include <QMainWindow>
#include <QPalette>
#include <QFrame>
#include <QLayout>
#include <QTimer>
#include <QTabWidget>
#include <qwt/qwt_dial.h>
#include <qwt/qwt_analog_clock.h>

class QwtDial;
class QwtAnalogClock;

class frmclk : public QFrame
{
    Q_OBJECT

public:
    frmclk(QWidget *parent = NULL);


private:
    QPalette colorTheme( const QColor & ) const;
    QwtDial *createDial( void );
};

#endif // FRMCLK_H
