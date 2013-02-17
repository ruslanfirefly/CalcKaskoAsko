#include "osagomaster.h"

#include "osagoblankdataform.h"
#include "osagotsblank.h"
#include "osagousinginfoform.h"
#include <stdexcept>
OsagoMaster::OsagoMaster(QObject *parent) :
    QObject(parent)
{
    dialogs.push_back(new osagoCalcForm);
    dialogs.push_back(new OsagoBlankDataForm(&data.insurancer,Driver::Insurancer, &data.insurancerIsOwner));
    dialogs.push_back(new OsagoBlankDataForm(&data.owner,Driver::Owner, &data.insurancerIsOwner));
    dialogs.push_back(new OsagoTsBlank(&data.insurancerIsOwner));
    dialogs.push_back(new OsagoUsingInfoForm);
    connect(qobject_cast<osagoCalcForm*>(dialogs.at(0)), SIGNAL(next()), this, SLOT(next()));
    connect(qobject_cast<OsagoBlankDataForm*>(dialogs.at(1)), SIGNAL(prev()), this, SLOT(prev()));
    connect(qobject_cast<OsagoBlankDataForm*>(dialogs.at(1)), SIGNAL(next(int)), this, SLOT(next(int)));
    connect(qobject_cast<OsagoBlankDataForm*>(dialogs.at(2)), SIGNAL(prev()), this, SLOT(prev()));
    connect(qobject_cast<OsagoBlankDataForm*>(dialogs.at(2)), SIGNAL(next(int)), this, SLOT(next(int)));
    connect(qobject_cast<OsagoTsBlank*>(dialogs.at(3)), SIGNAL(prev(int)), this, SLOT(prev(int)));
    connect(qobject_cast<OsagoTsBlank*>(dialogs.at(3)), SIGNAL(next()), this, SLOT(next()));
    dialogs.at(0)->show();
    foreach (QDialog* dial, dialogs) {
        dial->setModal(true);
    }
}
void OsagoMaster::next()
{
    next(1);
}
void OsagoMaster::next(int s)
{
    step(s);
}
void OsagoMaster::prev()
{
    prev(1);
}
void OsagoMaster::prev(int s)
{
    step(-s);
}
void OsagoMaster::step(int s)
{
    dialogs.at(currentStep)->hide();
    currentStep+=s;
    dialogs.at(currentStep)->show();
}
