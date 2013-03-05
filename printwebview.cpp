#include "printwebview.h"
#include "ui_printwebview.h"

printWebView::printWebView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::printWebView)
{
    ui->setupUi(this);
}

printWebView::~printWebView()
{
    delete ui;
}
void printWebView::setViewPage(QWebPage *page)
{
    ui->webView->setPage(page);
    ui->webView->settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
}
