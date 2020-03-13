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

    // Initialise l'interface en fonction de l'utilisateur concerné
    void InitUserEditsInterface(User * user, QSqlQuery * query);

    // Getter de l'utilisateur concerné par l'édition
    User * GetUser();

    // Edite les différents attributs de l'utlisateur
    void EditFirstname(QString firstname);
    void EditLastname(QString lastname);
    void EditBirthDate(QDate birthDate);
    void EditHandicap(QString handicap);

    // Ajoute un pictogramme à l'interface de l'utilisateur sélectionné
    void AddPicto(Pictogram picto);

    // Supprime l'utilisateur
    void DeleteUser();

private slots:
    void on_validationButton_clicked();

private:
    Ui::AddEditUser *ui;

    User * user;

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
