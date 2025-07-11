/********************************************************************************
** Form generated from reading UI file 'connexion.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNEXION_H
#define UI_CONNEXION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_FenetreConnexion
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *FenetreConnexion)
    {
        if (FenetreConnexion->objectName().isEmpty())
            FenetreConnexion->setObjectName("FenetreConnexion");
        FenetreConnexion->resize(400, 300);
        buttonBox = new QDialogButtonBox(FenetreConnexion);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        retranslateUi(FenetreConnexion);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, FenetreConnexion, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, FenetreConnexion, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(FenetreConnexion);
    } // setupUi

    void retranslateUi(QDialog *FenetreConnexion)
    {
        FenetreConnexion->setWindowTitle(QCoreApplication::translate("FenetreConnexion", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FenetreConnexion: public Ui_FenetreConnexion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNEXION_H
