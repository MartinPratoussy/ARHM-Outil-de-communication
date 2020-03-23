#include "user.h"

User::User(QString firstname, QString lastname, QString birthDate, QString handicap, QSqlDatabase* database, QSqlQuery* query, int numUser)
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

#pragma region Recuperation des pictogrammes
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

    foreach(int value, values)
    {
        QString definition, urlImage, urlSound;
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
        QPixmap image(urlImage);
        Sound sound(urlSound);
        // Création de l'objet Pictogram
        this->pictos->append(new Pictogram(definition, urlImage, urlSound));
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
    foreach(Pictogram * picto, user.pictos) this->pictos->append(picto);

    return * this;
}
