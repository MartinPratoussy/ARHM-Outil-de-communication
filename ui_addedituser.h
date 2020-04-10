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
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddEditUser
{
public:
    QTextEdit *lastnameEdit;
    QTextEdit *firstnameEdit;
    QDateEdit *birthDateEdit;
    QLabel *lastnameLabel;
    QLabel *firstnameLabe;
    QLabel *birtDateLabel;
    QPushButton *validateButton;
    QPushButton *cancelButton;
    QGraphicsView *topBorder;
    QLabel *icon;
    QGraphicsView *graphicsView;
    QPushButton *deleteButton;

    void setupUi(QWidget *AddEditUser)
    {
        if (AddEditUser->objectName().isEmpty())
            AddEditUser->setObjectName(QString::fromUtf8("AddEditUser"));
        AddEditUser->resize(1920, 1080);
        lastnameEdit = new QTextEdit(AddEditUser);
        lastnameEdit->setObjectName(QString::fromUtf8("lastnameEdit"));
        lastnameEdit->setGeometry(QRect(890, 370, 811, 71));
        QFont font;
        font.setPointSize(28);
        lastnameEdit->setFont(font);
        firstnameEdit = new QTextEdit(AddEditUser);
        firstnameEdit->setObjectName(QString::fromUtf8("firstnameEdit"));
        firstnameEdit->setGeometry(QRect(890, 560, 811, 71));
        firstnameEdit->setFont(font);
        firstnameEdit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        firstnameEdit->setAutoFillBackground(false);
        birthDateEdit = new QDateEdit(AddEditUser);
        birthDateEdit->setObjectName(QString::fromUtf8("birthDateEdit"));
        birthDateEdit->setGeometry(QRect(1120, 770, 361, 71));
        birthDateEdit->setFont(font);
        birthDateEdit->setReadOnly(false);
        lastnameLabel = new QLabel(AddEditUser);
        lastnameLabel->setObjectName(QString::fromUtf8("lastnameLabel"));
        lastnameLabel->setGeometry(QRect(860, 300, 151, 61));
        QFont font1;
        font1.setPointSize(40);
        lastnameLabel->setFont(font1);
        firstnameLabe = new QLabel(AddEditUser);
        firstnameLabe->setObjectName(QString::fromUtf8("firstnameLabe"));
        firstnameLabe->setGeometry(QRect(860, 490, 251, 61));
        firstnameLabe->setFont(font1);
        birtDateLabel = new QLabel(AddEditUser);
        birtDateLabel->setObjectName(QString::fromUtf8("birtDateLabel"));
        birtDateLabel->setGeometry(QRect(850, 690, 441, 61));
        birtDateLabel->setFont(font1);
        validateButton = new QPushButton(AddEditUser);
        validateButton->setObjectName(QString::fromUtf8("validateButton"));
        validateButton->setGeometry(QRect(110, 920, 231, 71));
        QFont font2;
        font2.setPointSize(30);
        validateButton->setFont(font2);
        validateButton->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 0);"));
        cancelButton = new QPushButton(AddEditUser);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(450, 920, 231, 71));
        cancelButton->setFont(font2);
        cancelButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 4);"));
        topBorder = new QGraphicsView(AddEditUser);
        topBorder->setObjectName(QString::fromUtf8("topBorder"));
        topBorder->setGeometry(QRect(0, 0, 1921, 151));
        topBorder->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 0);"));
        icon = new QLabel(AddEditUser);
        icon->setObjectName(QString::fromUtf8("icon"));
        icon->setGeometry(QRect(250, 330, 291, 371));
        icon->setPixmap(QPixmap(QString::fromUtf8("data/icon.png")));
        icon->setScaledContents(true);
        graphicsView = new QGraphicsView(AddEditUser);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, -20, 1921, 1081));
        graphicsView->setStyleSheet(QString::fromUtf8("background-color: rgb(213, 213, 213);"));
        deleteButton = new QPushButton(AddEditUser);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(1060, 920, 461, 51));
        QFont font3;
        font3.setPointSize(22);
        deleteButton->setFont(font3);
        deleteButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        graphicsView->raise();
        lastnameEdit->raise();
        firstnameEdit->raise();
        birthDateEdit->raise();
        lastnameLabel->raise();
        firstnameLabe->raise();
        birtDateLabel->raise();
        validateButton->raise();
        cancelButton->raise();
        topBorder->raise();
        icon->raise();
        deleteButton->raise();

        retranslateUi(AddEditUser);

        QMetaObject::connectSlotsByName(AddEditUser);
    } // setupUi

    void retranslateUi(QWidget *AddEditUser)
    {
        AddEditUser->setWindowTitle(QCoreApplication::translate("AddEditUser", "Form", nullptr));
        lastnameEdit->setPlaceholderText(QCoreApplication::translate("AddEditUser", "Entrer le nom de l'utilisateur ici", nullptr));
        firstnameEdit->setPlaceholderText(QCoreApplication::translate("AddEditUser", "Entrez le pr\303\251nom de l'utilisateur ici", nullptr));
        lastnameLabel->setText(QCoreApplication::translate("AddEditUser", "Nom", nullptr));
        firstnameLabe->setText(QCoreApplication::translate("AddEditUser", "Pr\303\251nom", nullptr));
        birtDateLabel->setText(QCoreApplication::translate("AddEditUser", "Date de naissance", nullptr));
        validateButton->setText(QCoreApplication::translate("AddEditUser", "Valider", nullptr));
        cancelButton->setText(QCoreApplication::translate("AddEditUser", "Annuler", nullptr));
        icon->setText(QString());
        deleteButton->setText(QCoreApplication::translate("AddEditUser", "Supprimer l'utilisateur", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddEditUser: public Ui_AddEditUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEDITUSER_H
