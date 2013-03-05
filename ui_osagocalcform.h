/********************************************************************************
** Form generated from reading UI file 'osagocalcform.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OSAGOCALCFORM_H
#define UI_OSAGOCALCFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_osagoCalcForm
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QComboBox *autoTypeComboBox;
    QLabel *clientTypeLabel;
    QComboBox *clientTypeComboBox;
    QLabel *label_3;
    QComboBox *regTypeComboBox;
    QLabel *label_4;
    QLineEdit *townLineEdit;
    QLabel *classLabel;
    QComboBox *classComboBox;
    QLabel *agesLabel;
    QComboBox *agesComboBox;
    QLabel *powerLabel;
    QComboBox *powerComboBox;
    QLabel *foreignLabel;
    QComboBox *foreignComboBox;
    QLabel *internalLabel;
    QComboBox *internalComboBox;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QLabel *bonus;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *nextButton;

    void setupUi(QDialog *osagoCalcForm)
    {
        if (osagoCalcForm->objectName().isEmpty())
            osagoCalcForm->setObjectName(QStringLiteral("osagoCalcForm"));
        osagoCalcForm->resize(674, 390);
        verticalLayout = new QVBoxLayout(osagoCalcForm);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(osagoCalcForm);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        autoTypeComboBox = new QComboBox(osagoCalcForm);
        autoTypeComboBox->setObjectName(QStringLiteral("autoTypeComboBox"));
        autoTypeComboBox->setModelColumn(1);

        gridLayout_2->addWidget(autoTypeComboBox, 0, 1, 1, 1);

        clientTypeLabel = new QLabel(osagoCalcForm);
        clientTypeLabel->setObjectName(QStringLiteral("clientTypeLabel"));

        gridLayout_2->addWidget(clientTypeLabel, 1, 0, 1, 1);

        clientTypeComboBox = new QComboBox(osagoCalcForm);
        clientTypeComboBox->setObjectName(QStringLiteral("clientTypeComboBox"));
        clientTypeComboBox->setModelColumn(1);

        gridLayout_2->addWidget(clientTypeComboBox, 1, 1, 1, 1);

        label_3 = new QLabel(osagoCalcForm);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        regTypeComboBox = new QComboBox(osagoCalcForm);
        regTypeComboBox->setObjectName(QStringLiteral("regTypeComboBox"));
        regTypeComboBox->setModelColumn(1);

        gridLayout_2->addWidget(regTypeComboBox, 2, 1, 1, 1);

        label_4 = new QLabel(osagoCalcForm);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        townLineEdit = new QLineEdit(osagoCalcForm);
        townLineEdit->setObjectName(QStringLiteral("townLineEdit"));

        gridLayout_2->addWidget(townLineEdit, 3, 1, 1, 1);

        classLabel = new QLabel(osagoCalcForm);
        classLabel->setObjectName(QStringLiteral("classLabel"));

        gridLayout_2->addWidget(classLabel, 4, 0, 1, 1);

        classComboBox = new QComboBox(osagoCalcForm);
        classComboBox->setObjectName(QStringLiteral("classComboBox"));
        classComboBox->setModelColumn(1);

        gridLayout_2->addWidget(classComboBox, 4, 1, 1, 1);

        agesLabel = new QLabel(osagoCalcForm);
        agesLabel->setObjectName(QStringLiteral("agesLabel"));

        gridLayout_2->addWidget(agesLabel, 5, 0, 1, 1);

        agesComboBox = new QComboBox(osagoCalcForm);
        agesComboBox->setObjectName(QStringLiteral("agesComboBox"));
        agesComboBox->setModelColumn(1);

        gridLayout_2->addWidget(agesComboBox, 5, 1, 1, 1);

        powerLabel = new QLabel(osagoCalcForm);
        powerLabel->setObjectName(QStringLiteral("powerLabel"));

        gridLayout_2->addWidget(powerLabel, 6, 0, 1, 1);

        powerComboBox = new QComboBox(osagoCalcForm);
        powerComboBox->setObjectName(QStringLiteral("powerComboBox"));
        powerComboBox->setModelColumn(1);

        gridLayout_2->addWidget(powerComboBox, 6, 1, 1, 1);

        foreignLabel = new QLabel(osagoCalcForm);
        foreignLabel->setObjectName(QStringLiteral("foreignLabel"));

        gridLayout_2->addWidget(foreignLabel, 7, 0, 1, 1);

        foreignComboBox = new QComboBox(osagoCalcForm);
        foreignComboBox->setObjectName(QStringLiteral("foreignComboBox"));
        foreignComboBox->setModelColumn(1);

        gridLayout_2->addWidget(foreignComboBox, 7, 1, 1, 1);

        internalLabel = new QLabel(osagoCalcForm);
        internalLabel->setObjectName(QStringLiteral("internalLabel"));

        gridLayout_2->addWidget(internalLabel, 8, 0, 1, 1);

        internalComboBox = new QComboBox(osagoCalcForm);
        internalComboBox->setObjectName(QStringLiteral("internalComboBox"));
        internalComboBox->setModelColumn(1);

        gridLayout_2->addWidget(internalComboBox, 8, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalSpacer = new QSpacerItem(63, 27, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 0, 0, 1, 2);

        groupBox = new QGroupBox(osagoCalcForm);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(48, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 2, 1);

        horizontalSpacer = new QSpacerItem(48, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 2, 1);

        bonus = new QLabel(groupBox);
        bonus->setObjectName(QStringLiteral("bonus"));

        gridLayout->addWidget(bonus, 1, 1, 1, 1);


        gridLayout_3->addWidget(groupBox, 1, 0, 1, 2);

        verticalSpacer_2 = new QSpacerItem(63, 64, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 2, 0, 1, 2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 3, 0, 1, 1);

        nextButton = new QPushButton(osagoCalcForm);
        nextButton->setObjectName(QStringLiteral("nextButton"));

        gridLayout_3->addWidget(nextButton, 3, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout_3);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(osagoCalcForm);

        QMetaObject::connectSlotsByName(osagoCalcForm);
    } // setupUi

    void retranslateUi(QDialog *osagoCalcForm)
    {
        osagoCalcForm->setWindowTitle(QApplication::translate("osagoCalcForm", "\320\240\320\260\321\201\321\207\320\265\321\202 \320\276\321\201\320\260\320\263\320\276", 0));
        label->setText(QApplication::translate("osagoCalcForm", "\320\242\320\270\320\277 \321\202\321\200\320\260\320\275\321\201\320\277\320\276\321\200\321\202\320\275\320\276\320\263\320\276 \321\201\321\200\320\265\320\264\321\201\321\202\320\262\320\260", 0));
        autoTypeComboBox->setProperty("tableName", QVariant(QApplication::translate("osagoCalcForm", "auto_types", 0)));
        clientTypeLabel->setText(QApplication::translate("osagoCalcForm", "\320\241\320\276\320\261\321\201\321\202\320\262\320\265\320\275\320\275\320\270\320\272", 0));
        clientTypeComboBox->setProperty("tableName", QVariant(QApplication::translate("osagoCalcForm", "client_type", 0)));
        label_3->setText(QApplication::translate("osagoCalcForm", "\320\234\320\265\321\201\321\202\320\276 \321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\320\270", 0));
        regTypeComboBox->setProperty("tableName", QVariant(QApplication::translate("osagoCalcForm", "reg_type", 0)));
        label_4->setText(QApplication::translate("osagoCalcForm", "\320\240\320\265\320\263\320\270\320\276\320\275, \320\263\320\276\321\200\320\276\320\264", 0));
        townLineEdit->setProperty("tableName", QVariant(QApplication::translate("osagoCalcForm", "towns", 0)));
        classLabel->setText(QApplication::translate("osagoCalcForm", "\320\232\320\273\320\260\321\201\321\201", 0));
        classComboBox->setProperty("tableName", QVariant(QApplication::translate("osagoCalcForm", "classes", 0)));
        agesLabel->setText(QApplication::translate("osagoCalcForm", "\320\233\320\270\321\206\320\260, \320\264\320\276\320\277\321\203\321\211\320\265\320\275\320\275\321\213\320\265 \320\272 \321\203\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\321\216 \320\242\320\241", 0));
        agesComboBox->setProperty("tableName", QVariant(QApplication::translate("osagoCalcForm", "ages", 0)));
        powerLabel->setText(QApplication::translate("osagoCalcForm", "\320\234\320\276\321\211\320\275\320\276\321\201\321\202\321\214 \320\264\320\262\320\270\320\263\320\260\321\202\320\265\320\273\321\217", 0));
        powerComboBox->setProperty("tableName", QVariant(QApplication::translate("osagoCalcForm", "power", 0)));
        foreignLabel->setText(QApplication::translate("osagoCalcForm", "\320\241\321\200\320\276\320\272 \321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\320\270", 0));
        foreignComboBox->setProperty("tableName", QVariant(QApplication::translate("osagoCalcForm", "foreign_period", 0)));
        internalLabel->setText(QApplication::translate("osagoCalcForm", "\320\241\321\200\320\276\320\272 \321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\320\270", 0));
        internalComboBox->setProperty("tableName", QVariant(QApplication::translate("osagoCalcForm", "internal_period", 0)));
        groupBox->setTitle(QApplication::translate("osagoCalcForm", "\320\240\320\260\320\267\320\274\320\265\321\200 \321\201\321\202\321\200\320\260\321\205\320\276\320\262\320\276\320\271 \320\277\321\200\320\265\320\274\320\270\320\270", 0));
        bonus->setText(QString());
        nextButton->setText(QApplication::translate("osagoCalcForm", "\320\224\320\260\320\273\320\265\320\265", 0));
    } // retranslateUi

};

namespace Ui {
    class osagoCalcForm: public Ui_osagoCalcForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OSAGOCALCFORM_H
