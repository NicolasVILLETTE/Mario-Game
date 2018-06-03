#include "choix.h"
#include <QDebug>


Choix::Choix(QGraphicsPixmapItem *parent):QObject(),QGraphicsPixmapItem(parent){

    setPixmap(QPixmap(":/images/sombrero.png").scaled(50,50,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    setPos(200,500);
    soundC = new QMediaPlayer;
    soundC->setMedia(QUrl("qrc:/Sound/banana.ogg"));






}

Choix::~Choix()
{

}

