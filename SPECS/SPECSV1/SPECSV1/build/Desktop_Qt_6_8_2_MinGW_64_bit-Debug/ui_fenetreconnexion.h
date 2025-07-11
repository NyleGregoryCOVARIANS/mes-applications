/********************************************************************************
** Form generated from reading UI file 'fenetreconnexion.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENETRECONNEXION_H
#define UI_FENETRECONNEXION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FenetreConnexion
{
public:
    QGridLayout *gridLayout;
    QFrame *frameSPECS;
    QGridLayout *gridLayout1;
    QVBoxLayout *vboxLayout1;
    QLineEdit *lineEditSPECS;
    QComboBox *comboBoxSPECS;
    QVBoxLayout *vboxLayout;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_rs232;
    QFrame *framePICO;
    QGridLayout *gridLayout_2;
    QVBoxLayout *vboxLayout3;
    QLineEdit *lineEditPICO;
    QComboBox *comboBoxPICO;
    QVBoxLayout *vboxLayout2;
    QLabel *labelPICO_1;
    QLabel *labelPICO_2;
    QTextEdit *textEdit;

    void setupUi(QDialog *FenetreConnexion)
    {
        if (FenetreConnexion->objectName().isEmpty())
            FenetreConnexion->setObjectName("FenetreConnexion");
        FenetreConnexion->resize(648, 638);
        gridLayout = new QGridLayout(FenetreConnexion);
        gridLayout->setObjectName("gridLayout");
        frameSPECS = new QFrame(FenetreConnexion);
        frameSPECS->setObjectName("frameSPECS");
        frameSPECS->setFrameShape(QFrame::Shape::StyledPanel);
        frameSPECS->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout1 = new QGridLayout(frameSPECS);
        gridLayout1->setObjectName("gridLayout1");
        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setObjectName("vboxLayout1");
        lineEditSPECS = new QLineEdit(frameSPECS);
        lineEditSPECS->setObjectName("lineEditSPECS");
        QFont font;
        font.setPointSize(14);
        lineEditSPECS->setFont(font);

        vboxLayout1->addWidget(lineEditSPECS);

        comboBoxSPECS = new QComboBox(frameSPECS);
        comboBoxSPECS->addItem(QString());
        comboBoxSPECS->addItem(QString());
        comboBoxSPECS->addItem(QString());
        comboBoxSPECS->addItem(QString());
        comboBoxSPECS->setObjectName("comboBoxSPECS");
        comboBoxSPECS->setFont(font);

        vboxLayout1->addWidget(comboBoxSPECS);


        gridLayout1->addLayout(vboxLayout1, 0, 1, 1, 1);

        vboxLayout = new QVBoxLayout();
        vboxLayout->setObjectName("vboxLayout");
        label_2 = new QLabel(frameSPECS);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(200, 0));
        label_2->setFont(font);

        vboxLayout->addWidget(label_2);

        label_3 = new QLabel(frameSPECS);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        vboxLayout->addWidget(label_3);


        gridLayout1->addLayout(vboxLayout, 0, 0, 1, 1);


        gridLayout->addWidget(frameSPECS, 1, 0, 1, 1);

        pushButton_rs232 = new QPushButton(FenetreConnexion);
        pushButton_rs232->setObjectName("pushButton_rs232");
        QFont font1;
        font1.setPointSize(20);
        pushButton_rs232->setFont(font1);

        gridLayout->addWidget(pushButton_rs232, 0, 0, 1, 1);

        framePICO = new QFrame(FenetreConnexion);
        framePICO->setObjectName("framePICO");
        framePICO->setFrameShape(QFrame::Shape::StyledPanel);
        framePICO->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_2 = new QGridLayout(framePICO);
        gridLayout_2->setObjectName("gridLayout_2");
        vboxLayout3 = new QVBoxLayout();
        vboxLayout3->setObjectName("vboxLayout3");
        lineEditPICO = new QLineEdit(framePICO);
        lineEditPICO->setObjectName("lineEditPICO");
        lineEditPICO->setFont(font);

        vboxLayout3->addWidget(lineEditPICO);

        comboBoxPICO = new QComboBox(framePICO);
        comboBoxPICO->addItem(QString());
        comboBoxPICO->addItem(QString());
        comboBoxPICO->addItem(QString());
        comboBoxPICO->addItem(QString());
        comboBoxPICO->setObjectName("comboBoxPICO");
        comboBoxPICO->setFont(font);

        vboxLayout3->addWidget(comboBoxPICO);


        gridLayout_2->addLayout(vboxLayout3, 0, 1, 1, 1);

        vboxLayout2 = new QVBoxLayout();
        vboxLayout2->setObjectName("vboxLayout2");
        labelPICO_1 = new QLabel(framePICO);
        labelPICO_1->setObjectName("labelPICO_1");
        labelPICO_1->setMinimumSize(QSize(200, 0));
        labelPICO_1->setFont(font);

        vboxLayout2->addWidget(labelPICO_1);

        labelPICO_2 = new QLabel(framePICO);
        labelPICO_2->setObjectName("labelPICO_2");
        labelPICO_2->setFont(font);

        vboxLayout2->addWidget(labelPICO_2);


        gridLayout_2->addLayout(vboxLayout2, 0, 0, 1, 1);


        gridLayout->addWidget(framePICO, 2, 0, 1, 1);

        textEdit = new QTextEdit(FenetreConnexion);
        textEdit->setObjectName("textEdit");
        textEdit->setHtml(QString::fromUtf8("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Les valeurs possibles du port s\303\251rie en mode Windows sont :</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">COM1</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-ind"
                        "ent:0px;\"><span style=\" font-size:10pt;\">COM2</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">COM3</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">etc.</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">LPT1</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">LPT2</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">...</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px"
                        "; -qt-block-indent:0; text-indent:0px;\">Astuce : Pour trouver les valeurs des ports, aller dans Gestionnaire de p\303\251riph\303\251riques, puis dans COM.<br /></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Les valeurs possibles du port s\303\251rie en mode Linux sont :</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">/dev/ttyS0</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">/dev/ttyS1</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">/dev/ttyS2</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-"
                        "right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">...</span></p></body></html>"));

        gridLayout->addWidget(textEdit, 4, 0, 1, 1);


        retranslateUi(FenetreConnexion);

        QMetaObject::connectSlotsByName(FenetreConnexion);
    } // setupUi

    void retranslateUi(QDialog *FenetreConnexion)
    {
        FenetreConnexion->setWindowTitle(QCoreApplication::translate("FenetreConnexion", "Configuration RS232", nullptr));
        lineEditSPECS->setText(QCoreApplication::translate("FenetreConnexion", "COM19", nullptr));
        comboBoxSPECS->setItemText(0, QCoreApplication::translate("FenetreConnexion", "1200", nullptr));
        comboBoxSPECS->setItemText(1, QCoreApplication::translate("FenetreConnexion", "2400", nullptr));
        comboBoxSPECS->setItemText(2, QCoreApplication::translate("FenetreConnexion", "4800", nullptr));
        comboBoxSPECS->setItemText(3, QCoreApplication::translate("FenetreConnexion", "9600", nullptr));

        label_2->setText(QCoreApplication::translate("FenetreConnexion", "Port s\303\251rie SPECS", nullptr));
        label_3->setText(QCoreApplication::translate("FenetreConnexion", "Baud rate SPECS", nullptr));
        pushButton_rs232->setText(QCoreApplication::translate("FenetreConnexion", "Sauver et fermer la fen\303\252tre", nullptr));
        lineEditPICO->setText(QCoreApplication::translate("FenetreConnexion", "COM20", nullptr));
        comboBoxPICO->setItemText(0, QCoreApplication::translate("FenetreConnexion", "9600", nullptr));
        comboBoxPICO->setItemText(1, QCoreApplication::translate("FenetreConnexion", "4800", nullptr));
        comboBoxPICO->setItemText(2, QCoreApplication::translate("FenetreConnexion", "2400", nullptr));
        comboBoxPICO->setItemText(3, QCoreApplication::translate("FenetreConnexion", "1200", nullptr));

        labelPICO_1->setText(QCoreApplication::translate("FenetreConnexion", "Port s\303\251rie PICO", nullptr));
        labelPICO_2->setText(QCoreApplication::translate("FenetreConnexion", "Baud rate PICO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FenetreConnexion: public Ui_FenetreConnexion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENETRECONNEXION_H
