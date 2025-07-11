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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *Header;
    QLabel *label_1;
    QPushButton *pushButtonConnexion;
    QFrame *frame1;
    QVBoxLayout *verticalLayout_2;
    QFrame *frameEnergie;
    QGridLayout *_10;
    QLabel *labelEnergie;
    QLineEdit *lineEditEnergie;
    QLabel *valeurMesurer;
    QLabel *valeurMesurerEnergie;
    QFrame *frameCourantEmission;
    QGridLayout *_8;
    QLineEdit *lineEditCourantEmission;
    QLabel *labelCourantEmission;
    QLabel *valeurMesurerCourantEmission;
    QLabel *valeurMesurer_3;
    QFrame *frameFocus;
    QGridLayout *_9;
    QLineEdit *lineEditFocus;
    QLabel *valeurMesurer_2;
    QLabel *valeurMesurerFocus;
    QLabel *labelFocus;
    QLabel *valeurMesurer_9;
    QLabel *valeurMesurerFocusEv;
    QFrame *frameSourceVoltage;
    QGridLayout *_7;
    QLabel *valeurMesurer_4;
    QLabel *labelSourceVoltage;
    QLabel *valeurMesurerSourceVoltage;
    QLineEdit *lineEditSourceVoltage;
    QFrame *frameGridVoltage;
    QGridLayout *_11;
    QLabel *labelGridVoltage;
    QLabel *valeurMesurer_5;
    QLabel *valeurMesurerGridVoltage;
    QLineEdit *lineEditGridVoltage;
    QFrame *frameSourceCurrent;
    QGridLayout *_12;
    QLabel *labelSourceCurrent;
    QLabel *valeurMesurer_6;
    QLabel *valeurMesurerSourceCurrent;
    QLineEdit *lineEditSourceCurrent;
    QPushButton *ValidatePushButton;
    QMenuBar *menubar;
    QToolBar *toolBar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(856, 898);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 0, 821, 87));
        Header = new QVBoxLayout(verticalLayoutWidget);
        Header->setObjectName("Header");
        Header->setContentsMargins(0, 0, 0, 0);
        label_1 = new QLabel(verticalLayoutWidget);
        label_1->setObjectName("label_1");
        label_1->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);\n"
