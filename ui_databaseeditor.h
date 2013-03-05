/********************************************************************************
** Form generated from reading UI file 'databaseeditor.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASEEDITOR_H
#define UI_DATABASEEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_dataBaseEditor
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QComboBox *tablesNames;
    QSpacerItem *horizontalSpacer;
    QTableView *tableView;
    QPushButton *addButton;
    QPushButton *delButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *dataBaseEditor)
    {
        if (dataBaseEditor->objectName().isEmpty())
            dataBaseEditor->setObjectName(QStringLiteral("dataBaseEditor"));
        dataBaseEditor->resize(473, 300);
        horizontalLayout = new QHBoxLayout(dataBaseEditor);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tablesNames = new QComboBox(dataBaseEditor);
        tablesNames->setObjectName(QStringLiteral("tablesNames"));

        gridLayout->addWidget(tablesNames, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        tableView = new QTableView(dataBaseEditor);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout->addWidget(tableView, 1, 0, 3, 1);

        addButton = new QPushButton(dataBaseEditor);
        addButton->setObjectName(QStringLiteral("addButton"));

        gridLayout->addWidget(addButton, 1, 1, 1, 1);

        delButton = new QPushButton(dataBaseEditor);
        delButton->setObjectName(QStringLiteral("delButton"));

        gridLayout->addWidget(delButton, 2, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        retranslateUi(dataBaseEditor);

        QMetaObject::connectSlotsByName(dataBaseEditor);
    } // setupUi

    void retranslateUi(QDialog *dataBaseEditor)
    {
        dataBaseEditor->setWindowTitle(QApplication::translate("dataBaseEditor", "Dialog", 0));
        addButton->setText(QApplication::translate("dataBaseEditor", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0));
        delButton->setText(QApplication::translate("dataBaseEditor", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class dataBaseEditor: public Ui_dataBaseEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASEEDITOR_H
