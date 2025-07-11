/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *PICO;
    QFrame *framePICO1;
    QVBoxLayout *verticalLayout_3;
    QFrame *frameEnergieMininum;
    QGridLayout *_12;
    QLabel *labelEnergieMinimum;
    QLineEdit *lineEditEnergieMinimum;
    QFrame *frameEnergieMaximum;
    QGridLayout *_13;
    QLineEdit *lineEditEnergieMaximum;
    QLabel *labelEnergieMaximum;
    QFrame *framePas;
    QGridLayout *_14;
    QLineEdit *lineEditPas;
    QLabel *labelPas;
    QFrame *frameDuree;
    QGridLayout *_15;
    QLineEdit *lineEditDuree;
    QLabel *labelDuree;
    QPushButton *ValidatePushButtonPICO;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *HeaderPICO;
    QLabel *titrePICO;
    QPushButton *pushButtonConnexion;
    QLabel *labelIntensite_2;
    QLabel *labelInformationBalayage;
    QCustomPlot *customPlot;
    QMenuBar *menubar;
    QToolBar *toolBar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(869, 860);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setEnabled(true);
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        PICO = new QWidget();
        PICO->setObjectName("PICO");
        framePICO1 = new QFrame(PICO);
        framePICO1->setObjectName("framePICO1");
        framePICO1->setGeometry(QRect(60, 130, 691, 381));
        framePICO1->setMinimumSize(QSize(16, 196));
        QPalette palette;
        framePICO1->setPalette(palette);
        framePICO1->setAutoFillBackground(false);
        framePICO1->setStyleSheet(QString::fromUtf8("\n"
"border-color: rgb(0, 0, 255);"));
        framePICO1->setFrameShape(QFrame::Shape::WinPanel);
        framePICO1->setFrameShadow(QFrame::Shadow::Plain);
        framePICO1->setLineWidth(1);
        framePICO1->setMidLineWidth(0);
        verticalLayout_3 = new QVBoxLayout(framePICO1);
        verticalLayout_3->setSpacing(3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        frameEnergieMininum = new QFrame(framePICO1);
        frameEnergieMininum->setObjectName("frameEnergieMininum");
        QPalette palette1;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(240, 236, 227, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        frameEnergieMininum->setPalette(palette1);
        frameEnergieMininum->setAutoFillBackground(true);
        frameEnergieMininum->setFrameShape(QFrame::Shape::WinPanel);
        frameEnergieMininum->setFrameShadow(QFrame::Shadow::Plain);
        frameEnergieMininum->setLineWidth(1);
        _12 = new QGridLayout(frameEnergieMininum);
        _12->setSpacing(6);
        _12->setObjectName("_12");
        labelEnergieMinimum = new QLabel(frameEnergieMininum);
        labelEnergieMinimum->setObjectName("labelEnergieMinimum");
        QFont font;
        font.setPointSize(14);
        font.setBold(false);
        font.setStrikeOut(false);
        font.setKerning(false);
        labelEnergieMinimum->setFont(font);
        labelEnergieMinimum->setAlignment(Qt::AlignmentFlag::AlignCenter);

        _12->addWidget(labelEnergieMinimum, 0, 0, 1, 1);

        lineEditEnergieMinimum = new QLineEdit(frameEnergieMininum);
        lineEditEnergieMinimum->setObjectName("lineEditEnergieMinimum");
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setStrikeOut(false);
        font1.setKerning(false);
        lineEditEnergieMinimum->setFont(font1);

        _12->addWidget(lineEditEnergieMinimum, 1, 0, 1, 1);


        verticalLayout_3->addWidget(frameEnergieMininum);

        frameEnergieMaximum = new QFrame(framePICO1);
        frameEnergieMaximum->setObjectName("frameEnergieMaximum");
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Base, brush);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        frameEnergieMaximum->setPalette(palette2);
        frameEnergieMaximum->setAutoFillBackground(true);
        frameEnergieMaximum->setFrameShape(QFrame::Shape::WinPanel);
        frameEnergieMaximum->setFrameShadow(QFrame::Shadow::Plain);
        frameEnergieMaximum->setLineWidth(1);
        _13 = new QGridLayout(frameEnergieMaximum);
        _13->setSpacing(6);
        _13->setObjectName("_13");
        lineEditEnergieMaximum = new QLineEdit(frameEnergieMaximum);
        lineEditEnergieMaximum->setObjectName("lineEditEnergieMaximum");
        lineEditEnergieMaximum->setFont(font1);

        _13->addWidget(lineEditEnergieMaximum, 1, 0, 1, 1);

        labelEnergieMaximum = new QLabel(frameEnergieMaximum);
        labelEnergieMaximum->setObjectName("labelEnergieMaximum");
        labelEnergieMaximum->setFont(font);
        labelEnergieMaximum->setAlignment(Qt::AlignmentFlag::AlignCenter);

        _13->addWidget(labelEnergieMaximum, 0, 0, 1, 1);


        verticalLayout_3->addWidget(frameEnergieMaximum);

        framePas = new QFrame(framePICO1);
        framePas->setObjectName("framePas");
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Base, brush);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        framePas->setPalette(palette3);
        framePas->setAutoFillBackground(true);
        framePas->setFrameShape(QFrame::Shape::WinPanel);
        framePas->setFrameShadow(QFrame::Shadow::Plain);
        framePas->setLineWidth(1);
        _14 = new QGridLayout(framePas);
        _14->setSpacing(6);
        _14->setObjectName("_14");
        lineEditPas = new QLineEdit(framePas);
        lineEditPas->setObjectName("lineEditPas");
        lineEditPas->setFont(font1);

        _14->addWidget(lineEditPas, 1, 0, 1, 1);

        labelPas = new QLabel(framePas);
        labelPas->setObjectName("labelPas");
        labelPas->setFont(font);
        labelPas->setMouseTracking(false);
        labelPas->setAlignment(Qt::AlignmentFlag::AlignCenter);

        _14->addWidget(labelPas, 0, 0, 1, 1);


        verticalLayout_3->addWidget(framePas);

        frameDuree = new QFrame(framePICO1);
        frameDuree->setObjectName("frameDuree");
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Base, brush);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        frameDuree->setPalette(palette4);
        frameDuree->setAutoFillBackground(true);
        frameDuree->setFrameShape(QFrame::Shape::WinPanel);
        frameDuree->setFrameShadow(QFrame::Shadow::Plain);
        frameDuree->setLineWidth(1);
        _15 = new QGridLayout(frameDuree);
        _15->setSpacing(6);
        _15->setObjectName("_15");
        lineEditDuree = new QLineEdit(frameDuree);
        lineEditDuree->setObjectName("lineEditDuree");
        lineEditDuree->setFont(font1);

        _15->addWidget(lineEditDuree, 2, 0, 1, 1);

        labelDuree = new QLabel(frameDuree);
        labelDuree->setObjectName("labelDuree");
        labelDuree->setFont(font);
        labelDuree->setAlignment(Qt::AlignmentFlag::AlignCenter);

        _15->addWidget(labelDuree, 1, 0, 1, 1);


        verticalLayout_3->addWidget(frameDuree);

        ValidatePushButtonPICO = new QPushButton(PICO);
        ValidatePushButtonPICO->setObjectName("ValidatePushButtonPICO");
        ValidatePushButtonPICO->setGeometry(QRect(-40, 680, 861, 61));
        ValidatePushButtonPICO->setStyleSheet(QString::fromUtf8("font: 15pt \"Segoe UI\";"));
        verticalLayoutWidget_2 = new QWidget(PICO);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(0, 0, 841, 87));
        HeaderPICO = new QVBoxLayout(verticalLayoutWidget_2);
        HeaderPICO->setObjectName("HeaderPICO");
        HeaderPICO->setContentsMargins(0, 0, 0, 0);
        titrePICO = new QLabel(verticalLayoutWidget_2);
        titrePICO->setObjectName("titrePICO");
        titrePICO->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);\n"
