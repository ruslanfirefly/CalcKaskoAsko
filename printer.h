#ifndef PRINTER_H
#define PRINTER_H

#include <QObject>
#include <QTextEdit>
#include <QPrinter>
#include <QPrintPreviewDialog>
#include <QtWebKit/QWebView>
class Printer
{
    Printer();
    QWebView* textEdit;
    QPrinter* printer;
    QPrintPreviewDialog *prevDlg;
public:
    void printPreview(const QString& s);
    static Printer& getInstance();
    ~Printer();
};

#endif // PRINTER_H
