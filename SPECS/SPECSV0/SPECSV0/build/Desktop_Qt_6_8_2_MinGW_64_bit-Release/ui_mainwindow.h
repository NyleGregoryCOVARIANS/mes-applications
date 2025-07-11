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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *SPECS;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *HeaderSPECS;
    QLabel *titreSPECS;
    QPushButton *pushButtonConnexion;
    QFrame *frameSPECS1;
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
    QFrame *frameWehnelt;
    QGridLayout *_7;
    QLineEdit *lineEditWehnelt;
    QLabel *valeurMesurerWehnelt;
    QLabel *labelWehnelt;
    QLabel *valeurMesurer_4;
    QFrame *frameSPECS2;
    QGridLayout *gridLayout;
    QFrame *frameBalayageY;
    QGridLayout *_2;
    QLineEdit *lineEditBalayageY;
    QLabel *label_9;
    QLabel *valeurMesurer_8;
    QLabel *valeurMesurerBalayageY;
    QFrame *frameBalayageX;
    QGridLayout *_4;
    QLineEdit *lineEditBalayageX;
    QLabel *labelBalayageX;
    QLabel *valeurMesurer_7;
    QLabel *valeurMesurerBalayageX;
    QFrame *framePositionX;
    QGridLayout *_5;
    QLabel *labelPositionX;
    QLineEdit *lineEditPositionX;
    QLabel *valeurMesurer_5;
    QLabel *valeurMesurerPositionX;
    QFrame *framePositionY;
    QGridLayout *_3;
    QLabel *labelPositionY;
    QLineEdit *lineEditPositionY;
    QLabel *valeurMesurer_6;
    QLabel *valeurMesurerPositionY;
    QPushButton *ValidatePushButtonSPECS;
    QScrollBar *verticalScrollBar;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *frameControl;
    QCheckBox *checkBoxHV;
    QCheckBox *checkBoxOperate;
    QLabel *labelIntensite;
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
        SPECS = new QWidget();
        SPECS->setObjectName("SPECS");
        verticalLayoutWidget = new QWidget(SPECS);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 0, 841, 96));
        HeaderSPECS = new QVBoxLayout(verticalLayoutWidget);
        HeaderSPECS->setObjectName("HeaderSPECS");
        HeaderSPECS->setContentsMargins(0, 0, 0, 0);
        titreSPECS = new QLabel(verticalLayoutWidget);
        titreSPECS->setObjectName("titreSPECS");
        titreSPECS->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);\n"
