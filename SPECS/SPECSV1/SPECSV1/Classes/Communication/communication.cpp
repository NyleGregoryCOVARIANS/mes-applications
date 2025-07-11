#include <QSerialPort>
#include "communication.h"
#include <QRegularExpression> // Isoler uniquement la valeur numérique présente dans la réponse

// Constructeur
Communication::Communication()
{
    m_port = new QSerialPort();
}

// Destructeur
Communication::~Communication()
{
    delete m_port;
}

// Accesseurs : Obtiens le port
QSerialPort* Communication::obtenirPort() const
{
    return m_port;
}

// Se connecte au port série et met en place une configuration par défault
bool Communication::connexion(const QString& com, const QString& baud)
{


    // Configuration de base du port série
    m_port->setPortName(com);
    m_port->setBaudRate(baud.toInt());
    m_port->setFlowControl(QSerialPort::NoFlowControl);
    m_port->setParity(QSerialPort::NoParity);
    m_port->setDataBits(QSerialPort::Data8);
    m_port->setStopBits(QSerialPort::OneStop);

    // Ouverture du port en lecture/écriture
    return m_port->open(QIODevice::ReadWrite);
}


// Envoie une commande à l'alimentation
bool Communication::envoyer(QString commande)
{
    // Ajout des caractères de fin (CR + LF)
    commande += "\x0D\x0A";

    // Conversion en tableau d’octets pour l’envoi
    QByteArray commandeByte = commande.toUtf8();

    // Écriture sur le port série
    int bitsEcrits = m_port->write(commandeByte);

    // Vide les tampons pour forcer l'envoi immédiat
    m_port->flush();

    // Vérifie que toute la commande a bien été transmise
    return bitsEcrits == commande.length();
}

// Réception de la réponse de l'alimentation
QString Communication::recevoir()
{
    QByteArray reponseBrute;

    // Lecture en attente avec timeout : 100 ms max par itération
    while (m_port->waitForReadyRead(100)) {
        reponseBrute += m_port->readAll();
    }

    //On retire
    QString reponseString = QString(reponseBrute).trimmed();

    // Expression régulière pour extraire uniquement les valeurs numériques (ex. -42)
    QRegularExpression regex(R"(-?\d+)");
    QRegularExpressionMatchIterator it = regex.globalMatch(reponseString);

    // On garde le dernier nombre trouvé (souvent le plus significatif)
    QString dernierNombre;
    while (it.hasNext()) {
        QRegularExpressionMatch match = it.next();
        dernierNombre = match.captured(0);
    }

    return dernierNombre.isEmpty() ? "" : dernierNombre;
}

// ==========================
// Réception pour Keithley 6485
// ==========================
QString Communication::recevoirKeithley6485()
{
    QByteArray reponseBrute;

    if (m_port->waitForReadyRead(2000)) {
        while (!reponseBrute.contains('\n')) {
            if (m_port->waitForReadyRead(100)) {
                QByteArray chunk = m_port->readAll();
                reponseBrute += chunk;
            } else {
                break;
            }
        }

        QString reponseCompleteString = QString(reponseBrute).trimmed();

        // Regex pour capturer la valeur scientifique terminée par A (la mesure de courant)
        QRegularExpression regex(R"(([+-]?\d+\.\d+E[+-]?\d+)A)");
        QRegularExpressionMatch match = regex.match(reponseCompleteString);

        if (match.hasMatch()) {
            QString valeurCourant = match.captured(1); // Sans le A
            return valeurCourant;
        } else {
            qDebug() << "❌ Aucune mesure de courant détectée dans :" << reponseCompleteString;
            return "Erreur : Mesure non détectée";
        }
    } else {
        qDebug() << "⛔ Aucune réponse reçue du Keithley.";
        return "Erreur : Pas de réponse";
    }
}

