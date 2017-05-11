#include "Game.h"
#include <QTimer>
#include <QGraphicsRectItem> //dla sceny
#include <QGraphicsTextItem>
//#include <QFont>// JAK DODAM NAPIS KONCOWY
#include <bulb.h>
#include <ray.h>
#include <QBrush>
#include <QImage>
//#include <QMediaPlayer>


Game::Game(QWidget *parent){
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1200,800);
    setBackgroundBrush(QBrush(QImage(":/Images/Background.png")));
    // wybranie sceny
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1200,800);


    //create the BULB
    float pomoc = 0.40;
    bulb = new Bulb(pomoc);
    //bulb->setRect(0,0,30,30);
    bulb->setPos(100,400);
    // sfocusowac trzeba w razie co TESTOWE NA "SPACJE"
    //bulb->setFlag(QGraphicsItem::ItemIsFocusable);
    //bulb->setFocus();
    // dodac na scene
    scene->addItem(bulb);
    //finish -> CEL
    finish = new Finish();
    finish->setPos(900,480);
    scene->addItem(finish);

    //TO DO TESTOW ZE SPACJA
    //ray = new Ray(pomoc,-1);
    //ray->setPos(110,410);

    // SPAM SWIATLEM (RAY)
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),bulb,SLOT(spam()));
    timer->start(20);

    //play background music
    //QMediaPlayer * music = new QMediaPlayer();
    //music->setMedia(QUrl("qrc:/Images/Winner.mp3"));
    //music->play();

    show();
}
