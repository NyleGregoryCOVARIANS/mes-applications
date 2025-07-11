#include "fenetreconnexion.h"
#include "ui_fenetreconnexion.h"
#include <iostream>
#include "Classes/Communication/communication.h"
#include <QMessageBox>
#include <QDebug>


// Crée une fenêtre de connexion avec des instances par défaut de communication
FenetreConnexion::FenetreConnexion(QWidget *parent)
    : QDialog(parent)
    , m_ui(new Ui::FenetreConnexion)
{
    //Initialise l'interface graphique à partir du fichier .ui, instancie des communications pour SPECS et PICO par défaut, et instancie un controle d'instrument
    m_ui->setupUi(this);
    m_communication_SPECS = new Communication();
    m_communication_PICO = new Communication();
    m_controleInstrument = new ControleInstrument(m_communication_SPECS, m_communication_PICO, this);
}

// Crée une fenêtre de connexion avec des instances de communication fournies
FenetreConnexion::FenetreConnexion(QWidget *parent, Communication *m_communicationSPECS, Communication *m_communicationPICO)
    : QDialog(parent)
    , m_ui(new Ui::FenetreConnexion)
{
    //Initialise l'interface graphique à partir du fichier .ui, instancie les communications pour SPECS et PICO avec les paramètres,
    // et instancie un controle d'instrument
    m_ui->setupUi(this);
    m_communication_SPECS = m_communicationSPECS;
    m_communication_PICO = m_communicationPICO;
    m_controleInstrument = new ControleInstrument(m_communication_SPECS, m_communication_PICO, this);
}

// Libère la mémoire allouée pour l'interface graphique
FenetreConnexion::~FenetreConnexion()
{
    delete m_ui;
}

// Se connecte à l'alimentation SPECS et au picoampèremetre, active le control à distance et actualise
void FenetreConnexion::on_pushButton_rs232_clicked()
{
    // Récupère le port COM et le baud rate saisis par l'utilisateur pour SPECS
    m_com_SPECS = m_ui->lineEditSPECS->text();
    m_baudRate_SPECS = m_ui->comboBoxSPECS->currentText();

    // Récupère le port COM et le baud rate saisis par l'utilisateur pour PICO
    m_com_PICO = m_ui->lineEditPICO->text();
    m_baudRate_PICO = m_ui->comboBoxPICO->currentText();

    // Affiche les ports actuels pour débogage dans la console
    qDebug() << "SPECS port: " << m_communication_SPECS->obtenirPort();
    qDebug() << "PICO port: " << m_communication_PICO->obtenirPort();

    // Tente de se connecter aux instruments avec les paramètres récupérés
    estConnectePICO = m_communication_PICO->connexion(m_com_PICO, m_baudRate_PICO); // Retourne true si PICO connecté
    estConnecteSPECS = m_communication_SPECS->connexion(m_com_SPECS, m_baudRate_SPECS); // Retourne true si SPECS connecté

    // Si la connection au SPECS à réussis alors on initialise l'alimentation SPECS
    if (estConnecteSPECS) {
        m_controleInstrument->initialisationSPECS(m_communication_SPECS);
        QMessageBox::information(nullptr, "Connection SPECS", QString("Connection au SPECS réussis"));

    // Sinon on prévient l'utilisateur que le connection a échouée ( console + popup )
    } else {
        qDebug() << "Echec de connection SPECS";
        QMessageBox::information(nullptr, "Connection SPECS", QString("La connection au SPECS a échouée. Veuillez vérifier les bons COM")); // Affiche une erreur
    }

    // Si la connection au PICO à réussis alors on initialise le picoampèremetre
    if (estConnectePICO) {
        m_controleInstrument->initialisationPICO(m_communication_PICO);
        QMessageBox::information(nullptr, "Connection PICO", QString("Connection au picoampèremètre réussis"));

    // Sinon on prévient l'utilisateur que le connection a échouée ( console + popup )
    } else {
        qDebug() << "Echec de connection SPECS";
        QMessageBox::information(nullptr, "Connection PICO", QString("La connection au picoampèremètre a échouée. Veuillez vérifier les bons COM"));
    }

    if(estConnecteSPECS && estConnectePICO){
        connexionEtablie();
    }




    this->hide(); // Ferme la fenêtre de connexion après l'opération
}
