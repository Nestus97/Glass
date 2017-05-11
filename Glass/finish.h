#ifndef FINISH_H
#define FINISH_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Finish:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
private:
public:
    Finish(QGraphicsItem * parent=0);
};

#endif // FINISH_H
