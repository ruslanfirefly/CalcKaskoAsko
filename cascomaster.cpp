#include "cascomaster.h"
#include "calccascoform.h"
#include "cascodatadialog.h"
#include "cascotsinfodialog.h"
#include "cascousinginfodialog.h"
#include <QMutex>
#include "cascosummarydialog.h"
#include <QtWebKitWidgets>
#include "printwebview.h"
CascoMaster::CascoMaster(QObject *parent) :
    QObject(parent)
{
    fillForms( { new calcCascoForm
                 , new CascoDataDialog(CascoDataDialog::Insurancer, &data)
                 , new CascoDataDialog(CascoDataDialog::Owner, &data)
                 , new CascoDataDialog(CascoDataDialog::Profiter, &data)
                 , new CascoTsInfoDialog(&data)
                 , new CascoUsingInfoDialog(&data)
                 , new CascoSummaryDialog(&data)
               } ) ;
    showCurrentForm();
}
void CascoMaster::next(int s)
{
    step(s);
}
void CascoMaster::prev(int s)
{
    step(-s);
}
void CascoMaster::next()
{
    next(1);
}
void CascoMaster::prev()
{
    prev(1);
}
void CascoMaster::step(int step)
{
    m.lock();
    int newStep = currentStep+step;
    if(newStep>=0 && newStep<forms.count())
    {
        hideCurrentForm();
        currentStep = newStep;
        m.unlock();
        showCurrentForm();
    }
    else
    {
        m.unlock();
    }


}
void CascoMaster::showCurrentForm()
{
    forms[currentStep]->show();
}
void CascoMaster::hideCurrentForm()
{
    forms[currentStep]->hide();
}
void CascoMaster::fillForms(std::initializer_list<QDialog*> f)
{
    foreach (QDialog* dialog, f) {
        //dialog->setModal(true);
        connect(dialog, SIGNAL(next(int)), this, SLOT(next(int)));
        connect(dialog, SIGNAL(prev(int)), this, SLOT(prev(int)));
        connect(dialog, SIGNAL(printBlank()), this, SLOT(printBlank()));
        forms.push_back(dialog);
    }
}
void CascoMaster::printBlank()
{
    QWebView* tmpView = new QWebView();
    QUrl url = QUrl::fromLocalFile(QDir::toNativeSeparators(qApp->applicationDirPath()+"/templates/blank_casco.html"));
    tmpView->load(url);
    connect(tmpView, &QWebView::loadFinished, [this, tmpView](){
        fillBlank(tmpView);
    });
}
void CascoMaster::fillBlank(QWebView * view)
{
    QWebFrame* frame = view->page()->currentFrame();
    frame->findFirstElement("#polisNum").setPlainText(data.polisNum);
    frame->findFirstElement("#polisSerial").setPlainText(data.polisSerial);
    frame->findFirstElement("#currentDay").setPlainText(QDate::currentDate().toString("dd"));
    frame->findFirstElement("#currentMonth").setPlainText(QDate::currentDate().toString("MMMM"));
    frame->findFirstElement("#currentYear").setPlainText(QDate::currentDate().toString("yyyy"));

    openPrintDialog(view);
}
void CascoMaster::openPrintDialog(QWebView * view)
{
    printWebView* dlg = new printWebView();
    dlg->setViewPage(view->page(), printWebView::PLAIN);
    //dlg->setModal(true);
    dlg->setWindowState(Qt::WindowMaximized);
    dlg->show();
}
