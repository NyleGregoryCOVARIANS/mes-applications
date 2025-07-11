#ifndef RELEVERMESURE_H
#define RELEVERMESURE_H

#include <QObject>
#include <QTimer>
#include "Classes/Communication/communication.h"

class ReleverMesure : public QObject
{
    Q_OBJECT

public:
    explicit ReleverMesure(Communication *communication, QObject *parent = nullptr);
    ~ReleverMesure();



signals:
    void transmissionResultatPret(QString resultatRequeteEnergie, QString resultatRequeteSourceVoltage, QString resultatRequeteGridVoltage, QString resultatRequeteFocusVoltage,
                                  QString resultatRequeteCourantEmission, QString resultatRequeteSourceCurrent);

public slots:
    void actualisationMesures();
    void start();
    void stop();

private:
    Communication *m_communication;
    QTimer *m_timer;
};

#endif // RELEVERMESURE_H
