#ifndef ADDEDITUSER_H
#define ADDEDITUSER_H

#include <QWidget>

#include <QTextEdit>
#include <QDateEdit>

#include "userlist.h"

namespace Ui {
class AddEditUser;
}

class AddEditUser : public QWidget
{
    Q_OBJECT

public:
    explicit AddEditUser(QWidget *parent = nullptr);
    ~AddEditUser();

    // Ajoute un pictogramme à l'interface de l'utilisateur sélectionné
    void AddPicto(Pictogram picto);

    virtual void Validate(QString lastname, QString firstname, QDate birthDate, QString handicap) const;

private slots:

    void on_validationButton_clicked();

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
    QTextEdit * handicapEdit;
};

#endif // ADDEDITUSER_H
