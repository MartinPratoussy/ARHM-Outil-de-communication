#ifndef MAINIMPORT_H
#define MAINIMPORT_H

#include <QMainWindow>
// Format de chaène de caractêre de Qt
#include <QString>
// Format de date de Qt
#include <QDate>
// Contr�le les flux d'entrée/sortie
#include <iostream>

#include <qdebug>

// Permet d'accèder à des bases de données spécifiques
#include <QSqlDriver>
// Permet de charger une base de donn�es
#include <QSqlDatabase>
// Permet de génèrer des requêtes SQL en direction d'une base de donn�es
#include <QSqlQuery>
// Permet de génèrer une erreur lors d'un probl�me dans la base de donnn�es
#include <QSqlError>
// Permet d'ajouter une interface de selction de fichier
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainImport; }
QT_END_NAMESPACE

class MainImport : public QMainWindow
{
	Q_OBJECT

public:
	MainImport(QWidget* parent = nullptr);
	~MainImport();

private slots:

	void on_bPValide_clicked();

    void on_parBP_clicked();

private:
	Ui::MainImport* ui;
	
	//concte a la Db 
	void connectToDatabase();
	
	//intialise les catégory
	void initCategories(QString cat[4],int catId[4]);

	//pointe sur la basse de données
	QSqlDatabase* database;
	QSqlQuery* query;
	
	//boite de dialog de sélection de fichier
	QFileDialog imageDial;
	
	QString nom = NULL;
	QString enLecture = NULL;
	QString image = NULL;
	QString category = NULL;

    // contien les réference des catégorys de l'utlisateur
	int idCategory[4];
};
#endif // MAINIMPORT_H
