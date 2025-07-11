#include "mainwindow.h"
#include "Fenetres/Connexion/fenetreconnexion.h" // Inclure la bonne classe
#include "ui_mainwindow.h"
#include <string>
#include <QDebug>
#include "Classes/ReleverMesure/relevermesure.h"  // Ajoute l'inclusion de la nouvelle classe
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);
    m_communication = new Communication();
    m_fenetreConnexion = new FenetreConnexion(this, m_communication);


    // Crée une instance ReleverMesure, crée un nouveau thread,
    // Déplace ReleverMesure dans ce Thread afin de ne pas ralentir l'UI pendant les mesures.
    m_releverMesure = new ReleverMesure(m_communication, this);
    m_threadMesure = new QThread(this);
    m_releverMesure->moveToThread(m_threadMesure);


    // Si l'utilisateur ferme la fenêtre principale, alors on arrête le thread de mesure
    connect(this, &MainWindow::destroyed, m_threadMesure, &QThread::quit);

    // Si le thread de mesure est terminé alors on supprime l'objet ReleverMesure
    connect(m_threadMesure, &QThread::finished, m_releverMesure, &QObject::deleteLater);

    // Si le thread de mesure est terminé alors on supprime le thread
    connect(m_threadMesure, &QThread::finished, m_threadMesure, &QObject::deleteLater);



    // Si la connexion est établie alors on démarre le thread de mesure et on commence les mesures.
    connect(m_fenetreConnexion, &FenetreConnexion::connexionEtablie, this, [=]() {
        if (!m_threadMesure->isRunning()) m_threadMesure->start();
        QMetaObject::invokeMethod(m_releverMesure, "start", Qt::QueuedConnection);
    });



    connect(m_fenetreConnexion, &FenetreConnexion::connexionEtablie,
            m_releverMesure, &ReleverMesure::actualisationMesures); // Lance une mesure après connexion


    connect(m_releverMesure, &ReleverMesure::transmissionResultatPret,
            this, &MainWindow::transmissionResultatRecu);
    connect(m_ui->pushButtonConnexion, &QPushButton::clicked,
            this, &MainWindow::connexion_button_clicked);
    connect(m_ui->ValidatePushButton, &QPushButton::clicked,
            this, &MainWindow::validate_button_clicked);

    this->show();
}




// Règle les problèmes de conversion du manuel et affiche sur l'application les paramètres récupérés.
void MainWindow::transmissionResultatRecu(QString CurrentEnergie, QString CurrentSourceVoltage, QString CurrentGridVoltage, QString CurrentFocusVoltage,
                                           QString CurrentCourantEmission, QString CurrentSourceCurrent) {


    float CurrentEnergieInt = CurrentEnergie.toFloat() / 10; // division par 10 pourcorriger l'erreur d'échelle du manuel
    QString CurrentEnergieStr = QString::number(CurrentEnergieInt);
    m_ui->valeurMesurerEnergie->setText(CurrentEnergieStr + "V");

    float CurrentSourceVoltageInt = CurrentSourceVoltage.toFloat() / 1000; // division par 1000 pour corriger l'erreur d'échelle du manuel
    QString CurrentSourceVoltageStr = QString::number(CurrentSourceVoltageInt);
    //qDebug() << " SOURCE VOLTAGE APRES division : " + CurrentSourceVoltageStr;
    m_ui->valeurMesurerSourceVoltage->setText(CurrentSourceVoltageStr + "V");

    float CurrentGridVoltageInt = CurrentGridVoltage.toFloat() / 10; // division par 10 pourcorriger l'erreur d'échelle du manuel
    QString CurrentGridVoltageStr = QString::number(CurrentGridVoltageInt);
    //qDebug() << " GRID VOLTAGE APRES division : " + CurrentGridVoltageStr ;
    m_ui->valeurMesurerGridVoltage->setText(CurrentGridVoltageStr + "V");

    float CurrentCourantEmissionInt = CurrentCourantEmission.toFloat() / 1000 ; // division par 10 pourcorriger l'erreur d'échelle du manuel
    QString CurrentCourantEmissionStr = QString::number(CurrentCourantEmissionInt);
    //qDebug() << " CourantEmission APRES division : " + CurrentCourantEmissionStr;
    m_ui->valeurMesurerCourantEmission->setText(CurrentCourantEmissionStr + "mA");

    float CurrentSourceCurrentInt = CurrentSourceCurrent.toFloat() / 1000 ; // division par 1000 pour corriger l'erreur d'échelle du manuel
    QString CurrentSourceCurrentStr = QString::number(CurrentSourceCurrentInt);
    //qDebug() << " Source courant APRES division : " + CurrentSourceCurrentStr;
    m_ui->valeurMesurerSourceCurrent->setText(CurrentSourceCurrentStr + "A");



    // A TESTER
    float CurrentFocusInt = CurrentFocusVoltage.toFloat() / 10;
    qDebug() << "Focus actuelle : " + CurrentFocusVoltage;
    qDebug() << "Energie actuelle : " + QString::number(CurrentEnergieInt);

    float pourcentageInt =  ( CurrentFocusInt / CurrentEnergieInt ) * 100 ; // x100 pour mettre en % et x100 pour corriger l'erreur d'échelle du manuel


    QString pourcentageStr = QString::number(pourcentageInt);
    qDebug() << "Pourcentage actuelle : " + pourcentageStr;

    QString focusEvStr = QString::number(CurrentFocusInt);


    m_ui->valeurMesurerFocusEv->setText(focusEvStr + " V");
    m_ui->valeurMesurerFocus->setText(pourcentageStr + " %");



}






