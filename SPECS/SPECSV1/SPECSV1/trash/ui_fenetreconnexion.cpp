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
    QPushButton *pushButton_rs232;
    QFrame *frame;
    QGridLayout *gridLayout1;
    QVBoxLayout *vboxLayout;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *vboxLayout1;
    QLineEdit *lineEdit;
    QComboBox *comboBox;
    QTextEdit *textEdit;

    void setupUi(QDialog *FenetreConnexion)
    {
        if (FenetreConnexion->objectName().isEmpty())
            FenetreConnexion->setObjectName("FenetreConnexion");
        FenetreConnexion->resize(480, 416);
        gridLayout = new QGridLayout(FenetreConnexion);
        gridLayout->setSpacing(3);
        gridLayout->setContentsMargins(3, 3, 3, 3);
        gridLayout->setObjectName("gridLayout");
        pushButton_rs232 = new QPushButton(FenetreConnexion);
        pushButton_rs232->setObjectName("pushButton_rs232");
        QFont font;
        font.setPointSize(20);
        pushButton_rs232->setFont(font);

        gridLayout->addWidget(pushButton_rs232, 0, 0, 1, 1);

        frame = new QFrame(FenetreConnexion);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout1 = new QGridLayout(frame);
        gridLayout1->setSpacing(3);
        gridLayout1->setContentsMargins(3, 3, 3, 3);
        gridLayout1->setObjectName("gridLayout1");
        vboxLayout = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout->setContentsMargins(0, 0, 0, 0);
#endif
        vboxLayout->setObjectName("vboxLayout");
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(200, 0));
        QFont font1;
        font1.setPointSize(14);
        label_2->setFont(font1);

        vboxLayout->addWidget(label_2);

        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setFont(font1);

        vboxLayout->addWidget(label_3);


        gridLayout1->addLayout(vboxLayout, 0, 0, 1, 1);

        vboxLayout1 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout1->setSpacing(6);
#endif
        vboxLayout1->setContentsMargins(0, 0, 0, 0);
        vboxLayout1->setObjectName("vboxLayout1");
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setFont(font1);

        vboxLayout1->addWidget(lineEdit);

        comboBox = new QComboBox(frame);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setFont(font1);

        vboxLayout1->addWidget(comboBox);


        gridLayout1->addLayout(vboxLayout1, 0, 1, 1, 1);


        gridLayout->addWidget(frame, 1, 0, 1, 1);

        textEdit = new QTextEdit(FenetreConnexion);
        textEdit->setObjectName("textEdit");

        gridLayout->addWidget(textEdit, 2, 0, 1, 1);


        retranslateUi(FenetreConnexion);

        QMetaObject::connectSlotsByName(FenetreConnexion);
    } // setupUi

    void retranslateUi(QDialog *FenetreConnexion)
    {
        FenetreConnexion->setWindowTitle(QCoreApplication::translate("FenetreConnexion", "Configuration RS232", nullptr));
        pushButton_rs232->setText(QCoreApplication::translate("FenetreConnexion", "Sauver et fermer la fen\303\252tre", nullptr));
        label_2->setText(QCoreApplication::translate("FenetreConnexion", "Port s\303\251rie", nullptr));
        label_3->setText(QCoreApplication::translate("FenetreConnexion", "Baud rate", nullptr));
        lineEdit->setText(QCoreApplication::translate("FenetreConnexion", "COM1", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("FenetreConnexion", "9600", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("FenetreConnexion", "4800", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("FenetreConnexion", "2400", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("FenetreConnexion", "1200", nullptr));

        textEdit->setHtml(QCoreApplication::translate("FenetreConnexion", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
                                                                          "<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
                                                                          "p, li { white-space: pre-wrap; }\n"
                                                                          "hr { height: 1px; border-width: 0; }\n"
                                                                          "li.unchecked::marker { content: \"\\2610\"; }\n"
                                                                          "li.checked::marker { content: \"\\2612\"; }\n"
                                                                          "</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
                                                                          "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:10pt;\">Les valeurs possibles du port s\303\251rie en mode Windows sont :</span></p>\n"
                                                                          "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:10pt;\">COM1</span></p>\n"
                                                                          "<p style=\" margin-top:0px; margin-bottom:0px; margin-le"
                                                                          "ft:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:10pt;\">COM2</span></p>\n"
                                                                          "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:10pt;\">COM3</span></p>\n"
                                                                          "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:10pt;\">etc.</span></p>\n"
                                                                          "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:10pt;\">LPT1</span></p>\n"
                                                                          "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:10pt;\">LPT2</span></p>\n"
                                                                          "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0p"
                                                                          "x; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:10pt;\">...</span></p>\n"
                                                                          "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:10pt;\"><br /></p>\n"
                                                                          "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:10pt;\">Les valeurs possibles du port s\303\251rie en mode Linux sont :</span></p>\n"
                                                                          "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:10pt;\">/dev/ttyS0</span></p>\n"
                                                                          "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:10pt;\">/dev/ttyS1</span></"
                                                                          "p>\n"
                                                                          "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:10pt;\">/dev/ttyS2</span></p>\n"
                                                                          "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:10pt;\">...</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
class FenetreConnexion: public Ui_FenetreConnexion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENETRECONNEXION_H
