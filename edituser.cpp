#include "edituser.h"


void EditUser::on_validationButton_clicked()
{
    Validate(this->firstnameEdit->toPlainText(), this->lastnameEdit->toPlainText(), this->birtDateEdit->date().toString(), this->handicapEdit->toPlainText());
}

EditUser::EditUser()
{

}

User* EditUser::GetUser()
{
    return this->user;
}

void EditUser::DeleteUser()
{
    this->user->~User();
}

void EditUser::InitInterface(User* user, QSqlQuery* query)
{
    this->user = user;
    AddEditUser::query = query;

    lastnameEdit = new QTextEdit(this->user->getLastname(), this);
    firstnameEdit = new QTextEdit(this->user->getFirstname(), this);
    birtDateEdit = new QDateEdit(QDate::fromString(this->user->getBirthDate(), "dd/MM/yyyy"),  this);
    handicapEdit = new QTextEdit(this->user->getHandicap(), this);
    validation = new QPushButton("Valider", this);

    connect(validation, SIGNAL(released()), this, SLOT(on_validationButton_clicked()));
}

void EditUser::Validate(QString firstname, QString lastname, QString birthDate, QString handicap)
{
    this->user->setFirstname(firstname, query);
    this->user->setLastname(lastname, query);
    this->user->setBirthDate(birthDate, query);
    this->user->setHandicap(handicap, query);

    this->close();
}

