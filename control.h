#ifndef CONTROL_H
#define CONTROL_H

#include <QGraphicsScene>
#include <QBrush>
#include <QLabel>
#include <QFontDatabase>
#include <QMediaPlayer>
#include <QElapsedTimer>
#include <QObject>
#include <QTimer>
#include <QString>

#include "model.h"
#include "baril.h"
#include "view.h"


class View;
class Model;


class Control : QObject
{
    Q_OBJECT


public:

    Control(Model *m,View *v);


    void game();



    bool onGround {false};
    int spriteD = 0;
    int spriteG = 0;
    int spriteB = 0;

    inline void ColisiongroundMario();
    inline void ColisionTopMario();
    inline void ColisionMario();
    inline void ColisionLRMario();
    inline void ColisionBarilGround();
    inline void ColisionBarilLR();
    inline void ColisionMarioBaril();

    inline void init();
    inline void gameOver();

    void UpdateMario();
    void UpdateBaril();
    void UpdateBowser();

    void marioMove();
    void getMarioPos();


private slots :




private:
    void timerEvent(QTimerEvent *event);
    float gravityB{0.2};
    float gravity;
    double posX;
    double posY;
    bool gamStarted{false};
    bool initStarted{false};
    int timerId = 0;

     View *view;
     Model *model;
     QTimer *timerMarioPos;
     QTimer *timerM;
     QTimer *timerUpdate;
     QMediaPlayer *Back;
     QTimer *timerBarilTimer;


};

#endif // CONTROL_H
