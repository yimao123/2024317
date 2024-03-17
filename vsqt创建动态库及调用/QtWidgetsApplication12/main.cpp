#include "QtWidgetsApplication12.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtWidgetsApplication12 w;
    w.show();
    return a.exec();
}
