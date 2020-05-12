#ifndef IMPORT_H
#define IMPORT_H

#include <QWidget>

// Boite de dialogue avec l'explorateur de fichiers
#include <QFileDialog>

// Inclusion des classes des �l�ments fixes
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
	// Slot du bouton de s�lection d'image
	void on_imageButton_clicked();
	// Slot du bouton de s�lection de son
	void on_soundButton_clicked();

	// Slot du boutonde validation
	void on_validationButton_clicked();
	// Slot du bouton d'annulation
	void on_cancelButton_clicked();

private:
	Ui::Import* ui;

	// Utilisateur concern� par l'importation de contenu
	User* user;

	// Requ�te vers la base de donn�es
	QSqlQuery* query;

	// Positionne les �l�ments fixes
	void SetDisplayGeometry();

	// El�ments fixes de l'interface
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
