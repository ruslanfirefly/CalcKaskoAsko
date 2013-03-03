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
#include <QTextCodec>
int main(int argc, char *argv[])
{

        QApplication a(argc, argv);
        QResource::registerResource("resources.qrc");
        QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
        QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
        QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
        qDebug()<<qApp->applicationDirPath();
        MainWindow w;
        QWebView* tmpView = new QWebView();
        tmpView->settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
//        tmpView->load(QUrl("file://"+qApp->applicationDirPath()+"/templates/osago_zayavlenie.html"));
        tmpView->load(QUrl("file://"+qApp->applicationDirPath()+"/templates/blank_osago.html"));
        tmpView->show();
        w.show();
        return a.exec();

}
