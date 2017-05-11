#include "ray.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "bulb.h"
#include "game.h"

#include "finish.h"
//tu ma byc lustro include (h)
//#include <QDebug>
extern Game * game;
Ray::Ray(float d, char em, QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //instant d
    ray_d=d;
    m=em;
    znak=1;
    // JAK MA SIE ZMIENIAC POZYCJA CO RUCH
    if((ray_d>50.0)||(ray_d<-50.0)) // PROMIEN ~PIONOWY
    {
        if(ray_d>50.0)
        {
            ray_d=100.0;
            znak=1;
        }
        else
        {
            ray_d=-100.0;
            znak=-1;
        }
        xx=0;
        yy=10;
    }
    else if((ray_d>-0.02)&&(ray_d<0.02)) // PROMIEN ~POZIOMY
    {
        znak=1;
        ray_d=0;
        xx=10;
        yy=0;
    }
    else if(((ray_d>=-50.0)&&(ray_d<-1.0))||((ray_d>1.0)&&(ray_d<=50.0))) // W MIARE PIONOWY
    {
        if(ray_d<0)
            znak=-1;
        else
            znak=1;
        xx=10/ray_d;
        yy=10;
    }
    else // W MIARE POZIOMY
    {
        znak=1;
        xx=10;
        yy=10*ray_d;
    }



    // draw the PixMap
    setPixmap(QPixmap(":/Images/Ray.png"));

    // connect
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(20);
}

void Ray::change_m()
{
    m*=-1;
}

void Ray::move()
{
    //move the ray
    setPos(x()+m*znak*xx,y()-m*znak*yy);
    //jesli poza mapa
    if ((pos().x() > 1200)||(pos().x() < 0))
    {
        if(((ray_d>=-50.0)&&(ray_d<-1.0))||((ray_d>1.0)&&(ray_d<=50.0)))
            xx*=-1;
        if(((ray_d>=-1.0)&&(ray_d<=-0.02))||((ray_d>=0.02)&&(ray_d<=1.0)))
            yy*=-1;

        ray_d*=-1;
        change_m();
        if(ray_d<-1.0)
            znak=-1;
        else
            znak=1;
    }
    else if ((pos().y() > 800)||(pos().y() < 0))
    {
        if(((ray_d>=-50.0)&&(ray_d<-1.0))||((ray_d>1.0)&&(ray_d<=50.0)))
            xx*=-1;
        if(((ray_d>=-1.0)&&(ray_d<=-0.02))||((ray_d>=0.02)&&(ray_d<=1.0)))
            yy*=-1;

        ray_d*=-1;
        if(ray_d<-1.0)
            znak=-1;
        else
            znak=1;
    }
    else
    {
        QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i)
        {
            if (typeid(*(colliding_items[i])) == typeid(Finish))
            {
                // usunac z mapy i z pamieci
                scene()->removeItem(this);
                delete this;

                // dalej juz nie potrzebne
                return;
            }
        }

    }


    /*if((pos().x() > 1200)||(pos().x() < 0)||(pos().y() > 800)||(pos().y() < 0))
    {
        // JAK MA SIE ZMIENIAC POZYCJA CO RUCH
        if((ray_d>50.0)||(ray_d<-50.0)) // PROMIEN ~PIONOWY
        {
            ray_d=100;
            xx=0;
            yy=10;
        }
        else if((ray_d>-0.02)&&(ray_d<0.02)) // PROMIEN ~POZIOMY
        {
            ray_d=0;
            xx=10;
            yy=0;
        }
        else if(((ray_d>=-50.0)&&(ray_d<-1.0))||((ray_d>1.0)&&(ray_d<=50.0))) // W MIARE PIONOWY
        {
            xx=10/ray_d;
            yy=10;
        }
        else // W MIARE POZIOMY
        {
            xx=10;
            yy=10*ray_d;
        }
    }*/

       // scene()->removeItem(this);
      //  delete this;

/*  // JAK BEDZIE LUSTRO
    //move the ray
    setPos(x()+m*xx,y()-m*yy);

    //usuwanie jak wyjdzie poza mape
    if((pos().x() > 1200)||(pos().x() < 0)||(pos().y() > 800)||(pos().y() < 0))
    {
        scene()->removeItem(this);
        delete this;
        return;
    }
    //co zrobić jak trafi na lustro?
    // lista rzeczy na ktore trafil pocisk
    QList<QGraphicsItem *> colliding_items = collidingItems();

    //jezeli natrafil na lustro zmien tor ruchu
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Finish))
        {
            //usunac z mapy i z pamieci
            scene()->removeItem(this);
            delete this;
            // dalej juz nie potrzebne
            return;
        }

        else if (typeid(*(colliding_items[i])) == typeid(Lustro))
        {
            znak=1; //domyslnie
            //czyli natrafil na lustro
            float a;
            a=collding_items[i]->take_tangens();


            if(ray_d==a) //JEZELI POCISK TRAFIL NA CZUBEK LUSTRA - TRZEBA USUNAC PROMIEN
            {
                scene()->removeItem(this);
                delete this;
                return;
            }
            else if((a>50.0)||(a<-50.0)) //JEZELI PIONOWE (OKOLO LUB DOKLADNIE)
            {
                ray_d*=-1;
                m*=-1;
            }
            else if((a<0.02)&&(a>-0.02)) //JEZELI POZIOME (OKOLO LUB DOKLADNIE)
            {
                ray_d*=-1;
            }
            else
            {
                float d; // NOWE ODBICIE
                d=a+((a*a+1)*(ray_d-a)/(a*(a-2*ray_d)-1));
                if((a<1.0)&&(a<=50.0)) //PRZYPADEK 1
                {
                    if((ray_d<a)&&(d<a))
                    change_m();
                }
                else if((a<-1.0)&&(a>=-50.0)) //PRZYPADEK 2
                {
                    if((ray_d>a)&&(d>a))
                    change_m();
                }
                else if((a>=-1.0)&&(a<=-0.02)) //PRZYPADEK 3
                {
                    if((ray_d>a)&&(d>a))
                    change_m();
                }
                else // OSTATNI PRZYPADEK 4, gdy a nalezy <0.02;1.0>
                {
                    if((ray_d<a)&&(d<a))
                    change_m();
                }
                ray_d=d; //PRZYPISANIE NOWEGO ODBICIA
            }
            // JAK MA SIE ZMIENIAC POZYCJA CO RUCH
            if((ray_d>50.0)||(ray_d<-50.0)) // PROMIEN ~PIONOWY
            {
                ray_d=100;
                xx=0;
                yy=10;
            }
            else if((ray_d>-0.02)&&(ray_d<0.02)) // PROMIEN ~POZIOMY
            {
                ray_d=0;
                xx=10;
                yy=0;
            }
            else if(((ray_d>=-50.0)&&(ray_d<-1.0))||((ray_d>1.0)&&(ray_d<=50.0))) // W MIARE PIONOWY
            {
                if(ray_d<0)
                znak=-1;
                xx=10/ray_d;
                yy=10;
            }
            else // W MIARE POZIOMY
            {
                xx=10;
                yy=10*ray_d;
            }
        }
    }

*/
}

