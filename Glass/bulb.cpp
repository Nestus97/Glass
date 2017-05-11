#include "bulb.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "ray.h"
#include "game.h"
#include <QTimer>

Bulb::Bulb(float d, QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    bulb_d=d;
    //set the graphics
    setPixmap(QPixmap(":/Images/Bulb.png")); //TO WYGLAD ZRODLA
}

float Bulb::return_D()
{
    return bulb_d;
}
/*
void Bulb::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Space){
        //create a ray
        float k = return_D();

        Ray * ray = new Ray(k,1);
        ray->setPos(x()+10,y()+10);
        scene()->addItem(ray);
    }
}
*/
void Bulb::spam()
{
    float k = return_D();

    Ray * ray = new Ray(k,1);
    ray->setPos(x()+10,y()+10);
    scene()->addItem(ray);


}

/*void Bulb::spawn()   //TU SE WROCE GDY BEDE CHCIAL CIAGLE WYSYLKI SWIATLA
{
    // create a ray
    Ray * ray = new Ray();
    scene()->addItem(ray);
}*/

/*
#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"

Player::Player(QGraphicsItem *parent): QGraphicsRectItem(parent){

}
void Player::keyPressEvent(QKeyEvent *event){
    // move the player left and right
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
    }
    // shoot with the spacebar
    else if (event->key() == Qt::Key_Space){
        // create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
    }
}
void Player::spawn(){
    // create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
*/
