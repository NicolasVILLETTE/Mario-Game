#ifndef CHOIX_H
#define CHOIX_H
#include <QGraphicsItem>
#include <QObject>
#include <QKeyEvent>
#include <QMediaPlayer>
#include <QFontDatabase>



class Choix :public QObject, public QGraphicsPixmapItem
{
Q_OBJECT
public:


     Choix(QGraphicsPixmapItem * parent=0);
     QGraphicsPixmapItem *banana(int W, int H,int dx, int dy);
     ~Choix();



private:
     QMediaPlayer *soundC;


};


#endif // CHOIX_H
