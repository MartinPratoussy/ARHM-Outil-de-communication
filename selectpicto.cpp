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

void SelectPicto::InitiateSelectPicto(Category category)
{
	this->category = category;

	SetDisplayGeometry();
	DisplayPictograms();
}

void SelectPicto::SetDisplayGeometry()
{
	////////////////////////////////////////////////////////////////////////////////////
	// Bug avec le designer donc les composants fixes doivent être déclarés à la main //
	////////////////////////////////////////////////////////////////////////////////////

	// Bordure supérieure d l'interface où est affichée la catégorie
	topBorder = new QGraphicsView(this);
	topBorder->setGeometry(QRect(0, 0, 1921, 131));
	topBorder->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 0);"));

	// Zone de scrolling
	scrollArea = new QScrollArea(this);
	scrollArea->setGeometry(QRect(0, 130, 1921, 951));
	scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	scrollArea->setWidgetResizable(true);

	// Initialisation de la taille de la fenêtre
	this->width = this->scrollArea->width();
	this->height = this->scrollArea->height();
	
	// Initialisation de la taille du conteneur
	content = new QWidget();
	content->setGeometry(QRect(0, 0, 1919, 949));
	scrollArea->setWidget(content);
	this->scrollArea->widget()->setMinimumSize(this->width, this->height);
	this->scrollArea->widget()->setGeometry(this->scrollArea->x(), this->scrollArea->y(), this->width, this->height + this->height * ((this->nbPicto + 1) / NB_PICTO_DISPLAYABLE));

	// Label affichant le nom de la catégorie dans laquelle on se trouve
	selectionLabel = new QLabel(this);
	selectionLabel->setGeometry(QRect(656, 22, 751, 81));
	QFont font;
	font.setPointSize(28);
	selectionLabel->setFont(font);
	selectionLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
	selectionLabel->setAlignment(Qt::AlignCenter);
	this->selectionLabel->setText(this->category.GetText());
}

void SelectPicto::DisplayPictograms()
{
	int numPicto = 0;
	for each (Pictogram* picto in this->category.GetPicto()) 
	{
		this->pictoChose[numPicto]->setIcon(picto->GetPicture());
		numPicto++;
	}
	this->nbPicto = numPicto;


	// Placement des pictogrammes suivant le même algorithme que le placement des utilisateurs dans userlist.cpp
	int posX, posY, sizeX, sizeY;

	for (int numPictoY = 0; numPictoY < 2 * nbPicto / NB_PICTO_DISPLAYABLE; numPictoY++)
	{
		for (int numPictoX = 0; numPictoX < NB_PICTO_DISPLAYABLE / 2; numPictoX++)
		{
			numPicto = numPictoX + (NB_PICTO_DISPLAYABLE / 2) * numPictoY;

			posX = this->width / (WIDTH_PIECES * 4) + (NB_PICTO_DISPLAYABLE / 2) * numPictoX * this->width / (WIDTH_PIECES * 4);
			posY = this->height / (HEIGHT_PIECES * 4) + (NB_PICTO_DISPLAYABLE / 2) * numPictoY * this->height / (HEIGHT_PIECES * 4);
			sizeX = this->width * 3 / (WIDTH_PIECES * 4);
			sizeY = this->height * 3 / (HEIGHT_PIECES * 4);

			this->pictoChose[numPicto]->setGeometry(posX, posY, sizeX, sizeY);
		}
	}

	for (int i = 0; i < nbPicto % (NB_PICTO_DISPLAYABLE / 2); i++)
	{
		numPicto = i + (nbPicto / (NB_PICTO_DISPLAYABLE / 2)) * (NB_PICTO_DISPLAYABLE / 2);

		posX = this->width / (WIDTH_PIECES * 4) + (NB_PICTO_DISPLAYABLE / 2) * i * this->width / (WIDTH_PIECES * 4);
		posY = this->height / (HEIGHT_PIECES * 4) + (NB_PICTO_DISPLAYABLE / 2) * (2 * nbPicto / NB_PICTO_DISPLAYABLE) * (this->height / (HEIGHT_PIECES * 4));
		sizeX = this->width * 3 / (WIDTH_PIECES * 4);
		sizeY = this->height * 3 / (HEIGHT_PIECES * 4);

		this->pictoChose[numPicto]->setGeometry(posX, posY, sizeX, sizeY);
	}

	numPicto = 0;
	for each (QPushButton * button in this->pictoChose) {
		connect(button, &QPushButton::released, [=] { 
			on_pictoButton_clicked(numPicto); 
		});
		button->show();
		numPicto++;
	}
}

void SelectPicto::on_pictoButton_clicked(int numPicto)
{
	this->category.GetPicto()[numPicto]->GetSound().PlaySound();
	emit PictoSelected(this->category.GetPicto()[numPicto]);
	this->close();
}