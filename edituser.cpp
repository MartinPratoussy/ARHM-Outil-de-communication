#include "edituser.h"
#include "ui_addedituser.h"

EditUser::EditUser(User* user)
{
	this->user = user;

	// Connecte les boutons � leurs fonctions respectives
	connect(ui->validationButton, SIGNAL(released()), this, SLOT(on_validationButton_clicked()));
	connect(ui->deleteButton, SIGNAL(released()), this, SLOT(on_deleteButton_clicked()));
	connect(ui->cancelButton, SIGNAL(released()), this, SLOT(on_cancelButton_clicked()));
}

void EditUser::InitInterface(QSqlQuery* query)
{
	AddEditUser::query = query;

	// Rempli les champs de texte avec les valeurs actuelles de l'utlisateur
	ui->lastnameEdit->setText(this->user->getLastname());
	ui->firstnameEdit->setText(this->user->getFirstname());
	ui->birthDateEdit->setDate(QDate::fromString(this->user->getBirthDate(), "dd/MM/yyyy"));
}

User* EditUser::GetUser()
{
	return this->user;
}

void EditUser::on_validationButton_clicked()
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

	// Met � jour l'utlisateur dans la base de donn�es
	this->user->setFirstname(ui->firstnameEdit->toPlainText(), query);
	this->user->setLastname(ui->lastnameEdit->toPlainText(), query);
	this->user->setBirthDate(ui->birthDateEdit->date().toString("dd/mm/YYYY"), query);
	QString category[4] = {
		ui->category1Edit->text(),
		ui->category2Edit->text(),
		ui->category3Edit->text(),
		ui->category4Edit->text()
	};
	this->user->setCategory(category);

	// Met � jour la fen�tre principale
	this->parent->update();
	this->close();
}

void EditUser::on_deleteButton_clicked()
{
	// Supprime l'utlisateur de la base de donn�es
	if (!this->query->exec("DELETE FROM User WHERE userId = " + QString::number(this->user->getId()) + ";")) qWarning() << "ERROR: " << database->lastError().text();
	this->parent->update();
	this->close();
}

