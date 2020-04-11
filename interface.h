#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>

// Boutons dynamiques non créés depuis le designer
#include <QPushButton>

// Fournit les informations de l'écran
#include <QDesktopWidget>

#include "selectpicto.h"

namespace Ui {
class Interface;
}

class Interface : public QWidget
{
    Q_OBJECT

public:
    explicit Interface(QWidget *parent = nullptr);
    ~Interface();

    // Initialise l'interface en fonction de l'utilisateur concerné
    void InitInterface(User * user);

    // Annule l'action précédente
    void Cancel();

    // Getter de l'utlisateur de l'interface
    User * GetUser();

    // Surcharge de l'opérateur d'affection
    Interface & operator=(const Interface & interface);

public slots :
    // Ajoute un mot à la phrase
    void addWordToSentence(Pictogram * word);

    // La synthèse vocale lit la phrase
    void readSentence();

private slots:
    void on_firstCategoryButton_clicked();

    void on_secondCategoryButton_clicked();

    void on_thirdCategoryButton_clicked();

    void on_fourthCategoryButton_clicked();

private:
    Ui::Interface *ui;

    // Utilisateur de l'interface
    User * user;

    // Phrase créée par l'utilisateur
    QList<Pictogram*> sentence;

    // Interfaces de séléction des pictogrammes
    SelectPicto * selection[4];
};

#endif // INTERFACE_H
