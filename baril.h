#ifndef BARIL_H
#define BARIL_H

#include <QObject>
#include <QGraphicsPixmapItem>
class Baril: public QObject , public QGraphicsPixmapItem


{



public:
    Baril(double posX=0,double posY=0);
    ~Baril();
    bool onGround {false};
    double velocityX {2.5};
    double velocityY{0};
    double posX,posY;
    double gravity{0.2};
private:
Q_OBJECT

};

#endif // BARIL_H
