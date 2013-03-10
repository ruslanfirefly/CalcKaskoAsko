#include "cascomaster.h"
#include "calccascoform.h"

CascoMaster::CascoMaster(QObject *parent) :
    QObject(parent)
{
    calcCascoForm* cForm = new calcCascoForm;
    cForm->setModal(true);
    cForm->show();
}
