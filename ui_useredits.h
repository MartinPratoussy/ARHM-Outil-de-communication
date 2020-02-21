/********************************************************************************
** Form generated from reading UI file 'useredits.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USEREDITS_H
#define UI_USEREDITS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserEdits
{
public:

    void setupUi(QWidget *UserEdits)
    {
        if (UserEdits->objectName().isEmpty())
            UserEdits->setObjectName(QString::fromUtf8("UserEdits"));
        UserEdits->resize(400, 300);

        retranslateUi(UserEdits);

        QMetaObject::connectSlotsByName(UserEdits);
    } // setupUi

    void retranslateUi(QWidget *UserEdits)
    {
        UserEdits->setWindowTitle(QApplication::translate("UserEdits", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserEdits: public Ui_UserEdits {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USEREDITS_H
