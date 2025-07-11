#include "ReleverMesure.h"
#include <QDebug>
#include <QMessageBox>

// Constructeur
ReleverMesure::ReleverMesure(Communication *communicationSPECS, Communication *communicationPICO , QObject *parent)
    : QObject(parent), m_communication_SPECS(communicationSPECS), m_communication_PICO(communicationPICO)
{
    m_timer = nullptr;
    connect(this, &ReleverMesure::requestRestart, this, &ReleverMesure::restart, Qt::QueuedConnection);
    connect(this, &ReleverMesure::requestStop, this, &ReleverMesure::stop, Qt::QueuedConnection);
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
}


void ReleverMesure::startTimer()
{
    qDebug() << "🔁 [startTimer()] Thread ID =" << QThread::currentThread();

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



// Modifie stop pour plus de robustesse
void ReleverMesure::stop()
{
    if (m_timer && m_timer->isActive()) {
        m_timer->stop();
        qDebug() << "🛑 Timer arrêté.";
    }
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
    m_communication_PICO->envoyer("READ?"); // seulement la valeur mesurée
    resultatCourant = m_communication_PICO->recevoirKeithley6485();
    qDebug() << "Courant mesuré : " << resultatCourant;




    // Émission du signal avec les résultats obtenus
    emit transmissionResultatSPECS(resultatRequeteEnergie, resultatRequeteCourantEmission,
                                  resultatRequeteFocus, resultatRequeteWehnelt,
                                  resultatRequetePosX, resultatRequetePosY,
                                  resultatRequeteBalX, resultatRequeteBalY, resultatCourant);

}


void ReleverMesure::initialisationPICO(Communication *communicationPICO)
{

    if (this != nullptr) {
        qDebug() << "this = " << this;
    }

    qDebug() << "communicationPICO = " << communicationPICO;

    if (!communicationPICO) {
        qDebug() << "❌ ERREUR : communicationPICO est nullptr";
    }
    qDebug() << "Port : " << communicationPICO->obtenirPort();

    m_communication_PICO = communicationPICO;

    qDebug() << "--------------OPERATION PICO-----------------";
    m_communication_PICO->envoyer("*RST");
    m_communication_PICO->envoyer("SYST:ZCH ON");
    m_communication_PICO->envoyer("CURR:RANG:AUTO ON");
    m_communication_PICO->envoyer("INIT");
    m_communication_PICO->envoyer("SYST:ZCOR:ACQ");
    m_communication_PICO->envoyer("SYST:ZCOR ON");
    m_communication_PICO->envoyer("CURR:RANG:AUTO ON");
    m_communication_PICO->envoyer("SYST:ZCH OFF");


    m_communication_PICO->envoyer("CURR:NPLC 0.01");

}


void ReleverMesure::initialisationSPECS(Communication *m_communicationSPECS){
    qDebug() << "Activation du mode REMOTE";
    m_communicationSPECS->envoyer("RE");
}


void ReleverMesure::validate_button_clickedSPECS(const QString& energie,
                                                      const QString& courantEmission,
                                                      const QString& focus,
                                                      const QString& wehnelt,
                                                      const QString& posX,
                                                      const QString& posY,
                                                      const QString& balayageX,
                                                      const QString& balayageY)
{
    QString valTemp;

    if (!energie.isEmpty()) {
        if(( energie.toInt() >= 0 && energie.toInt() <= 5000 )){
            m_communication_SPECS->envoyer("EN " + energie);
            valTemp = m_communication_SPECS->recevoir();
            qDebug() << "Energie : " + energie + " | Réponse : " + valTemp;
        }
        else{
            QMessageBox::critical(nullptr, "Erreur", "L'énergie doit être comprise entre 0eV et 5000eV");
            qDebug() << "Énergie hors plage : " << energie;
        }
    }

    if (!courantEmission.isEmpty()) {
        if( courantEmission.toFloat() >= 0.01 && courantEmission.toFloat() <= 250){
            int courantInt = courantEmission.toInt() * 100;
            m_communication_SPECS->envoyer("EC " + QString::number(courantInt));
            qDebug() << "Courant d'émission : " << courantInt;
        }
        else{
            QMessageBox::critical(nullptr, "Erreur", "Le courant d'emission doit être comprise entre 0.01µA et 250µA");
            qDebug() << "Énergie hors plage : " << energie;
        }
    }

    if (!focus.isEmpty()) {
        int focusInt = focus.toInt() * 100;
        m_communication_SPECS->envoyer("F1 " + QString::number(focusInt));
        qDebug() << "Focus : " << focusInt;
    }

    if (!wehnelt.isEmpty()) {
        if(wehnelt.toFloat() >= 0 && wehnelt.toFloat() <= 250){
            int wehneltInt = wehnelt.toInt() * 10;
            m_communication_SPECS->envoyer("WE " + QString::number(wehneltInt));
            valTemp = m_communication_SPECS->recevoir();
            qDebug() << "Wehnelt : " << wehneltInt << " | Réponse : " << valTemp;
        }
        else{
            QMessageBox::critical(nullptr, "Erreur", "Le wehnelt doit être compris entre 0V et 250V");
            qDebug() << "Énergie hors plage : " << energie;
        }
    }

    if (!posX.isEmpty()) {
        int posXInt = posX.toInt() * 100;
        m_communication_SPECS->envoyer("X0 " + QString::number(posXInt));
        qDebug() << "Position X : " << posXInt;
    }

    if (!posY.isEmpty()) {
        int posYInt = posY.toInt() * 100;
        m_communication_SPECS->envoyer("Y0 " + QString::number(posYInt));
        qDebug() << "Position Y : " << posYInt;
    }

    if (!balayageX.isEmpty()) {
        int balayageXInt = balayageX.toInt() * 10;
        m_communication_SPECS->envoyer("WX " + QString::number(balayageXInt));
        qDebug() << "Balayage X : " << balayageXInt;
    }

    if (!balayageY.isEmpty()) {
        int balayageYInt = balayageY.toInt() * 10;
        m_communication_SPECS->envoyer("WY " + QString::number(balayageYInt));
        qDebug() << "Balayage Y : " << balayageYInt;
    }

    qDebug() << "Alimentation SPECS mise à jour";
}


// Active le mode Operate quand la case est cochée.
void ReleverMesure::on_checkBoxOperate_toggled(bool checked)
{
    if (checked) {
        qDebug() << "Activation du mode OPERATE";
        m_communication_SPECS->envoyer("OP 1");
    } else {
        m_communication_SPECS->envoyer("SB 1");
        qDebug() << "Désactivation du mode OPERATE";
    }
}

// Active le mode Haute Tension quand la case est cochée.
void ReleverMesure::on_checkBoxHV_toggled(bool checked)
{

    if (checked) {
        m_communication_SPECS->envoyer("HE 2");
        qDebug() << "Activation du mode Haute Tension";
    } else {
        m_communication_SPECS->envoyer("HA 2");
        qDebug() << "Désactivation du mode Haute Tension";
    }

}

