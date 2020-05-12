#ifndef SELECTPICTO_H
#define SELECTPICTO_H

#define WIDTH_PIECES 17
#define HEIGHT_PIECES 9
#define NB_PICTO_DISPLAYABLE 16

#include <QWidget>

#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>

#include <QPushButton>

#include "user.h"

namespace Ui {
class SelectPicto;
}

class SelectPicto : public QWidget
{
	Q_OBJECT

public:
	SelectPicto(QWidget *parent = Q_NULLPTR);
	~SelectPicto();

	void InitiateSelectPicto(Category category);

	void SetDisplayGeometry();

	void DisplayPictograms();

private slots:
	// Appui sur un pictogramme
	void on_pictoButton_clicked(int numPicto);

signals:
	// Envoi le pictogramme choisi dans la phrase
	void PictoSelected(Pictogram* word);

private:
	Ui::SelectPicto *ui;

	// Categorie sélectionnée
	Category category;

	// Liste des boutons de pictogrammes
	QList<QPushButton*> pictoChose;

	// Taille de la fenêtre
	int width, height;

	// Nombre de pictogrammes à afficher
	int nbPicto;

	// Objets de l'interface fixe
	QGraphicsView* topBorder;
	QScrollArea* scrollArea;
	QWidget* content;
	QLabel* selectionLabel;

};

#endif