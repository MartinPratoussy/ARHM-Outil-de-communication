#include "adduser.h"

AddUser::AddUser()
{

}

void AddUser::on_validationButton_clicked()
{
    Validate(this->firstnameEdit->toPlainText(), this->lastnameEdit->toPlainText(), this->birtDateEdit->date().toString(), this->handicapEdit->toPlainText());
}

void AddUser::InitInterface(QSqlDatabase* database, QSqlQuery* query)
{
    this->database = database;
    this->query = query;

    lastnameEdit = new QTextEdit(this);
    firstnameEdit = new QTextEdit(this);
    birtDateEdit = new QDateEdit(this);
    handicapEdit = new QTextEdit(this);
    validation = new QPushButton("Valider", this);

    connect(validation, SIGNAL(released()), this, SLOT(on_validationButton_clicked()));
}

void AddUser::Validate(QString lastname, QString firstname, QString birthDate, QString handicap)
{
    if (!this->query->exec("INSERT INTO User(firstname, lastname, birthDate, handicap) VALUES ("
        + lastname
        + firstname
        + birthDate
        + handicap
        + ")")
        ) qWarning() << "ERROR: " << this->database->lastError().text();
    this->close();
}


