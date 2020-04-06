#include "adduser.h"

AddUser::AddUser()
{

}

void AddUser::on_validationButton_clicked()
{
    Validate(this->firstnameEdit->toPlainText(), this->lastnameEdit->toPlainText(), this->birtDateEdit->date().toString());
}

void AddUser::InitInterface(QSqlDatabase* database, QSqlQuery* query)
{
    this->database = database;
    this->query = query;

    lastnameEdit = new QTextEdit(this);
    firstnameEdit = new QTextEdit(this);
    birtDateEdit = new QDateEdit(this);
    validation = new QPushButton("Valider", this);

    connect(validation, SIGNAL(released()), this, SLOT(on_validationButton_clicked()));
}

void AddUser::Validate(QString lastname, QString firstname, QString birthDate)
{
    if (!this->query->exec("INSERT INTO User(firstname, lastname, birthDate) VALUES ("
        + lastname
        + firstname
        + birthDate
        + ")")
        ) qWarning() << "ERROR: " << this->database->lastError().text();
    this->close();
}


