#include "fenetreconnexion.h"
#include "ui_fenetreconnexion.h"
#include <iostream>
#include <QTimer>

#include <QDebug>

FenetreConnexion::FenetreConnexion(QWidget *parent)
    : QDialog(parent)
    , m_ui(new Ui::FenetreConnexion)
{
    m_ui->setupUi(this);
}


FenetreConnexion::FenetreConnexion(QWidget *parent, Communication *communication)
    : QDialog(parent)
    , m_ui(new Ui::FenetreConnexion)
{
    m_ui->setupUi(this);

    // Recuperation des infos depuis l'interface
    m_com = m_ui->lineEdit->text();
    m_baudRate = m_ui->comboBox->currentText();

    m_communication = communication;
}

FenetreConnexion::~FenetreConnexion()
{
    delete m_ui;
}


// Se connecte à l'alimentation, active le control à distance et actualise
void FenetreConnexion::on_pushButton_rs232_clicked()
{
    m_com = m_ui->lineEdit->text();
    m_baudRate = m_ui->comboBox->currentText();
    bool estConnecte = m_communication->connexion(m_com, m_baudRate);

    if (estConnecte) {

        m_communication->envoyer("gs");
        qDebug() << m_communication->recevoir();

        m_communication->envoyer("po:0,1000"); // Modification de l'énergie

        m_communication->envoyer("gi:0"); // lecture energie
        qDebug() << m_communication->recevoir();

        m_communication->envoyer("po:4,500"); // Modification de focus V

        m_communication->envoyer("gi:4"); // lecture Focus V
        qDebug() << m_communication->recevoir();



        //emit connexionEtablie(); // Envoie le signal à MainWindow
    }

    this->hide();
}
