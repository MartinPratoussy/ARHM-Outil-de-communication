#include "user.h"

User::User(QString firstname, QString lastname, QString birthDate, QString handicap, QSqlDatabase * database, QSqlQuery * query, int numUser)
{
    this->firstname = firstname;
    this->lastname = lastname;
    this->birthDate = birthDate;
    this->handicap = handicap;

    // Ajout des attributs dans la table User de a base de données
    if(!query->exec("INSERT INTO user VALUES ('"
                  + this->firstname + "', '"
                  + this->lastname + "', '"
                  + this->birthDate + "', '"
                  + this->handicap + ")"))
            qWarning() << "ERROR: " << query->lastError().text();

#pragma region Récupération des pictogrammes
    // Selectionne tous les pictogrammes de l'utilisateur dans la base de données
    if (!query->exec(
        "'SELECT Pictogram.id FROM \"Pictogram\",\"User\",\"Pictogram_User\" WHERE Pictogram_User.idPictogram AND Pictogram_User.idUser = User.idUser AND Pictogram_User.idUser = " + numUser)
        ) qWarning() << "ERROR: " << database->lastError().text();
    // Tant qu'il y a des pictogrammes, le nombre de pictogramme s'incrémente
    while (query->next()) nbPicto++;
#pragma endregion

#pragma region Implémentation des pictogrammes
    for (int i = 0; i < nbPicto; i++)
    {
        QString definiton, urlImage, urlSound;
        // Requêtes SQL récupérant les trois attributs d'un pictogramme selon l'utlisateur qui le possède
        if (!query->exec(
            "SELECT Pictogram.definition FROM \"Pictogram\",\"User\",\"Pictogram_User\" WHERE Pictogram_User.idPictogram AND Pictogram_User.idUser = User.idUser AND Pictogram_User.idUser = " + numUser)
            ) qWarning() << "ERROR: " << database->lastError().text();
        while (query->next()) definiton = query->value(0).toString();
        if (!query->exec(
            "SELECT Pictogram.urlImage FROM \"Pictogram\",\"User\",\"Pictogram_User\" WHERE Pictogram_User.idPictogram AND Pictogram_User.idUser = User.idUser AND Pictogram_User.idUser = " + numUser)
            ) qWarning() << "ERROR: " << database->lastError().text();
        while (query->next()) urlImage = query->value(0).toString();
        if (!query->exec(
            "SELECT Pictogram.urlSound FROM \"Pictogram\",\"User\",\"Pictogram_User\" WHERE Pictogram_User.idPictogram AND Pictogram_User.idUser = User.idUser AND Pictogram_User.idUser = " + numUser)
            ) qWarning() << "ERROR: " << database->lastError().text();
        while (query->next()) urlSound = query->value(0).toString();
        QPixmap image(urlImage);
        Sound sound(urlSound);
        // Création de l'objet Pictogram
        this->pictos[i] = new Pictogram(definiton, image, sound);
    }
#pragma endregion

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

QString User::getHandicap()
{
    return this->handicap;
}

void User::setFirstname(QString firstname, QSqlQuery* query)
{
    this->firstname = firstname;
    if (!query->exec("UPDATE user SET firstname = '" + this->handicap + "WHERE firstname = " + this->firstname + "'")) qWarning() << "ERROR : " << query->lastError().text();
}

void User::setLastname(QString lastname, QSqlQuery* query)
{
    this->lastname = lastname;
    if (!query->exec("UPDATE user SET lastname = '" + this->handicap + "WHERE firstname = " + this->firstname + "'")) qWarning() << "ERROR : " << query->lastError().text();
}

void User::setBirthDate(QString birthDate, QSqlQuery* query)
{
    this->birthDate = birthDate;
    if (!query->exec("UPDATE user SET birthDate = '" + this->handicap + "WHERE firstname = " + this->firstname + "'")) qWarning() << "ERROR : " << query->lastError().text();
}

void User::setHandicap(QString handicap, QSqlQuery* query)
{
    this->handicap = handicap;
    if (!query->exec("UPDATE user SET handicap = '" + this->handicap + "WHERE firstname = " + this->firstname + "'")) qWarning() << "ERROR : " << query->lastError().text();
}


User & User::operator=(const User &user)
{
    this->firstname = user.firstname;
    this->lastname = user.lastname;
    this->birthDate = user.birthDate;
    this->handicap = user.handicap;
    //**this->pictos = **user.pictos;

    return * this;
}
