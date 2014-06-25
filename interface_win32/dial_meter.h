#ifndef DIAL_METER_H
#define DIAL_METER_H

#include <qstring.h>
#include <qwt_dial.h>

class dial_meter: public QwtDial
{
public:
    dial_meter( QWidget *parent = NULL );
    void setLabel( const QString & );

protected:
    virtual void drawScaleContents( QPainter *painter,const QPointF &center, double radius ) const;

private:
    QString d_label;
};

#endif // DIAL_METER_H
