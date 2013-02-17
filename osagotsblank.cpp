#include "osagotsblank.h"
#include "ui_osagotsblank.h"

OsagoTsBlank::OsagoTsBlank(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OsagoTsBlank)
{
    ui->setupUi(this);
    connect(ui->nextButton, SIGNAL(clicked()), this, SIGNAL(next()));
    connect(ui->prevButton, SIGNAL(clicked()), this, SLOT(sendPrev()));
}
OsagoTsBlank::OsagoTsBlank(bool *insurancerIsOwner, QWidget *parent) : OsagoTsBlank(parent)
{
    isOwner = insurancerIsOwner;
}

OsagoTsBlank::~OsagoTsBlank()
{
    delete ui;
}
void OsagoTsBlank::sendPrev()
{
    (*isOwner) ? (emit prev(2)) : (emit prev(1));
}

