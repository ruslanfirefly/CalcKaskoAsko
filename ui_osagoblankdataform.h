/********************************************************************************
** Form generated from reading UI file 'osagoblankdataform.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OSAGOBLANKDATAFORM_H
#define UI_OSAGOBLANKDATAFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
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

class Ui_OsagoBlankDataForm
{
public:
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *insurancerIsOwner;
    QGridLayout *gridLayout_3;
    QDateEdit *birthday;
    QLabel *dateInnLabel;
    QLineEdit *dateInnLineEdit;
    QLineEdit *fioLineEdit;
    QLabel *insurancerNameLabel;
    QCheckBox *checkBox;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *serialLineEdit;
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *typeLineEdit;
    QLabel *label;
    QLineEdit *numberLineEdit;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QLineEdit *country;
    QLineEdit *index;
    QLabel *label_5;
    QLineEdit *state;
    QLabel *label_6;
    QLineEdit *street;
    QLabel *label_8;
    QLabel *label_10;
    QLineEdit *corp;
    QLabel *label_7;
    QLineEdit *city;
    QLabel *label_9;
    QLabel *label_11;
    QLineEdit *house;
    QLineEdit *flat;
    QHBoxLayout *phoneLayout;
    QLabel *phoneLabel;
    QLineEdit *phone;
    QHBoxLayout *horizontalLayout;
    QPushButton *prevPushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *nextButton;

    void setupUi(QDialog *OsagoBlankDataForm)
    {
        if (OsagoBlankDataForm->objectName().isEmpty())
            OsagoBlankDataForm->setObjectName(QStringLiteral("OsagoBlankDataForm"));
        OsagoBlankDataForm->resize(654, 504);
        horizontalLayout_4 = new QHBoxLayout(OsagoBlankDataForm);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox = new QGroupBox(OsagoBlankDataForm);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        insurancerIsOwner = new QCheckBox(groupBox);
        insurancerIsOwner->setObjectName(QStringLiteral("insurancerIsOwner"));

        verticalLayout_2->addWidget(insurancerIsOwner);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        birthday = new QDateEdit(groupBox);
        birthday->setObjectName(QStringLiteral("birthday"));

        gridLayout_3->addWidget(birthday, 2, 1, 1, 1);

        dateInnLabel = new QLabel(groupBox);
        dateInnLabel->setObjectName(QStringLiteral("dateInnLabel"));

        gridLayout_3->addWidget(dateInnLabel, 2, 0, 1, 1);

        dateInnLineEdit = new QLineEdit(groupBox);
        dateInnLineEdit->setObjectName(QStringLiteral("dateInnLineEdit"));

        gridLayout_3->addWidget(dateInnLineEdit, 2, 2, 1, 1);

        fioLineEdit = new QLineEdit(groupBox);
        fioLineEdit->setObjectName(QStringLiteral("fioLineEdit"));

        gridLayout_3->addWidget(fioLineEdit, 1, 2, 1, 1);

        insurancerNameLabel = new QLabel(groupBox);
        insurancerNameLabel->setObjectName(QStringLiteral("insurancerNameLabel"));

        gridLayout_3->addWidget(insurancerNameLabel, 1, 0, 1, 1);

        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout_3->addWidget(checkBox, 0, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        serialLineEdit = new QLineEdit(groupBox_2);
        serialLineEdit->setObjectName(QStringLiteral("serialLineEdit"));

        gridLayout->addWidget(serialLineEdit, 0, 3, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        typeLineEdit = new QLineEdit(groupBox_2);
        typeLineEdit->setObjectName(QStringLiteral("typeLineEdit"));

        gridLayout->addWidget(typeLineEdit, 0, 1, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        numberLineEdit = new QLineEdit(groupBox_2);
        numberLineEdit->setObjectName(QStringLiteral("numberLineEdit"));

        gridLayout->addWidget(numberLineEdit, 1, 2, 1, 2);


        horizontalLayout_2->addLayout(gridLayout);


        verticalLayout_2->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout = new QVBoxLayout(groupBox_3);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        country = new QLineEdit(groupBox_3);
        country->setObjectName(QStringLiteral("country"));
        country->setMinimumSize(QSize(143, 0));

        gridLayout_2->addWidget(country, 0, 4, 1, 1);

        index = new QLineEdit(groupBox_3);
        index->setObjectName(QStringLiteral("index"));

        gridLayout_2->addWidget(index, 0, 1, 1, 1);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 0, 2, 1, 2);

        state = new QLineEdit(groupBox_3);
        state->setObjectName(QStringLiteral("state"));

        gridLayout_2->addWidget(state, 1, 1, 1, 1);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        street = new QLineEdit(groupBox_3);
        street->setObjectName(QStringLiteral("street"));

        gridLayout_2->addWidget(street, 2, 1, 1, 1);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_2->addWidget(label_8, 2, 0, 1, 1);

        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_2->addWidget(label_10, 3, 0, 1, 1);

        corp = new QLineEdit(groupBox_3);
        corp->setObjectName(QStringLiteral("corp"));

        gridLayout_2->addWidget(corp, 3, 1, 1, 1);

        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 1, 2, 1, 1);

        city = new QLineEdit(groupBox_3);
        city->setObjectName(QStringLiteral("city"));

        gridLayout_2->addWidget(city, 1, 4, 1, 1);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_2->addWidget(label_9, 2, 2, 1, 1);

        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_2->addWidget(label_11, 3, 2, 1, 1);

        house = new QLineEdit(groupBox_3);
        house->setObjectName(QStringLiteral("house"));

        gridLayout_2->addWidget(house, 2, 4, 1, 1);

        flat = new QLineEdit(groupBox_3);
        flat->setObjectName(QStringLiteral("flat"));

        gridLayout_2->addWidget(flat, 3, 4, 1, 1);


        verticalLayout->addLayout(gridLayout_2);


        verticalLayout_2->addWidget(groupBox_3);

        phoneLayout = new QHBoxLayout();
        phoneLayout->setObjectName(QStringLiteral("phoneLayout"));
        phoneLabel = new QLabel(groupBox);
        phoneLabel->setObjectName(QStringLiteral("phoneLabel"));

        phoneLayout->addWidget(phoneLabel);

        phone = new QLineEdit(groupBox);
        phone->setObjectName(QStringLiteral("phone"));

        phoneLayout->addWidget(phone);


        verticalLayout_2->addLayout(phoneLayout);


        verticalLayout_3->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        prevPushButton = new QPushButton(OsagoBlankDataForm);
        prevPushButton->setObjectName(QStringLiteral("prevPushButton"));

        horizontalLayout->addWidget(prevPushButton);

        horizontalSpacer = new QSpacerItem(198, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        nextButton = new QPushButton(OsagoBlankDataForm);
        nextButton->setObjectName(QStringLiteral("nextButton"));

        horizontalLayout->addWidget(nextButton);


        verticalLayout_3->addLayout(horizontalLayout);


        horizontalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(OsagoBlankDataForm);

        QMetaObject::connectSlotsByName(OsagoBlankDataForm);
    } // setupUi

    void retranslateUi(QDialog *OsagoBlankDataForm)
    {
        OsagoBlankDataForm->setWindowTitle(QApplication::translate("OsagoBlankDataForm", "\320\241\320\262\320\265\320\264\320\265\320\275\320\270\321\217 \320\276 \321\201\320\276\320\261\321\201\321\202\320\262\320\265\320\275\320\275\320\270\320\272\320\265 \320\242\320\241", 0));
        groupBox->setTitle(QApplication::translate("OsagoBlankDataForm", "\320\241\321\202\321\200\320\260\321\205\320\276\320\262\320\260\321\202\320\265\320\273\321\214", 0));
        insurancerIsOwner->setText(QApplication::translate("OsagoBlankDataForm", "\320\257\320\262\320\273\321\217\320\265\321\202\321\201\321\217 \321\201\320\276\320\261\321\201\321\202\320\262\320\265\320\275\320\275\320\270\320\272\320\276\320\274", 0));
        dateInnLabel->setText(QApplication::translate("OsagoBlankDataForm", "\320\224\320\260\321\202\320\260 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217 \320\263\321\200\320\260\320\266\320\264\320\260\320\275\320\270\320\275\320\260/\n"
"\320\230\320\235\320\235 \321\216\321\200\320\270\320\264\320\270\321\207\320\265\321\201\320\272\320\276\320\263\320\276 \320\273\320\270\321\206\320\260", 0));
        insurancerNameLabel->setText(QApplication::translate("OsagoBlankDataForm", "\320\237\320\276\320\275\320\276\320\265 \320\275\320\260\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\320\265 \321\216\321\200\320\270\320\264\320\270\321\207\320\265\321\201\320\272\320\276\320\263\320\276 \320\273\320\270\321\206\320\260/\n"
"\320\244\320\260\320\274\320\270\320\273\320\270\321\217, \320\270\320\274\321\217 \320\276\321\202\321\207\320\265\321\201\321\202\320\262\320\276 \320\263\321\200\320\260\320\266\320\264\320\260\320\275\320\270\320\275\320\260", 0));
        checkBox->setText(QApplication::translate("OsagoBlankDataForm", "\320\256\321\200\320\270\320\264\320\270\321\207\320\265\321\201\320\272\320\276\320\265 \320\273\320\270\321\206\320\276", 0));
        groupBox_2->setTitle(QApplication::translate("OsagoBlankDataForm", "\320\224\320\276\320\272\321\203\320\274\320\265\320\275\321\202, \321\203\320\264\320\276\321\201\321\202\320\276\320\262\320\265\321\200\321\217\321\216\321\211\320\270\320\271 \320\273\320\270\321\207\320\275\320\276\321\201\321\202\321\214", 0));
        label_3->setText(QApplication::translate("OsagoBlankDataForm", "\320\235\320\276\320\274\320\265\321\200", 0));
        label_2->setText(QApplication::translate("OsagoBlankDataForm", "\320\241\320\265\321\200\320\270\321\217", 0));
        label->setText(QApplication::translate("OsagoBlankDataForm", "\320\242\320\270\320\277 \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202\320\260", 0));
        groupBox_3->setTitle(QApplication::translate("OsagoBlankDataForm", "\320\220\320\264\321\200\320\265\321\201", 0));
        label_4->setText(QApplication::translate("OsagoBlankDataForm", "\320\230\320\275\320\264\320\265\320\272\321\201", 0));
        label_5->setText(QApplication::translate("OsagoBlankDataForm", "\320\223\320\276\321\201\321\203\320\264\320\260\321\200\321\201\321\202\320\262\320\276, \321\200\320\265\321\201\320\277\321\203\320\261\320\273\320\270\320\272\320\260, \320\272\321\200\320\260\320\271", 0));
        label_6->setText(QApplication::translate("OsagoBlankDataForm", "\320\240\320\260\320\271\320\276\320\275", 0));
        label_8->setText(QApplication::translate("OsagoBlankDataForm", "\320\243\320\273\320\270\321\206\320\260", 0));
        label_10->setText(QApplication::translate("OsagoBlankDataForm", "\320\232\320\276\321\200\320\277\321\203\321\201", 0));
        label_7->setText(QApplication::translate("OsagoBlankDataForm", "\320\235\320\260\321\201\320\265\320\273\320\265\320\275\320\275\321\213\320\271 \320\277\321\203\320\275\320\272\321\202", 0));
        label_9->setText(QApplication::translate("OsagoBlankDataForm", "\320\224\320\276\320\274", 0));
        label_11->setText(QApplication::translate("OsagoBlankDataForm", "\320\232\320\262\320\260\321\200\321\202\320\270\321\200\320\260", 0));
        phoneLabel->setText(QApplication::translate("OsagoBlankDataForm", "\320\232\320\276\320\275\321\202\320\260\320\272\321\202\320\275\321\213\320\271 \321\202\320\265\320\273\320\265\321\204\320\276\320\275", 0));
        prevPushButton->setText(QApplication::translate("OsagoBlankDataForm", "\320\235\320\260\320\267\320\260\320\264", 0));
        nextButton->setText(QApplication::translate("OsagoBlankDataForm", "\320\224\320\260\320\273\320\265\320\265", 0));
    } // retranslateUi

};

namespace Ui {
    class OsagoBlankDataForm: public Ui_OsagoBlankDataForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OSAGOBLANKDATAFORM_H
