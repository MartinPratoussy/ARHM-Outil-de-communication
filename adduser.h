#ifndef ADDUSER_H
#define ADDUSER_H

#include "addedituser.h"

class AddUser : public AddEditUser
{
public:
    // Initialise l'interface d'ajout d'utilisateur
    AddUser(QSqlDatabase * database, QSqlQuery* query);

private slots:
    // Enregistrement de informations dans la base de données 
    void on_validationButton_clicked();
};

#endif ADDUSER_H