#include "controleinstrument.h"
#include <QDebug>
#include <QElapsedTimer>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QMessageBox>

ControleInstrument::ControleInstrument(Communication* communicationSPECS,
                                       Communication* communicationPICO,
                                       QObject *parent)
    : QObject(parent),
    m_communicationSPECS(communicationSPECS),
    m_communicationPICO(communicationPICO)
{
}


// Met en pause le thread un certains temps sans compromettre l'interface.
// Cette méthode est utilisée pour donner le temps au courant d'émission de se calibrer sur la valeur voulu, pendant le balayage des énergies.
void ControleInstrument::attenteAsynchrone(int millisecondes)
{
    // Si on est dans un thread secondaire, en met en pause le thread
    if (QThread::currentThread() != qApp->thread()) {
        QThread::msleep(millisecondes);
    } else {
        // Si on est dans le thread principal (GUI)
        QEventLoop loop;
        QTimer::singleShot(millisecondes, &loop, SLOT(quit()));
        loop.exec();
    }
}






void ControleInstrument::changerPolarisation() {
    if(polarisation == "+50V"){
        polarisation = "-50V";
    }
    else{
        polarisation = "+50V";
    }
}



void ControleInstrument::validate_button_clickedPICO(
    const QString& EnergieMin,
    const QString& EnergieMax,
    const QString& Pas,
    const QString& Duree)
{
    m_communicationSPECS->envoyer("F1 7400");
    QMap<double, QVector<double>> mesuresParEnergie;
    QStringList tableau1Lignes;
    QMap<double, QMap<QString, double>> moyennes;

    // Vérification champs non vide
    if (EnergieMin.isEmpty() || EnergieMax.isEmpty() || Pas.isEmpty() || Duree.isEmpty()) {
        qDebug() << "Tous les champs doivent être remplis.";
        QMessageBox::critical(nullptr, "Erreur de champs vide", "Tous les champs doivent être remplis.");
        return;
    }

    if (!m_communicationPICO) {
        qDebug() << "❌ m_communicationPICO est null !";
        return;
    }

    int eMin = EnergieMin.toInt();
    int eMax = EnergieMax.toInt();
    int pas = Pas.toInt();
    int duree = Duree.toInt();

    // Vérification énergies correctes
    if ( !(0 <= eMin && eMin <= 2000 )  || !(0 <= eMax && eMax <= 2000 ) || !(eMin <= eMax) ) {
        qDebug() << "Valeurs de eMin, eMax,";
        QMessageBox::critical(nullptr, "Erreur de valeur", "énergie minimum et maximum doit être compris entre 0 et 2000,"
                                                           " et l'énergie minimum doit être inférieur à l'énergie maximum");
        return;
    }



    QFile fichier("C:/Users/Mesure/Documents/Nyle/mesures_pico.csv");
    if (!fichier.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qDebug() << "❌ Impossible d'ouvrir le fichier. Vérifier qu'il soit bien fermé.";
        QMessageBox::information(nullptr, "Demande balayage",
                                 QString("Impossible d'ouvrir le fichier. Vérifier qu'il soit bien fermé"));
        return;
    }
    QTextStream out(&fichier);


    // Écrire les en-têtes si le fichier est vide
    if (fichier.size() == 0) {
        out << "Date et heure;Temps ecoule (s);Energie (eV);Polarisation;Intensite brute;;"
            << "Energie (eV);Intensite moyenne (+50V);Intensite moyenne (-50V);SEY\n";
    }
    fichier.seek(fichier.size());

    // Fonction interne pour effectuer un balayage
    auto performBalayage = [&]() {
        if (polarisation == "+50V") {
            QMessageBox::information(nullptr, "Polarisation requise",
                                     QString("Merci de bien vouloir polariser à %1 avant de commencer.").arg(polarisation));
        }

        for (int energie = eMin; energie <= eMax; energie += pas) {
            m_communicationSPECS->envoyer("EN " + QString::number(energie));
            qDebug() << "Energie appliquée :" << energie;

            emit balayageStatusChanged("Balayage en cours ...", energie, NULL);
            attenteAsynchrone(2000);

            QElapsedTimer timer;
            timer.start();

            while (timer.elapsed() < duree * 1000) {
                m_communicationPICO->envoyer("READ?");
                QString intensite = m_communicationPICO->recevoirKeithley6485();
                bool ok;
                double intensiteNum = intensite.trimmed().toDouble(&ok);
                emit intensiteChanged(intensiteNum);

                if (ok) {
                    mesuresParEnergie[energie].append(intensiteNum);
                }

                QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
                double tempsEcoule = timer.elapsed() / 1000.0;

                QString ligne = QString("%1;%2;%3;%4;%5")
                                    .arg(timestamp)
                                    .arg(QString::number(tempsEcoule, 'f', 2))
                                    .arg(QString::number(energie, 'f', 2))
                                    .arg(polarisation)
                                    .arg(intensite.trimmed());
                tableau1Lignes.append(ligne);

                qDebug() << "⏱ Mesure :" << timestamp << " | " << tempsEcoule << "s | "
                         << energie << "eV | " << polarisation << " | " << intensite;
            }

            const QVector<double>& valeurs = mesuresParEnergie[energie];
            double somme = std::accumulate(valeurs.begin(), valeurs.end(), 0.0);
            double moyenne = valeurs.isEmpty() ? 0.0 : somme / valeurs.size();
            moyennes[energie][polarisation] = moyenne;
        }

        QStringList tableau2Lignes;
        for (auto it = moyennes.begin(); it != moyennes.end(); ++it) {
            int energie = it.key();
            double imPlus = it.value().value("+50V", std::numeric_limits<double>::quiet_NaN());
            double imMoins = it.value().value("-50V", std::numeric_limits<double>::quiet_NaN());
            QString sey;

            if (!std::isnan(imPlus) && !std::isnan(imMoins) && imPlus != 0) {
                double seyVal = 1 - (imMoins / imPlus);
                sey = QString::number(seyVal, 'f', 6);
            }

            QString ligne = QString("%1;%2;%3;%4")
                                .arg(QString::number(energie, 'f', 2))
                                .arg(std::isnan(imPlus) ? "" : QString::number(imPlus, 'e', 10))
                                .arg(std::isnan(imMoins) ? "" : QString::number(imMoins, 'e', 10))
                                .arg(sey);
            tableau2Lignes.append(ligne);
        }

        // Aligner les lignes et éviter la répétition
        int maxLignes = qMax(tableau1Lignes.size(), tableau2Lignes.size());
        for (int i = 0; i < maxLignes; ++i) {
            QString ligneTableau1 = (i < tableau1Lignes.size()) ? tableau1Lignes[i] : ";;;;";
            QString ligneTableau2 = (i < tableau2Lignes.size()) ? tableau2Lignes[i] : ";;;";
            // Si c'est une ligne supplémentaire du second tableau, écrire avec champs vides pour le premier
            if (i >= tableau1Lignes.size()) {
                out << ";;;;;;" << ligneTableau2 << "\n";
            } else {
                out << ligneTableau1 << ";;" << ligneTableau2 << "\n";
            }
        }
    };

    // Premier balayage
    performBalayage();

    // Second balayage
    if (polarisation == "+50V") {
        QMessageBox::information(nullptr, "Polarisation requise",
                                 QString("Merci de bien vouloir polariser à -50V avant de commencer."));
        changerPolarisation();
        mesuresParEnergie.clear();
        tableau1Lignes.clear();
        performBalayage();
    }

    // Ajouter 3 lignes vides
    for (int i = 0; i < 3; ++i) {
        out << "\n";
    }

    fichier.flush();
    fichier.close();
    changerPolarisation();
    qDebug() << "✅ Fichier mis à jour avec deux tableaux séparés sans répétition.";

    emit balayageStatusChanged("Balayage terminé", NULL, intensiteNum );
    QMessageBox::information(nullptr, "Balayage terminé",
                             QString("Le balayage est terminé, fichier mesures_pico mis à jour avec deux tableaux séparés."));
}



