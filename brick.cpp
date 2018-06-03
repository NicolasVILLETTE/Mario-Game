#include "brick.h"

Brick::Brick(double posX, double posY)
{
    setPixmap(QPixmap(":/images/Brick_Block.png").scaled(35,35,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    setPos(posX,posY);

}

Brick::~Brick()
{

}
