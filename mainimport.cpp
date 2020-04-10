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
	// Initialise la base de donn�es � utiliser
	database = new QSqlDatabase();
	const QString DRIVER("QSQLITE");
	if (QSqlDatabase::isDriverAvailable(DRIVER))
	{
		// D�fini le SGBD utilis�
		*database = QSqlDatabase::addDatabase(DRIVER);
		// Se connecte � la base de donn�es � utiliser
		database->setDatabaseName("database.db");
		// Ouvre la base de donn�es
        /*if (!database->open()) qWarning() << "ERROR: " << database->lastError().text();*/
	}
    /*else qWarning() << "ERROR: " << database->lastError().text();*/
}

void MainImport::on_BpValide_clicked()
{

}
