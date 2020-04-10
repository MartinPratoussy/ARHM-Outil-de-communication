#pragma once

#include <QWidget>
#include "user.h"

class SelectPicto : public QWidget
{
	Q_OBJECT

public:
	SelectPicto(QWidget *parent = Q_NULLPTR);
	~SelectPicto();

	void DisplayPictograms(QString category);

private:
	Ui::SelectPicto ui;

	User* user;
};
