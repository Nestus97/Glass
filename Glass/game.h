#ifndef GAME_H
#define GAME_H

//#include <QPaintEvent>
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "bulb.h"
#include "ray.h"
#include "finish.h"

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);
    QGraphicsScene * scene;
    Bulb * bulb;
    Ray * ray;
    Finish * finish;
};

#endif // GAME_H
