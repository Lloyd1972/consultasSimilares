/********************************************************************************
** Form generated from reading UI file 'patientdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTDIALOG_H
#define UI_PATIENTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PatientDialog
{
public:
    QGridLayout *gridLayout;
    QFrame *line;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_13;
    QLineEdit *colonyTextEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *nssTextEdit;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QLineEdit *numberTextEdit;
    QLabel *label_06;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_14;
    QLineEdit *townTextEdit;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_12;
    QLineEdit *postalCodeTextEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lastNameTextEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QLineEdit *streetTextEdit;
    QDialogButtonBox *buttonBox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *phoneTextEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDateEdit *birthDateEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *firstNameTextEdit;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *PatientDialog)
    {
        if (PatientDialog->objectName().isEmpty())
            PatientDialog->setObjectName("PatientDialog");
        PatientDialog->resize(661, 265);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/Icons/dr-simi-farmacias-similares-logo-svg-vector.svg"), QSize(), QIcon::Normal, QIcon::Off);
        PatientDialog->setWindowIcon(icon);
        PatientDialog->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: #ffffff;\n"
"	color: #000000\n"
"}"));
        gridLayout = new QGridLayout(PatientDialog);
        gridLayout->setObjectName("gridLayout");
        line = new QFrame(PatientDialog);
        line->setObjectName("line");
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 3, 0, 1, 3);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        label_13 = new QLabel(PatientDialog);
        label_13->setObjectName("label_13");
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(12);
        label_13->setFont(font);

        horizontalLayout_11->addWidget(label_13);

        colonyTextEdit = new QLineEdit(PatientDialog);
        colonyTextEdit->setObjectName("colonyTextEdit");
        colonyTextEdit->setMinimumSize(QSize(220, 0));
        colonyTextEdit->setFont(font);

        horizontalLayout_11->addWidget(colonyTextEdit);


        gridLayout->addLayout(horizontalLayout_11, 6, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(PatientDialog);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        nssTextEdit = new QLineEdit(PatientDialog);
        nssTextEdit->setObjectName("nssTextEdit");
        nssTextEdit->setMinimumSize(QSize(150, 0));
        nssTextEdit->setFont(font);

        horizontalLayout_2->addWidget(nssTextEdit);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_9 = new QLabel(PatientDialog);
        label_9->setObjectName("label_9");
        label_9->setFont(font);

        horizontalLayout_8->addWidget(label_9);

        numberTextEdit = new QLineEdit(PatientDialog);
        numberTextEdit->setObjectName("numberTextEdit");
        numberTextEdit->setMinimumSize(QSize(50, 0));
        numberTextEdit->setFont(font);

        horizontalLayout_8->addWidget(numberTextEdit);


        gridLayout->addLayout(horizontalLayout_8, 5, 1, 1, 1);

        label_06 = new QLabel(PatientDialog);
        label_06->setObjectName("label_06");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(14);
        font1.setBold(true);
        label_06->setFont(font1);
        label_06->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_06, 4, 0, 1, 3);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        label_14 = new QLabel(PatientDialog);
        label_14->setObjectName("label_14");
        label_14->setFont(font);

        horizontalLayout_12->addWidget(label_14);

        townTextEdit = new QLineEdit(PatientDialog);
        townTextEdit->setObjectName("townTextEdit");
        townTextEdit->setMinimumSize(QSize(150, 0));
        townTextEdit->setFont(font);

        horizontalLayout_12->addWidget(townTextEdit);


        gridLayout->addLayout(horizontalLayout_12, 6, 1, 1, 2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_12 = new QLabel(PatientDialog);
        label_12->setObjectName("label_12");
        label_12->setFont(font);

        horizontalLayout_9->addWidget(label_12);

        postalCodeTextEdit = new QLineEdit(PatientDialog);
        postalCodeTextEdit->setObjectName("postalCodeTextEdit");
        postalCodeTextEdit->setMinimumSize(QSize(70, 0));
        postalCodeTextEdit->setFont(font);

        horizontalLayout_9->addWidget(postalCodeTextEdit);


        gridLayout->addLayout(horizontalLayout_9, 5, 2, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_4 = new QLabel(PatientDialog);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        horizontalLayout_4->addWidget(label_4);

        lastNameTextEdit = new QLineEdit(PatientDialog);
        lastNameTextEdit->setObjectName("lastNameTextEdit");
        lastNameTextEdit->setMinimumSize(QSize(220, 0));
        lastNameTextEdit->setFont(font);

        horizontalLayout_4->addWidget(lastNameTextEdit);


        gridLayout->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_8 = new QLabel(PatientDialog);
        label_8->setObjectName("label_8");
        label_8->setFont(font);

        horizontalLayout_7->addWidget(label_8);

        streetTextEdit = new QLineEdit(PatientDialog);
        streetTextEdit->setObjectName("streetTextEdit");
        streetTextEdit->setMinimumSize(QSize(280, 0));
        streetTextEdit->setFont(font);

        horizontalLayout_7->addWidget(streetTextEdit);


        gridLayout->addLayout(horizontalLayout_7, 5, 0, 1, 1);

        buttonBox = new QDialogButtonBox(PatientDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setFont(font);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 8, 2, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_6 = new QLabel(PatientDialog);
        label_6->setObjectName("label_6");
        label_6->setFont(font);

        horizontalLayout_6->addWidget(label_6);

        phoneTextEdit = new QLineEdit(PatientDialog);
        phoneTextEdit->setObjectName("phoneTextEdit");
        phoneTextEdit->setMinimumSize(QSize(140, 0));
        phoneTextEdit->setFont(font);

        horizontalLayout_6->addWidget(phoneTextEdit);


        gridLayout->addLayout(horizontalLayout_6, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(PatientDialog);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        birthDateEdit = new QDateEdit(PatientDialog);
        birthDateEdit->setObjectName("birthDateEdit");
        birthDateEdit->setFont(font);
        birthDateEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        birthDateEdit->setCalendarPopup(true);

        horizontalLayout_3->addWidget(birthDateEdit);


        gridLayout->addLayout(horizontalLayout_3, 0, 1, 1, 2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_5 = new QLabel(PatientDialog);
        label_5->setObjectName("label_5");
        label_5->setFont(font);

        horizontalLayout_5->addWidget(label_5);

        firstNameTextEdit = new QLineEdit(PatientDialog);
        firstNameTextEdit->setObjectName("firstNameTextEdit");
        firstNameTextEdit->setMinimumSize(QSize(220, 0));
        firstNameTextEdit->setFont(font);

        horizontalLayout_5->addWidget(firstNameTextEdit);


        gridLayout->addLayout(horizontalLayout_5, 1, 1, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 7, 2, 1, 1);

        QWidget::setTabOrder(nssTextEdit, birthDateEdit);
        QWidget::setTabOrder(birthDateEdit, lastNameTextEdit);
        QWidget::setTabOrder(lastNameTextEdit, firstNameTextEdit);
        QWidget::setTabOrder(firstNameTextEdit, phoneTextEdit);
        QWidget::setTabOrder(phoneTextEdit, streetTextEdit);
        QWidget::setTabOrder(streetTextEdit, numberTextEdit);
        QWidget::setTabOrder(numberTextEdit, postalCodeTextEdit);
        QWidget::setTabOrder(postalCodeTextEdit, colonyTextEdit);
        QWidget::setTabOrder(colonyTextEdit, townTextEdit);

        retranslateUi(PatientDialog);

        QMetaObject::connectSlotsByName(PatientDialog);
    } // setupUi

    void retranslateUi(QWidget *PatientDialog)
    {
        PatientDialog->setWindowTitle(QCoreApplication::translate("PatientDialog", "Form", nullptr));
        label_13->setText(QCoreApplication::translate("PatientDialog", "Colonia:", nullptr));
        label_2->setText(QCoreApplication::translate("PatientDialog", "No. Seguro Social:", nullptr));
        label_9->setText(QCoreApplication::translate("PatientDialog", "No.:", nullptr));
        label_06->setText(QCoreApplication::translate("PatientDialog", "Domicilio", nullptr));
        label_14->setText(QCoreApplication::translate("PatientDialog", "Municipio:", nullptr));
        label_12->setText(QCoreApplication::translate("PatientDialog", "C.P.:", nullptr));
        label_4->setText(QCoreApplication::translate("PatientDialog", "Apellidos:", nullptr));
        label_8->setText(QCoreApplication::translate("PatientDialog", "Calle:", nullptr));
        label_6->setText(QCoreApplication::translate("PatientDialog", "Tel\303\251fono:", nullptr));
        label_3->setText(QCoreApplication::translate("PatientDialog", "Fecha de Nacimiento:", nullptr));
        label_5->setText(QCoreApplication::translate("PatientDialog", "Nombre(s):", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientDialog: public Ui_PatientDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTDIALOG_H
