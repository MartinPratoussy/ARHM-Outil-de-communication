#ifndef SELECTPICTO_H
#define SELECTPICTO_H

#include <QWidget>
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

	void DisplayPictograms(QString category);

private:
	Ui::SelectPicto *ui;

	User* user;
};

#endif