void ControleInstrument::initialisationPICO(Communication *communicationPICO)
{

    if (this != nullptr) {
        qDebug() << "this = " << this;
    }

    qDebug() << "communicationPICO = " << communicationPICO;

    if (!communicationPICO) {
        qDebug() << "❌ ERREUR : communicationPICO est nullptr";
    }
    qDebug() << "Port : " << communicationPICO->obtenirPort();

    m_communicationPICO = communicationPICO;

    qDebug() << "--------------OPERATION PICO-----------------";
    m_communicationPICO->envoyer("*RST");
    m_communicationPICO->envoyer("SYST:ZCH ON");
    m_communicationPICO->envoyer("CURR:RANG:AUTO ON");
    m_communicationPICO->envoyer("INIT");
    m_communicationPICO->envoyer("SYST:ZCOR:ACQ");
    m_communicationPICO->envoyer("SYST:ZCOR ON");
    m_communicationPICO->envoyer("CURR:RANG:AUTO ON");
    m_communicationPICO->envoyer("SYST:ZCH OFF");


    m_communicationPICO->envoyer("CURR:NPLC 0.01");

}


void ControleInstrument::initialisationSPECS(Communication *m_communicationSPECS){
    qDebug() << "Activation du mode REMOTE";
    m_communicationSPECS->envoyer("RE");
}

