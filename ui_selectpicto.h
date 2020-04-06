/********************************************************************************
** Form generated from reading UI file 'selectpicto.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTPICTO_H
#define UI_SELECTPICTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectPicto
{
public:

    void setupUi(QWidget *SelectPicto)
    {
        if (SelectPicto->objectName().isEmpty())
            SelectPicto->setObjectName(QString::fromUtf8("SelectPicto"));
        SelectPicto->resize(400, 300);

        retranslateUi(SelectPicto);

        QMetaObject::connectSlotsByName(SelectPicto);
    } // setupUi

    void retranslateUi(QWidget *SelectPicto)
    {
        SelectPicto->setWindowTitle(QCoreApplication::translate("SelectPicto", "SelectPicto", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SelectPicto: public Ui_SelectPicto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTPICTO_H
