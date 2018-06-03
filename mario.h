#ifndef MARIO_H
#define MARIO_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QMediaPlayer>


class Mario:public QObject, public QGraphicsPixmapItem
{

public:

    double velocityX, velocityY;
     double posX,posY;
    bool isMoving;
    bool onGround;
    bool blockG;
    bool blockD;
    double gravity;


    QPixmap spriteWalkD;
    QPixmap SpriteStaticD;
    QPixmap SpriteStaticG;
    QPixmap spriteWalkG;
    QMediaPlayer *jump;


    Mario();
    ~Mario();
private:

     Q_OBJECT


};




#endif // MARIO_H
