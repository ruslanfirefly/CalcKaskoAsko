/********************************************************************************
** Form generated from reading UI file 'printwebview.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINTWEBVIEW_H
#define UI_PRINTWEBVIEW_H

#include <QtCore/QVariant>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_printWebView
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *printButton;
    QWebView *webView;

    void setupUi(QDialog *printWebView)
    {
        if (printWebView->objectName().isEmpty())
            printWebView->setObjectName(QStringLiteral("printWebView"));
        printWebView->resize(400, 300);
        verticalLayout = new QVBoxLayout(printWebView);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer = new QSpacerItem(258, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        printButton = new QPushButton(printWebView);
        printButton->setObjectName(QStringLiteral("printButton"));

        gridLayout->addWidget(printButton, 0, 1, 1, 1);

        webView = new QWebView(printWebView);
        webView->setObjectName(QStringLiteral("webView"));
        webView->setUrl(QUrl(QStringLiteral("about:blank")));

        gridLayout->addWidget(webView, 1, 0, 1, 2);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(printWebView);

        QMetaObject::connectSlotsByName(printWebView);
    } // setupUi

    void retranslateUi(QDialog *printWebView)
    {
        printWebView->setWindowTitle(QApplication::translate("printWebView", "Dialog", 0));
        printButton->setText(QApplication::translate("printWebView", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class printWebView: public Ui_printWebView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINTWEBVIEW_H
