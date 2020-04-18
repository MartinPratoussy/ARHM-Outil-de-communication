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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddEditUser
{
public:
    QDateEdit *birthDateEdit;
    QLabel *lastnameLabel;
    QLabel *firstnameLabe;
    QLabel *birtDateLabel;
    QPushButton *validationButton;
    QPushButton *cancelButton;
    QGraphicsView *topBorder;
    QLabel *icon;
    QPushButton *deleteButton;
    QLineEdit *category1Edit;
    QLineEdit *category2Edit;
    QLineEdit *category3Edit;
    QLineEdit *category4Edit;
    QLabel *birtDateLabel_2;
    QLineEdit *lastnameEdit;
    QLineEdit *firstnameEdit;

    void setupUi(QWidget *AddEditUser)
    {
        if (AddEditUser->objectName().isEmpty())
            AddEditUser->setObjectName(QString::fromUtf8("AddEditUser"));
        AddEditUser->resize(1920, 1080);
        AddEditUser->setToolTipDuration(0);
        AddEditUser->setStyleSheet(QString::fromUtf8("background-color: rgb(202, 202, 202);"));
        birthDateEdit = new QDateEdit(AddEditUser);
        birthDateEdit->setObjectName(QString::fromUtf8("birthDateEdit"));
        birthDateEdit->setGeometry(QRect(1120, 640, 361, 71));
        QFont font;
        font.setPointSize(28);
        birthDateEdit->setFont(font);
        birthDateEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        birthDateEdit->setReadOnly(false);
        lastnameLabel = new QLabel(AddEditUser);
        lastnameLabel->setObjectName(QString::fromUtf8("lastnameLabel"));
        lastnameLabel->setGeometry(QRect(860, 170, 151, 61));
        QFont font1;
        font1.setPointSize(40);
        lastnameLabel->setFont(font1);
        firstnameLabe = new QLabel(AddEditUser);
        firstnameLabe->setObjectName(QString::fromUtf8("firstnameLabe"));
        firstnameLabe->setGeometry(QRect(860, 360, 251, 61));
        firstnameLabe->setFont(font1);
        birtDateLabel = new QLabel(AddEditUser);
        birtDateLabel->setObjectName(QString::fromUtf8("birtDateLabel"));
        birtDateLabel->setGeometry(QRect(850, 560, 441, 61));
        birtDateLabel->setFont(font1);
        validationButton = new QPushButton(AddEditUser);
        validationButton->setObjectName(QString::fromUtf8("validationButton"));
        validationButton->setGeometry(QRect(100, 850, 231, 71));
        QFont font2;
        font2.setPointSize(30);
        validationButton->setFont(font2);
        validationButton->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        cancelButton = new QPushButton(AddEditUser);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(440, 850, 231, 71));
        cancelButton->setFont(font2);
        cancelButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 4);\n"
"color: rgb(255, 255, 255);"));
        topBorder = new QGraphicsView(AddEditUser);
        topBorder->setObjectName(QString::fromUtf8("topBorder"));
        topBorder->setGeometry(QRect(0, 0, 1921, 151));
        topBorder->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 0);\n"
