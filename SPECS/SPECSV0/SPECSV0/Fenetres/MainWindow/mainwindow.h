#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>

#include "Fenetres/Connexion/fenetreconnexion.h"
#include "Classes/ReleverMesure/releverMesure.h"

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


private slots:
    // Affiche la fenêtre de connexion lorsqu'un bouton est cliqué
    void connexion_button_clicked();


    // Affiche les résultats reçus d'un instrument SPECS dans l'interface avec ajustement des échelles
    void affichageResultatRecuSPECS(QString CurrentEnergie, QString CurrentCourantEmission,
                                    QString CurrentFocus, QString CurrentWehnelt,
                                    QString CurrentPosX, QString CurrentPosY,
                                    QString CurrentBalX, QString CurrentBalY, QString CurrentCourant);



private:
    // Pointeurs
    Ui::MainWindow *m_ui;
    FenetreConnexion *m_fenetreConnexion;
    Communication *m_communication_SPECS;
    Communication *m_communication_PICO;
    ReleverMesure *m_releverMesure;
    QThread* m_threadMesure;

    // Variables QString pour stocker les paramètres de l'onglet SPECS (énergie, courant, etc.).
    QString Energie, CourantEmission, Focus, Wehnelt, PositionX, PositionY, BalayageX, BalayageY;

    // Variable QString pour stocker le courant mesuré par PICO.
    QString CourantPico;

};

#endif // MAINWINDOW_H
