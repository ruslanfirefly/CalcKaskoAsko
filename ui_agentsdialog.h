/********************************************************************************
** Form generated from reading UI file 'agentsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGENTSDIALOG_H
#define UI_AGENTSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_agentsDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *addAgentButton;
    QPushButton *delAgentButton;
    QSpacerItem *verticalSpacer;
    QTableView *agentsTable;

    void setupUi(QDialog *agentsDialog)
    {
        if (agentsDialog->objectName().isEmpty())
            agentsDialog->setObjectName(QStringLiteral("agentsDialog"));
        agentsDialog->resize(678, 342);
        horizontalLayout = new QHBoxLayout(agentsDialog);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        addAgentButton = new QPushButton(agentsDialog);
        addAgentButton->setObjectName(QStringLiteral("addAgentButton"));

        verticalLayout->addWidget(addAgentButton);

        delAgentButton = new QPushButton(agentsDialog);
        delAgentButton->setObjectName(QStringLiteral("delAgentButton"));

        verticalLayout->addWidget(delAgentButton);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 138, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);

        agentsTable = new QTableView(agentsDialog);
        agentsTable->setObjectName(QStringLiteral("agentsTable"));

        gridLayout->addWidget(agentsTable, 0, 0, 2, 1);


        horizontalLayout->addLayout(gridLayout);


        retranslateUi(agentsDialog);

        QMetaObject::connectSlotsByName(agentsDialog);
    } // setupUi

    void retranslateUi(QDialog *agentsDialog)
    {
        agentsDialog->setWindowTitle(QApplication::translate("agentsDialog", "Dialog", 0));
        addAgentButton->setText(QApplication::translate("agentsDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0));
        delAgentButton->setText(QApplication::translate("agentsDialog", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class agentsDialog: public Ui_agentsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGENTSDIALOG_H
