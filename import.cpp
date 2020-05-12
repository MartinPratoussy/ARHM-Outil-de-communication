#include "import.h"
#include "ui_import.h"

Import::Import(QWidget *parent) : 
	QWidget(parent)
{
	ui->setupUi(this);
}

Import::~Import()
{
}

void Import::InitImport(User* user, QSqlQuery* query)
{
	this->user = user;
    this->query = query;

    SetDisplayGeometry();

    // Initialise le texte des radioButton
	firstCategoryRadioButton->setText(this->user->GetCategory()[0].GetText());
	secondCategoryRadioButton->setText(this->user->GetCategory()[1].GetText());
	thirdCategoryRadioButton->setText(this->user->GetCategory()[2].GetText());
	fourthCategoryRadioButton->setText(this->user->GetCategory()[3].GetText());

    // Connecte les boutons d'explorateur de fichiers
    connect(urlImageButton, SIGNAL(released()), this, SLOT(on_imageButton_clicked()));
    connect(urlSoundButton, SIGNAL(released()), this, SLOT(on_soundButton_clicked()));

    // Connecte ls boutons de validation et d'annulation
    connect(validateButton, SIGNAL(released()), this, SLOT(on_validationButton_clicked()));
    connect(cancelButton, SIGNAL(released()), this, SLOT(on_cancelButton_clicked()));
}

void Import::on_imageButton_clicked()
{
    // Récupère le chemin d'accès dans l'explorateur de fichiers
    QFileDialog* fileDialog = new QFileDialog();
    QString urlImage = fileDialog->getOpenFileName(this, tr("Open Image"), "./data/Images", tr("Imagess Files (*.png *.jpg *)"));
    urlImageEdit->setText(urlImage);
    pictoPreviewLabel->setPixmap(QPixmap(urlImageEdit->text()));
}

void Import::on_soundButton_clicked()
{
    // Récupère le chemin d'accès dans l'explorateur de fichiers
    QFileDialog* fileDialog = new QFileDialog();
    QString urlSound = fileDialog->getOpenFileName(this, tr("Open Sound"), "./data/Sounds", tr("Imagess Files (*.mp3 *.wav *)"));
    urlSoundEdit->setText(urlSound);
}

void Import::on_validationButton_clicked()
{
    int idPicto = NULL;
    QString definition = definitionEdit->text();
    QString urlImage = urlImageEdit->text();
    QString urlSound = urlSoundEdit->text();

    if (!firstCategoryRadioButton->isChecked()
        && !secondCategoryRadioButton->isChecked()
        && !thirdCategoryRadioButton->isChecked()
        && !fourthCategoryRadioButton->isChecked()) return;

    if(definitionEdit->text().isEmpty()
        || urlImageEdit->text().isEmpty()) return;

    //enregistre dans la Basse de Donnée le pictograme 
    if (!query->exec("INSERT INTO Pictogram (definition, urlImage, urlSound)"
        "VALUES ('" + definition + "','" + urlImage + "','" + urlSound + "');")) qWarning() << "ERROR: Le pictogramme n'a pas été ajouté";

    //Récuper le dernier pictograme enregister dans la Base de Donnée
    if (!query->exec("SELECT idPictogram FROM Pictogram ORDER BY idPictogram DESC LIMIT 1;")) qWarning() << "ERROR: ";
    while (this->query->next()) idPicto = this->query->value(0).toInt();

    if (firstCategoryRadioButton->isChecked()) {
        if (!query->exec("INSERT INTO Pictogram_Category (pictogram, category)"
            "VALUES ('" + QString::number(idPicto) + "','" + QString::number(this->user->GetCategory()[0].GetId()) + "');")) qWarning() << "ERROR: ";
    }
    else if (secondCategoryRadioButton->isChecked()) {
        if (!query->exec("INSERT INTO Pictogram_Category (pictogram, category)"
            "VALUES ('" + QString::number(idPicto) + "','" + QString::number(this->user->GetCategory()[1].GetId()) + "');")) qWarning() << "ERROR: ";
    }
    else if (thirdCategoryRadioButton->isChecked()) {
        if (!query->exec("INSERT INTO Pictogram_Category (pictogram, category)"
            "VALUES ('" + QString::number(idPicto) + "','" + QString::number(this->user->GetCategory()[2].GetId()) + "');")) qWarning() << "ERROR: ";
    }
    else if (fourthCategoryRadioButton->isChecked()) {
        if (!query->exec("INSERT INTO Pictogram_Category (pictogram, category)"
            "VALUES ('" + QString::number(idPicto) + "','" + QString::number(this->user->GetCategory()[3].GetId()) + "');")) qWarning() << "ERROR: ";
    }

    this->close();
}

void Import::on_cancelButton_clicked()
{
    this->close();
}

