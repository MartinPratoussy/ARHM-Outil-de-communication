#ifndef USEREDITS_H
#define USEREDITS_H

#include <QWidget>
#include <QTextEdit>
#include <QDateEdit>

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

private slots:
    void on_validationButton_clicked();

private:
    Ui::UserEdits *ui;

    User * user;

    // Bouton de validation
    QPushButton * validation;

    // Zone d'édition des attributs de l'utilisateur
    QTextEdit * lastnameEdit;
    QTextEdit * firstnameEdit;
    QDateEdit * birtDateEdit;
    QTextEdit * handicapEdit;
};

#endif // USEREDITS_H
