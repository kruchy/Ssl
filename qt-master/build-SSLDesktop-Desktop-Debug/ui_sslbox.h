/********************************************************************************
** Form generated from reading UI file 'sslbox.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SSLBOX_H
#define UI_SSLBOX_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SslBox
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *hostLabel;
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *logTextEdit;
    QVBoxLayout *verticalLayout;
    QPushButton *udpListeningButton;
    QPushButton *initTcpButton;
    QPushButton *pairButton;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;

    void setupUi(QMainWindow *SslBox)
    {
        if (SslBox->objectName().isEmpty())
            SslBox->setObjectName(QStringLiteral("SslBox"));
        SslBox->resize(444, 268);
        centralwidget = new QWidget(SslBox);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        hostLabel = new QLabel(centralwidget);
        hostLabel->setObjectName(QStringLiteral("hostLabel"));
        hostLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(hostLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        logTextEdit = new QPlainTextEdit(centralwidget);
        logTextEdit->setObjectName(QStringLiteral("logTextEdit"));

        horizontalLayout->addWidget(logTextEdit);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        udpListeningButton = new QPushButton(centralwidget);
        udpListeningButton->setObjectName(QStringLiteral("udpListeningButton"));

        verticalLayout->addWidget(udpListeningButton);

        initTcpButton = new QPushButton(centralwidget);
        initTcpButton->setObjectName(QStringLiteral("initTcpButton"));

        verticalLayout->addWidget(initTcpButton);

        pairButton = new QPushButton(centralwidget);
        pairButton->setObjectName(QStringLiteral("pairButton"));

        verticalLayout->addWidget(pairButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_2);

        SslBox->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SslBox);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 444, 27));
        SslBox->setMenuBar(menubar);

        retranslateUi(SslBox);

        QMetaObject::connectSlotsByName(SslBox);
    } // setupUi

    void retranslateUi(QMainWindow *SslBox)
    {
        SslBox->setWindowTitle(QApplication::translate("SslBox", "MainWindow", 0));
        hostLabel->setText(QApplication::translate("SslBox", "NO HOST", 0));
        udpListeningButton->setText(QApplication::translate("SslBox", "startListening", 0));
        initTcpButton->setText(QApplication::translate("SslBox", "initTCP", 0));
        pairButton->setText(QApplication::translate("SslBox", "pairButton", 0));
    } // retranslateUi

};

namespace Ui {
    class SslBox: public Ui_SslBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SSLBOX_H
