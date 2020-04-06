/********************************************************************************
** Form generated from reading UI file 'addedituser.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDEDITUSER_H
#define UI_ADDEDITUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddEditUser
{
public:

    void setupUi(QWidget *AddEditUser)
    {
        if (AddEditUser->objectName().isEmpty())
            AddEditUser->setObjectName(QString::fromUtf8("AddEditUser"));
        AddEditUser->resize(400, 300);

        retranslateUi(AddEditUser);

        QMetaObject::connectSlotsByName(AddEditUser);
    } // setupUi

    void retranslateUi(QWidget *AddEditUser)
    {
        AddEditUser->setWindowTitle(QCoreApplication::translate("AddEditUser", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddEditUser: public Ui_AddEditUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEDITUSER_H
