#include "cascotsinfodialog.h"
#include "ui_cascotsinfodialog.h"

CascoTsInfoDialog::CascoTsInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CascoTsInfoDialog)
{
    ui->setupUi(this);
    connect(ui->nextButton, &QPushButton::clicked, [this](){ emit next(1); });
    connect(ui->prevButton, &QPushButton::clicked, [this](){ emit prev(1); });
    setWindowTitle(tr("Сведения о ТС"));
}

CascoTsInfoDialog::~CascoTsInfoDialog()
{
    delete ui;
}
CascoTsInfoDialog::CascoTsInfoDialog(OsagoData *d, QWidget *parent) : CascoTsInfoDialog(parent)
{

}
