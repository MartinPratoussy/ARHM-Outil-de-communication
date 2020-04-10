#ifndef MAINIMPORT_H
#define MAINIMPORT_H

#include <QMainWindow>
// Format de cha�ne de caract�re de Qt
#include <QString>
// Format de date de Qt
#include <QDate>
// Contr�le les flux d'entr�e/sortie
#include <iostream>

// Permet d'acc�der � des bases de donn�es sp�cifiques
#include <QSqlDriver>
// Permet de charger une base de donn�es
#include <QSqlDatabase>
// Permet de g�n�rer des requ�tes SQL en direction d'une base de donn�es
#include <QSqlQuery>
// Permet de g�n�rer une erreur lors d'un probl�me dans la base de donnn�es
#include <QSqlError>
QT_BEGIN_NAMESPACE
namespace Ui { class MainImport; }
QT_END_NAMESPACE

class MainImport : public QMainWindow
{
    Q_OBJECT

public:
    MainImport(QWidget *parent = nullptr);
    ~MainImport();

private slots:
    void on_BpValide_clicked();

private:
    Ui::MainImport *ui;
    //concte a la Db 
    void ConnectToDatabase();
    //pointe sur la basse de donn�es
    QSqlDatabase* database;
};
#endif // MAINIMPORT_H
