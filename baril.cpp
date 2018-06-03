#include "baril.h"

Baril::Baril(double posX, double posY)
{

    setPixmap(QPixmap(":/images/boule.png").scaled(35,35,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    setPos(posX,posY);


}

Baril::~Baril()
{

}
