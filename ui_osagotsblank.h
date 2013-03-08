/********************************************************************************
** Form generated from reading UI file 'osagotsblank.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OSAGOTSBLANK_H
#define UI_OSAGOTSBLANK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_OsagoTsBlank
{
public:
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLineEdit *modelLineEdit;
    QLabel *label_2;
    QLineEdit *vinLineEdit;
    QLabel *label_5;
    QSpinBox *powerSpinBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *kWtRadioButton;
    QRadioButton *hpRadioButton;
    QLabel *countLabel;
    QSpinBox *passengersCountSpinBox;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *yearSpinBox;
    QLabel *massLabel;
    QSpinBox *mass;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *trackLineEdit;
    QLineEdit *shassiLineEdit;
    QComboBox *tsTypeComboBox;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QComboBox *documentTypeComboBox;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout;
    QLabel *label_10;
    QLineEdit *serialLineEdit;
    QLabel *label_11;
    QLineEdit *numLineEdit;
    QLabel *label_12;
    QDateEdit *documentDateEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QLineEdit *gosNumber;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *isRentalCheckBox;
    QLabel *label_14;
    QComboBox *usingTypeComboBox;
    QGridLayout *gridLayout_3;
    QSpinBox *incidentsSpinBox;
    QLabel *label_15;
    QComboBox *classesComboBox;
    QLabel *label_16;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *prevButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *nextButton;

    void setupUi(QDialog *OsagoTsBlank)
    {
        if (OsagoTsBlank->objectName().isEmpty())
            OsagoTsBlank->setObjectName(QStringLiteral("OsagoTsBlank"));
        OsagoTsBlank->resize(780, 522);
        horizontalLayout_6 = new QHBoxLayout(OsagoTsBlank);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(OsagoTsBlank);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        modelLineEdit = new QLineEdit(OsagoTsBlank);
        modelLineEdit->setObjectName(QStringLiteral("modelLineEdit"));
        modelLineEdit->setMinimumSize(QSize(191, 0));

        gridLayout_2->addWidget(modelLineEdit, 0, 1, 1, 2);

        label_2 = new QLabel(OsagoTsBlank);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        vinLineEdit = new QLineEdit(OsagoTsBlank);
        vinLineEdit->setObjectName(QStringLiteral("vinLineEdit"));

        gridLayout_2->addWidget(vinLineEdit, 1, 1, 1, 2);

        label_5 = new QLabel(OsagoTsBlank);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        powerSpinBox = new QSpinBox(OsagoTsBlank);
        powerSpinBox->setObjectName(QStringLiteral("powerSpinBox"));
        powerSpinBox->setMaximum(2000);

        gridLayout_2->addWidget(powerSpinBox, 2, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        kWtRadioButton = new QRadioButton(OsagoTsBlank);
        kWtRadioButton->setObjectName(QStringLiteral("kWtRadioButton"));

        verticalLayout->addWidget(kWtRadioButton);

        hpRadioButton = new QRadioButton(OsagoTsBlank);
        hpRadioButton->setObjectName(QStringLiteral("hpRadioButton"));

        verticalLayout->addWidget(hpRadioButton);


        gridLayout_2->addLayout(verticalLayout, 2, 2, 1, 1);

        countLabel = new QLabel(OsagoTsBlank);
        countLabel->setObjectName(QStringLiteral("countLabel"));

        gridLayout_2->addWidget(countLabel, 3, 0, 1, 1);

        passengersCountSpinBox = new QSpinBox(OsagoTsBlank);
        passengersCountSpinBox->setObjectName(QStringLiteral("passengersCountSpinBox"));
        passengersCountSpinBox->setMaximum(500);
        passengersCountSpinBox->setValue(8);

        gridLayout_2->addWidget(passengersCountSpinBox, 3, 1, 1, 1);


        horizontalLayout_3->addLayout(gridLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(OsagoTsBlank);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        label_4 = new QLabel(OsagoTsBlank);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        yearSpinBox = new QSpinBox(OsagoTsBlank);
        yearSpinBox->setObjectName(QStringLiteral("yearSpinBox"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(yearSpinBox->sizePolicy().hasHeightForWidth());
        yearSpinBox->setSizePolicy(sizePolicy);
        yearSpinBox->setMinimum(1900);
        yearSpinBox->setMaximum(2013);

        gridLayout->addWidget(yearSpinBox, 1, 2, 1, 1);

        massLabel = new QLabel(OsagoTsBlank);
        massLabel->setObjectName(QStringLiteral("massLabel"));

        gridLayout->addWidget(massLabel, 2, 0, 1, 2);

        mass = new QSpinBox(OsagoTsBlank);
        mass->setObjectName(QStringLiteral("mass"));
        mass->setMaximum(10000);
        mass->setValue(3500);

        gridLayout->addWidget(mass, 2, 2, 1, 1);

        label_8 = new QLabel(OsagoTsBlank);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 3, 0, 1, 1);

        label_9 = new QLabel(OsagoTsBlank);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 4, 0, 1, 1);

        trackLineEdit = new QLineEdit(OsagoTsBlank);
        trackLineEdit->setObjectName(QStringLiteral("trackLineEdit"));

        gridLayout->addWidget(trackLineEdit, 4, 1, 1, 2);

        shassiLineEdit = new QLineEdit(OsagoTsBlank);
        shassiLineEdit->setObjectName(QStringLiteral("shassiLineEdit"));
        sizePolicy.setHeightForWidth(shassiLineEdit->sizePolicy().hasHeightForWidth());
        shassiLineEdit->setSizePolicy(sizePolicy);

        gridLayout->addWidget(shassiLineEdit, 3, 1, 1, 2);

        tsTypeComboBox = new QComboBox(OsagoTsBlank);
        tsTypeComboBox->setObjectName(QStringLiteral("tsTypeComboBox"));
        sizePolicy.setHeightForWidth(tsTypeComboBox->sizePolicy().hasHeightForWidth());
        tsTypeComboBox->setSizePolicy(sizePolicy);

        gridLayout->addWidget(tsTypeComboBox, 0, 2, 1, 1);


        horizontalLayout_3->addLayout(gridLayout);


        verticalLayout_2->addLayout(horizontalLayout_3);

        groupBox = new QGroupBox(OsagoTsBlank);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        documentTypeComboBox = new QComboBox(groupBox);
        documentTypeComboBox->setObjectName(QStringLiteral("documentTypeComboBox"));

        gridLayout_4->addWidget(documentTypeComboBox, 2, 1, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_4->addWidget(label_6, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout->addWidget(label_10);

        serialLineEdit = new QLineEdit(groupBox);
        serialLineEdit->setObjectName(QStringLiteral("serialLineEdit"));

        horizontalLayout->addWidget(serialLineEdit);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout->addWidget(label_11);

        numLineEdit = new QLineEdit(groupBox);
        numLineEdit->setObjectName(QStringLiteral("numLineEdit"));

        horizontalLayout->addWidget(numLineEdit);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout->addWidget(label_12);

        documentDateEdit = new QDateEdit(groupBox);
        documentDateEdit->setObjectName(QStringLiteral("documentDateEdit"));
        documentDateEdit->setCalendarPopup(true);

        horizontalLayout->addWidget(documentDateEdit);


        gridLayout_4->addLayout(horizontalLayout, 0, 0, 1, 2);


        verticalLayout_2->addWidget(groupBox);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_7 = new QLabel(OsagoTsBlank);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_2->addWidget(label_7);

        gosNumber = new QLineEdit(OsagoTsBlank);
        gosNumber->setObjectName(QStringLiteral("gosNumber"));

        horizontalLayout_2->addWidget(gosNumber);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        isRentalCheckBox = new QCheckBox(OsagoTsBlank);
        isRentalCheckBox->setObjectName(QStringLiteral("isRentalCheckBox"));

        horizontalLayout_4->addWidget(isRentalCheckBox);

        label_14 = new QLabel(OsagoTsBlank);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_4->addWidget(label_14);

        usingTypeComboBox = new QComboBox(OsagoTsBlank);
        usingTypeComboBox->setObjectName(QStringLiteral("usingTypeComboBox"));
        sizePolicy.setHeightForWidth(usingTypeComboBox->sizePolicy().hasHeightForWidth());
        usingTypeComboBox->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(usingTypeComboBox);


        verticalLayout_3->addLayout(horizontalLayout_4);


        verticalLayout_4->addLayout(verticalLayout_3);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        incidentsSpinBox = new QSpinBox(OsagoTsBlank);
        incidentsSpinBox->setObjectName(QStringLiteral("incidentsSpinBox"));

        gridLayout_3->addWidget(incidentsSpinBox, 1, 1, 1, 1);

        label_15 = new QLabel(OsagoTsBlank);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_3->addWidget(label_15, 0, 0, 1, 1);

        classesComboBox = new QComboBox(OsagoTsBlank);
        classesComboBox->setObjectName(QStringLiteral("classesComboBox"));
        sizePolicy.setHeightForWidth(classesComboBox->sizePolicy().hasHeightForWidth());
        classesComboBox->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(classesComboBox, 0, 1, 1, 1);

        label_16 = new QLabel(OsagoTsBlank);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout_3->addWidget(label_16, 1, 0, 1, 1);


        verticalLayout_4->addLayout(gridLayout_3);


        verticalLayout_5->addLayout(verticalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        prevButton = new QPushButton(OsagoTsBlank);
        prevButton->setObjectName(QStringLiteral("prevButton"));

        horizontalLayout_5->addWidget(prevButton);

        horizontalSpacer = new QSpacerItem(458, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        nextButton = new QPushButton(OsagoTsBlank);
        nextButton->setObjectName(QStringLiteral("nextButton"));

        horizontalLayout_5->addWidget(nextButton);


        verticalLayout_5->addLayout(horizontalLayout_5);


        horizontalLayout_6->addLayout(verticalLayout_5);


        retranslateUi(OsagoTsBlank);

        QMetaObject::connectSlotsByName(OsagoTsBlank);
    } // setupUi

    void retranslateUi(QDialog *OsagoTsBlank)
    {
        OsagoTsBlank->setWindowTitle(QApplication::translate("OsagoTsBlank", "\320\241\320\262\320\265\320\264\320\265\320\275\320\270\321\217 \320\276 \320\242\320\241", 0));
        label->setText(QApplication::translate("OsagoTsBlank", "\320\234\320\260\321\200\320\272\320\260, \320\274\320\276\320\264\320\265\320\273\321\214 \320\242\320\241", 0));
        label_2->setText(QApplication::translate("OsagoTsBlank", "\320\230\320\264\320\265\320\275\321\202\320\270\321\204\320\270\320\272\320\260\321\206\320\270\320\276\320\275\320\275\321\213\320\271 \320\275\320\276\320\274\320\265\321\200", 0));
        label_5->setText(QApplication::translate("OsagoTsBlank", "\320\234\320\276\321\211\320\275\320\276\321\201\321\202\321\214", 0));
        kWtRadioButton->setText(QApplication::translate("OsagoTsBlank", "\320\232\320\222\321\202", 0));
        hpRadioButton->setText(QApplication::translate("OsagoTsBlank", "\320\273.\321\201.", 0));
        countLabel->setText(QApplication::translate("OsagoTsBlank", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\277\320\260\321\201\321\201\320\260\320\266\320\270\321\200\321\201\320\272\320\270\321\205 \n"
"\320\274\320\265\321\201\321\202", 0));
        label_3->setText(QApplication::translate("OsagoTsBlank", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217 \320\242\320\241", 0));
        label_4->setText(QApplication::translate("OsagoTsBlank", "\320\223\320\276\320\264 \320\270\320\267\320\263\320\276\321\202\320\276\320\262\320\273\320\265\320\275\320\270\321\217", 0));
        massLabel->setText(QApplication::translate("OsagoTsBlank", "\320\240\320\260\320\267\321\200\320\265\321\210\320\265\320\275\320\275\320\260\321\217 \320\274\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\260\321\217 \320\274\320\260\321\201\321\201\320\260 (\320\272\320\263)", 0));
        label_8->setText(QApplication::translate("OsagoTsBlank", "\320\250\320\260\321\201\321\201\320\270 (\321\200\320\260\320\274\320\260) \342\204\226", 0));
        label_9->setText(QApplication::translate("OsagoTsBlank", "\320\232\321\203\320\267\320\276\320\262 (\320\277\321\200\320\270\321\206\320\265\320\277) \342\204\226", 0));
        tsTypeComboBox->clear();
        tsTypeComboBox->insertItems(0, QStringList()
         << QApplication::translate("OsagoTsBlank", "A", 0)
         << QApplication::translate("OsagoTsBlank", "B", 0)
         << QApplication::translate("OsagoTsBlank", "C", 0)
         << QApplication::translate("OsagoTsBlank", "D", 0)
         << QApplication::translate("OsagoTsBlank", "E", 0)
        );
        groupBox->setTitle(QApplication::translate("OsagoTsBlank", "\320\224\320\276\320\272\321\203\320\274\320\265\320\275\321\202 \320\276 \321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\320\270 \320\242\320\241", 0));
        documentTypeComboBox->clear();
        documentTypeComboBox->insertItems(0, QStringList()
         << QApplication::translate("OsagoTsBlank", "\320\237\320\260\321\201\320\277\320\276\321\200\321\202 \321\202\321\200\320\260\320\275\321\201\320\277\320\276\321\200\321\202\320\275\320\276\320\263\320\276 \321\201\321\200\320\265\320\264\321\201\321\202\320\262\320\260", 0)
         << QApplication::translate("OsagoTsBlank", "\320\241\320\262\320\270\320\264\320\265\321\202\320\265\320\273\321\214\321\201\321\202\320\262\320\276 \320\276 \321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\320\270", 0)
         << QApplication::translate("OsagoTsBlank", "\320\242\320\265\321\205\320\275\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \320\277\320\260\321\201\320\277\320\276\321\200\321\202", 0)
         << QApplication::translate("OsagoTsBlank", "\320\237\320\260\321\201\320\277\320\276\321\200\321\202 \321\201\320\260\320\274\320\276\321\205\320\276\320\264\320\275\320\276\320\271 \320\274\320\260\321\210\320\270\320\275\321\213", 0)
        );
        label_6->setText(QApplication::translate("OsagoTsBlank", "\320\242\320\270\320\277 \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202\320\260", 0));
        label_10->setText(QApplication::translate("OsagoTsBlank", "\320\241\320\265\321\200\320\270\321\217", 0));
        label_11->setText(QApplication::translate("OsagoTsBlank", "\320\235\320\276\320\274\320\265\321\200", 0));
        label_12->setText(QApplication::translate("OsagoTsBlank", "\320\224\320\260\321\202\320\260 \320\262\321\213\320\264\320\260\321\207\320\270", 0));
        label_7->setText(QApplication::translate("OsagoTsBlank", "\320\223\320\276\321\201\321\203\320\264\320\260\321\200\321\201\321\202\320\262\320\265\320\275\320\275\321\213\320\271 \321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\320\276\320\275\320\275\321\213\320\271 \320\275\320\276\320\274\320\265\321\200", 0));
        isRentalCheckBox->setText(QApplication::translate("OsagoTsBlank", "\320\242\320\241 \321\201\320\264\320\260\320\265\321\202\321\201\321\217 \320\262 \320\260\321\200\320\265\320\275\320\264\321\203", 0));
        label_14->setText(QApplication::translate("OsagoTsBlank", "\320\246\320\265\320\273\321\214 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\320\275\320\270\321\217 \320\242\320\241", 0));
        usingTypeComboBox->clear();
        usingTypeComboBox->insertItems(0, QStringList()
         << QApplication::translate("OsagoTsBlank", "\320\233\320\270\321\207\320\275\320\260\321\217", 0)
         << QApplication::translate("OsagoTsBlank", "\320\243\321\207\320\265\320\261\320\275\320\260\321\217 \320\265\320\267\320\264\320\260", 0)
         << QApplication::translate("OsagoTsBlank", "\320\242\320\260\320\272\321\201\320\270", 0)
         << QApplication::translate("OsagoTsBlank", "\320\224\320\276\321\200\320\276\320\266\320\275\321\213\320\265 \320\270 \321\201\320\277\320\265\321\206\320\270\320\260\320\273\321\214\320\275\321\213\320\265 \320\242\320\241", 0)
         << QApplication::translate("OsagoTsBlank", "\320\237\321\200\320\276\321\207\320\265\320\265", 0)
        );
        label_15->setText(QApplication::translate("OsagoTsBlank", "\320\232\320\273\320\260\321\201\321\201, \320\267\320\260\320\262\320\270\321\201\321\217\321\211\320\270\320\271 \320\276\321\202 \320\275\320\260\320\273\320\270\321\207\320\270\321\217 \321\201\321\202\321\200\320\260\321\205\320\276\320\262\321\213\321\205 \320\262\321\213\320\277\320\273\320\260\321\202,\n"
" \320\277\321\200\320\270\321\201\320\262\320\276\320\265\320\275\320\275\321\213\320\271 \321\201\320\276\320\261\321\201\321\202\320\262\320\265\320\275\320\275\320\270\320\272\321\203", 0));
        label_16->setText(QApplication::translate("OsagoTsBlank", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\201\321\202\321\200\320\260\321\205\320\276\320\262\321\213\321\205 \321\201\320\273\321\203\321\207\320\260\320\265\320\262 \320\277\320\276 \320\277\321\200\320\265\320\264\321\213\320\264\321\203\321\211\320\265\320\274\321\203 \320\264\320\276\320\263\320\276\320\262\320\276\321\200\321\203 \n"
"\320\276\320\261\321\217\320\267\320\260\321\202\320\265\320\273\321\214\320\275\320\276\320\263\320\276 \321\201\321\202\321\200\320\260\321\205\320\276\320\262\320\260\320\275\320\270\321\217 \320\262\320\273\320\260\320\264\320\265\320\273\321\214\321\206\320\265\320\262 \320\264\320\260\320\275\320\275\320\276\320\263\320\276 \320\242\320\241.", 0));
        prevButton->setText(QApplication::translate("OsagoTsBlank", "\320\235\320\260\320\267\320\260\320\264", 0));
        nextButton->setText(QApplication::translate("OsagoTsBlank", "\320\224\320\260\320\273\320\265\320\265", 0));
    } // retranslateUi

};

namespace Ui {
    class OsagoTsBlank: public Ui_OsagoTsBlank {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OSAGOTSBLANK_H