"border-color: rgb(0, 0, 255);"));

        HeaderPICO->addWidget(titrePICO);

        pushButtonConnexion = new QPushButton(verticalLayoutWidget_2);
        pushButtonConnexion->setObjectName("pushButtonConnexion");
        pushButtonConnexion->setStyleSheet(QString::fromUtf8("font: 15pt \"Segoe UI\";"));

        HeaderPICO->addWidget(pushButtonConnexion);

        labelIntensite_2 = new QLabel(PICO);
        labelIntensite_2->setObjectName("labelIntensite_2");
        labelIntensite_2->setGeometry(QRect(70, 90, 681, 35));
        labelIntensite_2->setFont(font);
        labelIntensite_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        labelInformationBalayage = new QLabel(PICO);
        labelInformationBalayage->setObjectName("labelInformationBalayage");
        labelInformationBalayage->setGeometry(QRect(110, 620, 671, 51));
        labelInformationBalayage->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";"));
        tabWidget->addTab(PICO, QString());
        customPlot = new QCustomPlot();
        customPlot->setObjectName("customPlot");
        tabWidget->addTab(customPlot, QString());

        horizontalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 869, 26));
        MainWindow->setMenuBar(menubar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::RightToolBarArea, toolBar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(whatsthis)
        PICO->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>dd</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        labelEnergieMinimum->setText(QCoreApplication::translate("MainWindow", "Energie minimum ( eV )", nullptr));
        labelEnergieMaximum->setText(QCoreApplication::translate("MainWindow", "Energie maximum ( eV )", nullptr));
        labelPas->setText(QCoreApplication::translate("MainWindow", "Pas ( eV )", nullptr));
        labelDuree->setText(QCoreApplication::translate("MainWindow", "Dur\303\251e de mesure par \303\251nergie ( s )", nullptr));
        ValidatePushButtonPICO->setText(QCoreApplication::translate("MainWindow", "Valider", nullptr));
        titrePICO->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">CONFIGURATION PICOAMPEREMETRE</span></p></body></html>", nullptr));
        pushButtonConnexion->setText(QCoreApplication::translate("MainWindow", "Connexion", nullptr));
        labelIntensite_2->setText(QCoreApplication::translate("MainWindow", "Intensit\303\251 :", nullptr));
        labelInformationBalayage->setText(QCoreApplication::translate("MainWindow", "Pr\303\252t pour le balayage", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(PICO), QCoreApplication::translate("MainWindow", "Configuration picoamperemetre", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(customPlot), QCoreApplication::translate("MainWindow", "Courbe SEY", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
