#include "interface.h"
#include "ui_interface.h"


Interface::Interface(QWidget* parent) :
	QWidget(parent),
	ui(new Ui::Interface)
{
	ui->setupUi(this);
}

void Interface::InitInterface(User* user)
{
	this->user = user;

	ui->progressBar->setValue(0);

	// Initialisation du texte des boutons
	ui->firstCategoryButton->setText(this->user->GetCategory()[0].GetText());
	ui->secondCategoryButton->setText(this->user->GetCategory()[1].GetText());
	ui->thirdCategoryButton->setText(this->user->GetCategory()[2].GetText());
	ui->fourthCategoryButton->setText(this->user->GetCategory()[3].GetText());

	// Connexion des boutons à leur méthode lors du clic
	connect(ui->firstCategoryButton, SIGNAL(released()), this, SLOT(on_firstCategoryButton_clicked()));
	connect(ui->secondCategoryButton, SIGNAL(released()), this, SLOT(on_secondCategoryButton_clicked()));
	connect(ui->thirdCategoryButton, SIGNAL(released()), this, SLOT(on_thirdCategoryButton_clicked()));
	connect(ui->fourthCategoryButton, SIGNAL(released()), this, SLOT(on_fourthCategoryButton_clicked()));

	// Connexion du bouton de retour arrière à la méthode correspondante
	connect(ui->backButton, SIGNAL(released()), this, SLOT(Cancel()));

	// Connexion du bouton de lecture à la méthode correspondante
	connect(ui->readButton, SIGNAL(released()), this, SLOT(ReadSentence()));
}

Interface::~Interface()
{
	delete ui;
}

void Interface::Cancel()
{
	// Vérifie si la phrase est vide et si non, le dernier mot est supprimé
	if (!this->sentence.isEmpty()) this->sentence.removeLast();
	ui->progressBar->setValue(100 * sentence.count() / 3);
	this->update();
}

User* Interface::GetUser()
{
	return this->user;
}

Interface& Interface::operator=(const Interface& interface)
{
	this->sentence = interface.sentence;
	return *this;
}

void Interface::AddWordToSentence(Pictogram* word)
{
	// Ajoute un mot à la phrase si elle n'est pas complète
	if (this->sentence.size() < 3)
	{
		this->sentence.append(word);
		// Selon la taille de la phrase, le bon QLabel est rempli
		switch (this->sentence.size())
		{
		case 0: ui->firstPictoLabel->setText(word->GetDefinition()); ui->progressBar->setValue(25);  break;
		case 1: ui->secondPictoLabel->setText(word->GetDefinition()); ui->progressBar->setValue(50); break;
		case 2: ui->thirdPictoLabel->setText(word->GetDefinition()); ui->progressBar->setValue(95); break;
		default: break;
		}
	}

	this->isFirstActive = false;
	this->isSecondActive = false;
	this->isThirdActive = false;
	this->isFourthActive = false;
}

void Interface::ReadSentence()
{
	for each (Pictogram * word in this->sentence) word->GetSound().PlaySound();
}

void Interface::on_firstCategoryButton_clicked()
{
	if (this->isFirstActive == false)
	{
		this->selection[0] = new SelectPicto();
		this->selection[0]->InitiateSelectPicto(this->user->GetCategory()[0]);
		connect(this->selection[0], SIGNAL(this->selection[0].PictoSelected(Pictogram*)), this, SLOT(AddWordToSentence(Pictogram*)));

		Sound m_speech(ui->firstCategoryButton->text());
		m_speech.PlaySound();
		this->selection[0]->show();

		this->isFirstActive = true;
	}
}

void Interface::on_secondCategoryButton_clicked()
{
	if (this->isSecondActive == false)
	{
		this->selection[1] = new SelectPicto();
		this->selection[1]->InitiateSelectPicto(this->user->GetCategory()[1]);
		connect(this->selection[1], SIGNAL(this->selection[1].PictoSelected(Pictogram*)), this, SLOT(AddWordToSentence(Pictogram*)));

		Sound m_speech(ui->secondCategoryButton->text());
		m_speech.PlaySound();
		this->selection[1]->show();

		this->isSecondActive == true;
	}
}

void Interface::on_thirdCategoryButton_clicked()
{
	if (this->isThirdActive == false)
	{
		this->selection[2] = new SelectPicto();
		this->selection[2]->InitiateSelectPicto(this->user->GetCategory()[2]);
		connect(this->selection[2], SIGNAL(this->selection[2].PictoSelected(Pictogram*)), this, SLOT(AddWordToSentence(Pictogram*)));

		Sound m_speech(ui->thirdCategoryButton->text());
		m_speech.PlaySound();
		this->selection[2]->show();

		this->isThirdActive = true;
	}
}

void Interface::on_fourthCategoryButton_clicked()
{
	if (this->isFourthActive == false)
	{
		this->selection[3] = new SelectPicto();
		this->selection[3]->InitiateSelectPicto(this->user->GetCategory()[3]);
		connect(this->selection[3], SIGNAL(this->selection[3].PictoSelected(Pictogram*)), this, SLOT(AddWordToSentence(Pictogram*)));

		Sound m_speech(ui->fourthCategoryButton->text());
		m_speech.PlaySound();
		this->selection[3]->show();

		isFourthActive = true;
	}
}
