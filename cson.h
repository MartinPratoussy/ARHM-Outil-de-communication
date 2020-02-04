#ifndef CSON_H
#define CSON_H
#include <QtTextToSpeech/QTextToSpeech>
#include <QMediaPlayer>

class CSon
{
public:
    CSon();
   /* [En stande By] // permet de lancé la lecture d'un fichier mp3/Wave
    // entrer: rien
    // renvoi: rien
    void lecture();
    // artte la lecture du fichier mp3/wav
    // entrer: rien
    // renvoi: rien
    void stop();
    // lance la lecture de la prahse saise
    // entrer: une chaine de carater QString
    // renvoi: rien*/
    void parle(QString tex);
    // Modifie le fichier audio choisis
    // entrer: le nom du ficher audio avec sont extension mp3/wav
    // renvoi: rien
    void setFichierSon(QString nomFicherEtExtension);
    QTextToSpeech * cara = new QTextToSpeech;

private:

    QMediaPlayer * Rat = new QMediaPlayer();
    //contien la racine du ficher audio.mp3/.wave mis en lecture
    QString m_fichierSon = "/storage/Stockageinterne/Music/les-ratz-pas-de-panique-a-bord-clip-officiel.mp3" ;
    QString m_phraseDite = "et bien le bonjour je suis cara";
};

#endif // CSON_Hbn
