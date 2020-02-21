/********************************************************************************
** Form generated from reading UI file 'userlist.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERLIST_H
#define UI_USERLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserList
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;

    void setupUi(QMainWindow *UserList)
    {
        if (UserList->objectName().isEmpty())
            UserList->setObjectName(QString::fromUtf8("UserList"));
        UserList->resize(1920, 1080);
        centralWidget = new QWidget(UserList);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 130, 80, 21));
        UserList->setCentralWidget(centralWidget);

        retranslateUi(UserList);

        QMetaObject::connectSlotsByName(UserList);
    } // setupUi

    void retranslateUi(QMainWindow *UserList)
    {
        UserList->setWindowTitle(QApplication::translate("UserList", "UserList", nullptr));
        pushButton->setText(QApplication::translate("UserList", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserList: public Ui_UserList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERLIST_H
