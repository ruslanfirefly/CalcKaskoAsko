#ifndef PRINTER_H
#define PRINTER_H

#include <QObject>
#include <QTextEdit>

#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintPreviewDialog>
#include <QtWebKitWidgets/QWebView>
class Printer
{
    Printer();
    QWebView* textEdit;
    QPrinter* printer;
    QPrintPreviewDialog *prevDlg;
public:
    void printPreview(const QString& s);
    void printPreview(QWebView* view);
    static Printer& getInstance();
    ~Printer();
};

#endif // PRINTER_H
