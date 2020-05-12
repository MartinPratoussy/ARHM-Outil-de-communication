/********************************************************************************
** Form generated from reading UI file 'import.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPORT_H
#define UI_IMPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Import
{
public:

    void setupUi(QWidget *Import)
    {
        if (Import->objectName().isEmpty())
            Import->setObjectName(QString::fromUtf8("Import"));
        Import->resize(1920, 1080);
        Import->setStyleSheet(QString::fromUtf8("background-color: rgb(157, 157, 157);"));

        retranslateUi(Import);

        QMetaObject::connectSlotsByName(Import);
    } // setupUi

    void retranslateUi(QWidget *Import)
    {
        Import->setWindowTitle(QCoreApplication::translate("Import", "Import", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Import: public Ui_Import {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPORT_H
