#include "adduser.h"
#include "ui_addedituser.h"

AddUser::AddUser(QSqlDatabase* database, QSqlQuery* query)
{
	this->database = database;
	this->query = query;
	ui->deleteButton->hide();
}

void AddUser::Validate()
{
	// V�rifie si les champs d'�dition sont bien tous rempli par l'utilisateur
	if (ui->firstnameEdit->text().isEmpty()
		|| ui->lastnameEdit->text().isEmpty()
		|| ui->birthDateEdit->date().toString().isEmpty()
		|| ui->category1Edit->text().isEmpty()
		|| ui->category2Edit->text().isEmpty()
		|| ui->category3Edit->text().isEmpty()
		|| ui->category4Edit->text().isEmpty()
		|| ui->photoEdit->text().isEmpty()
		) return;

	// Ajout el nouvel utlisateur dans la base de donn�es
	if (!this->query->exec("INSERT INTO \"User\"(firstname, lastname, birthDate, urlPhoto) VALUES (\""
		+ ui->firstnameEdit->text() + "\", \""
		+ ui->lastnameEdit->text() + "\", \""
		+ ui->birthDateEdit->date().toString("dd/MM/yyyy") + "\", \""
		+ ui->photoEdit->text() + "\");"
	)) qWarning() << "ERROR: new user has not been inserted into the database";
	
	// Ajoute les cat�gories de l'utilisateur dans la base de donn�es
	InsertCategories(ui->category1Edit->text());
	InsertCategories(ui->category2Edit->text());
	InsertCategories(ui->category3Edit->text());
	InsertCategories(ui->category4Edit->text());

	// S�lection du dernier utilisateur dans la base de donn�es
	int idUser;
	if (!this->query->exec("SELECT idUser FROM \"User\" ORDER BY idUser DESC LIMIT 1;")) qWarning() << "ERROR: last user has not been found";
	while (this->query->next()) idUser = this->query->value(0).toInt();

	// S�lection des 4 derni�res cat�gories dans la base de donn�es
	int categories[4];
	for (int i = 0; i < 4; i++)
	{
		if (!this->query->exec("SELECT idCategory FROM \"Category\" ORDER BY idCategory DESC LIMIT " + QString::number(i + 1) + ";")) qWarning() << "ERROR: last category has not been found";
		while (this->query->next()) categories[i] = this->query->value(0).toInt();
	}

	// Ajoute les liens entre l'utilisateur et ses cat�gories dans la base de donn�es
	for (int i = 3; i >= 0; i--)
	{
		if (!query->exec("INSERT INTO \"Category_User\"(category, user) VALUES ("
			+ QString::number(categories[i]) + ","
			+ QString::number(idUser) + ");")
			) qWarning() << "ERROR: category " + QString::number(idUser) + " has not been linked with user" + this->query->value(0).toInt();
	}

	// Met � jour la liste d'utilisateurs avec le nouvel utilisateur
	emit UpdateUsers();
	this->close();
	delete this;
}

void AddUser::InsertCategories(QString category)
{
	if (!this->query->exec("INSERT INTO \"Category\"(text) VALUES (\"" + category + "\");"
	)) qWarning() << "ERROR: new category has not been inserted into the database";
}

void AddUser::SetPhoto()
{
	if (!this->isActive) return;

	// R�cup�re le chemin d'acc�s dans l'explorateur de fichiers
	QFileDialog* fileDialog = new QFileDialog();
	QString urlPhoto = fileDialog->getOpenFileUrl().url();
	ui->photoEdit->setText(urlPhoto);
	ui->icon->setPixmap(QPixmap(ui->photoEdit->text()));
	
	this->isActive = false;
}
