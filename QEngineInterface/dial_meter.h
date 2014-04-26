#ifndef DIAL_METER_H
#define DIAL_METER_H

#include <qstring.h>
#include <qwt_dial.h>

class dial_Meter: public QwtDial
{
public:
    dial_Meter( QWidget *parent = NULL );

    void setLabel( const QString & );
    QString label() const;

protected:
    virtual void drawScaleContents( QPainter *painter,
        const QPointF &center, double radius ) const;

private:
    QString d_label;
};

#endif
