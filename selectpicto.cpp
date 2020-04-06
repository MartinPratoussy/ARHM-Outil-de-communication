#include "selectpicto.h"
#include "ui_selectpicto.h"


SelectPicto::SelectPicto(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

SelectPicto::~SelectPicto()
{
}

void SelectPicto::DisplayPictograms(QString category)
{
	for (int i = 0; i < this->user->getNbPicto; i++)
	{
		if (this->user->getPicto[i].getCategory() == category) {
			this->user->getPicto[i]->getPicture();
		}
	}
}
