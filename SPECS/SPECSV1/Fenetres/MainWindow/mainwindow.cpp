#include "mainwindow.h"
#include "Fenetres/Connexion/fenetreconnexion.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QCheckBox>
#include "Classes/ControleInstrument/controleinstrument.h"
#include "Classes/Graphique/qcustomplot.h"
#include <QtMath>
#include <QFile>
#include <QTextStream>
#include <algorithm> // Pour std::min_element et std::max_element


// Initialise l'interface, configure les communications et les connexions des signaux/slots, puis affiche la fenêtre
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);
    m_communication_SPECS = new Communication();
    m_communication_PICO = new Communication();
    m_controleInstrument = new ControleInstrument(m_communication_SPECS, m_communication_PICO, nullptr);
    m_fenetreConnexion = new FenetreConnexion(this, m_communication_SPECS, m_communication_PICO);
    m_customPlot = m_ui->customPlot;
    if (!m_customPlot) {
        qDebug() << "Erreur : m_customPlot non trouvé dans l'interface.";
    }

    m_releverMesure = new ReleverMesure(m_communication_SPECS, m_communication_PICO, nullptr);

    // Si le bouton connection est enclenché alors on affiche la fenêtre de connexion
    connect(m_ui->pushButtonConnexion, &QPushButton::clicked, this, &MainWindow::connexion_button_clicked);

    // Si le bouton valider pico est activé alors on lance un balayage et on met à jour la courbe de SEY
    connect(m_ui->ValidatePushButtonPICO, &QPushButton::clicked, this, [=]() {

        // Lance un balayage avec les paramètres renseignés
        m_controleInstrument->validate_button_clickedPICO(
            m_ui->lineEditEnergieMinimum->text(),
            m_ui->lineEditEnergieMaximum->text(),
            m_ui->lineEditPas->text(),
            m_ui->lineEditDuree->text()
            );

        updateCurve(); // Met à jour la courbe après le balayage
    });

    // Si un le status du balayage a changé alors on affiche le nouveau status et l'énergie actuelle du balayage ( exemple possible : Balayage en cours | énergie appliqué : 200 eV )
    connect(m_controleInstrument, &ControleInstrument::balayageStatusChanged, this, &MainWindow::updateBalayageStatus);
    connect(m_controleInstrument, &ControleInstrument::intensiteChanged, this, &MainWindow::updateintensite);

    this->show();
}

