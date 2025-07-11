#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>

#include "Fenetres/Connexion/fenetreconnexion.h"
#include "Classes/ReleverMesure/releverMesure.h"
#include "Classes/ControleInstrument/controleinstrument.h"
#include "Classes/Graphique/qcustomplot.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT // Q_OBJECT est nécessaire pour activer les fonctionnalités de méta-objets Qt (signaux, slots)


public:
    // Constructeur
    explicit MainWindow(QWidget *parent = nullptr);

    // Destructeur
    ~MainWindow();

    // Met à jour le graphique QCustomPlot avec les données du dernier balayage depuis un fichier CSV
    void updateCurve();


private slots:
    // Affiche la fenêtre de connexion lorsqu'un bouton est cliqué
    void connexion_button_clicked();

    // Met à jour le label avec le statut du balayage et l'énergie actuelle
    void updateBalayageStatus(const QString& status, int energie);
    void updateintensite(double intensite);

private:
    // Pointeurs
    Ui::MainWindow *m_ui;
    FenetreConnexion *m_fenetreConnexion;
    Communication *m_communication_SPECS;
    Communication *m_communication_PICO;
    ReleverMesure *m_releverMesure;
    ControleInstrument *m_controleInstrument;
    QThread* m_threadMesure;
    QCustomPlot *m_customPlot;

    // Variables QString pour stocker les paramètres de l'onglet SPECS (énergie, courant, etc.).
    QString Energie, CourantEmission;

    // Variables pour effectuer un balayage des énergies
    QString EnergieMin, EnergieMax, Pas, Duree;

    // Variable QString pour stocker le courant mesuré par PICO.
    QString CourantPico;

};

#endif // MAINWINDOW_H