void Import::SetDisplayGeometry()
{
    ////////////////////////////////////////////////////////////////////////////////////
    // Bug avec le designer donc les composants fixes doivent être déclarés à la main //
    ////////////////////////////////////////////////////////////////////////////////////

    categoryGroupBox = new QGroupBox(this);
    categoryGroupBox->setObjectName(QString::fromUtf8("categoryGroupBox"));
    categoryGroupBox->setGeometry(QRect(860, 150, 621, 371));
    categoryGroupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(206, 206, 206);"));

    firstCategoryRadioButton = new QRadioButton(categoryGroupBox);
    firstCategoryRadioButton->setObjectName(QString::fromUtf8("firstCategoryRadioButton"));
    firstCategoryRadioButton->setGeometry(QRect(60, 80, 201, 51));
    QFont font;
    font.setPointSize(24);
    firstCategoryRadioButton->setFont(font);

    thirdCategoryRadioButton = new QRadioButton(categoryGroupBox);
    thirdCategoryRadioButton->setObjectName(QString::fromUtf8("thirdCategoryRadioButton"));
    thirdCategoryRadioButton->setGeometry(QRect(60, 230, 201, 61));
    thirdCategoryRadioButton->setFont(font);

    fourthCategoryRadioButton = new QRadioButton(categoryGroupBox);
    fourthCategoryRadioButton->setObjectName(QString::fromUtf8("fourthCategoryRadioButton"));
    fourthCategoryRadioButton->setGeometry(QRect(330, 240, 201, 41));
    fourthCategoryRadioButton->setFont(font);

    secondCategoryRadioButton = new QRadioButton(categoryGroupBox);
    secondCategoryRadioButton->setObjectName(QString::fromUtf8("secondCategoryRadioButton"));
    secondCategoryRadioButton->setGeometry(QRect(330, 80, 201, 51));
    secondCategoryRadioButton->setFont(font);

    topBorder = new QGraphicsView(this);
    topBorder->setObjectName(QString::fromUtf8("topBorder"));
    topBorder->setGeometry(QRect(0, 0, 1921, 121));
    topBorder->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 0);"));

    pictoPreviewLabel = new QLabel(this);
    pictoPreviewLabel->setObjectName(QString::fromUtf8("pictoPreviewLabel"));
    pictoPreviewLabel->setGeometry(QRect(410, 200, 261, 261));
    pictoPreviewLabel->setPixmap(QPixmap(QString::fromUtf8("data/galerie.png")));
    pictoPreviewLabel->setScaledContents(true);

    pictoGroupBox = new QGroupBox(this);
    pictoGroupBox->setObjectName(QString::fromUtf8("pictoGroupBox"));
    pictoGroupBox->setGeometry(QRect(470, 640, 911, 371));
    pictoGroupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(206, 206, 206);"));
    
    definitionEdit = new QLineEdit(pictoGroupBox);
    definitionEdit->setObjectName(QString::fromUtf8("definitionEdit"));
    definitionEdit->setGeometry(QRect(110, 70, 691, 31));
    definitionEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
   
    urlSoundEdit = new QLineEdit(pictoGroupBox);
    urlSoundEdit->setObjectName(QString::fromUtf8("urlsoundEdit"));
    urlSoundEdit->setGeometry(QRect(110, 230, 631, 31));
    urlSoundEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
   
    urlImageEdit = new QLineEdit(pictoGroupBox);
    urlImageEdit->setObjectName(QString::fromUtf8("urlImageEdit"));
    urlImageEdit->setGeometry(QRect(110, 150, 631, 31));
    urlImageEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
    
    urlImageButton = new QPushButton(pictoGroupBox);
    urlImageButton->setObjectName(QString::fromUtf8("urlImageButton"));
    urlImageButton->setGeometry(QRect(750, 150, 51, 31));
    QIcon icon;
    icon.addFile(QString::fromUtf8("data/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
    urlImageButton->setIcon(icon);
    urlImageButton->setIconSize(QSize(32, 32));
    
    urlSoundButton = new QPushButton(pictoGroupBox);
    urlSoundButton->setObjectName(QString::fromUtf8("urlsoundButton"));
    urlSoundButton->setGeometry(QRect(750, 230, 51, 31));
    urlSoundButton->setIcon(icon);
    urlSoundButton->setIconSize(QSize(32, 32));
    
    validateButton = new QPushButton(pictoGroupBox);
    validateButton->setObjectName(QString::fromUtf8("validateButton"));
    validateButton->setGeometry(QRect(490, 290, 141, 51));
    QFont font1;
    font1.setPointSize(12);
    validateButton->setFont(font1);
    validateButton->setText("Valider");
    validateButton->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 0);"));
    
    cancelButton = new QPushButton(pictoGroupBox);
    cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
    cancelButton->setGeometry(QRect(280, 290, 141, 51));
    cancelButton->setFont(font1);
    cancelButton->setText("Annuler");
    cancelButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));
    
    defLabel = new QLabel(pictoGroupBox);
    defLabel->setObjectName(QString::fromUtf8("defLabel"));
    defLabel->setGeometry(QRect(110, 50, 61, 16));
    
    pictoLabel = new QLabel(pictoGroupBox);
    pictoLabel->setObjectName(QString::fromUtf8("pictoLabel"));
    pictoLabel->setGeometry(QRect(110, 130, 81, 16));
    
    soundLabel = new QLabel(pictoGroupBox);
    soundLabel->setObjectName(QString::fromUtf8("soundLabel"));
    soundLabel->setGeometry(QRect(110, 210, 47, 13));
}
