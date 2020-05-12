#ifndef IMPORT_H
#define IMPORT_H

#include <QWidget>

// Boite de dialogue avec l'explorateur de fichiers
#include <QFileDialog>

// Inclusion des classes des éléments fixes
#include <QGroupBox>
#include <QRadioButton>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QGraphicsView>


#include "user.h"

namespace Ui {
class Import;
}

class Import : public QWidget
{
	Q_OBJECT

public:
	Import(QWidget *parent = Q_NULLPTR);
	~Import();

	void InitImport(User* user, QSqlQuery* query);

private slots:
	// Slot du bouton de sélection d'image
	void on_imageButton_clicked();
	// Slot du bouton de sélection de son
	void on_soundButton_clicked();

	// Slot du boutonde validation
	void on_validationButton_clicked();
	// Slot du bouton d'annulation
	void on_cancelButton_clicked();

private:
	Ui::Import* ui;

	// Utilisateur concerné par l'importation de contenu
	User* user;

	// Requête vers la base de données
	QSqlQuery* query;

	// Positionne les éléments fixes
	void SetDisplayGeometry();

	// Eléments fixes de l'interface
	QGroupBox* categoryGroupBox;
	QGroupBox* pictoGroupBox;
	QRadioButton* firstCategoryRadioButton;
	QRadioButton* secondCategoryRadioButton;
	QRadioButton* thirdCategoryRadioButton;
	QRadioButton* fourthCategoryRadioButton;
	QGraphicsView* topBorder;
	QLabel* pictoPreviewLabel;
	QLabel* defLabel;
	QLabel* pictoLabel;
	QLabel* soundLabel;
	QLineEdit* definitionEdit;
	QLineEdit* urlImageEdit;
	QLineEdit* urlSoundEdit;
	QPushButton* urlImageButton;
	QPushButton* urlSoundButton;
	QPushButton* validateButton;
	QPushButton* cancelButton;
};

#endif //IMPORT_H
