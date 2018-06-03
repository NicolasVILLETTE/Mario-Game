#ifndef DK_H
#define DK_H
#include <QObject>
#include <QGraphicsPixmapItem>


class Dk:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:


    Dk(QGraphicsPixmapItem * parent=0);
    ~Dk();

   QPixmap  Sprite1;
   QPixmap  Sprite2;





};

#endif // DK_H
