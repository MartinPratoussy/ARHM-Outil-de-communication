#ifndef INTERFACE_H
#define INTERFACE_H

#define NB_MAX_PICTO 100

#include <QWidget>

#include "pictogram.h"
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

    // Annule l'action précédente
    void Cancel();

    // Surcharge de l'opérateur d'affection
    Interface & operator=(const Interface & interface);

private:
    Ui::Interface *ui;

    // Tableau contenant les pictogrammes que l'interface affiche
    Pictogram * pictos[NB_MAX_PICTO];
    // Phrase créée par l'utilisateur
    QString * sentence[3];
    // Nombre d'étapes de la phrase effectuées
    int numLevel = 0;
    // Nombre de pictogrammes sur l'interface
    int nbPicto = 0;
};

#endif // INTERFACE_H
