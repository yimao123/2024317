#include "testThread.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    testThread w;
    w.show();
    return a.exec();
}
