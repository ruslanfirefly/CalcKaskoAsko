#include "osagomaster.h"

#include "osagoblankdataform.h"
#include "osagotsblank.h"
#include "osagousinginfoform.h"
#include <stdexcept>
#include <QtWebKitWidgets/QWebView>
#include <QtWebKitWidgets/QWebFrame>
#include <QtWebKit/QWebElement>
#include <QApplication>
#include <printer.h>
#include <QSqlTableModel>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrintPreviewDialog>
#include <QDir>
#include <QMessageBox>
#include <QPushButton>
#include <printwebview.h>
typedef QPair<QDate, QDate> PairDates;
const QVector<QString> OsagoMaster::categories = { "A", "B", "C", "D", "E" };
const QVector<const char*> OsagoMaster::usingTypes = { "Личная", "Учебная езда", "Такси", "Дорожные и специальные", "Другое" };
const QVector<const char*> OsagoMaster::sexes = { "М", "Ж" };
const QVector<const char*> OsagoMaster::docTypes = { "Паспорт транспортного средства", "Свидетельство о регистрации", "Технический паспорт", "Паспорт самоходной машины"};
OsagoMaster::OsagoMaster(QObject *parent) :
    QObject(parent)
{
    dialogs.push_back(new osagoCalcForm(&data));
    dialogs.push_back(new OsagoBlankDataForm(&data.insurancer,Driver::Insurancer, &data.insurancerIsOwner));
    dialogs.push_back(new OsagoBlankDataForm(&data.owner,Driver::Owner, &data.insurancerIsOwner));
    dialogs.push_back(new OsagoTsBlank(&data.transport, &data.insurancerIsOwner));
    dialogs.push_back(new OsagoUsingInfoForm(&data));
    connect(qobject_cast<osagoCalcForm*>(dialogs.at(0)), SIGNAL(next()), this, SLOT(next()));
    connect(qobject_cast<OsagoBlankDataForm*>(dialogs.at(1)), SIGNAL(prev()), this, SLOT(prev()));
    connect(qobject_cast<OsagoBlankDataForm*>(dialogs.at(1)), SIGNAL(next(int)), this, SLOT(next(int)));
    connect(qobject_cast<OsagoBlankDataForm*>(dialogs.at(2)), SIGNAL(prev()), this, SLOT(prev()));
    connect(qobject_cast<OsagoBlankDataForm*>(dialogs.at(2)), SIGNAL(next(int)), this, SLOT(next(int)));
    connect(qobject_cast<OsagoTsBlank*>(dialogs.at(3)), SIGNAL(prev(int)), this, SLOT(prev(int)));
    connect(qobject_cast<OsagoTsBlank*>(dialogs.at(3)), SIGNAL(next()), this, SLOT(next()));
    connect(qobject_cast<OsagoUsingInfoForm*>(dialogs.at(4)), SIGNAL(prev()), this, SLOT(prev()));
    connect(qobject_cast<OsagoUsingInfoForm*>(dialogs.at(4)), SIGNAL(printRequest()), this, SLOT(printRequest()));
    connect(qobject_cast<OsagoUsingInfoForm*>(dialogs.at(4)), SIGNAL(printBlank()), this, SLOT(printBlank()));
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
void OsagoMaster::printBlank()
{
    QWebView* tmpView = new QWebView();
    QUrl url = QUrl::fromLocalFile(QDir::toNativeSeparators(qApp->applicationDirPath()+"/templates/blank_osago.html"));
    tmpView->load(url);
    connect(tmpView, SIGNAL(loadFinished(bool)), this, SLOT(printBlankPreview()));
}
void OsagoMaster::printBlankPreview()
{

    QWebView* view = qobject_cast<QWebView*>(sender());
    QWebFrame* frame = view->page()->currentFrame();
    frame->findFirstElement("#insurancer").setPlainText(data.insurancer.fio);
    frame->findFirstElement("#owner").setPlainText(data.owner.fio);
    frame->findFirstElement("#tsModel").setPlainText(data.transport.model);
    frame->findFirstElement("#tsVin").setPlainText(data.transport.vin==""?tr("ОТСУТСТВУЕТ"):data.transport.vin);
    frame->findFirstElement("#tsGosNumber").setPlainText(data.transport.gosNumber);
    frame->findFirstElement("#documentType").setPlainText(docTypes[data.transport.documentType]);
    frame->findFirstElement("#documentNumber").setPlainText(data.transport.number);
    frame->findFirstElement("#documentSerial").setPlainText(data.transport.serial);
     QWebElementCollection driversRows = frame->findFirstElement("#driversTable").findAll("tr");
    switch(data.dCount)
    {
    case OsagoData::LimitDrivers:
        frame->findFirstElement("#limitDrivers").setPlainText("X");

        for(int row = 0; row < data.drivers.count(); ++row)
        {
            QWebElementCollection driversColums = driversRows[row].findAll("td");
            driversColums[0].setPlainText(QString::number(row+1));
            driversColums[1].setPlainText(data.drivers[row].fio);
            driversColums[2].setPlainText(data.drivers[row].driverLicence);
        }
        break;
    case OsagoData::UnlimitedDrivers:
        frame->findFirstElement("#unlimitedDrivers").setPlainText("X");
        break;
    }

    frame->findFirstElement("#sum").setPlainText(QString::number(data.coeffs.sum));
    frame->findFirstElement("#notes").setPlainText(data.notes);
    QDate current = QDate::currentDate();
    frame->findFirstElement("#contractDate").setInnerXml(
                QString("<tr><td>%1</td><td>%2</td><td>%3</td></tr>")
                .arg(current.toString("dd"))
                .arg(current.toString("MMMM"))
                .arg(current.toString("yy"))

                );
    frame->findFirstElement("#polisDate").setInnerXml(
                QString("<tr><td>%1</td><td>%2</td><td>%3</td></tr>")
                .arg(current.toString("dd"))
                .arg(current.toString("MMMM"))
                .arg(current.toString("yy"))

                );
    QDateTime currentDT = QDateTime::currentDateTime();
    QDateTime fromDateTime = currentDT;
    if(currentDT.date() <= data.from) fromDateTime.setDate(data.from);

    frame->findFirstElement("#contractPeriodStart").setInnerXml(
                QString(QString("<tr>")+
                "<td>%1</td>"+
                "<td>%2</td>"+
                "<td>%3</td>"+
                "<td>%4</td>"+
                "<td>%5</td>"+
                "</tr>"+
                " <tr>"+
                "<td></td>"+
                "<td></td>"+
                "<td>%6</td>"+
                "<td>%7</td>"
                "<td>%8</td>"+
                "</tr>")
                .arg(fromDateTime.toString("hh"))
                .arg(fromDateTime.toString("mm"))
                .arg(fromDateTime.toString("dd"))
                .arg(fromDateTime.toString("MM"))
                .arg(fromDateTime.toString("yy"))
                .arg(data.to.toString("dd"))
                .arg(data.to.toString("MM"))
                .arg(data.to.toString("yy"))
                );

    QWebElementCollection periods = frame->findFirstElement("#usingPeriods").findAll("td");


    for(int p = 0; p < data.usingPeriods.count(); ++p)
    {
        periods[0+p*6].setPlainText(data.usingPeriods[p].first.toString("dd"));
        periods[1+p*6].setPlainText(data.usingPeriods[p].first.toString("MM"));
        periods[2+p*6].setPlainText(data.usingPeriods[p].first.toString("yy"));
        periods[3+p*6].setPlainText(data.usingPeriods[p].second.toString("dd"));
        periods[4+p*6].setPlainText(data.usingPeriods[p].second.toString("MM"));
        periods[5+p*6].setPlainText(data.usingPeriods[p].second.toString("yy"));
    }
    //view->show();
    printWebView* dlg = new printWebView();
    dlg->setViewPage(view->page());
    dlg->setModal(true);
    dlg->exec();
    connect(view, SLOT(close()), this, SLOT(startPrintThrowImage()));
    //printThrowImage(view);

}
void OsagoMaster::startPrintThrowImage()
{
    printThrowImage(qobject_cast<QWebView*>(sender()));
}

void OsagoMaster::printThrowImage(QWebView* view)
{
    QPrinter* printer = new QPrinter;
    QWebFrame* frame = view->page()->currentFrame();
    printer->setPageMargins(0,0,0,0, QPrinter::Inch);
    view->page()->setViewportSize(frame->contentsSize());
    QImage image(view->page()->viewportSize(), QImage::Format_ARGB32);
    QPainter painter(&image);
    view->page()->mainFrame()->render(&painter);
    painter.end();
    QPrintDialog* dlg = new QPrintDialog;
    if(dlg->exec() == QDialog::Accepted)
    {
        printer = dlg->printer();
        printer->setPageSize(QPrinter::A4);
        QPainter p(printer);
        QSizeF size = printer->pageSizeMM();

        QImage scaledImage = image.scaled(size.width()*image.dotsPerMeterX()/1000, size.height()*image.dotsPerMeterY()/1000
                                          , Qt::IgnoreAspectRatio
                                          , Qt::SmoothTransformation);

        p.drawImage(QPoint(0,0), scaledImage);
        p.end();
    }

}

void OsagoMaster::printRequest()
{
    QWebView* tmpView = new QWebView();
    QUrl url = QUrl::fromLocalFile(QDir::toNativeSeparators(qApp->applicationDirPath()+"/templates/osago_zayavlenie.html"));
    tmpView->load(url);
    connect(tmpView, SIGNAL(loadFinished(bool)), this, SLOT(printRequestPreview()));

}
void OsagoMaster::printRequestPreview()
{

    if(data.insurancerIsOwner) data.owner = data.insurancer;
    QWebView* view = qobject_cast<QWebView*>(sender());
    qDebug()<<"text";
    QWebFrame* frame = view->page()->currentFrame();
    fillDriverData("insurancer", &data.insurancer, frame);
    fillDriverData("owner", &data.owner, frame);
    fillTextField("#phone", data.insurancer.phone, frame);
    fillTextField("#fromDayIns", data.from.toString("dd"), frame);
    fillTextField("#fromMonthIns", data.from.toString("MMMM"), frame);
    fillTextField("#fromYearIns", data.from.toString("yyyy"), frame);
    fillTextField("#toDayIns", data.to.toString("dd"), frame);
    fillTextField("#toMonthIns", data.to.toString("MMMM"), frame);
    fillTextField("#toYearIns", data.to.toString("yyyy"), frame);

    fillTextField("#tsModel", data.transport.model, frame);
    fillTextField("#tsVin", data.transport.vin, frame);
    fillTextField("#tsShassi", data.transport.shassi, frame);
    fillTextField("#tsTrack", data.transport.track, frame);
    fillTextField("#tsSerial", data.transport.serial, frame);
    fillTextField("#tsNumber", data.transport.number, frame);
    fillTextField("#tsGosNumber", data.transport.gosNumber, frame);
    switch(data.transport.pType)
    {
    case ts::kWt:
        fillTextField("#tsPowerKWt", QString::number(data.transport.power), frame);
        fillTextField("#tsPowerHp", "", frame);
        break;
    case ts::hp:
        fillTextField("#tsPowerKWt", "", frame);
        fillTextField("#tsPowerHp", QString::number(data.transport.power), frame);
        break;
    }
    switch(data.transport.tCat)
    {
    case ts::C:
         fillTextField("#tsMass", QString::number(data.transport.mass), frame);
         break;
    case ts::D:
        fillTextField("#tsPassengersCount", QString::number(data.transport.passengersCount), frame);
        break;
    }
    fillTextField("#tsYear", QString::number(data.transport.year), frame);
    fillTextField("#tsCountOfIncidents", QString::number(data.transport.countOfIncidents), frame);
    fillTextField("#tsTCat", "категория "+categories[data.transport.tCat], frame);
    fillTextField("#tsDocumentDate", data.transport.documentDate.toString("dd.MM.yyyy"), frame);
    fillTextField("#tsUType", tr(usingTypes[data.transport.uType]), frame);
    fillTextField("#tsClassOwner", getClass(data.transport.classOwner), frame);
    if(data.transport.isRental)
    {
        fillTextField("#tsIsRental", tr("сдается"), frame);
    }
    else
    {
        fillTextField("#tsIsRental", tr("не сдается"), frame);
    }
    switch(data.dCount)
    {
    case OsagoData::UnlimitedDrivers:
        fillTextField("#unlimitedDrivers","X", frame);
        break;
    case OsagoData::LimitDrivers:
        fillTextField("#limitDrivers","X", frame);
         fillDriverInfoTable(data.drivers, frame);
        break;
    }
    foreach(const PairDates& p, data.usingPeriods) {
        frame->findFirstElement("#usingTimes").appendInside(createUsingInfo(&p));
    }
    if(data.hasLastOsago) frame->findFirstElement("#usingTimes").appendOutside(createLastOsagoInfo(&data));
    fillTextField("#otherInfo", tr("Иные сведения: ")+data.otherInfo, frame);
    fillTextField("#polisSerial", data.polisSerial, frame);
    fillTextField("#polisNumber", data.polisNum, frame);
    fillTextField("#notes", tr("Особые отметки:  ")+data.notes, frame);
    fillTextField("#agent", data.agent, frame);
    fillTextField("#insurancer", data.insurancer.fio, frame);
    fillTextField("#currentDateFirst", QDate::currentDate().toString("dd.MM.yyyy"), frame);
    fillTextField("#currentDateSecond", QDate::currentDate().toString("dd.MM.yyyy"), frame);
    fillTextField("#kbm", QString::number(data.coeffs.kbm), frame);
    fillTextField("#km", QString::number(data.coeffs.km), frame);
    fillTextField("#ko", QString::number(data.coeffs.ko), frame);
    fillTextField("#kp", QString::number(data.coeffs.kp), frame);
    fillTextField("#ks", QString::number(data.coeffs.ks), frame);
    fillTextField("#kt", QString::number(data.coeffs.kt), frame);
    fillTextField("#kvs", QString::number(data.coeffs.kvs), frame);
    fillTextField("#tb", QString::number(data.coeffs.tb), frame);
    Printer::getInstance().printPreview(qobject_cast<QWebView*>(sender()));
}
QString OsagoMaster::createUsingInfo(const QPair<QDate, QDate> *usingPeriods)
{
    return QString("с&nbsp;&nbsp;«%1»&nbsp;&nbsp;%2&nbsp;&nbsp;%3&nbsp;г.&nbsp;"
    "&nbsp;&nbsp;&nbsp;"
    "по&nbsp;&nbsp;«%4»&nbsp;&nbsp;%5&nbsp;&nbsp;%6&nbsp;г.<br />")
            .arg(usingPeriods->first.toString("dd"))
            .arg(usingPeriods->first.toString("MMMM"))
            .arg(usingPeriods->first.toString("yyyy"))
            .arg(usingPeriods->second.toString("dd"))
            .arg(usingPeriods->second.toString("MMMM"))
            .arg(usingPeriods->second.toString("yyyy"));
}

void OsagoMaster::fillDriverInfoTable(QList<DriverInfo> info, QWebFrame *frame)
{

    QWebElement table = frame->findFirstElement("#driverInfoTable");
    table.appendInside(
                "<tr>"
                "<td>№<br />п\п</td>"
                "<td>Фамилия, имя, отчество</td>"
                "<td>Дата рождения</td>"
                "<td>Пол</td>"
                "<td style=\"max-width: 100px;\">Водительское удостоверение (серия, номер когда выдано)</td>"
                "<td>Стаж вождения (год, месяц)</td>"
                "<td style=\"max-width: 170px; font-size: 7pt;\">Количество страховых случаев в течение срока действия предыдущего договора обязательного страхования</td>"
                "<td>Класс, зависящий от наличия страховых выплат</td>"
                "</tr>");
    for(int row = 0; row < info.count(); ++row)
    {
        table.appendInside(QString("<tr>"
                                   "<td>%1</td>"
                                   "<td>%2</td>"
                                   "<td>%3</td>"
                                   "<td>%4</td>"
                                   "<td>%5</td>"
                                   "<td>%6</td>"
                                   "<td>%7</td>"
                                   "<td>%8</td>"
                                   "</tr>")
                           .arg(row+1)
                           .arg(info[row].fio)
                           .arg(info[row].birthday.toString("dd.MM.yyyy"))
                           .arg(sexes[info[row].sex])
                           .arg(info[row].driverLicence)
                           .arg(info[row].stage)
                           .arg(info[row].countOfIncidents)
                           .arg(getClass(info[row].dClass)));
    }
}
QString OsagoMaster::createLastOsagoInfo(OsagoData *data)
{
    return QString(
                "<p class=\"field\">Предыдущий договор обязательного страхования гражданской ответственности владельцев транспортных средств </p><br />"
                "<p class=\"field\">в отношение указанного ТС<br /><span>&nbsp;</span></p>"
                "<p class=\"field\" style=\"text-decoration : underline;\" >&nbsp;&nbsp;%1<br /><span>(серия)</span></p>"
                "<p class=\"field\" style=\"margin-left: 10px; text-decoration : underline; \">%2<br /><span>(номер)</span></p><br /> "
                "<p class=\"field\">Страховщик: %3</p><br />")
            .arg(data->lastOsagoSerial)
            .arg(data->lastOsagoNum)
            .arg(data->lastOsagoCompany);
}

QString OsagoMaster::getClass(int num)
{
    QSqlTableModel* model = new QSqlTableModel(this, QSqlDatabase::database("calc.db"));
    model->setTable("classes");
    model->select();
    return model->index(num, 1).data().toString();
}

void OsagoMaster::fillDriverData(const QString &prefix, Driver *driver, QWebFrame *frame)
{
    fillTextField("#"+prefix+"Fio", driver->fio, frame);
    fillTextField("#"+prefix+"Inn", driver->inn, frame);
    fillTextField("#"+prefix+"Birthday", driver->birthday.toString("dd.MM.yyyy"), frame);
    fillTextField("#"+prefix+"DocumentType", driver->documentType, frame);
    fillTextField("#"+prefix+"DocumentSerial", driver->ser, frame);
    fillTextField("#"+prefix+"DocumentNum", driver->number, frame);
    fillTextField("#"+prefix+"Index", driver->addr.index, frame);
    fillTextField("#"+prefix+"Country", driver->addr.country, frame);
    fillTextField("#"+prefix+"State", driver->addr.state, frame);
    fillTextField("#"+prefix+"City", driver->addr.city, frame);
    fillTextField("#"+prefix+"Street", driver->addr.street, frame);
    fillTextField("#"+prefix+"House", driver->addr.house, frame);
    fillTextField("#"+prefix+"Corp", driver->addr.corp, frame);
    fillTextField("#"+prefix+"Flat", driver->addr.flat, frame);
}

void OsagoMaster::fillTextField(const QString &id, const QString &text, QWebFrame *frame)
{
    if(text == "")
    {
        frame->findFirstElement(id).setPlainText("-------");
    }
    else
    {
        frame->findFirstElement(id).setPlainText(text);
    }
}
