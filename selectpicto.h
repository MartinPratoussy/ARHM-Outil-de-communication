#ifndef SELECTPICTO_H
#define SELECTPICTO_H

#include <QWidget>

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

	void DisplayPictograms(Category category);

	void ChosePicto();

private slots:
	// Appui sur un pictogramme
	void on_pictoButton_clicked(int numPicto);

private:
	Ui::SelectPicto *ui;

	Category* category;

	QList<QPushButton*> pictoChose;
};

#endif