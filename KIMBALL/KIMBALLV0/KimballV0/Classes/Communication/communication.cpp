#include <QSerialPort>
#include "communication.h"
#include <QRegularExpression> // Isoler uniquement la valeur numérique présente dans la réponse

Communication::Communication()
{
    m_port = new QSerialPort();
}

Communication::~Communication()
{
    delete m_port;
}

// Accesseurs
QSerialPort* Communication::obtenirPort() const
{
    return m_port;
}

bool Communication::connexion(const QString& com, const QString& baud)
{
    if (m_port->isOpen())
    {
        m_port->close();
    }

    // On donne le nom du COM
    m_port->setPortName(com);

    // On choisit le baud rate
    int baudInt = baud.toInt();
    m_port->setBaudRate(baudInt);

    // A definir par defaut
    m_port->setFlowControl(QSerialPort::NoFlowControl);
    m_port->setParity(QSerialPort::NoParity);
    m_port->setDataBits(QSerialPort::Data8);
    m_port->setStopBits(QSerialPort::OneStop);

    // Ouverture du port
    return m_port->open(QIODevice::ReadWrite);
}


bool Communication::envoyer(QString commande)
{
    // On doit envoyer commande + <CR> + <LF>
    commande = commande + "\x0D" + "\x0A";

    // On prépare une commande du bon type à envoyer
    QByteArray commandeByte = commande.toUtf8();

    // On regarde la valeur de retour de la méthode write() pour voir si l'ecriture a fonctionne
    int bitsEcrits = m_port->write(commandeByte);

    // Vide les tampons d'entree et de sortie du port serie
    m_port->flush();

    // On vérifie que la commande est passée en entier
    bool estDeBonneTaille = bitsEcrits == commande.length();

    return estDeBonneTaille;
}


QString Communication::recevoir()
{
    QByteArray reponseBrute;
    while (m_port->waitForReadyRead(500)) { // Délai de 500 ms
        reponseBrute += m_port->readAll();
    }
    QString reponseString = QString(reponseBrute).trimmed();
    // Extraire la valeur numérique après le ':' ou le dernier nombre
    QRegularExpression regex(R"(\d+)"); // Recherche un ou plusieurs chiffres
    QRegularExpressionMatchIterator it = regex.globalMatch(reponseString);
    QString dernierNombre;
    while (it.hasNext()) {
        dernierNombre = it.next().captured(0);
    }

    return dernierNombre.isEmpty() ? "" : dernierNombre;
}


QString Communication::recevoirKeithley6485()
{
    QByteArray reponseBrute = m_port->readLine();
    QString reponseString = QString(reponseBrute);

    return reponseString;
}
