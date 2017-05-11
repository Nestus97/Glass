#ifndef RAY_H
#define RAY_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Ray: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
private:
    int znak;
    float xx,yy; // zmiana co ruch w x i w y
    float ray_d; //wspolczynnik nachylenia
    int m; // m-x i y - w zaleznosci w ktora strone idzie
    //char delta_x; //w ktora strone prostej podaza n-negative p-positive
public:
    Ray(float d, char em, QGraphicsItem * parent=0);
    void change_m();
public slots:
    void move();
};


#endif // RAY_H

