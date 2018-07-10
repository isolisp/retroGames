#include "gamechooser.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameChooser w;
    w.show();

    return a.exec();
}
