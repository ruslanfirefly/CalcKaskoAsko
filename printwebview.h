#ifndef PRINTWEBVIEW_H
#define PRINTWEBVIEW_H

#include <QDialog>
#include <QtWebKitWidgets/QWebFrame>
#include "QtPrintSupport"
namespace Ui {
class printWebView;
}

class printWebView : public QDialog
{
    Q_OBJECT
    
public:
    enum printType{ HTML, IMAGE };
    explicit printWebView(QWidget *parent = 0);
    ~printWebView();
    void setViewPage(QWebPage* page, printType type = IMAGE);
    
private:
    Ui::printWebView *ui;
    printType pType;
private slots:
    void print();
    void printHtml(QPrinter* printer);
    void printImage(QPrinter *printer);
};

#endif // PRINTWEBVIEW_H