// Met à jour le graphique QCustomPlot avec les données du dernier balayage depuis un fichier CSV
void MainWindow::updateCurve()
{
    // Efface les graphiques et plottables existants pour repartir de zéro
    m_customPlot->clearGraphs();
    m_customPlot->clearPlottables();

    // Ajoute un nouveau graphique vide et initialise les vecteurs pour les données
    m_customPlot->addGraph();
    QVector<double> x, y;

    // Ouvre le fichier CSV contenant les mesures effectuées
    QFile file("C:/Users/Mesure/Documents/Nyle/mesures_pico.csv");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {

        // Crée un flux de texte pour lire le fichier
        QTextStream in(&file);
        QVector<QStringList> secondTableData; // Stocke les lignes du second tableau (données principales)
        QString lastPolarization; // Variable pour suivre la dernière polarisation détectée

        bool firstLine = true; // Indicateur pour gérer la première ligne (en-tête)
        while (!in.atEnd()) {

            QString line = in.readLine().trimmed();// Lit chaque ligne du fichier et supprime les espaces superflus



            if (firstLine) {
                firstLine = false; // Passe à false après la première itération

                // Vérifie si la ligne correspond à l'en-tête attendu et l'ignore
                if (line.contains("Date et heure;Temps ecoule (s);Energie (eV);Polarisation;Intensite brute;;"
                                  "Energie (eV);Intensite moyenne (+50V);Intensite moyenne (-50V);SEY")) {

                    continue; // Passe à la ligne suivante
                }
            }
            // Sépare la ligne en deux parties sur le séparateur ";;"
            QStringList parts = line.split(";;");
            if (parts.size() >= 1) {

                // Traite la première partie pour extraire la polarisation
                QStringList firstPart = parts[0].split(";");
                if (firstPart.size() >= 4) {
                    lastPolarization = firstPart[3]; // Enregistre la polarisation (4e colonne)
                }


                // Traite la deuxième partie pour les données principales
                if (parts.size() >= 2) {
                    QStringList values = parts[1].split(";");
                    if (values.size() >= 4) { // Vérifie qu'il y a au moins 4 colonnes
                        secondTableData.append(values); // Ajoute les valeurs au tableau
                    }
                }
            }
        }
        file.close(); // Ferme le fichier après lecture

        // Affiche des informations de débogage sur les données lues
        qDebug() << "Total lines in secondTableData:" << secondTableData.size();
        qDebug() << "Last polarization:" << lastPolarization;

        // Détermine de l'index de départ
        int startIndex = 0; // Initialise l'index de départ
        if (!secondTableData.isEmpty()) {

            // Détermine le point de départ selon la polarisation
            if (lastPolarization == "-50V") {
                startIndex = secondTableData.size() - 1; // Commence par la fin

                // Recule tant que la première colonne est vide
                while (startIndex > 0 && secondTableData[startIndex][0].isEmpty()) startIndex--;

                // Recule jusqu'à détecter une énergie invalide ou négative
                while (startIndex > 0) {
                    bool ok;
                    double energie = secondTableData[startIndex][0].toDouble(&ok);
                    if (!ok || energie < 0) break; // Fin du balayage précédent
                    startIndex--;
                }
                startIndex++; // Revient au début du dernier balayage
            } else if (lastPolarization == "+50V") {
                startIndex = 0; // Utilise le début du tableau pour +50V
            }
            qDebug() << "Start index:" << startIndex;

            // Parcourt les lignes à partir de startIndex pour extraire les données
            for (int i = startIndex; i < secondTableData.size(); ++i) {
                bool okEnergie, okSEY;

                // Convertit la première colonne (énergie) en double
                double energie = secondTableData[i][0].toDouble(&okEnergie);

                // Convertit la quatrième colonne (SEY) en double
                double sey = secondTableData[i][3].toDouble(&okSEY);
                qDebug() << "Processing line" << i << ": Energie=" << energie << ", SEY=" << sey;

                // Vérifie la validité des conversions et l'absence de données vides
                if (okEnergie && okSEY && !secondTableData[i][3].isEmpty()) {
                    x.append(energie); // Ajoute l'énergie aux données X
                    y.append(sey); // Ajoute le SEY aux données Y
                }
            }
        }
    } else {
        // Gère l'échec d'ouverture du fichier avec un message de débogage
        qDebug() << "Erreur : Impossible d'ouvrir le fichier mesures_pico.csv";
        // Génère une courbe par défaut si le fichier est inaccessible
        for (int i = 0; i < 100; ++i) {
            x.append(i * 20); // Incrémente X par pas de 20
            y.append(qSin(i * 0.1)); // Calcule une onde sinusoïdale pour Y
        }
    }

    // Affiche les tailles des vecteurs pour vérification
    qDebug() << "X data size:" << x.size() << ", Y data size:" << y.size();

    // === Section : Configuration du graphique ===
    // Assigne les données aux graphiques
    m_customPlot->graph(0)->setData(x, y);
    // Définit les étiquettes des axes
    m_customPlot->xAxis->setLabel("Energie (eV)");
    m_customPlot->yAxis->setLabel("SEY");

    // Vérifie que les vecteurs x (énergies) et y (SEY) contiennent au moins une valeur, puis détermine les valeurs minimale et maximale pour ajuster les axes
    if (!x.isEmpty() && !y.isEmpty()) {
        // Abscisse : Définit la plage de l'axe X en utilisant la plus petite et la plus grande énergie, avec une marge de 10 de chaque côté
        m_customPlot->xAxis->setRange(*std::min_element(x.begin(), x.end()) - 10, *std::max_element(x.begin(), x.end()) + 10);

        // Ordonnée : Définit la plage de l'axe Y en utilisant la plus petite et la plus grande valeur de SEY, avec une marge de 0.1 de chaque côté
        m_customPlot->yAxis->setRange(*std::min_element(y.begin(), y.end()) - 0.1, *std::max_element(y.begin(), y.end()) + 0.1);
    }
    else {
    // Utilise des plages par défaut si aucune donnée valide
        m_customPlot->xAxis->setRange(0, 2000);
        m_customPlot->yAxis->setRange(-1.5, 1.5);
    }

    // Active le glisser-déposer et le zoom sur le graphique
    m_customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    m_customPlot->axisRect()->setRangeDrag(Qt::Horizontal | Qt::Vertical);
    m_customPlot->axisRect()->setRangeZoom(Qt::Horizontal | Qt::Vertical);

    // Rafraîchit le graphique pour afficher les modifications
    m_customPlot->replot();

    // Définit une taille minimale pour le graphique
    m_customPlot->setMinimumSize(400, 300);
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

// Met à jour le label avec le statut du balayage et l'énergie actuelle
void MainWindow::updateBalayageStatus(const QString& status, int energie)
{
    qDebug() << "Energie appliquée :" << energie;
    QString energieStr = QString::number(energie);
    qDebug() << "Energie appliquée :" << energieStr;

    m_ui->labelInformationBalayage->setText(status + " | Energie appliqué : " + energieStr);

}
void MainWindow::updateintensite(double energie){
    m_ui->labelIntensite_2->setText("intensité : " + QString::number(energie));
}

