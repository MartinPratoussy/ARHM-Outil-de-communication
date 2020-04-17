#include "adduser.h"
#include "ui_addedituser.h"

AddUser::AddUser(QSqlDatabase* database, QSqlQuery* query)
{
	ui->deleteButton->hide();
	this->database = database;
	this->query = query;
	connect(ui->validationButton, SIGNAL(released()), this, SLOT(on_validationButton_clicked()));
}

void AddUser::Validate()
{
	// Vérifie si les champs d'édition sont bien tous rempli par l'utilisateur
	if (ui->firstnameEdit->toPlainText().isEmpty()
		|| ui->lastnameEdit->toPlainText().isEmpty()
		|| ui->birthDateEdit->date().toString().isEmpty()
		|| ui->category1Edit->text().isEmpty()
		|| ui->category2Edit->text().isEmpty()
		|| ui->category3Edit->text().isEmpty()
		|| ui->category4Edit->text().isEmpty()
		) return;

	// Ajout el nouvel utlisateur dans la base de données
	if (!this->query->exec("INSERT INTO User(lastname, firstname, birthDate) VALUES ("
		+ ui->lastnameEdit->toPlainText() + ", "
		+ ui->firstnameEdit->toPlainText() + ", "
		+ ui->birthDateEdit->date().toString() + ");"
	)) qWarning() << "ERROR: " << this->database->lastError().text();

	// Met à jour la liste d'utilisateurs avec le nouvel utilisateur
	this->close();
}
