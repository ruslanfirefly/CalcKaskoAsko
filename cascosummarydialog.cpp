#include "cascosummarydialog.h"
#include "ui_cascosummarydialog.h"

CascoSummaryDialog::CascoSummaryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CascoSummaryDialog)
{
    ui->setupUi(this);
    connect(ui->prevButton, &QPushButton::clicked, [this](){
        emit this->prev(1);
    });
    connect(ui->printButton, &QPushButton::clicked,[this](){
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
}
CascoSummaryDialog::CascoSummaryDialog(OsagoData *d, QWidget *parent) : CascoSummaryDialog(parent)
{
    data = d;
}

CascoSummaryDialog::~CascoSummaryDialog()
{
    delete ui;
}
