/********************************************************************************
** Form generated from reading UI file 'userlist.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERLIST_H
#define UI_USERLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserList
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QLabel *label;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QMainWindow *UserList)
    {
        if (UserList->objectName().isEmpty())
            UserList->setObjectName(QString::fromUtf8("UserList"));
        UserList->resize(1920, 1080);
        UserList->setStyleSheet(QString::fromUtf8("background-color: rgb(195, 195, 195);"));
        centralWidget = new QWidget(UserList);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 1921, 131));
        graphicsView->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 0);"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(840, 10, 221, 101));
        label->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        label->setPixmap(QPixmap(QString::fromUtf8("data/arhm.png")));
        label->setScaledContents(true);
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 130, 1920, 951));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1918, 949));
        scrollArea->setWidget(scrollAreaWidgetContents);
        UserList->setCentralWidget(centralWidget);

        retranslateUi(UserList);

        QMetaObject::connectSlotsByName(UserList);
    } // setupUi

    void retranslateUi(QMainWindow *UserList)
    {
        UserList->setWindowTitle(QCoreApplication::translate("UserList", "UserList", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UserList: public Ui_UserList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERLIST_H
