#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Fenetres/Connexion/fenetreconnexion.h"
#include "Classes/ReleverMesure/releverMesure.h"  // Ajoute l'inclusion de la nouvelle classe



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void connexion_button_clicked();
    void validate_button_clicked();
    void transmissionResultatRecu(QString CurrentEnergie, QString CurrentSourceVoltage, QString CurrentGridVoltage, QString CurrentFocusVoltage,
                                  QString CurrentCourantEmission, QString CurrentSourceCurrent);




private:
    Ui::MainWindow *m_ui;
    FenetreConnexion *m_fenetreConnexion;
    Communication *m_communication;
    ReleverMesure * m_releverMesure;
    QThread* m_threadMesure;

};

#endif // MAINWINDOW_H
