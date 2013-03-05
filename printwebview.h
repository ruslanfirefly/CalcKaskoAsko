#ifndef PRINTWEBVIEW_H
#define PRINTWEBVIEW_H

#include <QDialog>
#include <QtWebKitWidgets/QWebFrame>
namespace Ui {
class printWebView;
}

class printWebView : public QDialog
{
    Q_OBJECT
    
public:
    explicit printWebView(QWidget *parent = 0);
    ~printWebView();
    void setViewPage(QWebPage* page);
    
private:
    Ui::printWebView *ui;
};

#endif // PRINTWEBVIEW_H
