#include "ReleverMesure.h"
#include <QDebug>

// Constructeur
ReleverMesure::ReleverMesure(Communication *communicationSPECS, Communication *communicationPICO , QObject *parent)
    : QObject(parent), m_communication_SPECS(communicationSPECS), m_communication_PICO(communicationPICO)
{
    m_timer = nullptr;
}

// Destructeur
ReleverMesure::~ReleverMesure()
{
    delete m_timer;
}

// Lance le timer avec un intervalle de 5 secondes pour rafraîchir les mesures périodiquement
void ReleverMesure::start()
{
    qDebug() << "🔁 [start()] Thread ID =" << QThread::currentThread();

    if (!m_timer) {
        m_timer = new QTimer(this);
        connect(m_timer, &QTimer::timeout, this, &ReleverMesure::actualisationMesuresSPECS);
    }

    if (!m_timer->isActive()) {
        m_timer->start(3000);
        qDebug() << "Timer lancé.";
    } else {
        qDebug() << "Timer déjà actif, lancement ignoré.";
    }
}

void ReleverMesure::restart()
{
    qDebug() << "🔄 Restart demandé.";

    if (m_timer) {
        if (m_timer->isActive()) {
            qDebug() << "🛑 Timer actif, arrêt...";
            m_timer->stop();
        }
        qDebug() << "▶️ Redémarrage du timer.";
        m_timer->start(3000);
    } else {
        qDebug() << "❌ Timer inexistant, création.";
        m_timer = new QTimer(this);
        connect(m_timer, &QTimer::timeout, this, &ReleverMesure::actualisationMesuresSPECS);
        m_timer->start(2000);
    }
}



// Stop le timer
void ReleverMesure::stop()
{
    m_timer->stop();
}


// Envoie des requêtes pour récupérer les paramètres de l'alimentation, émet un signal contenant les valeurs reçues, puis démarre un timer pour répéter ce processus toutes les 5 secondes.
void ReleverMesure::actualisationMesuresSPECS()
{
    qDebug() << "[actualisationMesuresSPECS()] Thread ID =" << QThread::currentThread();
    qDebug() << "ACTUALISATION: Début de la mise à jour des mesures.";

    QString resultatRequeteEnergie, resultatRequeteCourantEmission, resultatRequeteFocus, resultatRequeteWehnelt;
    QString resultatRequetePosX, resultatRequetePosY, resultatRequeteBalX, resultatRequeteBalY;
    QString resultatCourant;

    // Envoi des commandes et réception des valeurs
    m_communication_SPECS->envoyer("EN ?");resultatRequeteEnergie = m_communication_SPECS->recevoir();
    m_communication_SPECS->envoyer("EC ?");resultatRequeteCourantEmission = m_communication_SPECS->recevoir();
    m_communication_SPECS->envoyer("F1 ?");resultatRequeteFocus = m_communication_SPECS->recevoir();
    m_communication_SPECS->envoyer("WE ?");resultatRequeteWehnelt = m_communication_SPECS->recevoir();
    m_communication_SPECS->envoyer("X0 ?");resultatRequetePosX = m_communication_SPECS->recevoir();
    m_communication_SPECS->envoyer("Y0 ?");resultatRequetePosY = m_communication_SPECS->recevoir();
    m_communication_SPECS->envoyer("WX ?");resultatRequeteBalX = m_communication_SPECS->recevoir();
    m_communication_SPECS->envoyer("WY ?"); resultatRequeteBalY = m_communication_SPECS->recevoir();




    // Quand on fait une mesure depuis
    //m_communication_PICO->envoyer("READ?"); // seulement la valeur mesurée
    //resultatCourant = m_communication_PICO->recevoirKeithley6485();
 //   qDebug() << "Courant mesuré : " << resultatCourant;




    // Émission du signal avec les résultats obtenus
    emit transmissionResultatSPECS(resultatRequeteEnergie, resultatRequeteCourantEmission,
                                  resultatRequeteFocus, resultatRequeteWehnelt,
                                  resultatRequetePosX, resultatRequetePosY,
                                  resultatRequeteBalX, resultatRequeteBalY, resultatCourant = "");

}



