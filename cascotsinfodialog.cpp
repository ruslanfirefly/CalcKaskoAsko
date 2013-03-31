#include "cascotsinfodialog.h"
#include "ui_cascotsinfodialog.h"

CascoTsInfoDialog::CascoTsInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CascoTsInfoDialog)
{
    ui->setupUi(this);   
    setWindowTitle(tr("Сведения о ТС"));
}

CascoTsInfoDialog::~CascoTsInfoDialog()
{
    delete ui;
}
CascoTsInfoDialog::CascoTsInfoDialog(OsagoData *d, QWidget *parent) : CascoTsInfoDialog(parent)
{
    data = d;
    connect(ui->nextButton, &QPushButton::clicked, [this](){ emit next(1); });
    connect(ui->prevButton, &QPushButton::clicked, [this](){
        if(data->insurancerIsProfiter && data->insurancerIsOwner)
        {
            emit prev(3);
        }
        else if(data->insurancerIsProfiter)
        {
            emit prev(2);
        }
        else
        {
            emit prev(1);
        }
    });
    connect(this, SIGNAL(next(int)), this, SLOT(fillData()));
    connect(this, SIGNAL(prev(int)), this, SLOT(fillData()));
}
void CascoTsInfoDialog::fillFields()
{


}
void CascoTsInfoDialog::fillData()
{
    data->transport.gosNumber = ui->gosNumber->text();
    data->transport.color = ui->color->text();
    data->transport.vin = ui->vinLineEdit->text();
    data->transport.year = ui->yearSpinBox->value();
    data->transport.track = ui->trackLineEdit->text();
    data->transport.engineNum = ui->engineNum->text();
    data->transport.mileage = ui->mileage->value();
    data->transport.ptsData = ui->ptsData->text();
    data->transport.stsData = ui->stsData->text();
    data->transport.uType = static_cast<ts::UsingType>(ui->usingType->currentIndex());
}
