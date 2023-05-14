#include "turnitout.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TurnItOut w;
    w.show();
    return a.exec();
}
