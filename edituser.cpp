#include "edituser.h"
#include "ui_addedituser.h"

EditUser::EditUser(User* user)
{
	this->user = user;

	// Connecte les boutons à leurs fonctions respectives
	//connect(ui->validationButton, SIGNAL(released()), this, SLOT(on_validationButton_clicked()));
	connect(ui->deleteButton, SIGNAL(released()), this, SLOT(on_deleteButton_clicked()));
	connect(ui->cancelButton, SIGNAL(released()), this, SLOT(on_cancelButton_clicked()));
}

void EditUser::InitInterface(QSqlQuery* query)
{
	AddEditUser::query = query;

	// Rempli les champs de texte avec les valeurs actuelles de l'utlisateur
	ui->lastnameEdit->setText(this->user->GetLastname());
	ui->firstnameEdit->setText(this->user->GetFirstname());
	ui->birthDateEdit->setDate(QDate::fromString(this->user->GetBirthDate(), "dd/MM/yyyy"));
}

User* EditUser::GetUser()
{
	return this->user;
}

void EditUser::Validate()
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

	// Met à jour l'utlisateur dans la base de données
	this->user->SetFirstname(ui->firstnameEdit->toPlainText(), query);
	this->user->SetLastname(ui->lastnameEdit->toPlainText(), query);
	this->user->SetBirthDate(ui->birthDateEdit->date().toString("dd/mm/YYYY"), query);
	QString category[4] = {
		ui->category1Edit->text(),
		ui->category2Edit->text(),
		ui->category3Edit->text(),
		ui->category4Edit->text()
	};
	this->user->SetCategory(category, query);

	// Met à jour la fenêtre principale
	this->close();
}

void EditUser::on_deleteButton_clicked()
{
	// Supprime l'utlisateur de la base de données
	if (!this->query->exec("DELETE FROM User WHERE userId = " + QString::number(this->user->GetId()) + ";")) qWarning() << "ERROR: " << database->lastError().text();
	this->close();
}

