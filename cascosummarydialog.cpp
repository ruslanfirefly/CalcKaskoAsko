#include "cascosummarydialog.h"
#include "ui_cascosummarydialog.h"

CascoSummaryDialog::CascoSummaryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CascoSummaryDialog)
{
    ui->setupUi(this);
    connect(ui->prevButton, &QPushButton::clicked, [this](){
        fillData();
        emit this->prev(1);
    });
    connect(ui->printButton, &QPushButton::clicked,[this](){
        fillData();
        emit this->printBlank();
    });

    QButtonGroup* b = new QButtonGroup(this);
    b->addButton(ui->onePayment);
    b->addButton(ui->morePayments);
    b = new QButtonGroup(this);
    b->addButton(ui->cashPayment);
    b->addButton(ui->bankPayment);
    ui->onePayment->setChecked(true);
    ui->cashPayment->setChecked(true);    
    connect(ui->theft, &QCheckBox::toggled, [this](bool b){
        setElementsState(b, { ui->theftPrem, ui->theftSum, ui->theftTarif} );
    });
    connect(ui->damadge, &QCheckBox::toggled, [this](bool b){
        setElementsState(b, { ui->damadgePrem, ui->damadgeSum, ui->damadgeTarif} );
    });
    connect(ui->uts, &QCheckBox::toggled, [this](bool b){
        setElementsState(b, { ui->utsPrem, ui->utsTarif, ui->utsSum} );
    });
    connect(ui->additionalEquip, &QCheckBox::toggled, [this](bool b){
        setElementsState(b, { ui->additionalEqPrem, ui->additionalEqSum, ui->additionalEqTarif} );
    });
    connect(ui->life, &QCheckBox::toggled, [this](bool b){
        setElementsState(b, { ui->lifePrem, ui->lifeSum, ui->lifeTarif} );
    });
    ui->lookTime->setTime(QTime::currentTime());
}
CascoSummaryDialog::CascoSummaryDialog(OsagoData *d, QWidget *parent) : CascoSummaryDialog(parent)
{
    data = d;
}
void CascoSummaryDialog::showEvent(QShowEvent *e)
{
    ui->casco->setChecked(true);
    ui->cascoPrem->setText(QString::number(data->cascoData.prem*1000, 'f', 2));
    ui->cascoSum->setValue(data->cascoData.sum*1000);
    ui->cascoTarif->setValue(data->cascoData.tarif);
    QDialog::showEvent(e);
}

CascoSummaryDialog::~CascoSummaryDialog()
{
    delete ui;
}
void CascoSummaryDialog::setElementsState(bool state, QWidgetList elements)
{
    foreach (QWidget* e, elements) {
        e->setEnabled(state);
    }
}

void CascoSummaryDialog::fillData()
{
    if(ui->lifeInsNone->isChecked())
    {
        data->lifeIns = OsagoData::NoLifeIns;
    }
    else if(ui->lifeInsByCount->isChecked())
    {
        data->lifeIns = OsagoData::LifeInsBySeatsCount;
        data->seatsCount = ui->seatsCount->value();
    }
    else if(ui->lifeInsNone->isChecked())
    {
        data->lifeIns = OsagoData::LifeInsFull;
    }
    if(ui->withAmort->isChecked())
    {
        data->withAmortisation = true;
    }
    if(ui->calculateByIndependet->isChecked())
    {
        data->calculateType = OsagoData::CalculateByIndependetRater;
    }
    else if(ui->calculateByIns->isChecked())
    {
        data->calculateType = OsagoData::CalculateByInsurer;
    }
    else if(ui->calculateBySto->isChecked())
    {
        data->calculateType = OsagoData::CalculateBySto;
    }
    data->singlePayment = ui->onePayment->isChecked();
    data->cashPayment = ui->cashPayment->isChecked();
    data->cashSum = ui->cashSums->value();
    data->paymentDoc = ui->paymentDoc->text();
    data->risks[risk::RiskCasco].enabled = ui->casco->isChecked();
    data->risks[risk::RiskCasco].sum = ui->cascoSum->value();
    data->risks[risk::RiskCasco].prem = ui->cascoPrem->text();
    data->risks[risk::RiskCasco].tarif = ui->cascoTarif->value();

    data->risks[risk::RiskLife].enabled = ui->life->isChecked();
    data->risks[risk::RiskLife].sum = ui->lifeSum->value();
    data->risks[risk::RiskLife].prem = ui->lifePrem->text();
    data->risks[risk::RiskLife].tarif = ui->lifeTarif->value();
    data->lookTime = ui->lookTime->time();
    data->hasDamadge = ui->hasDamadge->isChecked();
    data->damadgeDesription = ui->damadgeDescription->text();
}
