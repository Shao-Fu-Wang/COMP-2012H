/********************************************************************************
** Form generated from reading UI file 'roundwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROUNDWINDOW_H
#define UI_ROUNDWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "key.h"

QT_BEGIN_NAMESPACE

class Ui_RoundWindow
{
public:
    QAction *actionGive_Up;
    QAction *actionReset_Round;
    QAction *actionCheat;
    QAction *actionHint;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayoutGuesses;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *gridLayoutBox;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QGridLayout *gridLayoutKey;
    Key *toolButton_Y;
    Key *toolButton_K;
    Key *toolButton_W;
    Key *toolButton_H;
    Key *toolButton_G;
    Key *toolButton_I;
    Key *toolButton_F;
    Key *toolButton_S;
    Key *toolButton_E;
    Key *toolButton_Q;
    Key *toolButton_O;
    Key *toolButton_P;
    Key *toolButton_J;
    Key *toolButton_T;
    Key *toolButton_A;
    Key *toolButton_R;
    Key *toolButton_D;
    Key *toolButton_U;
    QPushButton *pushButton_Del;
    QPushButton *pushButton_Enter;
    Key *toolButton_Z;
    Key *toolButton_X;
    Key *toolButton_C;
    Key *toolButton_V;
    Key *toolButton_B;
    Key *toolButton_N;
    Key *toolButton_L;
    Key *toolButton_M;
    QSpacerItem *horizontalSpacer_6;
    QMenuBar *menubar;
    QMenu *menuOptions;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RoundWindow)
    {
        if (RoundWindow->objectName().isEmpty())
            RoundWindow->setObjectName(QString::fromUtf8("RoundWindow"));
        RoundWindow->resize(525, 558);
        actionGive_Up = new QAction(RoundWindow);
        actionGive_Up->setObjectName(QString::fromUtf8("actionGive_Up"));
        actionReset_Round = new QAction(RoundWindow);
        actionReset_Round->setObjectName(QString::fromUtf8("actionReset_Round"));
        actionCheat = new QAction(RoundWindow);
        actionCheat->setObjectName(QString::fromUtf8("actionCheat"));
        actionHint = new QAction(RoundWindow);
        actionHint->setObjectName(QString::fromUtf8("actionHint"));
        centralwidget = new QWidget(RoundWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 505, 373));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayoutGuesses = new QHBoxLayout();
        horizontalLayoutGuesses->setObjectName(QString::fromUtf8("horizontalLayoutGuesses"));
        horizontalSpacer_3 = new QSpacerItem(239, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutGuesses->addItem(horizontalSpacer_3);

        gridLayoutBox = new QGridLayout();
        gridLayoutBox->setObjectName(QString::fromUtf8("gridLayoutBox"));
        gridLayoutBox->setSizeConstraint(QLayout::SetMinAndMaxSize);

        horizontalLayoutGuesses->addLayout(gridLayoutBox);

        horizontalSpacer_4 = new QSpacerItem(238, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutGuesses->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayoutGuesses);

        verticalSpacer = new QSpacerItem(20, 307, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalSpacer_5 = new QSpacerItem(13, 86, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        gridLayoutKey = new QGridLayout();
        gridLayoutKey->setObjectName(QString::fromUtf8("gridLayoutKey"));
        gridLayoutKey->setSizeConstraint(QLayout::SetMaximumSize);
        toolButton_Y = new Key(centralwidget);
        toolButton_Y->setObjectName(QString::fromUtf8("toolButton_Y"));

        gridLayoutKey->addWidget(toolButton_Y, 6, 5, 1, 1);

        toolButton_K = new Key(centralwidget);
        toolButton_K->setObjectName(QString::fromUtf8("toolButton_K"));

        gridLayoutKey->addWidget(toolButton_K, 7, 7, 1, 1);

        toolButton_W = new Key(centralwidget);
        toolButton_W->setObjectName(QString::fromUtf8("toolButton_W"));

        gridLayoutKey->addWidget(toolButton_W, 6, 1, 1, 1);

        toolButton_H = new Key(centralwidget);
        toolButton_H->setObjectName(QString::fromUtf8("toolButton_H"));

        gridLayoutKey->addWidget(toolButton_H, 7, 5, 1, 1);

        toolButton_G = new Key(centralwidget);
        toolButton_G->setObjectName(QString::fromUtf8("toolButton_G"));

        gridLayoutKey->addWidget(toolButton_G, 7, 4, 1, 1);

        toolButton_I = new Key(centralwidget);
        toolButton_I->setObjectName(QString::fromUtf8("toolButton_I"));

        gridLayoutKey->addWidget(toolButton_I, 6, 7, 1, 1);

        toolButton_F = new Key(centralwidget);
        toolButton_F->setObjectName(QString::fromUtf8("toolButton_F"));

        gridLayoutKey->addWidget(toolButton_F, 7, 3, 1, 1);

        toolButton_S = new Key(centralwidget);
        toolButton_S->setObjectName(QString::fromUtf8("toolButton_S"));

        gridLayoutKey->addWidget(toolButton_S, 7, 1, 1, 1);

        toolButton_E = new Key(centralwidget);
        toolButton_E->setObjectName(QString::fromUtf8("toolButton_E"));

        gridLayoutKey->addWidget(toolButton_E, 6, 2, 1, 1);

        toolButton_Q = new Key(centralwidget);
        toolButton_Q->setObjectName(QString::fromUtf8("toolButton_Q"));

        gridLayoutKey->addWidget(toolButton_Q, 6, 0, 1, 1);

        toolButton_O = new Key(centralwidget);
        toolButton_O->setObjectName(QString::fromUtf8("toolButton_O"));

        gridLayoutKey->addWidget(toolButton_O, 6, 8, 1, 1);

        toolButton_P = new Key(centralwidget);
        toolButton_P->setObjectName(QString::fromUtf8("toolButton_P"));

        gridLayoutKey->addWidget(toolButton_P, 6, 9, 1, 1);

        toolButton_J = new Key(centralwidget);
        toolButton_J->setObjectName(QString::fromUtf8("toolButton_J"));

        gridLayoutKey->addWidget(toolButton_J, 7, 6, 1, 1);

        toolButton_T = new Key(centralwidget);
        toolButton_T->setObjectName(QString::fromUtf8("toolButton_T"));

        gridLayoutKey->addWidget(toolButton_T, 6, 4, 1, 1);

        toolButton_A = new Key(centralwidget);
        toolButton_A->setObjectName(QString::fromUtf8("toolButton_A"));

        gridLayoutKey->addWidget(toolButton_A, 7, 0, 1, 1);

        toolButton_R = new Key(centralwidget);
        toolButton_R->setObjectName(QString::fromUtf8("toolButton_R"));

        gridLayoutKey->addWidget(toolButton_R, 6, 3, 1, 1);

        toolButton_D = new Key(centralwidget);
        toolButton_D->setObjectName(QString::fromUtf8("toolButton_D"));

        gridLayoutKey->addWidget(toolButton_D, 7, 2, 1, 1);

        toolButton_U = new Key(centralwidget);
        toolButton_U->setObjectName(QString::fromUtf8("toolButton_U"));

        gridLayoutKey->addWidget(toolButton_U, 6, 6, 1, 1);

        pushButton_Del = new QPushButton(centralwidget);
        pushButton_Del->setObjectName(QString::fromUtf8("pushButton_Del"));

        gridLayoutKey->addWidget(pushButton_Del, 6, 10, 1, 1);

        pushButton_Enter = new QPushButton(centralwidget);
        pushButton_Enter->setObjectName(QString::fromUtf8("pushButton_Enter"));

        gridLayoutKey->addWidget(pushButton_Enter, 7, 10, 2, 1);

        toolButton_Z = new Key(centralwidget);
        toolButton_Z->setObjectName(QString::fromUtf8("toolButton_Z"));

        gridLayoutKey->addWidget(toolButton_Z, 8, 1, 1, 1);

        toolButton_X = new Key(centralwidget);
        toolButton_X->setObjectName(QString::fromUtf8("toolButton_X"));

        gridLayoutKey->addWidget(toolButton_X, 8, 2, 1, 1);

        toolButton_C = new Key(centralwidget);
        toolButton_C->setObjectName(QString::fromUtf8("toolButton_C"));

        gridLayoutKey->addWidget(toolButton_C, 8, 3, 1, 1);

        toolButton_V = new Key(centralwidget);
        toolButton_V->setObjectName(QString::fromUtf8("toolButton_V"));

        gridLayoutKey->addWidget(toolButton_V, 8, 4, 1, 1);

        toolButton_B = new Key(centralwidget);
        toolButton_B->setObjectName(QString::fromUtf8("toolButton_B"));

        gridLayoutKey->addWidget(toolButton_B, 8, 5, 1, 1);

        toolButton_N = new Key(centralwidget);
        toolButton_N->setObjectName(QString::fromUtf8("toolButton_N"));

        gridLayoutKey->addWidget(toolButton_N, 8, 6, 1, 1);

        toolButton_L = new Key(centralwidget);
        toolButton_L->setObjectName(QString::fromUtf8("toolButton_L"));

        gridLayoutKey->addWidget(toolButton_L, 7, 8, 1, 2);

        toolButton_M = new Key(centralwidget);
        toolButton_M->setObjectName(QString::fromUtf8("toolButton_M"));

        gridLayoutKey->addWidget(toolButton_M, 8, 7, 1, 2);


        horizontalLayout_3->addLayout(gridLayoutKey);

        horizontalSpacer_6 = new QSpacerItem(13, 86, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_3);

        RoundWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RoundWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 525, 21));
        menuOptions = new QMenu(menubar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        RoundWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(RoundWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        RoundWindow->setStatusBar(statusbar);

        menubar->addAction(menuOptions->menuAction());
        menuOptions->addAction(actionGive_Up);
        menuOptions->addAction(actionReset_Round);
        menuOptions->addSeparator();
        menuOptions->addAction(actionCheat);
        menuOptions->addAction(actionHint);

        retranslateUi(RoundWindow);

        QMetaObject::connectSlotsByName(RoundWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RoundWindow)
    {
        RoundWindow->setWindowTitle(QCoreApplication::translate("RoundWindow", "Wordle", nullptr));
        actionGive_Up->setText(QCoreApplication::translate("RoundWindow", "Give Up", nullptr));
        actionReset_Round->setText(QCoreApplication::translate("RoundWindow", "Reset Round", nullptr));
        actionCheat->setText(QCoreApplication::translate("RoundWindow", "Cheat", nullptr));
        actionHint->setText(QCoreApplication::translate("RoundWindow", "Hint", nullptr));
        label->setText(QCoreApplication::translate("RoundWindow", "Wordle", nullptr));
        toolButton_Y->setText(QCoreApplication::translate("RoundWindow", "Y", nullptr));
        toolButton_K->setText(QCoreApplication::translate("RoundWindow", "K", nullptr));
        toolButton_W->setText(QCoreApplication::translate("RoundWindow", "W", nullptr));
        toolButton_H->setText(QCoreApplication::translate("RoundWindow", "H", nullptr));
        toolButton_G->setText(QCoreApplication::translate("RoundWindow", "G", nullptr));
        toolButton_I->setText(QCoreApplication::translate("RoundWindow", "I", nullptr));
        toolButton_F->setText(QCoreApplication::translate("RoundWindow", "F", nullptr));
        toolButton_S->setText(QCoreApplication::translate("RoundWindow", "S", nullptr));
        toolButton_E->setText(QCoreApplication::translate("RoundWindow", "E", nullptr));
        toolButton_Q->setText(QCoreApplication::translate("RoundWindow", "Q", nullptr));
        toolButton_O->setText(QCoreApplication::translate("RoundWindow", "O", nullptr));
        toolButton_P->setText(QCoreApplication::translate("RoundWindow", "P", nullptr));
        toolButton_J->setText(QCoreApplication::translate("RoundWindow", "J", nullptr));
        toolButton_T->setText(QCoreApplication::translate("RoundWindow", "T", nullptr));
        toolButton_A->setText(QCoreApplication::translate("RoundWindow", "A", nullptr));
        toolButton_R->setText(QCoreApplication::translate("RoundWindow", "R", nullptr));
        toolButton_D->setText(QCoreApplication::translate("RoundWindow", "D", nullptr));
        toolButton_U->setText(QCoreApplication::translate("RoundWindow", "U", nullptr));
        pushButton_Del->setText(QCoreApplication::translate("RoundWindow", "Del", nullptr));
        pushButton_Enter->setText(QCoreApplication::translate("RoundWindow", "Enter", nullptr));
        toolButton_Z->setText(QCoreApplication::translate("RoundWindow", "Z", nullptr));
        toolButton_X->setText(QCoreApplication::translate("RoundWindow", "X", nullptr));
        toolButton_C->setText(QCoreApplication::translate("RoundWindow", "C", nullptr));
        toolButton_V->setText(QCoreApplication::translate("RoundWindow", "V", nullptr));
        toolButton_B->setText(QCoreApplication::translate("RoundWindow", "B", nullptr));
        toolButton_N->setText(QCoreApplication::translate("RoundWindow", "N", nullptr));
        toolButton_L->setText(QCoreApplication::translate("RoundWindow", "L", nullptr));
        toolButton_M->setText(QCoreApplication::translate("RoundWindow", "M", nullptr));
        menuOptions->setTitle(QCoreApplication::translate("RoundWindow", "Options", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RoundWindow: public Ui_RoundWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROUNDWINDOW_H
