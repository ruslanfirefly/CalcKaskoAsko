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
    fillForms( { new calcCascoForm(&data)
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
        dialog->setModal(true);
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
    Driver* owner = data.insurancerIsOwner ? &data.insurancer : &data.owner;
    Driver* profiter = data.insurancerIsProfiter ? &data.insurancer : &data.owner;
    frame->findFirstElement("#polisNum").setPlainText(data.polisNum);
    frame->findFirstElement("#polisSerial").setPlainText(data.polisSerial);
    frame->findFirstElement("#currentDay").setPlainText(QDate::currentDate().toString("dd"));
    frame->findFirstElement("#currentMonth").setPlainText(QDate::currentDate().toString("MMMM"));
    frame->findFirstElement("#currentYear").setPlainText(QDate::currentDate().toString("yyyy"));
    frame->findFirstElement("#insurancer_fio").setPlainText(data.insurancer.fio);
    frame->findFirstElement("#insurancer_fio2").setPlainText(data.insurancer.fio);
    frame->findFirstElement("#insurancer_addr").setPlainText(addrToString(&data.insurancer.addr));
    if(!data.insurancer.fizik) frame->findFirstElement("#insurancer_inn").setPlainText(tr("Инн: ")+data.insurancer.inn);
    frame->findFirstElement("#doctype").setPlainText(data.insurancer.documentType);
    frame->findFirstElement("#insurancer_serial").setPlainText(data.insurancer.ser);
    frame->findFirstElement("#insurancer_num").setPlainText(data.insurancer.number);
    frame->findFirstElement("#insurancer_document_date").setPlainText(data.insurancer.documentDate.toString("dd.MM.yyyy"));
    frame->findFirstElement("#insurancer_document_customer").setPlainText(data.insurancer.documentCustomer);
    frame->findFirstElement("#owner").setPlainText(getDriverData(owner, !data.insurancerIsOwner));
    frame->findFirstElement("#profiter").setPlainText(getDriverData(profiter, !data.insurancerIsProfiter));
    frame->findFirstElement("#model").setPlainText(data.transport.model);
    frame->findFirstElement("#ts_number").setPlainText(data.transport.gosNumber);
    frame->findFirstElement("#ts_color").setPlainText(data.transport.color);
    QWebElementCollection vins = frame->findAllElements("p.vin");
    QString::iterator vin_it = data.transport.vin.begin();
    foreach (QWebElement vin, vins) {
        if(vin_it != data.transport.vin.end())
        {
            vin.setPlainText(*vin_it);
            ++vin_it;
        }
    }
    frame->findFirstElement("#ts_year").setPlainText(QString::number(data.transport.year));
    frame->findFirstElement("#engine_num").setPlainText(data.transport.engineNum);
    frame->findFirstElement("#track_num").setPlainText(data.transport.track);
    frame->findFirstElement("#mileage").setPlainText(QString::number(data.transport.mileage));
    frame->findFirstElement("#pts_data").setPlainText(data.transport.ptsData);
    frame->findFirstElement("#sts_data").setPlainText(data.transport.stsData);
    frame->findFirstElement("#using_type_"+QString::number(data.transport.uType)).setPlainText("V");
    frame->findFirstElement("#cost").setPlainText(QString::number(data.cascoData.sum * 1000,'f',2));
    frame->findFirstElement((data.dCount == OsagoData::UnlimitedDrivers)?"#unlimited_drivers":"#limit_drivers")
            .setPlainText("V");
    if(data.dCount == OsagoData::LimitDrivers)
    {
        QWebElementCollection drivers = frame->findAllElements(".driver");
        QList<DriverInfo>::iterator d_it = data.drivers.begin();
        foreach (QWebElement d, drivers) {
            if(d_it != data.drivers.end())
            {
                d.findFirst(".driver_fio").setPlainText(d_it->fio);
                d.findFirst(".driver_licence").setPlainText(d_it->driverLicence);
                d.findFirst(".driver_age").setPlainText(d_it->birthday.toString("dd.MM.yyyy"));
                d.findFirst(".driver_stage").setPlainText(d_it->stage);
                ++d_it;
            }
        }
    }
    QWebElementCollection dops = frame->findAllElements(".dop");
    QList<AdditionalEquipment>::iterator a_it = data.dops.begin();
    qreal totalDopCost=0, totalDopPrem=0;
    if(data.hasDop)
    {
        foreach (QWebElement d, dops) {
            if(a_it != data.dops.end())
            {
                d.findFirst(".name").setPlainText(a_it->name);
                d.findFirst(".model").setPlainText(a_it->model);
                d.findFirst(".count").setPlainText(QString::number(a_it->count));
                d.findFirst(".cost").setPlainText(QString::number(a_it->cost));
                d.findFirst(".prem").setPlainText(QString::number(a_it->prem));
                totalDopCost += a_it->cost;
                totalDopPrem += a_it->prem;
                ++a_it;
            }
        }
    }
    if(totalDopCost != 0 )
    {
        frame->findFirstElement("#total_dop_cost").setPlainText(QString::number(totalDopCost));
    }
    if(totalDopPrem != 0 )
    {
        frame->findFirstElement("#total_dop_prem").setPlainText(QString::number(totalDopPrem));
    }
    if(data.lifeIns == OsagoData::LifeInsBySeatsCount)
    {
        frame->findFirstElement("#life_ins_by_seats").setPlainText("V");
        frame->findFirstElement("#seats_count").setPlainText(QString::number(data.seatsCount));
    }
    else if(data.lifeIns == OsagoData::LifeInsFull)
    {
        frame->findFirstElement("#life_ins_full").setPlainText("V");
    }
    frame->findFirstElement(data.withAmortisation ? "#with_amort" : "#without_amort").setPlainText("V");
    if(data.calculateType == OsagoData::CalculateByIndependetRater)
    {
        frame->findFirstElement("#calculate_ind").setPlainText("V");
    }
    else if(data.calculateType == OsagoData::CalculateByInsurer)
    {
        frame->findFirstElement("#calculate_ins").setPlainText("V");
    }
    else if(data.calculateType == OsagoData::CalculateBySto)
    {
        frame->findFirstElement("#calculate_sto").setPlainText("V");
    }
    qreal full_prem=0;
    foreach (risk r, data.risks) {
        if(r.enabled)
        {
            frame->findFirstElement("#"+r.htmlClassPrefix+"_enable").setPlainText("V");
            frame->findFirstElement("#"+r.htmlClassPrefix+"_prem").setPlainText(r.prem);
            frame->findFirstElement("#"+r.htmlClassPrefix+"_sum").setPlainText(QString::number(r.sum,'f',2));
            frame->findFirstElement("#"+r.htmlClassPrefix+"_tarif").setPlainText(QString::number(r.tarif, 'f',2));
            full_prem += r.prem.toFloat();
        }
    }
    frame->findFirstElement("#full_prem").setPlainText(QString::number(full_prem, 'f', 2));
    frame->findFirstElement(data.cashPayment ? "#cash_payment" : "#bank_payment").setPlainText("V");
    frame->findFirstElement(data.singlePayment ? "#one_payment" : "#more_payment").setPlainText("V");
    frame->findFirstElement("#cash_sum").setPlainText(QString::number(data.cashSum,'f', 2));
    frame->findFirstElement("#payment_doc").setPlainText(data.paymentDoc);
    frame->findFirstElement("#start_hour").setPlainText(data.startDate.toString("hh:mm"));
    frame->findFirstElement("#start_day").setPlainText(data.startDate.toString("dd"));
    frame->findFirstElement("#start_month").setPlainText(data.startDate.toString("MMMM"));
    frame->findFirstElement("#start_year").setPlainText(data.startDate.toString("yy"));
    QDateTime stopDate = data.startDate.addYears(1).addDays(-1);
    stopDate.setTime(QTime(0,0));
    frame->findFirstElement("#stop_hour").setPlainText(stopDate.toString("hh:mm"));
    frame->findFirstElement("#stop_day").setPlainText(stopDate.toString("dd"));
    frame->findFirstElement("#stop_month").setPlainText(stopDate.toString("MMMM"));
    frame->findFirstElement("#stop_year").setPlainText(stopDate.toString("yy"));
    frame->findFirstElement("#notes").setPlainText(data.notes);
    frame->findFirstElement(data.hasDamadge ? "#has_damadge" : "#no_damadge").setPlainText("V");
    frame->findFirstElement("#agent").setPlainText(data.agent);
    frame->findFirstElement("#look_hour").setPlainText(data.lookTime.toString("hh"));
    frame->findFirstElement("#look_min").setPlainText(data.lookTime.toString("mm"));
    frame->findFirstElement("#agent_number").setPlainText(data.agentNumber);
    frame->findFirstElement("#agent_date").setPlainText(QDate::fromString(data.agentDate,"yyyy-MM-dd").toString("dd.MMMM.yyyy"));
    openPrintDialog(view);
}

void CascoMaster::openPrintDialog(QWebView * view)
{
    printWebView* dlg = new printWebView();
    dlg->setViewPage(view->page(), printWebView::PLAIN);
    dlg->setModal(true);
    dlg->setWindowState(Qt::WindowMaximized);
    dlg->show();
}
QString CascoMaster::addrToString(const Addr *addres)
{
    QString addr;
    addr += (addres->index!="")? (addres->index+", ") : "";
    addr += (addres->country!="")? (addres->country+", ") : "";
    addr += (addres->state!="")? (addres->state+", ") : "";
    addr += (addres->city!="")? (addres->city+", ") : "";
    addr += (addres->street!="")? (addres->street+", ") : "";
    addr += (addres->house!="")? ("дом " + addres->house+", ") : "";
    addr += (addres->corp!="")? ("корпус " + addres->corp+", ") : "";
    addr += (addres->flat!="")? ("квартира " + addres->flat+", ") : "";
    return addr;
}
QString CascoMaster::getDriverData(const Driver *driver, bool fullData)
{
    QString data = driver->fio;
    if(fullData)
    {
        data += " " + addrToString(&driver->addr);
        if(driver->fizik)
        {
            data += QString("%1 серия %2 номер %3 выдан: %4")
                                    .arg(driver->documentType)
                                    .arg(driver->ser)
                                    .arg(driver->number)
                                    .arg(driver->documentDate.toString("dd.MM.yyyy"))
                                    .arg(driver->documentCustomer);
        }
        else
        {
            data+= " " + driver->inn;
        }
        data += " " + driver->phone;
    }
    return data;
}
