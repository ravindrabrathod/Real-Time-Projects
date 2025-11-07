#include "sighin_up.h"

#include <QApplication> //Qt class that starts and manages your GUI application

int main(int argc, char *argv[]) //argument count argc,argv[] stored that comment
{
    QApplication a(argc, argv); //This creates the application object.
    sighin_up w;
    w.show();
    return a.exec();
}
