QT       += core gui
QT += serialport printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Classes/Communication/communication.cpp \
    Classes/ControleInstrument/controleinstrument.cpp \
    Classes/Graphique/qcustomplot.cpp \
    Classes/ReleverMesure/relevermesure.cpp \
    Fenetres/Connexion/fenetreconnexion.cpp \
    main.cpp \
    Fenetres/MainWindow/mainwindow.cpp

HEADERS += \
    Classes/Communication/communication.h \
    Classes/ControleInstrument/controleinstrument.h \
    Classes/Graphique/qcustomplot.h \
    Classes/ReleverMesure/relevermesure.h \
    Fenetres/Connexion/fenetreconnexion.h \
    Fenetres/MainWindow/mainwindow.h

FORMS += \
    Fenetres/Connexion/fenetreconnexion.ui \
    Fenetres/MainWindow/mainwindow.ui

# Ajouter le chemin d'inclusion pour QCustomPlot
INCLUDEPATH += $$PWD/Classes/Graphique

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
