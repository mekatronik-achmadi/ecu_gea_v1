#include <qlayout.h>
#include <qtimer.h>
#include <qwt_analog_clock.h>
#include <qwt_round_scale_draw.h>
#include <dial_meter.h>
#include "dial_display.h"
#include "interface.h"

extern int val_tps;
extern int val_rpm;
extern int val_inj;
extern int val_ign;
extern int val_map;
extern int val_temp;

dial_display::dial_display(QWidget *parent ):
    QFrame( parent )
{
    setAutoFillBackground( true );

    QGridLayout *layout = new QGridLayout( this );
    layout->setSpacing( 5 );
    layout->setMargin( 0 );

    /*
    QwtDial *dialclk = createDial( 0 );
    layout->addWidget( dialclk, 0, 0 );
    */

    QwtDial *dialtps = createDial( 1 );
    layout->addWidget( dialtps, 0, 0 );

    QwtDial *dialrpm = createDial( 2 );
    layout->addWidget( dialrpm, 0, 1 );

    QwtDial *dialinj = createDial( 3 );
    layout->addWidget( dialinj, 0, 2 );

    QwtDial *dialign= createDial( 4 );
    layout->addWidget( dialign, 1, 0 );

    QwtDial *dialtemp= createDial( 5 );
    layout->addWidget( dialtemp, 1, 1 );

    QwtDial *dialmap= createDial( 6 );
    layout->addWidget( dialmap, 1, 2 );

    int i;
    for ( i = 0; i < layout->columnCount(); i++ ){layout->setColumnStretch( i, 1 );}
    for ( i = 0; i < layout->rowCount(); i++ ){layout->setRowStretch( i, 1 );}

    tmrUpdateValue = new QTimer(this);
    connect(tmrUpdateValue,SIGNAL(timeout()),this,SLOT(updateValue()));
    tmrUpdateValue->start(100);
}

QwtDial* dial_display::createDial(int pos){
    QwtDial *dial = NULL;

    switch( pos ){

    /*
    case 0: {
        d_clock = new QwtAnalogClock( this );
        d_clock->scaleDraw()->setTickLength( QwtScaleDiv::MinorTick, 0 );
        const QColor knobColor = QColor( Qt::gray ).light( 130 );

        for ( int i = 0; i < QwtAnalogClock::NHands; i++ )
        {
            QColor handColor = QColor( Qt::gray ).light( 150 );
            int width = 8;

            if ( i == QwtAnalogClock::SecondHand )
            {
                handColor = Qt::gray;
                width = 5;
            }

            QwtDialSimpleNeedle *hand = new QwtDialSimpleNeedle(
                QwtDialSimpleNeedle::Arrow, true, handColor, knobColor );
            hand->setWidth( width );

            d_clock->setHand( static_cast<QwtAnalogClock::Hand>( i ), hand );
        }

        QTimer *timer = new QTimer( d_clock );
        timer->connect( timer, SIGNAL(timeout()),d_clock, SLOT( setCurrentTime() ) );
        timer->start( 1000 );

        dial = d_clock;
        break;
    }*/

    case 1: {
        d_tps = new dial_meter( this );
        d_tps->setScaleStepSize( 10.0 );
        d_tps->setScale( 0.0, 100.0 );
        d_tps->scaleDraw()->setPenWidth( 2 );
        d_tps->setLabel("Throttle");
        dial = d_tps;
        break;
    }

    case 2: {
        d_rpm = new dial_meter( this );
        d_rpm->setScaleStepSize( 500.0 );
        d_rpm->setScale( 0.0, 6000.0 );
        d_rpm->scaleDraw()->setPenWidth( 2 );
        d_rpm->setLabel("RPM");
        dial = d_rpm;
        break;
    }

    case 3: {
        d_inj = new dial_meter( this );
        d_inj->setScaleStepSize( 10.0 );
        d_inj->setScale( 0.0, 150.0 );
        d_inj->scaleDraw()->setPenWidth( 2 );
        d_inj->setLabel("Injection");
        dial = d_inj;
        break;
    }

    case 4: {
        d_ign = new dial_meter( this );
        d_ign->setScaleStepSize( 5.0 );
        d_ign->setScale( 0.0, 45.0 );
        d_ign->scaleDraw()->setPenWidth( 2 );
        d_ign->setLabel("Ignition");
        dial = d_ign;
        break;
    }

    case 5: {
        d_temp = new dial_meter( this );
        d_temp->setScaleStepSize( 10.0 );
        d_temp->setScale( 0.0, 150.0 );
        d_temp->scaleDraw()->setPenWidth( 2 );
        d_temp->setLabel("Temperature");
        dial = d_temp;
        break;
    }

    case 6: {
        d_map = new dial_meter( this );
        d_map->setScaleStepSize( 10.0 );
        d_map->setScale( 0.0, 150.0 );
        d_map->scaleDraw()->setPenWidth( 2 );
        d_map->setLabel("MAP");
        dial = d_map;
        break;
    }

    }

    if ( dial )
    {
        dial->setReadOnly( true );
        dial->setLineWidth( 4 );
        dial->setFrameShadow( QwtDial::Sunken );
    }

    return dial;
}

void dial_display::updateValue(){
    d_tps->setValue(val_tps);
    d_rpm->setValue(val_rpm);
    d_inj->setValue(val_inj);
    d_ign->setValue(val_ign);
    d_map->setValue(val_map);
    d_temp->setValue(val_temp);
}
