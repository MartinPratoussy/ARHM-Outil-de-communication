#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>

// Boutons dynamiques non créés depuis le designer
#include <QPushButton>

// Fournit les informations de l'écran
#include <QDesktopWidget>

#include "user.h"

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

    // Affiche le menu principal
    void ShowMainMenu();

    // Surcharge de l'opérateur d'affection
    Interface & operator=(const Interface & interface);

public slots :
    void addWordToSentence(Pictogram * word);

private slots:
    void on_button1_clicked();

    void on_button2_clicked();

    void on_button3_clicked();

    void on_button4_clicked();

private:
    Ui::Interface *ui;

    // Utilisateur de l'interface
    User * user;

    // Phrase créée par l'utilisateur
    QList<QString> sentence[3];

    // Boutons de l'interface principale
    QPushButton * button[4];

    // Bouton d'annulation du drenier mot de la phrase
    QPushButton * cancelButton;

    // Interfaces de séléction des pictogrammes
    SelectPicto * selection[4];
};

#endif // INTERFACE_H
