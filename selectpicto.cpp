#include "selectpicto.h"
#include "ui_selectpicto.h"


SelectPicto::SelectPicto(QWidget *parent)
	: QWidget(parent)
{
	ui->setupUi(this);
}

SelectPicto::~SelectPicto()
{
}

void SelectPicto::DisplayPictograms(Category category)
{
	for each (Pictogram * picto in category)
}
