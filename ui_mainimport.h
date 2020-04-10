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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainImport
{
public:
    QWidget *centralwidget;
    QPushButton *BpValide;
    QTextEdit *NomSql;
    QLabel *Image;
    QTextEdit *LectureSql;
    QLineEdit *ImageSql;
    QLabel *LectureAudio;
    QLabel *Nom;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainImport)
    {
        if (MainImport->objectName().isEmpty())
            MainImport->setObjectName(QString::fromUtf8("MainImport"));
        MainImport->resize(800, 600);
        centralwidget = new QWidget(MainImport);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        BpValide = new QPushButton(centralwidget);
        BpValide->setObjectName(QString::fromUtf8("BpValide"));
        BpValide->setGeometry(QRect(650, 480, 75, 23));
        NomSql = new QTextEdit(centralwidget);
        NomSql->setObjectName(QString::fromUtf8("NomSql"));
        NomSql->setGeometry(QRect(100, 130, 461, 41));
        Image = new QLabel(centralwidget);
        Image->setObjectName(QString::fromUtf8("Image"));
        Image->setGeometry(QRect(100, 300, 81, 16));
        Image->setTextFormat(Qt::AutoText);
        LectureSql = new QTextEdit(centralwidget);
        LectureSql->setObjectName(QString::fromUtf8("LectureSql"));
        LectureSql->setGeometry(QRect(100, 220, 461, 41));
        ImageSql = new QLineEdit(centralwidget);
        ImageSql->setObjectName(QString::fromUtf8("ImageSql"));
        ImageSql->setGeometry(QRect(100, 320, 461, 41));
        LectureAudio = new QLabel(centralwidget);
        LectureAudio->setObjectName(QString::fromUtf8("LectureAudio"));
        LectureAudio->setGeometry(QRect(100, 200, 111, 16));
        Nom = new QLabel(centralwidget);
        Nom->setObjectName(QString::fromUtf8("Nom"));
        Nom->setGeometry(QRect(100, 110, 47, 13));
        MainImport->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainImport);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainImport->setMenuBar(menubar);
        statusbar = new QStatusBar(MainImport);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainImport->setStatusBar(statusbar);

        retranslateUi(MainImport);

        QMetaObject::connectSlotsByName(MainImport);
    } // setupUi

    void retranslateUi(QMainWindow *MainImport)
    {
        MainImport->setWindowTitle(QCoreApplication::translate("MainImport", "MainImport", nullptr));
        BpValide->setText(QCoreApplication::translate("MainImport", "Valider", nullptr));
        Image->setText(QCoreApplication::translate("MainImport", "Image", nullptr));
        LectureAudio->setText(QCoreApplication::translate("MainImport", "Mie en lecture audio", nullptr));
        Nom->setText(QCoreApplication::translate("MainImport", "nom", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainImport: public Ui_MainImport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINIMPORT_H
