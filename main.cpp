#include <QApplication>
#include "mainwindow.h"
#include <database.h>
#include <QMessageBox>
#include <QDebug>
#include <stdexcept>
#include <QResource>
#include <QDir>
#include <QApplication>
//#include <QtWebKit/QWebView>
#include <QtWebKitWidgets/QWebView>
#include <QTextCodec>
int main(int argc, char *argv[])
{

        QApplication a(argc, argv);
        QResource::registerResource("resources.qrc");

        QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

        MainWindow w;
;

        w.show();
        return a.exec();

}
