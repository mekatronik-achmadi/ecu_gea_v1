#include "frmtps.h"
#include "dial_meter.h"

extern int val_tps;

frmtps::frmtps(QWidget *parent) :
    QFrame(parent)
{
    setAutoFillBackground( true );

    setPalette( colorTheme( QColor( Qt::darkRed ).dark( 150 ) ) );

    QGridLayout *layout = new QGridLayout( this );
    layout->setSpacing( 5 );
    layout->setMargin( 0 );


    QwtDial *dial = createDial();
    layout->addWidget( dial, 0, 0 );

}

QwtDial *frmtps::createDial(void){
    QwtDial *dial=NULL;

    d_tps = new dial_Meter( this );
    d_tps->setScaleStepSize( 10.0 );
    d_tps->setScale( 0.0, 100.0 );
    d_tps->scaleDraw()->setPenWidth( 2 );
    d_tps->setLabel("TPS");

    QTimer *timer = new QTimer( d_tps );
    timer->connect( timer, SIGNAL( timeout() ),this, SLOT( changeTPS() ) );
    timer->start( 10 );

    dial = d_tps;
    return dial;
}

QPalette frmtps::colorTheme(const QColor &base) const{
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

void frmtps::changeTPS(void){
    double value = val_tps;
    d_tps->setValue(value);
}
