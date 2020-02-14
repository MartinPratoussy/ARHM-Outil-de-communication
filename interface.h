#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QLoggingCategory>
#include <QPushButton>
#include <QApplication>
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
    void InitInterface(User * user);
    ~Interface();

    // Annule l'action précédente
    void Cancel();

    // Getter de l'utlisateur de l'interface
    User * GetUser();

    // Affiche le menu principal
    void ShowMainMenu();

    // Surcharge de l'opérateur d'affection
    Interface & operator=(const Interface & interface);

private slots:
    void on_jeVeuxButton_clicked();

    void on_jeSuisButton_clicked();

    void on_objetsButton_clicked();

    void on_personnesButton_clicked();

private:
    Ui::Interface *ui;

    // Phrase créée par l'utilisateur
    QString * sentence[3];

    // Nombre d'étapes de la phrase effectuées
    int numLevel = 0;

    // Utilisateur de l'interface
    User * user;

    // Boutons de l'interface principale
    QPushButton * button[4];
};

#endif // INTERFACE_H
