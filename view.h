#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>

#include "control.h"

class Control;



class View : public QGraphicsView
{
    Q_OBJECT

public:


    bool moveR;
    bool moveL;
    bool moveJ;
    bool moveD;
    bool moveUp;
    bool enter;
    bool releaseR;
    bool releaseL;

    explicit View(QGraphicsView *parent=0);
    void setControl(Control * control){this->control = control;}
    ~View();


void keyPressEvent(QKeyEvent *event);
void keyReleaseEvent(QKeyEvent *event);
private:




    Control *control;
    QKeyEvent *event;

};

#endif // VIEW_H