"border-color: rgb(0, 0, 255);"));

        Header->addWidget(label_1);

        pushButtonConnexion = new QPushButton(verticalLayoutWidget);
        pushButtonConnexion->setObjectName("pushButtonConnexion");
        pushButtonConnexion->setStyleSheet(QString::fromUtf8("font: 15pt \"Segoe UI\";"));

        Header->addWidget(pushButtonConnexion);

        frame1 = new QFrame(centralwidget);
        frame1->setObjectName("frame1");
        frame1->setGeometry(QRect(70, 100, 691, 651));
        frame1->setMinimumSize(QSize(16, 196));
        QPalette palette;
        frame1->setPalette(palette);
        frame1->setAutoFillBackground(false);
        frame1->setStyleSheet(QString::fromUtf8("\n"
"border-color: rgb(0, 0, 255);"));
        frame1->setFrameShape(QFrame::Shape::WinPanel);
        frame1->setFrameShadow(QFrame::Shadow::Plain);
        frame1->setLineWidth(1);
        frame1->setMidLineWidth(0);
        verticalLayout_2 = new QVBoxLayout(frame1);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setObjectName("verticalLayout_2");
        frameEnergie = new QFrame(frame1);
        frameEnergie->setObjectName("frameEnergie");
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
        frameEnergie->setPalette(palette1);
        frameEnergie->setAutoFillBackground(true);
        frameEnergie->setFrameShape(QFrame::Shape::WinPanel);
        frameEnergie->setFrameShadow(QFrame::Shadow::Plain);
        frameEnergie->setLineWidth(1);
        _10 = new QGridLayout(frameEnergie);
        _10->setSpacing(6);
        _10->setObjectName("_10");
        labelEnergie = new QLabel(frameEnergie);
        labelEnergie->setObjectName("labelEnergie");
        QFont font;
        font.setPointSize(14);
        font.setBold(false);
        font.setStrikeOut(false);
        font.setKerning(false);
        labelEnergie->setFont(font);
        labelEnergie->setAlignment(Qt::AlignmentFlag::AlignCenter);

        _10->addWidget(labelEnergie, 0, 0, 1, 1);

        lineEditEnergie = new QLineEdit(frameEnergie);
        lineEditEnergie->setObjectName("lineEditEnergie");
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setStrikeOut(false);
        font1.setKerning(false);
        lineEditEnergie->setFont(font1);

        _10->addWidget(lineEditEnergie, 1, 0, 1, 1);

        valeurMesurer = new QLabel(frameEnergie);
        valeurMesurer->setObjectName("valeurMesurer");
        valeurMesurer->setFont(font);
        valeurMesurer->setAlignment(Qt::AlignmentFlag::AlignCenter);

        _10->addWidget(valeurMesurer, 0, 1, 1, 1);

        valeurMesurerEnergie = new QLabel(frameEnergie);
        valeurMesurerEnergie->setObjectName("valeurMesurerEnergie");
        valeurMesurerEnergie->setStyleSheet(QString::fromUtf8("font: 20pt \"Segoe UI\";"));

        _10->addWidget(valeurMesurerEnergie, 1, 1, 1, 1);


        verticalLayout_2->addWidget(frameEnergie);

        frameCourantEmission = new QFrame(frame1);
        frameCourantEmission->setObjectName("frameCourantEmission");
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Base, brush);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        frameCourantEmission->setPalette(palette2);
        frameCourantEmission->setAutoFillBackground(true);
        frameCourantEmission->setFrameShape(QFrame::Shape::WinPanel);
        frameCourantEmission->setFrameShadow(QFrame::Shadow::Plain);
        frameCourantEmission->setLineWidth(1);
        _8 = new QGridLayout(frameCourantEmission);
        _8->setSpacing(6);
        _8->setObjectName("_8");
        lineEditCourantEmission = new QLineEdit(frameCourantEmission);
        lineEditCourantEmission->setObjectName("lineEditCourantEmission");
        lineEditCourantEmission->setFont(font1);

        _8->addWidget(lineEditCourantEmission, 1, 0, 1, 1);

        labelCourantEmission = new QLabel(frameCourantEmission);
        labelCourantEmission->setObjectName("labelCourantEmission");
        labelCourantEmission->setFont(font);
        labelCourantEmission->setAlignment(Qt::AlignmentFlag::AlignCenter);

        _8->addWidget(labelCourantEmission, 0, 0, 1, 1);

        valeurMesurerCourantEmission = new QLabel(frameCourantEmission);
        valeurMesurerCourantEmission->setObjectName("valeurMesurerCourantEmission");
        valeurMesurerCourantEmission->setStyleSheet(QString::fromUtf8("font: 20pt \"Segoe UI\";"));

        _8->addWidget(valeurMesurerCourantEmission, 1, 1, 1, 1);

        valeurMesurer_3 = new QLabel(frameCourantEmission);
        valeurMesurer_3->setObjectName("valeurMesurer_3");
        valeurMesurer_3->setFont(font);
        valeurMesurer_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        _8->addWidget(valeurMesurer_3, 0, 1, 1, 1);


        verticalLayout_2->addWidget(frameCourantEmission);

        frameFocus = new QFrame(frame1);
        frameFocus->setObjectName("frameFocus");
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Base, brush);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        frameFocus->setPalette(palette3);
        frameFocus->setAutoFillBackground(true);
        frameFocus->setFrameShape(QFrame::Shape::WinPanel);
        frameFocus->setFrameShadow(QFrame::Shadow::Plain);
        frameFocus->setLineWidth(1);
        _9 = new QGridLayout(frameFocus);
        _9->setSpacing(6);
        _9->setObjectName("_9");
        lineEditFocus = new QLineEdit(frameFocus);
        lineEditFocus->setObjectName("lineEditFocus");
        lineEditFocus->setFont(font1);

        _9->addWidget(lineEditFocus, 1, 0, 1, 1);

        valeurMesurer_2 = new QLabel(frameFocus);
        valeurMesurer_2->setObjectName("valeurMesurer_2");
        valeurMesurer_2->setFont(font);
        valeurMesurer_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        _9->addWidget(valeurMesurer_2, 0, 1, 1, 1);

        valeurMesurerFocus = new QLabel(frameFocus);
        valeurMesurerFocus->setObjectName("valeurMesurerFocus");
        valeurMesurerFocus->setStyleSheet(QString::fromUtf8("font: 20pt \"Segoe UI\";"));

        _9->addWidget(valeurMesurerFocus, 1, 1, 1, 1);

        labelFocus = new QLabel(frameFocus);
        labelFocus->setObjectName("labelFocus");
        labelFocus->setFont(font);
        labelFocus->setMouseTracking(false);
        labelFocus->setAlignment(Qt::AlignmentFlag::AlignCenter);

        _9->addWidget(labelFocus, 0, 0, 1, 1);

        valeurMesurer_9 = new QLabel(frameFocus);
        valeurMesurer_9->setObjectName("valeurMesurer_9");
        valeurMesurer_9->setFont(font);
        valeurMesurer_9->setAlignment(Qt::AlignmentFlag::AlignCenter);

        _9->addWidget(valeurMesurer_9, 0, 2, 1, 1);

        valeurMesurerFocusEv = new QLabel(frameFocus);
        valeurMesurerFocusEv->setObjectName("valeurMesurerFocusEv");
        valeurMesurerFocusEv->setStyleSheet(QString::fromUtf8("font: 20pt \"Segoe UI\";"));

        _9->addWidget(valeurMesurerFocusEv, 1, 2, 1, 1);


        verticalLayout_2->addWidget(frameFocus);

        frameSourceVoltage = new QFrame(frame1);
        frameSourceVoltage->setObjectName("frameSourceVoltage");
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Base, brush);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        frameSourceVoltage->setPalette(palette4);
        frameSourceVoltage->setAutoFillBackground(true);
        frameSourceVoltage->setFrameShape(QFrame::Shape::WinPanel);
        frameSourceVoltage->setFrameShadow(QFrame::Shadow::Plain);
        frameSourceVoltage->setLineWidth(1);
        _7 = new QGridLayout(frameSourceVoltage);
        _7->setSpacing(6);
        _7->setObjectName("_7");
        valeurMesurer_4 = new QLabel(frameSourceVoltage);
        valeurMesurer_4->setObjectName("valeurMesurer_4");
        valeurMesurer_4->setFont(font);
        valeurMesurer_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        _7->addWidget(valeurMesurer_4, 1, 1, 1, 1);

        labelSourceVoltage = new QLabel(frameSourceVoltage);
        labelSourceVoltage->setObjectName("labelSourceVoltage");
        labelSourceVoltage->setFont(font);
        labelSourceVoltage->setAlignment(Qt::AlignmentFlag::AlignCenter);

        _7->addWidget(labelSourceVoltage, 1, 0, 1, 1);

        valeurMesurerSourceVoltage = new QLabel(frameSourceVoltage);
        valeurMesurerSourceVoltage->setObjectName("valeurMesurerSourceVoltage");
        valeurMesurerSourceVoltage->setStyleSheet(QString::fromUtf8("font: 20pt \"Segoe UI\";"));

        _7->addWidget(valeurMesurerSourceVoltage, 2, 1, 1, 1);

        lineEditSourceVoltage = new QLineEdit(frameSourceVoltage);
        lineEditSourceVoltage->setObjectName("lineEditSourceVoltage");
        lineEditSourceVoltage->setFont(font1);

        _7->addWidget(lineEditSourceVoltage, 2, 0, 1, 1);


        verticalLayout_2->addWidget(frameSourceVoltage);

        frameGridVoltage = new QFrame(frame1);
        frameGridVoltage->setObjectName("frameGridVoltage");
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Base, brush);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        frameGridVoltage->setPalette(palette5);
        frameGridVoltage->setAutoFillBackground(true);
        frameGridVoltage->setFrameShape(QFrame::Shape::WinPanel);
        frameGridVoltage->setFrameShadow(QFrame::Shadow::Plain);
        frameGridVoltage->setLineWidth(1);
        _11 = new QGridLayout(frameGridVoltage);
        _11->setSpacing(6);
        _11->setObjectName("_11");
        labelGridVoltage = new QLabel(frameGridVoltage);
        labelGridVoltage->setObjectName("labelGridVoltage");
        labelGridVoltage->setFont(font);
        labelGridVoltage->setAlignment(Qt::AlignmentFlag::AlignCenter);

        _11->addWidget(labelGridVoltage, 1, 0, 1, 1);

        valeurMesurer_5 = new QLabel(frameGridVoltage);
        valeurMesurer_5->setObjectName("valeurMesurer_5");
        valeurMesurer_5->setFont(font);
        valeurMesurer_5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        _11->addWidget(valeurMesurer_5, 0, 1, 1, 1);

        valeurMesurerGridVoltage = new QLabel(frameGridVoltage);
        valeurMesurerGridVoltage->setObjectName("valeurMesurerGridVoltage");
        valeurMesurerGridVoltage->setStyleSheet(QString::fromUtf8("font: 20pt \"Segoe UI\";"));

        _11->addWidget(valeurMesurerGridVoltage, 2, 1, 1, 1);

        lineEditGridVoltage = new QLineEdit(frameGridVoltage);
        lineEditGridVoltage->setObjectName("lineEditGridVoltage");
        lineEditGridVoltage->setFont(font1);

        _11->addWidget(lineEditGridVoltage, 2, 0, 1, 1);


        verticalLayout_2->addWidget(frameGridVoltage);

        frameSourceCurrent = new QFrame(frame1);
        frameSourceCurrent->setObjectName("frameSourceCurrent");
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Base, brush);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        frameSourceCurrent->setPalette(palette6);
        frameSourceCurrent->setAutoFillBackground(true);
        frameSourceCurrent->setFrameShape(QFrame::Shape::WinPanel);
        frameSourceCurrent->setFrameShadow(QFrame::Shadow::Plain);
        frameSourceCurrent->setLineWidth(1);
        _12 = new QGridLayout(frameSourceCurrent);
        _12->setSpacing(6);
        _12->setObjectName("_12");
        labelSourceCurrent = new QLabel(frameSourceCurrent);
        labelSourceCurrent->setObjectName("labelSourceCurrent");
        labelSourceCurrent->setFont(font);
        labelSourceCurrent->setAlignment(Qt::AlignmentFlag::AlignCenter);

        _12->addWidget(labelSourceCurrent, 1, 0, 1, 1);

        valeurMesurer_6 = new QLabel(frameSourceCurrent);
        valeurMesurer_6->setObjectName("valeurMesurer_6");
        valeurMesurer_6->setFont(font);
        valeurMesurer_6->setAlignment(Qt::AlignmentFlag::AlignCenter);

        _12->addWidget(valeurMesurer_6, 0, 1, 1, 1);

        valeurMesurerSourceCurrent = new QLabel(frameSourceCurrent);
        valeurMesurerSourceCurrent->setObjectName("valeurMesurerSourceCurrent");
        valeurMesurerSourceCurrent->setStyleSheet(QString::fromUtf8("font: 20pt \"Segoe UI\";"));

        _12->addWidget(valeurMesurerSourceCurrent, 2, 1, 1, 1);

        lineEditSourceCurrent = new QLineEdit(frameSourceCurrent);
        lineEditSourceCurrent->setObjectName("lineEditSourceCurrent");
        lineEditSourceCurrent->setFont(font1);

        _12->addWidget(lineEditSourceCurrent, 2, 0, 1, 1);


        verticalLayout_2->addWidget(frameSourceCurrent);

        ValidatePushButton = new QPushButton(centralwidget);
        ValidatePushButton->setObjectName("ValidatePushButton");
        ValidatePushButton->setGeometry(QRect(0, 760, 831, 51));
        ValidatePushButton->setStyleSheet(QString::fromUtf8("font: 15pt \"Segoe UI\";"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 856, 26));
        MainWindow->setMenuBar(menubar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::RightToolBarArea, toolBar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_1->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">CONFIGURATION</span></p></body></html>", nullptr));
        pushButtonConnexion->setText(QCoreApplication::translate("MainWindow", "Connexion", nullptr));
        labelEnergie->setText(QCoreApplication::translate("MainWindow", "Energie ( eV )", nullptr));
        valeurMesurer->setText(QCoreApplication::translate("MainWindow", "Valeur mesur\303\251e", nullptr));
        valeurMesurerEnergie->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labelCourantEmission->setText(QCoreApplication::translate("MainWindow", "Courant d'\303\251mission ( \302\265A )", nullptr));
        valeurMesurerCourantEmission->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        valeurMesurer_3->setText(QCoreApplication::translate("MainWindow", "Valeur mesur\303\251e", nullptr));
        valeurMesurer_2->setText(QCoreApplication::translate("MainWindow", "Valeur mesur\303\251e", nullptr));
        valeurMesurerFocus->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labelFocus->setText(QCoreApplication::translate("MainWindow", "Focus Voltage ( % )", nullptr));
        valeurMesurer_9->setText(QCoreApplication::translate("MainWindow", "Valeur mesur\303\251e", nullptr));
        valeurMesurerFocusEv->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        valeurMesurer_4->setText(QCoreApplication::translate("MainWindow", "Valeur mesur\303\251e", nullptr));
        labelSourceVoltage->setText(QCoreApplication::translate("MainWindow", "Source Voltage ( V )", nullptr));
        valeurMesurerSourceVoltage->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labelGridVoltage->setText(QCoreApplication::translate("MainWindow", "GridVoltage ( V )", nullptr));
        valeurMesurer_5->setText(QCoreApplication::translate("MainWindow", "Valeur mesur\303\251e", nullptr));
        valeurMesurerGridVoltage->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labelSourceCurrent->setText(QCoreApplication::translate("MainWindow", "Source Current", nullptr));
        valeurMesurer_6->setText(QCoreApplication::translate("MainWindow", "Valeur mesur\303\251e", nullptr));
        valeurMesurerSourceCurrent->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        ValidatePushButton->setText(QCoreApplication::translate("MainWindow", "Valider", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
