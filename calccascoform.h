#ifndef CALCCASCOFORM_H
#define CALCCASCOFORM_H

#include <QDialog>
#include <QComboBox>
#include <QModelIndex>
namespace Ui {
class calcCascoForm;
}

class calcCascoForm : public QDialog
{
    Q_OBJECT
    
public:
    explicit calcCascoForm(QWidget *parent = 0);
    ~calcCascoForm();
private slots:
    void changeCarModel(QModelIndex);
private:
    Ui::calcCascoForm *ui;
    void createModelField();
    void activateComboBoxes();
    void setComboBoxModel(const QString &tableName, QComboBox *cb, int column);
     qreal getCoefFromIndex(QModelIndex);
private slots:
    void calculate();

};

#endif // CALCCASCOFORM_H
