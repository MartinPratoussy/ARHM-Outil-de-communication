#include "interface.h"
#include "ui_interface.h"

#include <QLoggingCategory>


Interface::Interface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Interface)
{
    ui->setupUi(this);
}

void Interface::InitInterface(User *user)
{
    this->user = user;
}

Interface::~Interface()
{
    delete ui;
}

void Interface::Cancel()
{
    *sentence[numLevel] = "";
    numLevel--;
}

User * Interface::getUser()
{
    return this->user;
}

Interface & Interface::operator=(const Interface & interface)
{
    *this->sentence = *interface.sentence;
    this->numLevel = interface.numLevel;

    return * this;
}

void Interface::on_jeVeuxButton_clicked()
{
    Sound m_speech;
    m_speech.say(ui->jeVeuxButton->text());
}

void Interface::on_jeSuisButton_clicked()
{
    Sound m_speech;
    m_speech.say(ui->jeSuisButton->text());
}

void Interface::on_objetsButton_clicked()
{
    Sound m_speech;
    m_speech.say(ui->objetsButton->text());
}

void Interface::on_personnesButton_clicked()
{
    Sound m_speech;
    m_speech.say(ui->personnesButton->text());
}
