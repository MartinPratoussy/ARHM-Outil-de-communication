#include "user.h"

User::User(QString firstname, QString lastname, QString birthDate, QSqlDatabase* database, QSqlQuery* query, int numUser)
{
    this->firstname = firstname;
    this->lastname = lastname;
    this->birthDate = birthDate;

    // Ajout des attributs dans la table User de a base de données
    if(!query->exec("INSERT INTO user VALUES ('"
                  + this->firstname + "', '"
                  + this->lastname + "', '"
                  + this->birthDate + ")"))
            qWarning() << "ERROR: " << query->lastError().text();

    QList<int> values;
    // Selectionne tous les pictogrammes de l'utilisateur dans la base de données
    if (!query->exec("SELECT Pictogram.id FROM \"Pictogram\",\"User\",\"Pictogram_User\" WHERE Pictogram_User.idPictogram = Pictogram.idPictogram AND Pictogram_User.idUser = User.idUser AND Pictogram_User.idUser = " + numUser)
        ) qWarning() << "ERROR: " << database->lastError().text();
    // Tant qu'il y a des pictogrammes, le nombre de pictogramme s'incrémente
    while (query->next())
    {
        nbPicto++;
        values.append(query->value(nbPicto).toInt());
    }

    // Création des pictogrammes dans le code
    QString definition, urlImage, urlSound, category;
    for each(int value in values)
    {
        // Requêtes SQL récupérant les trois attributs d'un pictogramme selon l'utlisateur qui le possède
        if (!query->exec(
            "SELECT definition FROM \"Pictogram\" WHERE idPictogram = " + value)
            ) qWarning() << "ERROR: " << database->lastError().text();
        while (query->next()) definition = query->value(0).toString();
        if (!query->exec(
            "SELECT urlImage FROM \"Pictogram\" WHERE idPictogram = " + value)
            ) qWarning() << "ERROR: " << database->lastError().text();
        while (query->next()) urlImage = query->value(0).toString();
        if (!query->exec(
            "SELECT urlSound FROM \"Pictogram\" WHERE idPictogram = " + value)
            ) qWarning() << "ERROR: " << database->lastError().text();
        while (query->next()) urlSound = query->value(0).toString();
        if (!query->exec(
            "SELECT category FROM \"Pictogram\" WHERE idPictogram = " + value)
            ) qWarning() << "ERROR: " << database->lastError().text();
        while (query->next()) category = query->value(0).toString();
        //Conversion des QString en QPixmap et en Sound
        QPixmap image(urlImage);
        Sound sound(urlSound);
        // Création de l'objet Pictogram
        this->pictos->append(new Pictogram(definition, urlImage, urlSound, category));
    }
}

User::~User()
{
}

QString User::getFirstname()
{
    return this->firstname;
}

QString User::getLastname()
{
    return this->lastname;
}

QString User::getBirthDate()
{
    return this->birthDate;
}

int User::getNbPicto()
{
    return nbPicto;
}

QList<Pictogram*> User::getPicto()
{
    return *this->pictos;
}

QString User::getCategory(int i)
{
    return this->category[i];
}

void User::setFirstname(QString firstname, QSqlQuery* query)
{
    this->firstname = firstname;
    if (!query->exec("UPDATE user SET firstname = '" + this->firstname + "WHERE firstname = " + this->firstname + "'")) qWarning() << "ERROR : " << query->lastError().text();
}

void User::setLastname(QString lastname, QSqlQuery* query)
{
    this->lastname = lastname;
    if (!query->exec("UPDATE user SET lastname = '" + this->lastname + "WHERE firstname = " + this->firstname + "'")) qWarning() << "ERROR : " << query->lastError().text();
}

void User::setBirthDate(QString birthDate, QSqlQuery* query)
{
    this->birthDate = birthDate;
    if (!query->exec("UPDATE user SET birthDate = '" + this->birthDate + "WHERE firstname = " + this->firstname + "'")) qWarning() << "ERROR : " << query->lastError().text();
}

User & User::operator=(const User &user)
{
    this->firstname = user.firstname;
    this->lastname = user.lastname;
    this->birthDate = user.birthDate;
    //for each (Pictogram * picto in user.pictos) this->pictos->append(picto);

    return * this;
}
