#include "adduser.h"
#include "ui_addedituser.h"

AddUser::AddUser(QSqlDatabase* database, QSqlQuery* query)
{
	this->database = database;
	this->query = query;
	connect(ui->validationButton, SIGNAL(released()), this, SLOT(on_validationButton_clicked()));
	this->parentWidget();
}

void AddUser::on_validationButton_clicked()
{
	if (!this->query->exec("INSERT INTO User(lastname, firstname, birthDate) VALUES ("
		+ ui->lastnameEdit->toPlainText() + ", "
		+ ui->firstnameEdit->toPlainText() + ", "
		+ ui->birthDateEdit->date().toString() + ");"
	)) qWarning() << "ERROR: " << this->database->lastError().text();
	this->parent->update();
	this->close();
}
