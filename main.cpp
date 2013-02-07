#include <QApplication>
#include "mainwindow.h"
#include <database.h>
#include <QMessageBox>
#include <QDebug>
#include <stdexcept>
#include <QResource>
int main(int argc, char *argv[])
{

        QApplication a(argc, argv);
        QResource::registerResource("resources.qrc");
        MainWindow w;
        w.show();
        return a.exec();

}
