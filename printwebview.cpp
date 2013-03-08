#include "printwebview.h"
#include "ui_printwebview.h"
#include "QtWebKitWidgets/QWebView"

printWebView::printWebView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::printWebView)
{
    ui->setupUi(this);

    connect(ui->printButton, SIGNAL(clicked()), this, SLOT(print()));
}

printWebView::~printWebView()
{
    delete ui;
}
void printWebView::setViewPage(QWebPage *page, printType type)
{
    ui->webView->setPage(page);
    ui->webView->settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
    pType=type;
}
void printWebView::print()
{
    QPrintDialog* dlg = new QPrintDialog(this);
    if(dlg->exec() == QDialog::Accepted)
    {
        QPrinter* printer = dlg->printer();
        switch(pType)
        {
        case HTML:
            printHtml(printer);
            break;
        case IMAGE:
            printImage(printer);
            break;
        }

    }
   // this->deleteLater();
}
void printWebView::printHtml(QPrinter *printer)
{
    QWebView* view = ui->webView;
    QWebFrame* frame = view->page()->currentFrame();
    view->page()->setViewportSize(frame->contentsSize());
    QImage image(view->page()->viewportSize(), QImage::Format_ARGB32);
    QPainter painter(&image);
    view->page()->mainFrame()->render(&painter);
    painter.end();
    printer->setPageSize(QPrinter::A4);
    QPainter p(printer);

    QSizeF size = printer->pageSizeMM();
    QImage scaledImage = /*image.scaled(size.width()*image.dotsPerMeterX()/1000, size.height()*image.dotsPerMeterY()/1000
                                      , Qt::IgnoreAspectRatio
                                      , Qt::SmoothTransformation);*/
            image.scaledToWidth(size.width()*image.dotsPerMeterX()/1000,Qt::SmoothTransformation);
    p.drawImage(QPointF(0,0), scaledImage, QRectF(0,0, scaledImage.width(), size.height()*image.dotsPerMeterY()/1000));
    printer->newPage();
    p.drawImage(QPointF(0,0) ,scaledImage, QRectF(0, size.height()*image.dotsPerMeterY()/1000, scaledImage.width(), size.height()*image.dotsPerMeterY()/1000 ));
    p.end();
}
void printWebView::printImage(QPrinter *printer)
{
    QWebView* view = ui->webView;
    QWebFrame* frame = view->page()->currentFrame();
    view->page()->setViewportSize(frame->contentsSize());
    QImage image(view->page()->viewportSize(), QImage::Format_ARGB32);
    QPainter painter(&image);
    view->page()->mainFrame()->render(&painter);
    painter.end();
    printer->setPageSize(QPrinter::A4);
    QPainter p(printer);
    QSizeF size = printer->pageSizeMM();
    QImage scaledImage = image.scaled(size.width()*image.dotsPerMeterX()/1000, size.height()*image.dotsPerMeterY()/1000
                                      , Qt::IgnoreAspectRatio
                                      , Qt::SmoothTransformation);
    p.drawImage(QPoint(0,0), scaledImage);
    p.end();
}
