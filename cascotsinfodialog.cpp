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
}