void MainWindow::validate_button_clicked()
{
    // Récupérer les valeurs saisies par l'utilisateur depuis l'interface
    QString energieStr = m_ui->lineEditEnergie->text();
    QString sourceVoltageStr = m_ui->lineEditSourceVoltage->text();
    QString gridVoltageStr = m_ui->lineEditGridVoltage->text();
    QString focusVoltageStr = m_ui->lineEditFocus->text();


    qDebug() << "TESTTTTT";


    // Convertir les chaînes en float
    bool ok;
    float energie = energieStr.toFloat(&ok);
    if (ok) {
        if (energie >= 50 && energie <= 1500 ) {
            // #0 Énergie : multiplier par 10
            float energieScaled = energie * 10;
            m_communication->envoyer(QString("po:0,%1").arg(energieScaled));
            qDebug() << "Énergie envoyée : " << energieScaled;
        } else {
            QMessageBox::critical(nullptr, "Erreur", "L'énergie doit être comprise entre 50 et 1500eV");
            qDebug() << "Énergie hors plage : " << energie;
        }
    } else {
        qDebug() << "Champs non remplis pour Énergie";
    }


    float sourceVoltage = sourceVoltageStr.toFloat(&ok);
    if (ok) {
        if (sourceVoltage >= 0 && sourceVoltage <= 1.44 ){ //
            // #1 Source Voltage : multiplier par 1000
            float sourceVoltageScaled = sourceVoltage * 1000;
            m_communication->envoyer(QString("po:1,%1").arg(sourceVoltageScaled));
            qDebug() << "Source Voltage envoyée : " << sourceVoltageScaled;
        }
        else{
            QMessageBox::critical(nullptr, "Erreur", "Source Voltage doit être comprise entre 0 et 1.44V");
            qDebug() << "Énergie hors plage : " << sourceVoltage;
        }

    } else {
        qDebug() << "Champs non remplis pour Source Voltage";
    }

    float gridVoltage = gridVoltageStr.toFloat(&ok);
    if (ok) {
        if (gridVoltage >= 0 && gridVoltage <= 200 ){
            // #2 Grid Voltage : multiplier par 10
            float gridVoltageScaled = gridVoltage * 10;
            m_communication->envoyer(QString("po:2,%1").arg(gridVoltageScaled));
            qDebug() << "Grid Voltage envoyée : " << gridVoltageScaled;
        }
        else{
            QMessageBox::critical(nullptr, "Erreur", "Grid Voltage doit être comprise entre 0 et 200V");
            qDebug() << "Grid Voltage hors plage : " << gridVoltage;
        }
    } else {
        qDebug() << "Champs non remplis pour Grid Voltage";
    }

    float focusVoltage = focusVoltageStr.toFloat(&ok);
    if (ok) {
        if (focusVoltage >= 0 && focusVoltage <= 1500 ){
            // #4 Focus Voltage : multiplier par 10
            float focusVoltageScaled = focusVoltage * 10;

            qDebug() << "Commande envoyée : " << QString("po:4,%1").arg(focusVoltageScaled);

            m_communication->envoyer(QString("po:4,%1").arg(focusVoltageScaled));

            qDebug() << "Focus Voltage envoyée : " << focusVoltageScaled;
        }
        else{
            QMessageBox::critical(nullptr, "Erreur", "Focus Voltage doit être comprise entre 0 et 1500V");
            qDebug() << "Grid Voltage hors plage : " << focusVoltage;
        }
    } else {
        qDebug() << "Champs non remplis pour Focus Voltage";
    }
}



// Affiche la fenetre de connexion
void MainWindow::connexion_button_clicked(){
    m_fenetreConnexion->show();
}

// Destructeur
MainWindow::~MainWindow()
{
    delete m_fenetreConnexion;
}
