#include "mainimport.h"
#include "ui_mainimport.h"

MainImport::MainImport(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainImport)
{
    ui->setupUi(this);
}

MainImport::~MainImport()
{
    delete ui;
}

void MainImport::ConnectToDatabase()
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
        /*if (!database->open()) qWarning() << "ERROR: " << database->lastError().text();*/
	}
    /*else qWarning() << "ERROR: " << database->lastError().text();*/
}

void MainImport::on_BpValide_clicked()
{

}
