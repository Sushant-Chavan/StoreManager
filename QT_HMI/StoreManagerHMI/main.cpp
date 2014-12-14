#include "primaryhmi.h"
#include "WidgetManager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    widgetManager w;
    w.show();

    return a.exec();
}
