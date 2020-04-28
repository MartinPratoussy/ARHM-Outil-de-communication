#include "mainimport.h"
#include "ui_mainimport.h"

MainImport::MainImport(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainImport)
{
    ui->setupUi(this);
	connectToDatabase();
	
}

MainImport::~MainImport()
{
    delete ui;
}

void MainImport::connectToDatabase()
{
	// Initialise la base de données à utiliser
	database = new QSqlDatabase();
	const QString DRIVER("QSQLITE");
	if (QSqlDatabase::isDriverAvailable(DRIVER))
	{
		// Défini le SGBD utilisé
		*database = QSqlDatabase::addDatabase(DRIVER);
		// Se connecte à la base de données à utiliser
		database->setDatabaseName("database.db");
		// Ouvre la base de données
		if(!database->open())qWarning() << "ERROR: " << database->lastError().text();
	}
    else qWarning() << "ERROR: " << database->lastError().text();
	query = new QSqlQuery(*database);
	
}

void MainImport::returnCategories()
{

	ui->rBCat1->setText("Object");
	ui->rBCat2->setText("Persone");
	ui->rBCat3->setText("Action");
	ui->rBCat4->setText("Interaction");
}

void MainImport::on_bPValide_clicked()
{
	int idPicto(NULL);
	int *idCategory(NULL);
	
	nom = ui->nomSql->toPlainText();
	enLecture = ui->lectureSql->toPlainText();
	image = ui->imageSql->toPlainText();
	/*************************************[SQL]*************************************/
	
	//enregistre dans la Basse de Donnée le pictograme 
	if (!query->exec("INSERT INTO Pictogram (definition,urlSound,urlImage)"
		"VALUES ('" + nom + "','" + enLecture + "','" + image +"')")) qWarning() << "ERROR: " << database->lastError().text();

	//Récuper le dernier pictograme enregister dans la Base de Donnée
	if (!query->exec("SELECT idPictogram FROM Pictogram ORDER BY idPictogram DESC LIMIT 1;")) qWarning() << "ERROR: " << database->lastError().text();
	while (this->query->next()) idPicto = this->query->value(0).toInt();
	
	if (ui->rBCat1->isChecked()) {
		/*if (!query->exec("INSERT INTO Pictogram_Category (pictogram,category)" 
			"VALUES ('"+idPicto+"','6')")) qWarning() << "ERROR: " << database->lastError().text();*/
	} 
	else if (ui->rBCat2->isChecked()) {

	}
	else if (ui->rBCat3->isChecked()) {

	}
	else if (ui->rBCat4->isChecked()) {

	}

	
	
}


void MainImport::on_parBP_clicked()
{
	//Ouvre une boite de dialoge + récup URL du ficher Selctioner 
	ui->imageSql->setText(imageDial.getOpenFileUrl().url());
}
