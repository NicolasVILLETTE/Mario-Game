#ifndef BRICK_H
#define BRICK_H
#include <QObject>
#include <QGraphicsPixmapItem>

class Brick: public QObject, public QGraphicsPixmapItem
{


public :


 Brick(double posX=0,double posY=0);
 ~Brick();

private :
  Q_OBJECT
 double posX,posY;
};

#endif // BRICK_H
