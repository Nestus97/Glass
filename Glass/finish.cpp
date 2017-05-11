#include "finish.h"
#include <QGraphicsScene>

Finish::Finish(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/Images/Finish.png")); //TO WYGLAD ZRODLA
}

