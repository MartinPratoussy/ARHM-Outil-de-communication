#include "adduser.h"

AddUser::AddUser()
{

}

void AddUser::InitAddEditsInterface(QSqlDatabase* database, QSqlQuery* query)
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

void AddUser::Validate(QString lastname, QString firstname, QDate birthDate, QString handicap)
{
    if (!this->query->exec("INSERT INTO User(firstname, lastname, birthDate, handicap) VALUES ("
        + lastname
        + firstname
        + birthDate.toString()
        + handicap
        + ")")
        ) qWarning() << "ERROR: " << this->database->lastError().text();
    this->close();
}


