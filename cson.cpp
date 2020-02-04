#include "cson.h"


CSon::CSon()
{

}

void CSon::setFichierSon(QString nomFicherEtExtension)
{
    m_fichierSon = "/Stockage interne/Music/" + nomFicherEtExtension;
}

void CSon::lecture()
{
    Rat -> setMedia(QUrl::fromLocalFile(m_fichierSon));
    Rat->setVolume(100);
    Rat -> play();
}

void CSon::stop()
{
    Rat-> stop();
}

void CSon::parle(QString tex)
{
    cara->setPitch(0.2);
    cara->setRate(-0.2);
    cara->say(tex);
}
