#include <QApplication>
#include "mainwindow.h"
#include <database.h>
#include <QMessageBox>
#include <QDebug>
#include <stdexcept>
#include <QResource>
#include <QDir>
#include <QApplication>
#include <QtWebKit/QWebView>
int main(int argc, char *argv[])
{

        QApplication a(argc, argv);
        QResource::registerResource("resources.qrc");
        qDebug()<<qApp->applicationDirPath();
        MainWindow w;
        /*QWebView* tmpView = new QWebView();
        tmpView->settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
        tmpView->load(QUrl("file://"+qApp->applicationDirPath()+"/templates/osago_zayavlenie.html"));
        tmpView->show();*/
        w.show();
        return a.exec();
}
