#include "primaryhmi.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PrimaryHMI w;
    w.show();

    return a.exec();
}
