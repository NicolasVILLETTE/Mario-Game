#ifndef COLISIONTHREAD_H
#define COLISIONTHREAD_H
#include <QString>
#include <QThread>
#include "control.h"

class Control;
class Mario;
class ColisionThread:  QThread  {

public:

 explicit ColisionThread(QString s);
 void run();

private:
 QString name;
 Control *control;

};

#endif // COLISIONTHREAD_H
