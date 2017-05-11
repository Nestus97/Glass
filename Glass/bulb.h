#ifndef BULB_H
#define BULB_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Bulb:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
private:
    float bulb_d;
public:
    Bulb(float d, QGraphicsItem * parent=0);
    //void keyPressEvent(QKeyEvent * event);
    float return_D();
public slots:
    void spam();
};

#endif // BULB_H