"border-color: rgb(0, 0, 255);"));

        HeaderSPECS->addWidget(titreSPECS);

        pushButtonConnexion = new QPushButton(verticalLayoutWidget);
        pushButtonConnexion->setObjectName("pushButtonConnexion");
        pushButtonConnexion->setStyleSheet(QString::fromUtf8("font: 15pt \"Segoe UI\";"));

        HeaderSPECS->addWidget(pushButtonConnexion);

        frameSPECS1 = new QFrame(SPECS);
        frameSPECS1->setObjectName("frameSPECS1");
        frameSPECS1->setGeometry(QRect(70, 140, 691, 321));
        frameSPECS1->setMinimumSize(QSize(16, 196));
        QPalette palette;
        frameSPECS1->setPalette(palette);
        frameSPECS1->setAutoFillBackground(false);
        frameSPECS1->setStyleSheet(QString::fromUtf8("\n"
"border-color: rgb(0, 0, 255);"));
        frameSPECS1->setFrameShape(QFrame::Shape::WinPanel);
        frameSPECS1->setFrameShadow(QFrame::Shadow::Plain);
        frameSPECS1->setLineWidth(1);
        frameSPECS1->setMidLineWidth(0);
        verticalLayout_2 = new QVBoxLayout(frameSPECS1);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setObjectName("verticalLayout_2");
        frameEnergie = new QFrame(frameSPECS1);
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

        frameCourantEmission = new QFrame(frameSPECS1);
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

        frameFocus = new QFrame(frameSPECS1);
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

        frameWehnelt = new QFrame(frameSPECS1);
        frameWehnelt->setObjectName("frameWehnelt");
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Base, brush);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        frameWehnelt->setPalette(palette4);
        frameWehnelt->setAutoFillBackground(true);
        frameWehnelt->setFrameShape(QFrame::Shape::WinPanel);
        frameWehnelt->setFrameShadow(QFrame::Shadow::Plain);
        frameWehnelt->setLineWidth(1);
        _7 = new QGridLayout(frameWehnelt);
        _7->setSpacing(6);
        _7->setObjectName("_7");
        lineEditWehnelt = new QLineEdit(frameWehnelt);
        lineEditWehnelt->setObjectName("lineEditWehnelt");
        lineEditWehnelt->setFont(font1);

        _7->addWidget(lineEditWehnelt, 2, 0, 1, 1);

        valeurMesurerWehnelt = new QLabel(frameWehnelt);
        valeurMesurerWehnelt->setObjectName("valeurMesurerWehnelt");
        valeurMesurerWehnelt->setStyleSheet(QString::fromUtf8("font: 20pt \"Segoe UI\";"));

        _7->addWidget(valeurMesurerWehnelt, 2, 1, 1, 1);

        labelWehnelt = new QLabel(frameWehnelt);
        labelWehnelt->setObjectName("labelWehnelt");
        labelWehnelt->setFont(font);
        labelWehnelt->setAlignment(Qt::AlignmentFlag::AlignCenter);

        _7->addWidget(labelWehnelt, 1, 0, 1, 1);

        valeurMesurer_4 = new QLabel(frameWehnelt);
        valeurMesurer_4->setObjectName("valeurMesurer_4");
        valeurMesurer_4->setFont(font);
        valeurMesurer_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        _7->addWidget(valeurMesurer_4, 1, 1, 1, 1);


        verticalLayout_2->addWidget(frameWehnelt);

        frameSPECS2 = new QFrame(SPECS);
        frameSPECS2->setObjectName("frameSPECS2");
        frameSPECS2->setGeometry(QRect(30, 460, 781, 231));
        frameSPECS2->setMinimumSize(QSize(16, 196));
        QPalette palette5;
        frameSPECS2->setPalette(palette5);
        frameSPECS2->setAutoFillBackground(false);
        frameSPECS2->setFrameShape(QFrame::Shape::WinPanel);
        frameSPECS2->setFrameShadow(QFrame::Shadow::Plain);
        frameSPECS2->setLineWidth(1);
        frameSPECS2->setMidLineWidth(0);
        gridLayout = new QGridLayout(frameSPECS2);
        gridLayout->setSpacing(3);
        gridLayout->setContentsMargins(3, 3, 3, 3);
        gridLayout->setObjectName("gridLayout");
        frameBalayageY = new QFrame(frameSPECS2);
        frameBalayageY->setObjectName("frameBalayageY");
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Base, brush);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        frameBalayageY->setPalette(palette6);
        frameBalayageY->setAutoFillBackground(true);
        frameBalayageY->setFrameShape(QFrame::Shape::WinPanel);
        frameBalayageY->setFrameShadow(QFrame::Shadow::Plain);
        frameBalayageY->setLineWidth(1);
        _2 = new QGridLayout(frameBalayageY);
        _2->setSpacing(6);
        _2->setObjectName("_2");
        lineEditBalayageY = new QLineEdit(frameBalayageY);
        lineEditBalayageY->setObjectName("lineEditBalayageY");
        lineEditBalayageY->setFont(font1);

        _2->addWidget(lineEditBalayageY, 1, 0, 1, 1);

        label_9 = new QLabel(frameBalayageY);
        label_9->setObjectName("label_9");
        label_9->setFont(font);
        label_9->setAlignment(Qt::AlignmentFlag::AlignCenter);

        _2->addWidget(label_9, 0, 0, 1, 1);

        valeurMesurer_8 = new QLabel(frameBalayageY);
        valeurMesurer_8->setObjectName("valeurMesurer_8");
        valeurMesurer_8->setFont(font);
        valeurMesurer_8->setAlignment(Qt::AlignmentFlag::AlignCenter);

        _2->addWidget(valeurMesurer_8, 0, 1, 1, 1);

        valeurMesurerBalayageY = new QLabel(frameBalayageY);
        valeurMesurerBalayageY->setObjectName("valeurMesurerBalayageY");
        valeurMesurerBalayageY->setStyleSheet(QString::fromUtf8("font: 20pt \"Segoe UI\";"));

        _2->addWidget(valeurMesurerBalayageY, 1, 1, 1, 1);


        gridLayout->addWidget(frameBalayageY, 1, 1, 1, 1);

        frameBalayageX = new QFrame(frameSPECS2);
        frameBalayageX->setObjectName("frameBalayageX");
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Base, brush);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        frameBalayageX->setPalette(palette7);
        frameBalayageX->setAutoFillBackground(true);
        frameBalayageX->setFrameShape(QFrame::Shape::WinPanel);
        frameBalayageX->setFrameShadow(QFrame::Shadow::Plain);
        frameBalayageX->setLineWidth(1);
        _4 = new QGridLayout(frameBalayageX);
        _4->setSpacing(6);
        _4->setObjectName("_4");
        lineEditBalayageX = new QLineEdit(frameBalayageX);
        lineEditBalayageX->setObjectName("lineEditBalayageX");
        lineEditBalayageX->setFont(font1);

        _4->addWidget(lineEditBalayageX, 1, 0, 1, 1);

        labelBalayageX = new QLabel(frameBalayageX);
        labelBalayageX->setObjectName("labelBalayageX");
        labelBalayageX->setFont(font);
        labelBalayageX->setMouseTracking(false);
        labelBalayageX->setAlignment(Qt::AlignmentFlag::AlignCenter);

        _4->addWidget(labelBalayageX, 0, 0, 1, 1);

        valeurMesurer_7 = new QLabel(frameBalayageX);
        valeurMesurer_7->setObjectName("valeurMesurer_7");
        valeurMesurer_7->setFont(font);
        valeurMesurer_7->setAlignment(Qt::AlignmentFlag::AlignCenter);

        _4->addWidget(valeurMesurer_7, 0, 1, 1, 1);

        valeurMesurerBalayageX = new QLabel(frameBalayageX);
        valeurMesurerBalayageX->setObjectName("valeurMesurerBalayageX");
        valeurMesurerBalayageX->setStyleSheet(QString::fromUtf8("font: 20pt \"Segoe UI\";"));

        _4->addWidget(valeurMesurerBalayageX, 1, 1, 1, 1);


        gridLayout->addWidget(frameBalayageX, 1, 0, 1, 1);

        framePositionX = new QFrame(frameSPECS2);
        framePositionX->setObjectName("framePositionX");
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::Base, brush);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        framePositionX->setPalette(palette8);
        framePositionX->setAutoFillBackground(true);
        framePositionX->setFrameShape(QFrame::Shape::WinPanel);
        framePositionX->setFrameShadow(QFrame::Shadow::Plain);
        framePositionX->setLineWidth(1);
        _5 = new QGridLayout(framePositionX);
        _5->setSpacing(6);
        _5->setObjectName("_5");
        labelPositionX = new QLabel(framePositionX);
        labelPositionX->setObjectName("labelPositionX");
        labelPositionX->setFont(font);
        labelPositionX->setAlignment(Qt::AlignmentFlag::AlignCenter);

        _5->addWidget(labelPositionX, 0, 0, 1, 1);

        lineEditPositionX = new QLineEdit(framePositionX);
        lineEditPositionX->setObjectName("lineEditPositionX");
        lineEditPositionX->setFont(font1);

        _5->addWidget(lineEditPositionX, 1, 0, 1, 1);

        valeurMesurer_5 = new QLabel(framePositionX);
        valeurMesurer_5->setObjectName("valeurMesurer_5");
        valeurMesurer_5->setFont(font);
        valeurMesurer_5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        _5->addWidget(valeurMesurer_5, 0, 1, 1, 1);

        valeurMesurerPositionX = new QLabel(framePositionX);
        valeurMesurerPositionX->setObjectName("valeurMesurerPositionX");
        valeurMesurerPositionX->setStyleSheet(QString::fromUtf8("font: 20pt \"Segoe UI\";"));

        _5->addWidget(valeurMesurerPositionX, 1, 1, 1, 1);


        gridLayout->addWidget(framePositionX, 0, 0, 1, 1);

        framePositionY = new QFrame(frameSPECS2);
        framePositionY->setObjectName("framePositionY");
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::Base, brush);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        framePositionY->setPalette(palette9);
        framePositionY->setAutoFillBackground(true);
        framePositionY->setFrameShape(QFrame::Shape::WinPanel);
        framePositionY->setFrameShadow(QFrame::Shadow::Plain);
        framePositionY->setLineWidth(1);
        _3 = new QGridLayout(framePositionY);
        _3->setSpacing(6);
        _3->setObjectName("_3");
        labelPositionY = new QLabel(framePositionY);
        labelPositionY->setObjectName("labelPositionY");
        labelPositionY->setFont(font);
        labelPositionY->setAlignment(Qt::AlignmentFlag::AlignCenter);

        _3->addWidget(labelPositionY, 0, 0, 1, 1);

        lineEditPositionY = new QLineEdit(framePositionY);
        lineEditPositionY->setObjectName("lineEditPositionY");
        lineEditPositionY->setFont(font1);

        _3->addWidget(lineEditPositionY, 1, 0, 1, 1);

        valeurMesurer_6 = new QLabel(framePositionY);
        valeurMesurer_6->setObjectName("valeurMesurer_6");
        valeurMesurer_6->setFont(font);
        valeurMesurer_6->setAlignment(Qt::AlignmentFlag::AlignCenter);

        _3->addWidget(valeurMesurer_6, 0, 1, 1, 1);

        valeurMesurerPositionY = new QLabel(framePositionY);
        valeurMesurerPositionY->setObjectName("valeurMesurerPositionY");
        valeurMesurerPositionY->setStyleSheet(QString::fromUtf8("font: 20pt \"Segoe UI\";"));

        _3->addWidget(valeurMesurerPositionY, 1, 1, 1, 1);


        gridLayout->addWidget(framePositionY, 0, 1, 1, 1);

        ValidatePushButtonSPECS = new QPushButton(SPECS);
        ValidatePushButtonSPECS->setObjectName("ValidatePushButtonSPECS");
        ValidatePushButtonSPECS->setGeometry(QRect(30, 700, 761, 51));
        ValidatePushButtonSPECS->setStyleSheet(QString::fromUtf8("font: 15pt \"Segoe UI\";"));
        verticalScrollBar = new QScrollBar(SPECS);
        verticalScrollBar->setObjectName("verticalScrollBar");
        verticalScrollBar->setGeometry(QRect(880, -31, 20, 891));
        verticalScrollBar->setOrientation(Qt::Orientation::Vertical);
        horizontalLayoutWidget_2 = new QWidget(SPECS);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(70, 100, 691, 37));
        frameControl = new QHBoxLayout(horizontalLayoutWidget_2);
        frameControl->setObjectName("frameControl");
        frameControl->setContentsMargins(0, 0, 0, 0);
        checkBoxHV = new QCheckBox(horizontalLayoutWidget_2);
        checkBoxHV->setObjectName("checkBoxHV");
        checkBoxHV->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";"));

        frameControl->addWidget(checkBoxHV);

        checkBoxOperate = new QCheckBox(horizontalLayoutWidget_2);
        checkBoxOperate->setObjectName("checkBoxOperate");
        checkBoxOperate->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";"));

        frameControl->addWidget(checkBoxOperate);

        labelIntensite = new QLabel(horizontalLayoutWidget_2);
        labelIntensite->setObjectName("labelIntensite");
        labelIntensite->setFont(font);
        labelIntensite->setAlignment(Qt::AlignmentFlag::AlignCenter);

        frameControl->addWidget(labelIntensite);

        tabWidget->addTab(SPECS, QString());

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
        titreSPECS->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">CONFIGURATION ALIMENTATION SPECS</span></p></body></html>", nullptr));
        pushButtonConnexion->setText(QCoreApplication::translate("MainWindow", "Connexion", nullptr));
        labelEnergie->setText(QCoreApplication::translate("MainWindow", "Energie ( eV )", nullptr));
        valeurMesurer->setText(QCoreApplication::translate("MainWindow", "Valeur mesur\303\251e", nullptr));
        valeurMesurerEnergie->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labelCourantEmission->setText(QCoreApplication::translate("MainWindow", "Courant d'\303\251mission ( \302\265A )", nullptr));
        valeurMesurerCourantEmission->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        valeurMesurer_3->setText(QCoreApplication::translate("MainWindow", "Valeur mesur\303\251e", nullptr));
        valeurMesurer_2->setText(QCoreApplication::translate("MainWindow", "Valeur mesur\303\251e", nullptr));
        valeurMesurerFocus->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labelFocus->setText(QCoreApplication::translate("MainWindow", "Focus ( % )", nullptr));
        valeurMesurer_9->setText(QCoreApplication::translate("MainWindow", "Valeur mesur\303\251e", nullptr));
        valeurMesurerFocusEv->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        valeurMesurerWehnelt->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labelWehnelt->setText(QCoreApplication::translate("MainWindow", "Wehnelt ( V )", nullptr));
        valeurMesurer_4->setText(QCoreApplication::translate("MainWindow", "Valeur mesur\303\251e", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Balayage Y ( mm )", nullptr));
        valeurMesurer_8->setText(QCoreApplication::translate("MainWindow", "Valeur mesur\303\251e", nullptr));
        valeurMesurerBalayageY->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labelBalayageX->setText(QCoreApplication::translate("MainWindow", "Balayage X ( mm )", nullptr));
        valeurMesurer_7->setText(QCoreApplication::translate("MainWindow", "Valeur mesur\303\251e", nullptr));
        valeurMesurerBalayageX->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labelPositionX->setText(QCoreApplication::translate("MainWindow", "Position X ( mm )", nullptr));
        valeurMesurer_5->setText(QCoreApplication::translate("MainWindow", "Valeur mesur\303\251e", nullptr));
        valeurMesurerPositionX->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labelPositionY->setText(QCoreApplication::translate("MainWindow", "Position Y ( mm )", nullptr));
        valeurMesurer_6->setText(QCoreApplication::translate("MainWindow", "Valeur mesur\303\251e", nullptr));
        valeurMesurerPositionY->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        ValidatePushButtonSPECS->setText(QCoreApplication::translate("MainWindow", "Valider", nullptr));
        checkBoxHV->setText(QCoreApplication::translate("MainWindow", "Haute Tension", nullptr));
        checkBoxOperate->setText(QCoreApplication::translate("MainWindow", "Operate", nullptr));
        labelIntensite->setText(QCoreApplication::translate("MainWindow", "Intensit\303\251 :", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(SPECS), QCoreApplication::translate("MainWindow", "SPECS", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
