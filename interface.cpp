#include "interface.h"
#include "ui_interface.h"


Interface::Interface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Interface)
{
    ui->setupUi(this);

    for (int i = 0; i < 4; i++) button[i] = new QPushButton(this);

    // Initialisation du texte des boutons
    button[0]->setText(this->user->getCategory[0]);
    button[1]->setText(this->user->getCategory[1]);
    button[2]->setText(this->user->getCategory[2]);
    button[3]->setText(this->user->getCategory[3]);

    // Connexion des boutons à leur méthode lors du clic
    connect(button[0], SIGNAL(released()), this, SLOT(on_button1_clicked()));
    connect(button[1], SIGNAL(released()), this, SLOT(on_button2_clicked()));
    connect(button[2], SIGNAL(released()), this, SLOT(on_button3_clicked()));
    connect(button[3], SIGNAL(released()), this, SLOT(on_button4_clicked()));

    // Connexion du bouton de retour arrière à la méthode correspondante
    connect(cancelButton, SIGNAL(released()), this, SLOT(Cancel()));

    // Connexion du bouton de lecture à la méthode correspondante
    connect(readButton, SIGNAL(released()), this, SLOT(readSentence()));

    // Affichage de l'interface
    this->ShowMainMenu();
}

void Interface::InitInterface(User *user)
{
    this->user = user;
}

Interface::~Interface()
{
    delete ui;
}

void Interface::ShowMainMenu()
{
    // Placement et affichage des boutons dans l'interface
    int numButton = 0;
    for (int j = 0; j < 2; j++)
        for (int i = 0; i < 2; i++)
        {
            // Placement automatique des boutons selon la taille de l'écran
            button[numButton]->setGeometry(
                        ((2*i)+1)*QApplication::desktop()->width()/5,
                        ((2*j)+1)*QApplication::desktop()->height()/5,
                        this->width()/5,
                        this->height()/5);
            // Affichage du bouton
            button[numButton]->show();
            numButton++;
        }
}

void Interface::Cancel()
{
    // Vérifie si la phrase est vide et si non, le dernier mot est supprimé
    if (!this->sentence->isEmpty()) this->sentence->removeLast();
}

User * Interface::GetUser()
{
    return this->user;
}

Interface & Interface::operator=(const Interface & interface)
{
    *this->sentence = *interface.sentence;
    return * this;
}

void Interface::addWordToSentence(Pictogram* word)
{
    // Ajoute un mot à la phrase si elle n'est pas complète
    if(this->sentence->size() < 3 ) this->sentence->append(word);
}

void Interface::readSentence()
{
    foreach (Pictogram word, this->sentence)
    {
        word.getSound().play(word.getDefinition());
    }
}

void Interface::on_button1_clicked()
{
    Sound m_speech;
    m_speech.say(button[0]->text());
    this->selection[0] = new SelectPicto();
    this->selection->DisplayPictograms(this->button[0]->text());
}

void Interface::on_button2_clicked()
{
    Sound m_speech;
    m_speech.say(button[1]->text());
    this->selection[1] = new SelectPicto();
    this->selection->DisplayPictograms(this->button[1]->text());
}

void Interface::on_button3_clicked()
{
    Sound m_speech;
    m_speech.say(button[2]->text());
    this->selection[2] = new SelectPicto();
    this->selection->DisplayPictograms(this->button[2]->text());
}

void Interface::on_button4_clicked()
{
    Sound m_speech;
    m_speech.say(button[3]->text());
    this->selection[3] = new SelectPicto();
    this->selection->DisplayPictograms(this->button[3]->text());
}
