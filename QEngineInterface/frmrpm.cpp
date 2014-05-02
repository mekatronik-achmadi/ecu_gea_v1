#include "frmrpm.h"
#include "dial_meter.h"

extern int val_rpm;

frmrpm::frmrpm(QWidget *parent) :
    QFrame(parent)
{
    setAutoFillBackground( true );

    setPalette( colorTheme( QColor( Qt::darkBlue ).dark( 150 ) ) );

    QGridLayout *layout = new QGridLayout( this );
    layout->setSpacing( 5 );
    layout->setMargin( 0 );


    QwtDial *dial = createDial();
    layout->addWidget( dial, 0, 0 );

}

QwtDial *frmrpm::createDial(void){
    QwtDial *dial=NULL;

    d_tacho = new dial_Meter( this );
    d_tacho->setScaleStepSize( 1000.0 );
    d_tacho->setScale( 0.0, 15000.0 );
    d_tacho->scaleDraw()->setPenWidth( 2 );
    d_tacho->setLabel("RPM");

    QTimer *timer = new QTimer( d_tacho );
    timer->connect( timer, SIGNAL( timeout() ),this, SLOT( changeRPM() ) );
    timer->start( 10 );

    dial = d_tacho;
    return dial;
}

QPalette frmrpm::colorTheme(const QColor &base) const{
    QPalette palette;
    palette.setColor( QPalette::Base, base );
    palette.setColor( QPalette::Window, base.dark( 150 ) );
    palette.setColor( QPalette::Mid, base.dark( 110 ) );
    palette.setColor( QPalette::Light, base.light( 170 ) );
    palette.setColor( QPalette::Dark, base.dark( 170 ) );
    palette.setColor( QPalette::Text, base.dark( 200 ).light( 800 ) );
    palette.setColor( QPalette::WindowText, base.dark( 200 ) );

    return palette;
}

void frmrpm::changeRPM(void){
    double value = val_rpm;
    d_tacho->setValue(value);
}

