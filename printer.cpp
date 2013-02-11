#include "printer.h"
#include <QDir>
#include <QApplication>
#include <QDebug>
Printer::Printer()
{

    textEdit = new QWebView;
    textEdit->settings()->setAttribute(QWebSettings::AutoLoadImages, true);
    textEdit->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
    textEdit->settings()->setAttribute(QWebSettings::LocalContentCanAccessFileUrls, true);
    textEdit->settings()->setAttribute(QWebSettings::LocalContentCanAccessRemoteUrls, true);
    printer = new QPrinter;
    prevDlg = new QPrintPreviewDialog(printer);
}
void Printer::printPreview(const QString &s)
{

    QPrintPreviewDialog* tmp= new QPrintPreviewDialog;
    textEdit->setHtml(s, QUrl("file://"+qApp->applicationDirPath()+"/templates/"));
    QObject::connect(prevDlg, SIGNAL(paintRequested(QPrinter*)), textEdit, SLOT(print(QPrinter*)));
    //textEdit->show();
    prevDlg->exec();
}
Printer& Printer::getInstance()
{
    static Printer printer;
    return printer;
}
Printer::~Printer()
{
    prevDlg->deleteLater();
    textEdit->deleteLater();
    delete printer;

}
