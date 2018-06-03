#include "mario.h"

Mario::Mario()
{
    setPos(650,450);
    this->velocityX = 0.0 ;
    this->velocityY = 0;
    this->isMoving = false;
    this->onGround = false;
    this->blockG = false;
    this->blockD = false;
    this->gravity = 0.4;



    this->SpriteStaticD.load(":/images/MarioStaticD.png");
    this->SpriteStaticD = this->SpriteStaticD.scaled(33,50,Qt::KeepAspectRatio,Qt::SmoothTransformation);

    this->setPixmap(this->SpriteStaticD);
    this->spriteWalkD.load(":/images/MarioWakingD.png");
    this->spriteWalkD = this->spriteWalkD.scaled(33,50,Qt::KeepAspectRatio,Qt::SmoothTransformation);

    this->SpriteStaticG.load(":/images/MarioStaticG.png");
    this->SpriteStaticG = this->SpriteStaticG.scaled(33,50,Qt::KeepAspectRatio,Qt::SmoothTransformation);

    this->spriteWalkG.load(":/images/MarioWalkingG.png");
    this->spriteWalkG = this->spriteWalkG.scaled(33,50,Qt::KeepAspectRatio,Qt::SmoothTransformation);

    jump = new QMediaPlayer;
    jump->setMedia(QUrl("qrc:/Sound/Mario-Jump.ogg"));
    jump->setVolume(50);

}

Mario::~Mario()
{

}

