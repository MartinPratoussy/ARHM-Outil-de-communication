#ifndef ADDUSER_H
#define ADDUSER_H

#include "addedituser.h"

class AddUser : public AddEditUser
{
public:
    AddUser();

    // Initialise l'interface d'ajout d'utilisateur
    void InitInterface(QSqlDatabase * database, QSqlQuery* query);

    // Enregistrement de informations dans la base de données 
    void Validate(QString lastname, QString firstname, QString birthDate);

private slots:
    void on_validationButton_clicked();
};

#endif ADDUSER_H