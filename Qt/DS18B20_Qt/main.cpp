#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.setWindowTitle("Temperature Sensor Reading");
    w.setFixedSize(800,600);
    w.show();

    return a.exec();
}
