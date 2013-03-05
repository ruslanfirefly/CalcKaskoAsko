/********************************************************************************
** Form generated from reading UI file 'osagousinginfoform.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OSAGOUSINGINFOFORM_H
#define UI_OSAGOUSINGINFOFORM_H

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

class Ui_OsagoUsingInfoForm
{
public:
    QVBoxLayout *verticalLayout_6;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_4;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_2;
    QRadioButton *unlimDriversButton;
    QRadioButton *constDriversButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *showDriverButton;
    QPushButton *hideDriverButton;
    QSpacerItem *horizontalSpacer;
    QGridLayout *driversGridLayout;
    QComboBox *comboBox_6;
    QLineEdit *lineEdit_13;
    QDateEdit *dateEdit_2;
    QComboBox *comboBox_7;
    QLineEdit *lineEdit_10;
    QLabel *label_7;
    QLineEdit *lineEdit_15;
    QLineEdit *lineEdit_8;
    QComboBox *comboBox_8;
    QLabel *label_11;
    QComboBox *comboBox_5;
    QLabel *label_6;
    QComboBox *comboBox_4;
    QLabel *label_9;
    QComboBox *comboBox_2;
    QDateEdit *dateEdit_4;
    QComboBox *comboBox;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_12;
    QLabel *label_8;
    QLineEdit *lineEdit_14;
    QDateEdit *dateEdit_6;
    QLineEdit *lineEdit_11;
    QDateEdit *dateEdit_8;
    QLabel *label_10;
    QComboBox *comboBox_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_16;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QSpinBox *spinBox_4;
    QLabel *label_24;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_22;
    QDateEdit *fromInsDate;
    QLabel *label_23;
    QDateEdit *toInsDate;
    QCheckBox *compareWithUsing;
    QGroupBox *usingPeriodsGroupBox;
    QHBoxLayout *horizontalLayout_5;
    QGridLayout *timeGridLayout;
    QSpacerItem *horizontalSpacer_2;
    QDateEdit *dateEdit;
    QDateEdit *dateEdit_12;
    QLabel *label_5;
    QDateEdit *dateEdit_14;
    QLabel *label_4;
    QLabel *label_13;
    QLabel *label_12;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *addTimeButton;
    QPushButton *delTimeButton;
    QLabel *label;
    QDateEdit *dateEdit_10;
    QDateEdit *dateEdit_16;
    QLabel *label_3;
    QLabel *label_14;
    QDateEdit *dateEdit_15;
    QDateEdit *dateEdit_13;
    QDateEdit *dateEdit_11;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout;
    QGridLayout *lastOsagoGridLayout;
    QLineEdit *lastOsagoSerial;
    QLabel *label_17;
    QLineEdit *lastOsagoNum;
    QLabel *label_15;
    QLabel *label_16;
    QCheckBox *lastOsagoContractCheckBox;
    QLineEdit *lastOsagoCompany;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_4;
    QLineEdit *notesLineEdit;
    QLabel *label_19;
    QLabel *label_18;
    QLineEdit *otherInfoLineEdit;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_25;
    QComboBox *agentsComboBox;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *prevButton;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *printRequest;
    QPushButton *printBlank;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_20;
    QLineEdit *polisSerialLineEdit;
    QLabel *label_21;
    QLineEdit *polisNumLineEdit;

    void setupUi(QDialog *OsagoUsingInfoForm)
    {
        if (OsagoUsingInfoForm->objectName().isEmpty())
            OsagoUsingInfoForm->setObjectName(QStringLiteral("OsagoUsingInfoForm"));
        OsagoUsingInfoForm->resize(823, 777);
        verticalLayout_6 = new QVBoxLayout(OsagoUsingInfoForm);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox_2 = new QGroupBox(OsagoUsingInfoForm);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        unlimDriversButton = new QRadioButton(groupBox_2);
        unlimDriversButton->setObjectName(QStringLiteral("unlimDriversButton"));

        gridLayout_2->addWidget(unlimDriversButton, 0, 0, 1, 2);

        constDriversButton = new QRadioButton(groupBox_2);
        constDriversButton->setObjectName(QStringLiteral("constDriversButton"));

        gridLayout_2->addWidget(constDriversButton, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        showDriverButton = new QPushButton(groupBox_2);
        showDriverButton->setObjectName(QStringLiteral("showDriverButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(showDriverButton->sizePolicy().hasHeightForWidth());
        showDriverButton->setSizePolicy(sizePolicy);
        showDriverButton->setMinimumSize(QSize(31, 27));
        showDriverButton->setMaximumSize(QSize(31, 27));

        horizontalLayout->addWidget(showDriverButton);

        hideDriverButton = new QPushButton(groupBox_2);
        hideDriverButton->setObjectName(QStringLiteral("hideDriverButton"));
        sizePolicy.setHeightForWidth(hideDriverButton->sizePolicy().hasHeightForWidth());
        hideDriverButton->setSizePolicy(sizePolicy);
        hideDriverButton->setMinimumSize(QSize(31, 27));
        hideDriverButton->setMaximumSize(QSize(31, 27));

        horizontalLayout->addWidget(hideDriverButton);


        gridLayout_2->addLayout(horizontalLayout, 1, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_2, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer, 0, 1, 1, 1);

        driversGridLayout = new QGridLayout();
        driversGridLayout->setObjectName(QStringLiteral("driversGridLayout"));
        comboBox_6 = new QComboBox(groupBox_2);
        comboBox_6->setObjectName(QStringLiteral("comboBox_6"));

        driversGridLayout->addWidget(comboBox_6, 2, 2, 1, 1);

        lineEdit_13 = new QLineEdit(groupBox_2);
        lineEdit_13->setObjectName(QStringLiteral("lineEdit_13"));

        driversGridLayout->addWidget(lineEdit_13, 3, 3, 1, 1);

        dateEdit_2 = new QDateEdit(groupBox_2);
        dateEdit_2->setObjectName(QStringLiteral("dateEdit_2"));

        driversGridLayout->addWidget(dateEdit_2, 1, 1, 1, 1);

        comboBox_7 = new QComboBox(groupBox_2);
        comboBox_7->setObjectName(QStringLiteral("comboBox_7"));

        driversGridLayout->addWidget(comboBox_7, 3, 2, 1, 1);

        lineEdit_10 = new QLineEdit(groupBox_2);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));

        driversGridLayout->addWidget(lineEdit_10, 2, 0, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        driversGridLayout->addWidget(label_7, 0, 4, 1, 1);

        lineEdit_15 = new QLineEdit(groupBox_2);
        lineEdit_15->setObjectName(QStringLiteral("lineEdit_15"));

        driversGridLayout->addWidget(lineEdit_15, 4, 3, 1, 1);

        lineEdit_8 = new QLineEdit(groupBox_2);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setMinimumSize(QSize(136, 0));

        driversGridLayout->addWidget(lineEdit_8, 1, 0, 1, 1);

        comboBox_8 = new QComboBox(groupBox_2);
        comboBox_8->setObjectName(QStringLiteral("comboBox_8"));

        driversGridLayout->addWidget(comboBox_8, 4, 2, 1, 1);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));

        driversGridLayout->addWidget(label_11, 0, 0, 1, 1);

        comboBox_5 = new QComboBox(groupBox_2);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));

        driversGridLayout->addWidget(comboBox_5, 4, 5, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        driversGridLayout->addWidget(label_6, 0, 5, 1, 1);

        comboBox_4 = new QComboBox(groupBox_2);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));

        driversGridLayout->addWidget(comboBox_4, 1, 2, 1, 1);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        driversGridLayout->addWidget(label_9, 0, 1, 1, 1);

        comboBox_2 = new QComboBox(groupBox_2);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        driversGridLayout->addWidget(comboBox_2, 2, 5, 1, 1);

        dateEdit_4 = new QDateEdit(groupBox_2);
        dateEdit_4->setObjectName(QStringLiteral("dateEdit_4"));

        driversGridLayout->addWidget(dateEdit_4, 2, 1, 1, 1);

        comboBox = new QComboBox(groupBox_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        driversGridLayout->addWidget(comboBox, 1, 5, 1, 1);

        lineEdit_9 = new QLineEdit(groupBox_2);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));

        driversGridLayout->addWidget(lineEdit_9, 1, 3, 1, 1);

        lineEdit_12 = new QLineEdit(groupBox_2);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));

        driversGridLayout->addWidget(lineEdit_12, 3, 0, 1, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        driversGridLayout->addWidget(label_8, 0, 2, 1, 1);

        lineEdit_14 = new QLineEdit(groupBox_2);
        lineEdit_14->setObjectName(QStringLiteral("lineEdit_14"));

        driversGridLayout->addWidget(lineEdit_14, 4, 0, 1, 1);

        dateEdit_6 = new QDateEdit(groupBox_2);
        dateEdit_6->setObjectName(QStringLiteral("dateEdit_6"));

        driversGridLayout->addWidget(dateEdit_6, 3, 1, 1, 1);

        lineEdit_11 = new QLineEdit(groupBox_2);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));

        driversGridLayout->addWidget(lineEdit_11, 2, 3, 1, 1);

        dateEdit_8 = new QDateEdit(groupBox_2);
        dateEdit_8->setObjectName(QStringLiteral("dateEdit_8"));

        driversGridLayout->addWidget(dateEdit_8, 4, 1, 1, 1);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        driversGridLayout->addWidget(label_10, 0, 3, 1, 1);

        comboBox_3 = new QComboBox(groupBox_2);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));

        driversGridLayout->addWidget(comboBox_3, 3, 5, 1, 1);

        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        driversGridLayout->addWidget(lineEdit, 1, 4, 1, 1);

        lineEdit_2 = new QLineEdit(groupBox_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        driversGridLayout->addWidget(lineEdit_2, 2, 4, 1, 1);

        lineEdit_3 = new QLineEdit(groupBox_2);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        driversGridLayout->addWidget(lineEdit_3, 3, 4, 1, 1);

        lineEdit_16 = new QLineEdit(groupBox_2);
        lineEdit_16->setObjectName(QStringLiteral("lineEdit_16"));

        driversGridLayout->addWidget(lineEdit_16, 4, 4, 1, 1);

        spinBox = new QSpinBox(groupBox_2);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        driversGridLayout->addWidget(spinBox, 1, 6, 1, 1);

        spinBox_2 = new QSpinBox(groupBox_2);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));

        driversGridLayout->addWidget(spinBox_2, 2, 6, 1, 1);

        spinBox_3 = new QSpinBox(groupBox_2);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));

        driversGridLayout->addWidget(spinBox_3, 3, 6, 1, 1);

        spinBox_4 = new QSpinBox(groupBox_2);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));

        driversGridLayout->addWidget(spinBox_4, 4, 6, 1, 1);

        label_24 = new QLabel(groupBox_2);
        label_24->setObjectName(QStringLiteral("label_24"));
        QFont font;
        font.setPointSize(6);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label_24->setFont(font);

        driversGridLayout->addWidget(label_24, 0, 6, 1, 1);

        driversGridLayout->setRowStretch(1, 1);

        gridLayout_5->addLayout(driversGridLayout, 1, 0, 1, 2);


        horizontalLayout_4->addLayout(gridLayout_5);


        gridLayout->addWidget(groupBox_2, 0, 0, 1, 3);

        groupBox_5 = new QGroupBox(OsagoUsingInfoForm);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        verticalLayout_5 = new QVBoxLayout(groupBox_5);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_22 = new QLabel(groupBox_5);
        label_22->setObjectName(QStringLiteral("label_22"));

        horizontalLayout_9->addWidget(label_22);

        fromInsDate = new QDateEdit(groupBox_5);
        fromInsDate->setObjectName(QStringLiteral("fromInsDate"));

        horizontalLayout_9->addWidget(fromInsDate);

        label_23 = new QLabel(groupBox_5);
        label_23->setObjectName(QStringLiteral("label_23"));

        horizontalLayout_9->addWidget(label_23);

        toInsDate = new QDateEdit(groupBox_5);
        toInsDate->setObjectName(QStringLiteral("toInsDate"));

        horizontalLayout_9->addWidget(toInsDate);


        verticalLayout_4->addLayout(horizontalLayout_9);

        compareWithUsing = new QCheckBox(groupBox_5);
        compareWithUsing->setObjectName(QStringLiteral("compareWithUsing"));

        verticalLayout_4->addWidget(compareWithUsing);


        verticalLayout_5->addLayout(verticalLayout_4);


        gridLayout->addWidget(groupBox_5, 1, 0, 1, 2);

        usingPeriodsGroupBox = new QGroupBox(OsagoUsingInfoForm);
        usingPeriodsGroupBox->setObjectName(QStringLiteral("usingPeriodsGroupBox"));
        horizontalLayout_5 = new QHBoxLayout(usingPeriodsGroupBox);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        timeGridLayout = new QGridLayout();
        timeGridLayout->setObjectName(QStringLiteral("timeGridLayout"));
        horizontalSpacer_2 = new QSpacerItem(158, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        timeGridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 3);

        dateEdit = new QDateEdit(usingPeriodsGroupBox);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        timeGridLayout->addWidget(dateEdit, 1, 1, 1, 2);

        dateEdit_12 = new QDateEdit(usingPeriodsGroupBox);
        dateEdit_12->setObjectName(QStringLiteral("dateEdit_12"));

        timeGridLayout->addWidget(dateEdit_12, 2, 1, 1, 2);

        label_5 = new QLabel(usingPeriodsGroupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        timeGridLayout->addWidget(label_5, 3, 0, 1, 1);

        dateEdit_14 = new QDateEdit(usingPeriodsGroupBox);
        dateEdit_14->setObjectName(QStringLiteral("dateEdit_14"));

        timeGridLayout->addWidget(dateEdit_14, 3, 1, 1, 2);

        label_4 = new QLabel(usingPeriodsGroupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        timeGridLayout->addWidget(label_4, 2, 3, 1, 1);

        label_13 = new QLabel(usingPeriodsGroupBox);
        label_13->setObjectName(QStringLiteral("label_13"));

        timeGridLayout->addWidget(label_13, 4, 0, 1, 1);

        label_12 = new QLabel(usingPeriodsGroupBox);
        label_12->setObjectName(QStringLiteral("label_12"));

        timeGridLayout->addWidget(label_12, 3, 3, 1, 1);

        label_2 = new QLabel(usingPeriodsGroupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        timeGridLayout->addWidget(label_2, 1, 3, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        addTimeButton = new QPushButton(usingPeriodsGroupBox);
        addTimeButton->setObjectName(QStringLiteral("addTimeButton"));
        sizePolicy.setHeightForWidth(addTimeButton->sizePolicy().hasHeightForWidth());
        addTimeButton->setSizePolicy(sizePolicy);
        addTimeButton->setMinimumSize(QSize(31, 27));
        addTimeButton->setMaximumSize(QSize(31, 27));

        horizontalLayout_2->addWidget(addTimeButton);

        delTimeButton = new QPushButton(usingPeriodsGroupBox);
        delTimeButton->setObjectName(QStringLiteral("delTimeButton"));
        sizePolicy.setHeightForWidth(delTimeButton->sizePolicy().hasHeightForWidth());
        delTimeButton->setSizePolicy(sizePolicy);
        delTimeButton->setMinimumSize(QSize(31, 27));
        delTimeButton->setMaximumSize(QSize(31, 27));

        horizontalLayout_2->addWidget(delTimeButton);


        timeGridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 2);

        label = new QLabel(usingPeriodsGroupBox);
        label->setObjectName(QStringLiteral("label"));

        timeGridLayout->addWidget(label, 1, 0, 1, 1);

        dateEdit_10 = new QDateEdit(usingPeriodsGroupBox);
        dateEdit_10->setObjectName(QStringLiteral("dateEdit_10"));

        timeGridLayout->addWidget(dateEdit_10, 1, 4, 1, 1);

        dateEdit_16 = new QDateEdit(usingPeriodsGroupBox);
        dateEdit_16->setObjectName(QStringLiteral("dateEdit_16"));

        timeGridLayout->addWidget(dateEdit_16, 4, 1, 1, 2);

        label_3 = new QLabel(usingPeriodsGroupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        timeGridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_14 = new QLabel(usingPeriodsGroupBox);
        label_14->setObjectName(QStringLiteral("label_14"));

        timeGridLayout->addWidget(label_14, 4, 3, 1, 1);

        dateEdit_15 = new QDateEdit(usingPeriodsGroupBox);
        dateEdit_15->setObjectName(QStringLiteral("dateEdit_15"));

        timeGridLayout->addWidget(dateEdit_15, 4, 4, 1, 1);

        dateEdit_13 = new QDateEdit(usingPeriodsGroupBox);
        dateEdit_13->setObjectName(QStringLiteral("dateEdit_13"));

        timeGridLayout->addWidget(dateEdit_13, 3, 4, 1, 1);

        dateEdit_11 = new QDateEdit(usingPeriodsGroupBox);
        dateEdit_11->setObjectName(QStringLiteral("dateEdit_11"));

        timeGridLayout->addWidget(dateEdit_11, 2, 4, 1, 1);


        horizontalLayout_5->addLayout(timeGridLayout);


        gridLayout->addWidget(usingPeriodsGroupBox, 2, 0, 1, 1);

        groupBox_3 = new QGroupBox(OsagoUsingInfoForm);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout = new QVBoxLayout(groupBox_3);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lastOsagoGridLayout = new QGridLayout();
        lastOsagoGridLayout->setObjectName(QStringLiteral("lastOsagoGridLayout"));
        lastOsagoSerial = new QLineEdit(groupBox_3);
        lastOsagoSerial->setObjectName(QStringLiteral("lastOsagoSerial"));

        lastOsagoGridLayout->addWidget(lastOsagoSerial, 1, 1, 1, 1);

        label_17 = new QLabel(groupBox_3);
        label_17->setObjectName(QStringLiteral("label_17"));

        lastOsagoGridLayout->addWidget(label_17, 3, 0, 1, 1);

        lastOsagoNum = new QLineEdit(groupBox_3);
        lastOsagoNum->setObjectName(QStringLiteral("lastOsagoNum"));

        lastOsagoGridLayout->addWidget(lastOsagoNum, 2, 1, 1, 1);

        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QStringLiteral("label_15"));

        lastOsagoGridLayout->addWidget(label_15, 1, 0, 1, 1);

        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QStringLiteral("label_16"));

        lastOsagoGridLayout->addWidget(label_16, 2, 0, 1, 1);

        lastOsagoContractCheckBox = new QCheckBox(groupBox_3);
        lastOsagoContractCheckBox->setObjectName(QStringLiteral("lastOsagoContractCheckBox"));

        lastOsagoGridLayout->addWidget(lastOsagoContractCheckBox, 0, 0, 1, 2);

        lastOsagoCompany = new QLineEdit(groupBox_3);
        lastOsagoCompany->setObjectName(QStringLiteral("lastOsagoCompany"));

        lastOsagoGridLayout->addWidget(lastOsagoCompany, 3, 1, 1, 1);


        verticalLayout->addLayout(lastOsagoGridLayout);


        gridLayout->addWidget(groupBox_3, 2, 1, 1, 2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        notesLineEdit = new QLineEdit(OsagoUsingInfoForm);
        notesLineEdit->setObjectName(QStringLiteral("notesLineEdit"));

        gridLayout_4->addWidget(notesLineEdit, 1, 1, 1, 1);

        label_19 = new QLabel(OsagoUsingInfoForm);
        label_19->setObjectName(QStringLiteral("label_19"));

        gridLayout_4->addWidget(label_19, 1, 0, 1, 1);

        label_18 = new QLabel(OsagoUsingInfoForm);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_4->addWidget(label_18, 0, 0, 1, 1);

        otherInfoLineEdit = new QLineEdit(OsagoUsingInfoForm);
        otherInfoLineEdit->setObjectName(QStringLiteral("otherInfoLineEdit"));

        gridLayout_4->addWidget(otherInfoLineEdit, 0, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_4);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_25 = new QLabel(OsagoUsingInfoForm);
        label_25->setObjectName(QStringLiteral("label_25"));

        horizontalLayout_10->addWidget(label_25);

        agentsComboBox = new QComboBox(OsagoUsingInfoForm);
        agentsComboBox->setObjectName(QStringLiteral("agentsComboBox"));

        horizontalLayout_10->addWidget(agentsComboBox);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));

        verticalLayout_2->addLayout(horizontalLayout_7);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        prevButton = new QPushButton(OsagoUsingInfoForm);
        prevButton->setObjectName(QStringLiteral("prevButton"));

        horizontalLayout_8->addWidget(prevButton);

        horizontalSpacer_4 = new QSpacerItem(428, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);

        printRequest = new QPushButton(OsagoUsingInfoForm);
        printRequest->setObjectName(QStringLiteral("printRequest"));

        horizontalLayout_8->addWidget(printRequest);

        printBlank = new QPushButton(OsagoUsingInfoForm);
        printBlank->setObjectName(QStringLiteral("printBlank"));

        horizontalLayout_8->addWidget(printBlank);


        verticalLayout_3->addLayout(horizontalLayout_8);


        gridLayout->addLayout(verticalLayout_3, 3, 0, 1, 3);

        groupBox_4 = new QGroupBox(OsagoUsingInfoForm);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        horizontalLayout_6 = new QHBoxLayout(groupBox_4);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_20 = new QLabel(groupBox_4);
        label_20->setObjectName(QStringLiteral("label_20"));

        horizontalLayout_3->addWidget(label_20);

        polisSerialLineEdit = new QLineEdit(groupBox_4);
        polisSerialLineEdit->setObjectName(QStringLiteral("polisSerialLineEdit"));

        horizontalLayout_3->addWidget(polisSerialLineEdit);

        label_21 = new QLabel(groupBox_4);
        label_21->setObjectName(QStringLiteral("label_21"));

        horizontalLayout_3->addWidget(label_21);

        polisNumLineEdit = new QLineEdit(groupBox_4);
        polisNumLineEdit->setObjectName(QStringLiteral("polisNumLineEdit"));

        horizontalLayout_3->addWidget(polisNumLineEdit);


        horizontalLayout_6->addLayout(horizontalLayout_3);


        gridLayout->addWidget(groupBox_4, 1, 2, 1, 1);


        verticalLayout_6->addLayout(gridLayout);

        label_25->raise();
        agentsComboBox->raise();

        retranslateUi(OsagoUsingInfoForm);

        QMetaObject::connectSlotsByName(OsagoUsingInfoForm);
    } // setupUi

    void retranslateUi(QDialog *OsagoUsingInfoForm)
    {
        OsagoUsingInfoForm->setWindowTitle(QApplication::translate("OsagoUsingInfoForm", "Dialog", 0));
        groupBox_2->setTitle(QApplication::translate("OsagoUsingInfoForm", "\320\222\320\276\320\264\320\270\321\202\320\265\320\273\320\270, \320\264\320\276\320\277\321\203\321\211\320\265\320\275\320\275\321\213\320\265 \320\264\320\276 \321\203\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\321\217 \320\242\320\241", 0));
        unlimDriversButton->setText(QApplication::translate("OsagoUsingInfoForm", "\320\233\321\216\320\261\321\213\320\265 \320\262\320\276\320\264\320\270\321\202\320\265\320\273\320\270 (\320\261\320\265\320\267 \320\276\320\263\321\200\320\260\320\275\320\270\321\207\320\265\320\275\320\270\320\271)", 0));
        constDriversButton->setText(QApplication::translate("OsagoUsingInfoForm", "\320\242\320\276\320\273\321\214\320\272\320\276 \321\201\320\273\320\265\320\264\321\203\321\216\321\211\320\270\320\265 \320\262\320\276\320\264\320\270\321\202\320\265\320\273\320\270:", 0));
        showDriverButton->setText(QApplication::translate("OsagoUsingInfoForm", "+", 0));
        hideDriverButton->setText(QApplication::translate("OsagoUsingInfoForm", "-", 0));
        comboBox_6->clear();
        comboBox_6->insertItems(0, QStringList()
         << QApplication::translate("OsagoUsingInfoForm", "\320\234", 0)
         << QApplication::translate("OsagoUsingInfoForm", "\320\226", 0)
        );
        comboBox_7->clear();
        comboBox_7->insertItems(0, QStringList()
         << QApplication::translate("OsagoUsingInfoForm", "\320\234", 0)
         << QApplication::translate("OsagoUsingInfoForm", "\320\226", 0)
        );
        label_7->setText(QApplication::translate("OsagoUsingInfoForm", "\320\241\321\202\320\260\320\266", 0));
        comboBox_8->clear();
        comboBox_8->insertItems(0, QStringList()
         << QApplication::translate("OsagoUsingInfoForm", "\320\234", 0)
         << QApplication::translate("OsagoUsingInfoForm", "\320\226", 0)
        );
        label_11->setText(QApplication::translate("OsagoUsingInfoForm", "\320\244\320\230\320\236", 0));
        label_6->setText(QApplication::translate("OsagoUsingInfoForm", "\320\232\320\273\320\260\321\201\321\201", 0));
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("OsagoUsingInfoForm", "\320\234", 0)
         << QApplication::translate("OsagoUsingInfoForm", "\320\226", 0)
        );
        label_9->setText(QApplication::translate("OsagoUsingInfoForm", "\320\224\320\260\321\202\320\260 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217", 0));
        label_8->setText(QApplication::translate("OsagoUsingInfoForm", "\320\237\320\276\320\273", 0));
        label_10->setText(QApplication::translate("OsagoUsingInfoForm", "\320\222\320\276\320\264\320\270\321\202\320\265\320\273\321\214\321\201\320\272\320\276\320\265 \321\203\320\264\320\276\321\201\321\202\320\276\320\262\320\265\321\200\320\265\320\275\320\270\320\265\n"
" (\321\201\320\265\321\200\320\270\321\217, \320\275\320\276\320\274\320\265\321\200)", 0));
        label_24->setText(QApplication::translate("OsagoUsingInfoForm", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\201\321\202\321\200\320\260\321\205\320\276\320\262\321\213\321\205 \321\201\320\273\321\203\321\207\320\260\320\265\320\262\n"
" \320\262 \321\202\320\265\321\207\320\265\320\275\320\270\320\265 \321\201\321\200\320\276\320\272\320\260 \320\264\320\265\320\271\321\201\321\202\320\262\320\270\321\217\n"
" \320\277\321\200\320\265\320\264\321\213\320\264\321\203\321\211\320\265\320\263\320\276 \320\264\320\276\320\263\320\276\320\262\320\276\321\200\320\260\n"
" \320\276\320\261\321\217\320\267\320\260\321\202\320\265\320\273\321\214\320\275\320\276\320\263\320\276\n"
" \321\201\321\202\321\200\320\260\321\205\320\276\320\262\320\260\320\275\320\270\321\217", 0));
        groupBox_5->setTitle(QApplication::translate("OsagoUsingInfoForm", "\320\237\320\265\321\200\320\270\320\276\320\264 \321\201\321\202\321\200\320\260\321\205\320\276\320\262\320\260\320\275\320\270\321\217", 0));
        label_22->setText(QApplication::translate("OsagoUsingInfoForm", "\320\241", 0));
        label_23->setText(QApplication::translate("OsagoUsingInfoForm", "\320\237\320\276", 0));
        compareWithUsing->setText(QApplication::translate("OsagoUsingInfoForm", "\320\241\320\276\320\262\320\277\320\260\320\264\320\260\320\265\321\202 \321\201 \320\277\320\265\321\200\320\270\320\276\320\264\320\276\320\274 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\320\275\320\270\321\217", 0));
        usingPeriodsGroupBox->setTitle(QApplication::translate("OsagoUsingInfoForm", "\320\237\320\265\321\200\320\270\320\276\320\264 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\320\275\320\270\321\217 \320\242\320\241", 0));
        label_5->setText(QApplication::translate("OsagoUsingInfoForm", "\320\241", 0));
        label_4->setText(QApplication::translate("OsagoUsingInfoForm", "\320\237\320\276", 0));
        label_13->setText(QApplication::translate("OsagoUsingInfoForm", "\320\241", 0));
        label_12->setText(QApplication::translate("OsagoUsingInfoForm", "\320\237\320\276", 0));
        label_2->setText(QApplication::translate("OsagoUsingInfoForm", "\320\237\320\276", 0));
        addTimeButton->setText(QApplication::translate("OsagoUsingInfoForm", "+", 0));
        delTimeButton->setText(QApplication::translate("OsagoUsingInfoForm", "-", 0));
        label->setText(QApplication::translate("OsagoUsingInfoForm", "\320\241", 0));
        label_3->setText(QApplication::translate("OsagoUsingInfoForm", "\320\241", 0));
        label_14->setText(QApplication::translate("OsagoUsingInfoForm", "\320\237\320\276", 0));
        groupBox_3->setTitle(QApplication::translate("OsagoUsingInfoForm", "\320\240\320\260\320\275\320\265\320\265 \320\267\320\260\320\272\320\273\321\216\321\207\320\265\320\275\320\275\321\213\320\265 \320\264\320\276\320\263\320\276\320\262\320\276\321\200\320\260 \320\236\320\241\320\220\320\223\320\236", 0));
        label_17->setText(QApplication::translate("OsagoUsingInfoForm", "\320\241\321\202\321\200\320\260\321\205\320\276\320\262\320\260\321\217\n"
"\320\272\320\276\320\274\320\277\320\260\320\275\320\270\321\217", 0));
        label_15->setText(QApplication::translate("OsagoUsingInfoForm", "\320\241\320\265\321\200\320\270\321\217", 0));
        label_16->setText(QApplication::translate("OsagoUsingInfoForm", "\320\235\320\276\320\274\320\265\321\200", 0));
        lastOsagoContractCheckBox->setText(QApplication::translate("OsagoUsingInfoForm", "\320\222 \320\276\321\202\320\275\320\276\321\210\320\265\320\275\320\270\320\265 \320\264\320\260\320\275\320\275\320\276\320\263\320\276 \320\242\320\241 \321\200\320\260\320\275\320\265\320\265 \n"
"\321\203\320\266\320\265 \320\267\320\260\320\272\320\273\321\216\321\207\320\260\320\273\321\201\321\217 \320\264\320\276\320\263\320\276\320\262\320\276\321\200 \320\236\320\241\320\220\320\223\320\236", 0));
        label_19->setText(QApplication::translate("OsagoUsingInfoForm", "\320\236\321\201\320\276\320\261\321\213\320\265 \320\276\321\202\320\274\320\265\321\202\320\272\320\270", 0));
        label_18->setText(QApplication::translate("OsagoUsingInfoForm", "\320\230\320\275\321\213\320\265 \321\201\320\262\320\265\320\264\320\265\320\275\320\270\321\217", 0));
        label_25->setText(QApplication::translate("OsagoUsingInfoForm", "\320\241\321\202\321\200\320\260\321\205\320\276\320\262\320\276\320\271 \320\260\320\263\320\265\320\275\321\202", 0));
        prevButton->setText(QApplication::translate("OsagoUsingInfoForm", "\320\235\320\260\320\267\320\260\320\264", 0));
        printRequest->setText(QApplication::translate("OsagoUsingInfoForm", "\320\237\320\265\321\207\320\260\321\202\321\214 \320\267\320\260\321\217\320\262\320\273\320\265\320\275\320\270\321\217", 0));
        printBlank->setText(QApplication::translate("OsagoUsingInfoForm", "\320\237\320\265\321\207\320\260\321\202\321\214 \320\261\320\273\320\260\320\275\320\272\320\260", 0));
        groupBox_4->setTitle(QApplication::translate("OsagoUsingInfoForm", "\320\241\321\202\321\200\320\260\321\205\320\276\320\262\320\276\320\271 \320\277\320\276\320\273\320\270\321\201", 0));
        label_20->setText(QApplication::translate("OsagoUsingInfoForm", "\320\241\320\265\321\200\320\270\321\217", 0));
        label_21->setText(QApplication::translate("OsagoUsingInfoForm", "\320\235\320\276\320\274\320\265\321\200", 0));
    } // retranslateUi

};

namespace Ui {
    class OsagoUsingInfoForm: public Ui_OsagoUsingInfoForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OSAGOUSINGINFOFORM_H
