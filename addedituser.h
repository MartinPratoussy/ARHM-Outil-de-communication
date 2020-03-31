#ifndef ADDEDITUSER_H
#define ADDEDITUSER_H

#include <QWidget>

#include <QTextEdit>
#include <QDateEdit>

#include "interface.h"

namespace Ui {
class AddEditUser;
}

class AddEditUser : public QWidget
{
    Q_OBJECT

public:
    explicit AddEditUser(QWidget *parent = nullptr);
    virtual ~AddEditUser() = 0;

protected:
    Ui::AddEditUser *ui;

    // Pointeur de la base de données
    QSqlDatabase* database;

    // Pointeur de la requête SQL
    QSqlQuery * query;

    // Bouton de validation
    QPushButton * validation;

    // Zone d'édition des attributs de l'utilisateur
    QTextEdit * lastnameEdit;
    QTextEdit * firstnameEdit;
    QDateEdit * birtDateEdit;
};

#endif // ADDEDITUSER_H
