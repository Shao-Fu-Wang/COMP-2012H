/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *labelLogo;
    QGridLayout *gridLayout;
    QSpinBox *spinBoxNumWords;
    QComboBox *comboBoxTime;
    QSpinBox *spinBoxWordLength;
    QLabel *labelMode;
    QLabel *labelNumWords;
    QLabel *labelWordLength;
    QComboBox *comboBoxMode;
    QCheckBox *checkBoxHardMode;
    QLabel *labelTime;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(284, 354);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labelLogo = new QLabel(centralwidget);
        labelLogo->setObjectName(QString::fromUtf8("labelLogo"));
        labelLogo->setScaledContents(true);
        labelLogo->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelLogo);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        spinBoxNumWords = new QSpinBox(centralwidget);
        spinBoxNumWords->setObjectName(QString::fromUtf8("spinBoxNumWords"));
        spinBoxNumWords->setMinimum(2);
        spinBoxNumWords->setMaximum(8);

        gridLayout->addWidget(spinBoxNumWords, 4, 2, 1, 1);

        comboBoxTime = new QComboBox(centralwidget);
        comboBoxTime->addItem(QString());
        comboBoxTime->addItem(QString());
        comboBoxTime->addItem(QString());
        comboBoxTime->addItem(QString());
        comboBoxTime->setObjectName(QString::fromUtf8("comboBoxTime"));

        gridLayout->addWidget(comboBoxTime, 7, 2, 1, 1);

        spinBoxWordLength = new QSpinBox(centralwidget);
        spinBoxWordLength->setObjectName(QString::fromUtf8("spinBoxWordLength"));
        spinBoxWordLength->setMinimum(1);
        spinBoxWordLength->setMaximum(31);
        spinBoxWordLength->setValue(5);

        gridLayout->addWidget(spinBoxWordLength, 9, 2, 1, 1);

        labelMode = new QLabel(centralwidget);
        labelMode->setObjectName(QString::fromUtf8("labelMode"));

        gridLayout->addWidget(labelMode, 1, 1, 1, 1);

        labelNumWords = new QLabel(centralwidget);
        labelNumWords->setObjectName(QString::fromUtf8("labelNumWords"));

        gridLayout->addWidget(labelNumWords, 4, 1, 1, 1);

        labelWordLength = new QLabel(centralwidget);
        labelWordLength->setObjectName(QString::fromUtf8("labelWordLength"));

        gridLayout->addWidget(labelWordLength, 9, 1, 1, 1);

        comboBoxMode = new QComboBox(centralwidget);
        comboBoxMode->addItem(QString());
        comboBoxMode->addItem(QString());
        comboBoxMode->addItem(QString());
        comboBoxMode->addItem(QString());
        comboBoxMode->setObjectName(QString::fromUtf8("comboBoxMode"));

        gridLayout->addWidget(comboBoxMode, 1, 2, 1, 1);

        checkBoxHardMode = new QCheckBox(centralwidget);
        checkBoxHardMode->setObjectName(QString::fromUtf8("checkBoxHardMode"));

        gridLayout->addWidget(checkBoxHardMode, 10, 1, 1, 1);

        labelTime = new QLabel(centralwidget);
        labelTime->setObjectName(QString::fromUtf8("labelTime"));

        gridLayout->addWidget(labelTime, 7, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 284, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Wordle", nullptr));
        labelLogo->setText(QString());
        comboBoxTime->setItemText(0, QCoreApplication::translate("MainWindow", "1 minute", nullptr));
        comboBoxTime->setItemText(1, QCoreApplication::translate("MainWindow", "3 minutes", nullptr));
        comboBoxTime->setItemText(2, QCoreApplication::translate("MainWindow", "5 minutes", nullptr));
        comboBoxTime->setItemText(3, QCoreApplication::translate("MainWindow", "10 minutes", nullptr));

        labelMode->setText(QCoreApplication::translate("MainWindow", "Mode", nullptr));
        labelNumWords->setText(QCoreApplication::translate("MainWindow", "Number of Words", nullptr));
        labelWordLength->setText(QCoreApplication::translate("MainWindow", "Word Length", nullptr));
        comboBoxMode->setItemText(0, QCoreApplication::translate("MainWindow", "Regular", nullptr));
        comboBoxMode->setItemText(1, QCoreApplication::translate("MainWindow", "Absurd", nullptr));
        comboBoxMode->setItemText(2, QCoreApplication::translate("MainWindow", "Multiple", nullptr));
        comboBoxMode->setItemText(3, QCoreApplication::translate("MainWindow", "Timed", nullptr));

        checkBoxHardMode->setText(QCoreApplication::translate("MainWindow", "Hard Mode", nullptr));
        labelTime->setText(QCoreApplication::translate("MainWindow", "Time", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
