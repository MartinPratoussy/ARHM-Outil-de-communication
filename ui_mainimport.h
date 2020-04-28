/********************************************************************************
** Form generated from reading UI file 'mainimport.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINIMPORT_H
#define UI_MAINIMPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainImport
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *nom;
    QTextEdit *nomSql;
    QTextEdit *lectureSql;
    QLabel *lectureAudio;
    QTextEdit *imageSql;
    QLabel *Image;
    QPushButton *parBP;
    QPushButton *bPValide;
    QGroupBox *groupBox_2;
    QRadioButton *rBCat1;
    QRadioButton *rBCat3;
    QRadioButton *rBCat4;
    QRadioButton *rBCat2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainImport)
    {
        if (MainImport->objectName().isEmpty())
            MainImport->setObjectName(QString::fromUtf8("MainImport"));
        MainImport->resize(769, 555);
        centralwidget = new QWidget(MainImport);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(90, 220, 581, 261));
        nom = new QLabel(groupBox);
        nom->setObjectName(QString::fromUtf8("nom"));
        nom->setGeometry(QRect(30, 30, 47, 13));
        nomSql = new QTextEdit(groupBox);
        nomSql->setObjectName(QString::fromUtf8("nomSql"));
        nomSql->setGeometry(QRect(30, 50, 461, 31));
        lectureSql = new QTextEdit(groupBox);
        lectureSql->setObjectName(QString::fromUtf8("lectureSql"));
        lectureSql->setGeometry(QRect(30, 110, 461, 31));
        lectureAudio = new QLabel(groupBox);
        lectureAudio->setObjectName(QString::fromUtf8("lectureAudio"));
        lectureAudio->setGeometry(QRect(30, 90, 111, 16));
        imageSql = new QTextEdit(groupBox);
        imageSql->setObjectName(QString::fromUtf8("imageSql"));
        imageSql->setGeometry(QRect(30, 180, 461, 31));
        Image = new QLabel(groupBox);
        Image->setObjectName(QString::fromUtf8("Image"));
        Image->setGeometry(QRect(30, 160, 81, 16));
        Image->setTextFormat(Qt::AutoText);
        parBP = new QPushButton(groupBox);
        parBP->setObjectName(QString::fromUtf8("parBP"));
        parBP->setGeometry(QRect(490, 180, 71, 31));
        bPValide = new QPushButton(groupBox);
        bPValide->setObjectName(QString::fromUtf8("bPValide"));
        bPValide->setGeometry(QRect(270, 220, 75, 23));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(230, 20, 261, 191));
        rBCat1 = new QRadioButton(groupBox_2);
        rBCat1->setObjectName(QString::fromUtf8("rBCat1"));
        rBCat1->setGeometry(QRect(10, 30, 91, 61));
        rBCat3 = new QRadioButton(groupBox_2);
        rBCat3->setObjectName(QString::fromUtf8("rBCat3"));
        rBCat3->setGeometry(QRect(10, 110, 81, 71));
        rBCat4 = new QRadioButton(groupBox_2);
        rBCat4->setObjectName(QString::fromUtf8("rBCat4"));
        rBCat4->setGeometry(QRect(160, 120, 91, 61));
        rBCat2 = new QRadioButton(groupBox_2);
        rBCat2->setObjectName(QString::fromUtf8("rBCat2"));
        rBCat2->setGeometry(QRect(160, 20, 91, 81));
        MainImport->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainImport);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainImport->setStatusBar(statusbar);

        retranslateUi(MainImport);

        QMetaObject::connectSlotsByName(MainImport);
    } // setupUi

    void retranslateUi(QMainWindow *MainImport)
    {
        MainImport->setWindowTitle(QCoreApplication::translate("MainImport", "MainImport", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainImport", "Pictograme", nullptr));
        nom->setText(QCoreApplication::translate("MainImport", "Nom", nullptr));
        lectureAudio->setText(QCoreApplication::translate("MainImport", "Mie en lecture audio", nullptr));
        Image->setText(QCoreApplication::translate("MainImport", "Image", nullptr));
        parBP->setText(QCoreApplication::translate("MainImport", "Parcourir", nullptr));
        bPValide->setText(QCoreApplication::translate("MainImport", "Valider", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainImport", "Cat\303\251gory", nullptr));
        rBCat1->setText(QCoreApplication::translate("MainImport", "RadioButton", nullptr));
        rBCat3->setText(QCoreApplication::translate("MainImport", "RadioButton", nullptr));
        rBCat4->setText(QCoreApplication::translate("MainImport", "RadioButton", nullptr));
        rBCat2->setText(QCoreApplication::translate("MainImport", "RadioButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainImport: public Ui_MainImport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINIMPORT_H
