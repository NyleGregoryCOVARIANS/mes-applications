#include "mainwindow.h"
#include "Fenetres/Connexion/fenetreconnexion.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QCheckBox>
#include "Classes/ReleverMesure/relevermesure.h"
#include <QTextStream>


// Initialise l'interface, configure les communications et les connexions des signaux/slots, puis affiche la fenêtre
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);
    m_communication_SPECS = new Communication();
    m_communication_PICO = new Communication();
    m_fenetreConnexion = new FenetreConnexion(this, m_communication_SPECS, m_communication_PICO);


    // Implémentation d'un thread
    m_releverMesure = new ReleverMesure(m_communication_SPECS, m_communication_PICO, nullptr);

    // Créati   on du thread de mesure
    m_threadMesure = new QThread(this); // pour que le thread soit détruit automatiquement avec MainWindow
    m_releverMesure->moveToThread(m_threadMesure);

    // Démarre le thread immédiatement
    m_threadMesure->start();
    qDebug() << "m_threadMesure démarré, running =" << m_threadMesure->isRunning();

    // Connecte le signal started pour appeler start
    connect(m_threadMesure, &QThread::started, m_releverMesure, &ReleverMesure::start);

    // Ferme proprement le thread à la fermeture de MainWindow
    connect(this, &MainWindow::destroyed, m_threadMesure, &QThread::quit);
    connect(m_threadMesure, &QThread::finished, m_releverMesure, &QObject::deleteLater);
    connect(m_threadMesure, &QThread::finished, m_threadMesure, &QObject::deleteLater);

    // Connexions directes pour connexionEtablie
    connect(m_fenetreConnexion, &FenetreConnexion::connexionEtablie, m_releverMesure, &ReleverMesure::startTimer, Qt::QueuedConnection);
    connect(m_fenetreConnexion, &FenetreConnexion::connexionEtablie, m_releverMesure, &ReleverMesure::actualisationMesuresSPECS, Qt::QueuedConnection);

    // Si un résultat SPECS est transmis alors on met à jour l'affichage sur l'interface
    connect(m_releverMesure, &ReleverMesure::transmissionResultatSPECS, this, &MainWindow::affichageResultatRecuSPECS);

    // Si le bouton connexion est enclenché alors on affiche la fenêtre de connexion
    connect(m_ui->pushButtonConnexion, &QPushButton::clicked, this, &MainWindow::connexion_button_clicked);

    // Si le bouton de validation SPECS est cliqué alors on met à jour les paramètres de l'alimentation SPECS avec les nouveaux paramètres
    connect(m_ui->ValidatePushButtonSPECS, &QPushButton::clicked, this, [=]() {
        m_releverMesure->validate_button_clickedSPECS(

            // Trimmed permet de retirer les espaces vides
            m_ui->lineEditEnergie->text().trimmed(),
            m_ui->lineEditCourantEmission->text().trimmed(),
            m_ui->lineEditFocus->text().trimmed(),
            m_ui->lineEditWehnelt->text().trimmed(),
            m_ui->lineEditPositionX->text().trimmed(),
            m_ui->lineEditPositionY->text().trimmed(),
            m_ui->lineEditBalayageX->text().trimmed(),
            m_ui->lineEditBalayageY->text().trimmed()
            );
    });




    // Si la case operate est coché alors on active le mode "OPERATE" de l'alimentation SPECS
    connect(m_ui->checkBoxOperate, &QCheckBox::toggled, m_releverMesure, &ReleverMesure::on_checkBoxOperate_toggled);

    // Si la case Haut Voltage est coché alors on active le mode "Haut Voltage" de l'alimentation SPECS
    connect(m_ui->checkBoxHV, &QCheckBox::toggled, m_releverMesure, &ReleverMesure::on_checkBoxHV_toggled);

}

// Affiche les résultats reçus d'un instrument SPECS dans l'interface avec ajustement des échelles
void MainWindow::affichageResultatRecuSPECS(QString CurrentEnergie, QString CurrentCourantEmission, QString CurrentFocus, QString CurrentWehnelt,
                                            QString CurrentPosX, QString CurrentPosY, QString CurrentBalX, QString CurrentBalY, QString CurrentCourant) {
    m_ui->valeurMesurerEnergie->setText(CurrentEnergie + "eV");
    m_ui->valeurMesurerFocus->setText(CurrentFocus + " V");
    m_ui->valeurMesurerCourantEmission->setText(QString::number(CurrentCourantEmission.toFloat() / 100) + " µA"); // Conversion en µA
    m_ui->valeurMesurerFocusEv->setText(QString::number((CurrentFocus.toFloat() / CurrentEnergie.toFloat()) * 100) + " %");
    m_ui->valeurMesurerWehnelt->setText(QString::number(CurrentWehnelt.toFloat() / 10) + " V"); // Conversion en V
    m_ui->valeurMesurerPositionX->setText(QString::number(CurrentPosX.toFloat() / 1000) + " mm"); // Conversion en mm
    m_ui->valeurMesurerPositionY->setText(QString::number(CurrentPosY.toFloat() / 1000) + " mm"); // Conversion en mm
    m_ui->valeurMesurerBalayageX->setText(QString::number(CurrentBalX.toFloat() / 1000) + " mm"); // Conversion en mm
    m_ui->valeurMesurerBalayageY->setText(QString::number(CurrentBalY.toFloat() / 1000) + " mm"); // Conversion en mm
    m_ui->labelIntensite->setText("Intensité : " + QString::number(CurrentCourant.toFloat()) );
}

// Affiche la fenêtre de connexion lorsqu'un bouton est cliqué
void MainWindow::connexion_button_clicked()
{
    m_fenetreConnexion->show();
}

// Libère les ressources allouées (fenêtre, communications, UI) lors de la destruction
MainWindow::~MainWindow()
{
    delete m_fenetreConnexion;
    delete m_communication_SPECS;
    delete m_communication_PICO;
    delete m_ui;
}


