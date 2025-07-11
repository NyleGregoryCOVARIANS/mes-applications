#include "ReleverMesure.h"
#include <QDebug>

ReleverMesure::ReleverMesure(Communication *communication, QObject *parent)
    : QObject(parent), m_communication(communication)
{
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &ReleverMesure::actualisationMesures);
}

ReleverMesure::~ReleverMesure()
{
    delete m_timer;
}

	void ReleverMesure::start()
	{
		m_timer->start(5000);  // Lancer toutes les 5 secondes
	}

	void ReleverMesure::stop()
	{
		m_timer->stop();
	}

void ReleverMesure::actualisationMesures()
{
    qDebug() << "ACTUALISATION: Début de la mise à jour des mesures.";

    QString resultatRequeteEnergie, resultatRequeteCourantEmission, resultatRequeteFocusVoltage;
    QString resultatRequeteSourceVoltage, resultatRequeteGridVoltage, resultatRequeteSourceCurrent;

    m_communication->envoyer("gi:0");
    qDebug() << m_communication->recevoir();


    // Envoi des commandes et réception des valeurs
    m_communication->envoyer("gi:0"); resultatRequeteEnergie = m_communication->recevoir();// qDebug() << "Energie récupéré par Kimball : " + resultatRequeteEnergie;
    m_communication->envoyer("gi:1"); resultatRequeteSourceVoltage = m_communication->recevoir();// qDebug() << "Source Voltage récupéré par Kimball : " + resultatRequeteSourceVoltage;
    m_communication->envoyer("gi:2"); resultatRequeteGridVoltage = m_communication->recevoir();// qDebug() << "Grid Voltage récupéré par Kimball : " + resultatRequeteGridVoltage;
    m_communication->envoyer("gi:4"); resultatRequeteFocusVoltage = m_communication->recevoir(); qDebug() << "Focus Voltage récupéré par Kimball : " + resultatRequeteFocusVoltage;
    m_communication->envoyer("gi:10"); resultatRequeteCourantEmission = m_communication->recevoir();// qDebug() << "Courant d'émission récupéré par Kimball : " + resultatRequeteCourantEmission;
    m_communication->envoyer("gi:11"); resultatRequeteSourceCurrent = m_communication->recevoir();// qDebug() << "Source Current récupéré par Kimball : " + resultatRequeteSourceCurrent;


    // Émission du signal avec les résultats obtenus
    emit transmissionResultatPret(resultatRequeteEnergie, resultatRequeteSourceVoltage,
                                  resultatRequeteGridVoltage, resultatRequeteFocusVoltage, resultatRequeteCourantEmission, resultatRequeteSourceCurrent);

    // Démarre le timer pour la mise à jour continue
    this->start();
}