"background-color: rgb(255, 170, 0);"));
        icon = new QLabel(AddEditUser);
        icon->setObjectName(QString::fromUtf8("icon"));
        icon->setGeometry(QRect(250, 330, 291, 371));
        icon->setPixmap(QPixmap(QString::fromUtf8("data/icon.png")));
        icon->setScaledContents(true);
        deleteButton = new QPushButton(AddEditUser);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(190, 970, 381, 41));
        QFont font3;
        font3.setPointSize(22);
        deleteButton->setFont(font3);
        deleteButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        category1Edit = new QLineEdit(AddEditUser);
        category1Edit->setObjectName(QString::fromUtf8("category1Edit"));
        category1Edit->setGeometry(QRect(900, 840, 381, 71));
        category1Edit->setFont(font);
        category1Edit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        category2Edit = new QLineEdit(AddEditUser);
        category2Edit->setObjectName(QString::fromUtf8("category2Edit"));
        category2Edit->setGeometry(QRect(1300, 840, 381, 71));
        category2Edit->setFont(font);
        category2Edit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        category3Edit = new QLineEdit(AddEditUser);
        category3Edit->setObjectName(QString::fromUtf8("category3Edit"));
        category3Edit->setGeometry(QRect(900, 930, 381, 71));
        category3Edit->setFont(font);
        category3Edit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        category4Edit = new QLineEdit(AddEditUser);
        category4Edit->setObjectName(QString::fromUtf8("category4Edit"));
        category4Edit->setGeometry(QRect(1300, 930, 381, 71));
        category4Edit->setFont(font);
        category4Edit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        birtDateLabel_2 = new QLabel(AddEditUser);
        birtDateLabel_2->setObjectName(QString::fromUtf8("birtDateLabel_2"));
        birtDateLabel_2->setGeometry(QRect(850, 750, 691, 71));
        birtDateLabel_2->setFont(font1);
        lastnameEdit = new QLineEdit(AddEditUser);
        lastnameEdit->setObjectName(QString::fromUtf8("lastnameEdit"));
        lastnameEdit->setGeometry(QRect(900, 260, 781, 71));
        lastnameEdit->setFont(font);
        lastnameEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        firstnameEdit = new QLineEdit(AddEditUser);
        firstnameEdit->setObjectName(QString::fromUtf8("firstnameEdit"));
        firstnameEdit->setGeometry(QRect(900, 450, 781, 71));
        firstnameEdit->setFont(font);
        firstnameEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        birthDateEdit->raise();
        lastnameLabel->raise();
        firstnameLabe->raise();
        birtDateLabel->raise();
        validationButton->raise();
        cancelButton->raise();
        topBorder->raise();
        deleteButton->raise();
        icon->raise();
        category1Edit->raise();
        category2Edit->raise();
        category3Edit->raise();
        category4Edit->raise();
        birtDateLabel_2->raise();
        lastnameEdit->raise();
        firstnameEdit->raise();

        retranslateUi(AddEditUser);

        QMetaObject::connectSlotsByName(AddEditUser);
    } // setupUi

    void retranslateUi(QWidget *AddEditUser)
    {
        AddEditUser->setWindowTitle(QCoreApplication::translate("AddEditUser", "Form", nullptr));
        lastnameLabel->setText(QCoreApplication::translate("AddEditUser", "Nom", nullptr));
        firstnameLabe->setText(QCoreApplication::translate("AddEditUser", "Pr\303\251nom", nullptr));
        birtDateLabel->setText(QCoreApplication::translate("AddEditUser", "Date de naissance", nullptr));
        validationButton->setText(QCoreApplication::translate("AddEditUser", "Valider", nullptr));
        cancelButton->setText(QCoreApplication::translate("AddEditUser", "Annuler", nullptr));
        icon->setText(QString());
        deleteButton->setText(QCoreApplication::translate("AddEditUser", "Supprimer l'utilisateur", nullptr));
        category1Edit->setText(QString());
        category1Edit->setPlaceholderText(QCoreApplication::translate("AddEditUser", "Cat\303\251gorie 1", nullptr));
        category2Edit->setText(QString());
        category2Edit->setPlaceholderText(QCoreApplication::translate("AddEditUser", "Cat\303\251gorie 2", nullptr));
        category3Edit->setText(QString());
        category3Edit->setPlaceholderText(QCoreApplication::translate("AddEditUser", "Cat\303\251gorie 3", nullptr));
        category4Edit->setText(QString());
        category4Edit->setPlaceholderText(QCoreApplication::translate("AddEditUser", "Cat\303\251gorie 4", nullptr));
        birtDateLabel_2->setText(QCoreApplication::translate("AddEditUser", "Cat\303\251gories de pictogrammes", nullptr));
        lastnameEdit->setPlaceholderText(QCoreApplication::translate("AddEditUser", "Entrez le nom de l'utilisateur ici", nullptr));
        firstnameEdit->setPlaceholderText(QCoreApplication::translate("AddEditUser", "Entrez le pr\303\251nom de l'utilisateur ici", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddEditUser: public Ui_AddEditUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEDITUSER_H
