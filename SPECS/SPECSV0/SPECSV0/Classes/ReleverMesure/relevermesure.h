#ifndef RELEVERMESURE_H
#define RELEVERMESURE_H

#include <QObject>
#include <QTimer>
#include "Classes/Communication/communication.h"

class ReleverMesure : public QObject
{
    Q_OBJECT

public:    
    explicit ReleverMesure(Communication *m_communication_SPECS, Communication *m_communication_PICO, QObject *parent = nullptr);
    void initialisationSPECS(Communication *m_communicationSPECS);
    void initialisationPICO(Communication *m_communicationPICO);

    void validate_button_clickedSPECS(
        const QString& Energie,
        const QString& CourantEmission,
        const QString& Focus,
        const QString& Wehnelt,
        const QString& PositionX,
        const QString& PositionY,
        const QString& BalayageX,
        const QString& BalayageY
        );

    void on_checkBoxHV_toggled(bool checked);
    void on_checkBoxOperate_toggled(bool checked);

    ~ReleverMesure();

    Q_INVOKABLE void start();
    Q_INVOKABLE void restart();
    void stop();


signals:
    void transmissionResultatSPECS(QString CurrentEnergie, QString CurrentCourantEmission, QString CurrentFocus, QString CurrentWehnelt,
                                  QString CurrentPosX, QString CurrentPosY, QString CurrentBalX, QString CurrentBalY, QString CurrentCourant);
    void requestRestart(); // signal pour demandé un restart au timer ( utilisation pas obligatoire )
    void requestStop(); // signal pour demandé un stop au timer ( utilisation pas obligatoire )

public slots:
    void actualisationMesuresSPECS();
    void startTimer();

private:
    Communication *m_communication_SPECS;
    Communication *m_communication_PICO;
    QTimer *m_timer;
};

#endif // RELEVERMESURE_H
