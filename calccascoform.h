#ifndef CALCCASCOFORM_H
#define CALCCASCOFORM_H

#include <QDialog>
#include <QComboBox>
#include <QModelIndex>
#include <QSortFilterProxyModel>
#include <dataObjects.h>
namespace Ui {
class calcCascoForm;
}

class calcCascoForm : public QDialog
{
    Q_OBJECT
    
public:
    explicit calcCascoForm(QWidget *parent = 0);
    calcCascoForm(OsagoData* data, QWidget *parent = 0);
    ~calcCascoForm();
private slots:
    void changeCarModel(QModelIndex);
private:
    OsagoData* data;
    Ui::calcCascoForm *ui;
    void createModelField();
    void activateComboBoxes();
    void setComboBoxModel(const QString &tableName, QComboBox *cb, int column);
    qreal getCoefFromIndex(QModelIndex);
    qreal getCoefFromModelLineEDit();
     QSortFilterProxyModel* sortModel;
private slots:
    void calculate();
signals:
    void next(int);

};

#endif // CALCCASCOFORM_H
