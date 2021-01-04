#include <QApplication>
#include "gameboard.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameBoard w;
    w.show();

    return a.exec();
}
