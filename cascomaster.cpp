#include "cascomaster.h"
#include "calccascoform.h"
#include "cascodatadialog.h"
#include "cascotsinfodialog.h"
#include "cascousinginfodialog.h"
#include <QMutex>
CascoMaster::CascoMaster(QObject *parent) :
    QObject(parent)
{
    fillForms( { new calcCascoForm
                 , new CascoDataDialog(CascoDataDialog::Insurancer, &data)
                 , new CascoDataDialog(CascoDataDialog::Owner, &data)
                 , new CascoDataDialog(CascoDataDialog::Profiter, &data)
                 , new CascoTsInfoDialog(&data)
                 , new CascoUsingInfoDialog(&data)
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
        dialog->setModal(true);
        connect(dialog, SIGNAL(next(int)), this, SLOT(next(int)));
        connect(dialog, SIGNAL(prev(int)), this, SLOT(prev(int)));
        forms.push_back(dialog);
    }
}
