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

	// Initialisation du texte des boutons
	ui->firstCategoryButton->setText(this->user->getCategory()[0]);
	ui->secondCategoryButton->setText(this->user->getCategory()[1]);
	ui->thirdCategoryButton->setText(this->user->getCategory()[2]);
	ui->fourthCategoryButton->setText(this->user->getCategory()[3]);

	// Connexion des boutons à leur méthode lors du clic
	connect(ui->firstCategoryButton, SIGNAL(released()), this, SLOT(on_firstCategoryButton_clicked()));
	connect(ui->secondCategoryButton, SIGNAL(released()), this, SLOT(on_secondCategoryButton_clicked()));
	connect(ui->thirdCategoryButton, SIGNAL(released()), this, SLOT(on_thirdCategoryButton_clicked()));
	connect(ui->fourthCategoryButton, SIGNAL(released()), this, SLOT(on_fourthCategoryButton_clicked()));

	// Connexion du bouton de retour arrière à la méthode correspondante
	connect(ui->backButton, SIGNAL(released()), this, SLOT(Cancel()));

	// Connexion du bouton de lecture à la méthode correspondante
	connect(ui->readButton, SIGNAL(released()), this, SLOT(readSentence()));
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

void Interface::addWordToSentence(Pictogram* word)
{
	// Ajoute un mot à la phrase si elle n'est pas complète
	if (this->sentence.size() < 3) this->sentence.append(word);
}

void Interface::readSentence()
{
	for each (Pictogram * word in this->sentence)
	{
		word->getSound().play(word->getDefinition());
	}
}

void Interface::on_firstCategoryButton_clicked()
{
	Sound m_speech;
	m_speech.say(ui->firstCategoryButton->text());
	this->selection[0] = new SelectPicto();
	this->selection[0]->DisplayPictograms(ui->firstCategoryButton->text());
}

void Interface::on_secondCategoryButton_clicked()
{
	Sound m_speech;
	m_speech.say(ui->secondCategoryButton->text());
	this->selection[1] = new SelectPicto();
	this->selection[1]->DisplayPictograms(ui->secondCategoryButton->text());
}

void Interface::on_thirdCategoryButton_clicked()
{
	Sound m_speech;
	m_speech.say(ui->thirdCategoryButton->text());
	this->selection[2] = new SelectPicto();
	this->selection[2]->DisplayPictograms(ui->thirdCategoryButton->text());
}

void Interface::on_fourthCategoryButton_clicked()
{
	Sound m_speech;
	m_speech.say(ui->fourthCategoryButton->text());
	this->selection[3] = new SelectPicto();
	this->selection[3]->DisplayPictograms(ui->fourthCategoryButton->text());
}
