#include "dk.h"

Dk::Dk(QGraphicsPixmapItem * parent):QObject(),QGraphicsPixmapItem(parent)

{
    this->Sprite1.load(":/images/BowserD.png");
    this->Sprite1 = this->Sprite1.scaled(100,100,Qt::KeepAspectRatio,Qt::SmoothTransformation);

    this->Sprite2.load(":/images/BowserG.png");
    this->Sprite2 = this->Sprite2.scaled(100,100,Qt::KeepAspectRatio,Qt::SmoothTransformation);

    setPos(8,109);

}

Dk::~Dk()
{

}
