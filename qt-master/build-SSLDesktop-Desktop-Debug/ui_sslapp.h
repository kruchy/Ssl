/********************************************************************************
** Form generated from reading UI file 'sslapp.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SSLAPP_H
#define UI_SSLAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SslApp
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *hostsConnectedLabel;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *logTextEdit;
    QVBoxLayout *verticalLayout;
    QPushButton *startBrodcastButton;
    QPushButton *pressCountButton;
    QPushButton *closeConnectionButton;
    QSpacerItem *verticalSpacer;
    QPushButton *pairButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SslApp)
    {
        if (SslApp->objectName().isEmpty())
            SslApp->setObjectName(QStringLiteral("SslApp"));
        SslApp->resize(434, 300);
        centralwidget = new QWidget(SslApp);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        hostsConnectedLabel = new QLabel(centralwidget);
        hostsConnectedLabel->setObjectName(QStringLiteral("hostsConnectedLabel"));
        hostsConnectedLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(hostsConnectedLabel);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        logTextEdit = new QPlainTextEdit(centralwidget);
        logTextEdit->setObjectName(QStringLiteral("logTextEdit"));
        logTextEdit->setReadOnly(true);

        horizontalLayout->addWidget(logTextEdit);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        startBrodcastButton = new QPushButton(centralwidget);
        startBrodcastButton->setObjectName(QStringLiteral("startBrodcastButton"));

        verticalLayout->addWidget(startBrodcastButton);

        pressCountButton = new QPushButton(centralwidget);
        pressCountButton->setObjectName(QStringLiteral("pressCountButton"));

        verticalLayout->addWidget(pressCountButton);

        closeConnectionButton = new QPushButton(centralwidget);
        closeConnectionButton->setObjectName(QStringLiteral("closeConnectionButton"));

        verticalLayout->addWidget(closeConnectionButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        pairButton = new QPushButton(centralwidget);
        pairButton->setObjectName(QStringLiteral("pairButton"));

        verticalLayout_2->addWidget(pairButton);


        verticalLayout_3->addLayout(verticalLayout_2);


        horizontalLayout_2->addLayout(verticalLayout_3);

        SslApp->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SslApp);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 434, 27));
        SslApp->setMenuBar(menubar);
        statusbar = new QStatusBar(SslApp);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        SslApp->setStatusBar(statusbar);

        retranslateUi(SslApp);

        QMetaObject::connectSlotsByName(SslApp);
    } // setupUi

    void retranslateUi(QMainWindow *SslApp)
    {
        SslApp->setWindowTitle(QApplication::translate("SslApp", "MainWindow", 0));
        hostsConnectedLabel->setText(QApplication::translate("SslApp", "NO HOST CONNECTED", 0));
        startBrodcastButton->setText(QApplication::translate("SslApp", "broadcast msg", 0));
        pressCountButton->setText(QApplication::translate("SslApp", "send press count", 0));
        closeConnectionButton->setText(QApplication::translate("SslApp", "close connection", 0));
        pairButton->setText(QApplication::translate("SslApp", "pairButton", 0));
    } // retranslateUi

};

namespace Ui {
    class SslApp: public Ui_SslApp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SSLAPP_H
