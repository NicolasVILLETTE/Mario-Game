#include "view.h"
#include "control.h"
#include "QObject"

View::View(QGraphicsView *parent):QGraphicsView(parent)

{



    moveR=false;
    moveL=false;
    moveJ=false;
    moveUp=false;
    moveD=false;
    enter=false;
    releaseL=false;
    releaseR=false;
    setSceneRect(0,0,800,600);
    setFixedSize(805,605);
    show();

}

View::~View()
{

}

void View::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Right){

        moveR = true;
        releaseR = false;
    }
    else if (event->key() == Qt::Key_Left){

        moveL =true;
        releaseL = false;
    }

    else if ( event->key() == Qt::Key_Space){

      moveJ = true;
}
    else if (event->key() == Qt::Key_Up){

        moveUp = true;

    }
    else if (event->key() == Qt::Key_Down){

        moveD = true;

    }
    if (event->key() == Qt::Key_0){

        enter = true;

    }

}

void View::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Right){

        moveR = false;
        releaseR = true;

    }
    else if (event->key() == Qt::Key_Left){

        moveL =false;
        releaseL = true;
    }
    else if ( event->key() == Qt::Key_Space){

      moveJ = false;

    }
    else if (event->key() == Qt::Key_Up){

        moveUp = false;

    }
    else if (event->key() == Qt::Key_Down){

        moveD = false;

    }
    if (event->key() == Qt::Key_0){

        enter = false;

    }

}






