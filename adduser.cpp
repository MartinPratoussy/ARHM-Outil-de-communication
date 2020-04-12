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
	// V�rifie si les champs d'�dition sont bien tous rempli par l'utilisateur
	if (ui->firstnameEdit->toPlainText().isEmpty()
		|| ui->lastnameEdit->toPlainText().isEmpty()
		|| ui->birthDateEdit->date().toString().isEmpty()
		|| ui->category1Edit->text().isEmpty()
		|| ui->category2Edit->text().isEmpty()
		|| ui->category3Edit->text().isEmpty()
		|| ui->category4Edit->text().isEmpty()
		) return;

	// Ajout el nouvel utlisateur dans la base de donn�es
	if (!this->query->exec("INSERT INTO User(lastname, firstname, birthDate) VALUES ("
		+ ui->lastnameEdit->toPlainText() + ", "
		+ ui->firstnameEdit->toPlainText() + ", "
		+ ui->birthDateEdit->date().toString() + ");"
	)) qWarning() << "ERROR: " << this->database->lastError().text();

	// Met � jour la liste d'utilisateurs avec le nouvel utilisateur
	this->parent->update();
	this->close();
}
