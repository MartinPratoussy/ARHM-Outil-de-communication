#include "edituser.h"
#include "ui_addedituser.h"

EditUser::EditUser(User* user)
{
	this->user = user;

	// Connecte les boutons � leurs fonctions respectives
	connect(ui->deleteButton, SIGNAL(released()), this, SLOT(on_deleteButton_clicked()));
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
	// V�rifie si les champs d'�dition sont bien tous rempli par l'utilisateur
	if (ui->firstnameEdit->text().isEmpty()
		|| ui->lastnameEdit->text().isEmpty()
		|| ui->birthDateEdit->date().toString().isEmpty()
		|| ui->category1Edit->text().isEmpty()
		|| ui->category2Edit->text().isEmpty()
		|| ui->category3Edit->text().isEmpty()
		|| ui->category4Edit->text().isEmpty()
		) return;

	// Met � jour l'utlisateur dans la base de donn�es
	this->user->SetFirstname(ui->firstnameEdit->text(), query);
	this->user->SetLastname(ui->lastnameEdit->text(), query);
	this->user->SetBirthDate(ui->birthDateEdit->date().toString("dd/MM/yyyy"), query);

	QString category[4] = {
		ui->category1Edit->text(),
		ui->category2Edit->text(),
		ui->category3Edit->text(),
		ui->category4Edit->text()
	};
	this->user->SetCategory(category, query);

	// Met � jour la fen�tre principale
	this->close();
}

void EditUser::on_deleteButton_clicked()
{
	// Supprime l'utlisateur de la base de donn�es
	if (!this->query->exec("DELETE FROM User WHERE userId = " + QString::number(this->user->GetId()) + ";")) qWarning() << "ERROR: user has not been deleted";

	// Supprime les liens de l'utilisateur � ses cat�gories
	if (!this->query->exec("DELETE FROM Category_User WHERE user = " + QString::number(this->user->GetId()) + ";")) qWarning() << "ERROR: link between category and user has not been deleted";
	
	// Supprime les cat�gories de l'utilisateur
	for (int i = 0; i < 4; i++)	
		if (!this->query->exec("DELETE FROM Category WHERE id = " + QString::number(this->user->GetCategory()[i].GetId()) + ";")) qWarning() << "ERROR: category has not been deleted";
	
	this->close();
}
