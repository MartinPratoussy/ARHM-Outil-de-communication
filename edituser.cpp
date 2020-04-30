#include "edituser.h"
#include "ui_addedituser.h"

EditUser::EditUser(User* user)
{
	this->user = user;

	// Connecte les boutons à leurs fonctions respectives
	connect(ui->deleteButton, SIGNAL(released()), this, SLOT(on_deleteButton_clicked()));
}

void EditUser::InitInterface(QSqlQuery* query)
{
	this->query = query;

	// Rempli les champs de texte avec les valeurs actuelles de l'utlisateur
	ui->lastnameEdit->setText(this->user->GetLastname());
	ui->firstnameEdit->setText(this->user->GetFirstname());
	ui->birthDateEdit->setDate(QDate::fromString(this->user->GetBirthDate(), "dd/MM/yyyy"));
	ui->category1Edit->setText(this->user->GetCategory()[0].GetText());
	ui->category2Edit->setText(this->user->GetCategory()[1].GetText());
	ui->category3Edit->setText(this->user->GetCategory()[2].GetText());
	ui->category4Edit->setText(this->user->GetCategory()[3].GetText());
	if (!this->query->exec("SELECT urlPhoto FROM User WHERE idUser = " + QString::number(this->user->GetId()) + ";")) qWarning() << "ERROR: No urlPhoto found for user " + this->user->GetId();
	while(this->query->next()) ui->photoEdit->setText(this->query->value(0).toString());
	ui->icon->setPixmap(ui->photoEdit->text());
}

void EditUser::SetPhoto()
{
	if (!this->isActive) return;

	// Récupère le chemin d'accès dans l'eexplorateur de fichiers
	QFileDialog* fileDialog = new QFileDialog();
	QString urlPhoto = fileDialog->getOpenFileUrl().url();
	ui->photoEdit->setText(urlPhoto);

	this->isActive = false;
}

User* EditUser::GetUser()
{
	return this->user;
}

void EditUser::Validate()
{
	// Vérifie si les champs d'édition sont bien tous rempli par l'utilisateur
	if (ui->firstnameEdit->text().isEmpty()
		|| ui->lastnameEdit->text().isEmpty()
		|| ui->birthDateEdit->date().toString().isEmpty()
		|| ui->category1Edit->text().isEmpty()
		|| ui->category2Edit->text().isEmpty()
		|| ui->category3Edit->text().isEmpty()
		|| ui->category4Edit->text().isEmpty()
		|| ui->photoEdit->text().isEmpty()
		) return;

	// Met à jour l'utlisateur dans la base de données
	this->user->SetFirstname(ui->firstnameEdit->text(), this->query);
	this->user->SetLastname(ui->lastnameEdit->text(), this->query);
	this->user->SetBirthDate(ui->birthDateEdit->date().toString("dd/MM/yyyy"), this->query);
	this->user->SetPhoto(ui->photoEdit->text(), this->query);

	QString category[4] = {
		ui->category1Edit->text(),
		ui->category2Edit->text(),
		ui->category3Edit->text(),
		ui->category4Edit->text()
	};
	this->user->SetCategory(category, this->query);

	// Met à jour la fenêtre principale
	this->close();
}

void EditUser::on_deleteButton_clicked()
{
	// Supprime l'utlisateur de la base de données
	if (!this->query->exec("DELETE FROM User WHERE userId = " + QString::number(this->user->GetId()) + ";")) qWarning() << "ERROR: user has not been deleted";

	// Supprime les liens de l'utilisateur à ses catégories
	if (!this->query->exec("DELETE FROM Category_User WHERE user = " + QString::number(this->user->GetId()) + ";")) qWarning() << "ERROR: link between category and user has not been deleted";
	
	// Supprime les catégories de l'utilisateur
	for (int i = 0; i < 4; i++)	
		if (!this->query->exec("DELETE FROM Category WHERE id = " + QString::number(this->user->GetCategory()[i].GetId()) + ";")) qWarning() << "ERROR: category has not been deleted";
	
	this->close();
}
