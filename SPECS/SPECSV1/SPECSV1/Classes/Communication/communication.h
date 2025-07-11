#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <QtCore>
#include <QSerialPort>

/*
    Permet de gérer la communication RS232
*/
class Communication
{
public:
    Communication();
    ~Communication();

    //Accesseurs
    QSerialPort* obtenirPort() const; // Retourne un pointeur vers le port série

    // Connexion a l'appareil par protocole RS232
    bool connexion(const QString& com, const QString& baud);

    // Envoyer et recevoir des commandes RS232
    bool envoyer(QString commande);
    QString recevoir();
    QString recevoirKeithley6485();

private:
    QSerialPort *m_port;
};

#endif // COMMUNICATION_H
