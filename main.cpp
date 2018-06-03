#include "control.h"
#include "choix.h"
#include "view.h"



#include <QApplication>

int main (int argc, char *argv[])
{
    //qputenv("QT_DEBUG_PLUGINS",QByteArray("1"));
    QApplication app(argc, argv);

        Model m;
        View v;
        Control window(&m, &v);
        v.setWindowTitle("Mario Game");
        v.show();



    return app.exec();

}
