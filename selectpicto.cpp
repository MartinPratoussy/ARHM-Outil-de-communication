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
	int numPicto = 0;
	for each (Pictogram* picto in category.GetPicto()) 
	{
		this->pictoChose[numPicto]->setGeometry(200, 0, 100, 100);
		this->pictoChose[numPicto]->setIcon(picto->GetPicture());
		this->pictoChose[numPicto]->show();
		numPicto++;
	}
	numPicto = 0;
	for each (QPushButton * button in this->pictoChose)
	{
		connect(button, SIGNAL(released()), this, SLOT(on_pictoButton_clicked(numPicto)));
	}
}

void SelectPicto::ChosePicto()
{

}

void SelectPicto::on_pictoButton_clicked(int numPicto)
{
	this->category->GetPicto()[numPicto]->GetSound().PlaySound();
	this->close();
}