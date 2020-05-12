/********************************************************************************
** Form generated from reading UI file 'interface.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_H
#define UI_INTERFACE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Interface
{
public:
    QGraphicsView *graphicsView;
    QPushButton *readButton;
    QPushButton *backButton;
    QProgressBar *progressBar;
    QLabel *firstPictoLabel;
    QLabel *secondPictoLabel;
    QLabel *thirdPictoLabel;
    QPushButton *firstCategoryButton;
    QPushButton *thirdCategoryButton;
    QPushButton *secondCategoryButton;
    QPushButton *fourthCategoryButton;

    void setupUi(QWidget *Interface)
    {
        if (Interface->objectName().isEmpty())
            Interface->setObjectName(QString::fromUtf8("Interface"));
        Interface->resize(1920, 1104);
        Interface->setStyleSheet(QString::fromUtf8("background-color: rgb(197, 197, 197);"));
        graphicsView = new QGraphicsView(Interface);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(-5, 0, 1931, 331));
        graphicsView->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 0);"));
        readButton = new QPushButton(Interface);
        readButton->setObjectName(QString::fromUtf8("readButton"));
        readButton->setGeometry(QRect(1730, 20, 141, 121));
        readButton->setAutoFillBackground(false);
        readButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("data/read.png"), QSize(), QIcon::Normal, QIcon::Off);
        readButton->setIcon(icon);
        readButton->setIconSize(QSize(128, 128));
        readButton->setAutoRepeat(false);
        backButton = new QPushButton(Interface);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(1730, 190, 141, 121));
        backButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("data/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        backButton->setIcon(icon1);
        backButton->setIconSize(QSize(128, 128));
        progressBar = new QProgressBar(Interface);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(80, 112, 1511, 91));
        progressBar->setValue(17);
        progressBar->setTextVisible(false);
        firstPictoLabel = new QLabel(Interface);
        firstPictoLabel->setObjectName(QString::fromUtf8("firstPictoLabel"));
        firstPictoLabel->setGeometry(QRect(250, 70, 291, 181));
        QFont font;
        font.setPointSize(48);
        firstPictoLabel->setFont(font);
        firstPictoLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        firstPictoLabel->setScaledContents(true);
        firstPictoLabel->setAlignment(Qt::AlignCenter);
        secondPictoLabel = new QLabel(Interface);
        secondPictoLabel->setObjectName(QString::fromUtf8("secondPictoLabel"));
        secondPictoLabel->setGeometry(QRect(770, 70, 291, 181));
        secondPictoLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        secondPictoLabel->setAlignment(Qt::AlignCenter);
        thirdPictoLabel = new QLabel(Interface);
        thirdPictoLabel->setObjectName(QString::fromUtf8("thirdPictoLabel"));
        thirdPictoLabel->setGeometry(QRect(1300, 70, 291, 181));
        thirdPictoLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        thirdPictoLabel->setAlignment(Qt::AlignCenter);
        firstCategoryButton = new QPushButton(Interface);
        firstCategoryButton->setObjectName(QString::fromUtf8("firstCategoryButton"));
        firstCategoryButton->setGeometry(QRect(250, 440, 551, 241));
        QFont font1;
        font1.setPointSize(36);
        firstCategoryButton->setFont(font1);
        firstCategoryButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        thirdCategoryButton = new QPushButton(Interface);
        thirdCategoryButton->setObjectName(QString::fromUtf8("thirdCategoryButton"));
        thirdCategoryButton->setGeometry(QRect(250, 750, 551, 241));
        thirdCategoryButton->setFont(font1);
        thirdCategoryButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        secondCategoryButton = new QPushButton(Interface);
        secondCategoryButton->setObjectName(QString::fromUtf8("secondCategoryButton"));
        secondCategoryButton->setGeometry(QRect(1090, 440, 551, 241));
        secondCategoryButton->setFont(font1);
        secondCategoryButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        fourthCategoryButton = new QPushButton(Interface);
        fourthCategoryButton->setObjectName(QString::fromUtf8("fourthCategoryButton"));
        fourthCategoryButton->setGeometry(QRect(1090, 750, 551, 241));
        fourthCategoryButton->setFont(font1);
        fourthCategoryButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        retranslateUi(Interface);

        QMetaObject::connectSlotsByName(Interface);
    } // setupUi

    void retranslateUi(QWidget *Interface)
    {
        Interface->setWindowTitle(QCoreApplication::translate("Interface", "Form", nullptr));
        readButton->setText(QString());
        backButton->setText(QString());
        firstPictoLabel->setText(QString());
        secondPictoLabel->setText(QString());
        thirdPictoLabel->setText(QString());
        firstCategoryButton->setText(QString());
        thirdCategoryButton->setText(QString());
        secondCategoryButton->setText(QString());
        fourthCategoryButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Interface: public Ui_Interface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_H
