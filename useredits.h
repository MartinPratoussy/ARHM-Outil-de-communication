#ifndef USEREDITS_H
#define USEREDITS_H

#include <QWidget>
#include <iostream>

#include "interface.h"

namespace Ui {
class UserEdits;
}

class UserEdits : public QWidget
{
    Q_OBJECT

public:
    explicit UserEdits(QWidget *parent = nullptr);
    ~UserEdits();

    // Affiche l'interface personnalisée de l'utlisateur
    void DisplayInterface();
    // Edite les différents attributs de l'utlisateur
    void EditFirstname(QString firstname);
    void EditLastname(QString lastname);
    void EditBirthDate(QDate birthDate);
    void EditHandicap(QString handicap);
    // Ajoute un pictogramme à l'interface de l'utilisateur sélectionné
    void AddPicto(Pictogram picto);
    // Supprime l'utilisateur
    void DeleteUser();

private:
    Ui::UserEdits *ui;

    User * user;
};

#endif // USEREDITS_H
