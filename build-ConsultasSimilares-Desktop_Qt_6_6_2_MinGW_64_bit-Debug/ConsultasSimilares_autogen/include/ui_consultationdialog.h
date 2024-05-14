/********************************************************************************
** Form generated from reading UI file 'consultationdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSULTATIONDIALOG_H
#define UI_CONSULTATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConsultationDialog
{
public:
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_01;
    QDateTimeEdit *dateTimeEdit;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_02;
    QLineEdit *doctorText;
    QPushButton *doctorButton;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_03;
    QLineEdit *patientText;
    QPushButton *patientButton;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_04;
    QLineEdit *nssText;
    QFrame *line;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QLineEdit *diagnosisCodeText;
    QPushButton *diagnosisButton;
    QGridLayout *gridMedicine;
    QLineEdit *medicine3Edit;
    QLineEdit *medicine1Edit;
    QLabel *label_07;
    QLineEdit *medicine2Edit;
    QSpacerItem *verticalSpacer;
    QPushButton *medicine1Button;
    QPushButton *medicine2Button;
    QPushButton *medicine3Button;
    QDialogButtonBox *buttonBox;
    QGridLayout *gridDiagnosis;
    QLabel *label_05;
    QLabel *label_06;
    QTextBrowser *diagnosisTextBrowser;
    QTextBrowser *indicationsTextBrowser;

    void setupUi(QWidget *ConsultationDialog)
    {
        if (ConsultationDialog->objectName().isEmpty())
            ConsultationDialog->setObjectName("ConsultationDialog");
        ConsultationDialog->resize(1224, 325);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/Icons/dr-simi-farmacias-similares-logo-svg-vector.svg"), QSize(), QIcon::Normal, QIcon::Off);
        ConsultationDialog->setWindowIcon(icon);
        ConsultationDialog->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: #ffffff;\n"
"	color: #000000\n"
"}"));
        gridLayout_3 = new QGridLayout(ConsultationDialog);
        gridLayout_3->setObjectName("gridLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_01 = new QLabel(ConsultationDialog);
        label_01->setObjectName("label_01");
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(12);
        label_01->setFont(font);

        horizontalLayout->addWidget(label_01);

        dateTimeEdit = new QDateTimeEdit(ConsultationDialog);
        dateTimeEdit->setObjectName("dateTimeEdit");
        dateTimeEdit->setMinimumSize(QSize(170, 0));
        dateTimeEdit->setFont(font);
        dateTimeEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dateTimeEdit->setAccelerated(true);
        dateTimeEdit->setCalendarPopup(true);

        horizontalLayout->addWidget(dateTimeEdit);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_02 = new QLabel(ConsultationDialog);
        label_02->setObjectName("label_02");
        label_02->setFont(font);

        horizontalLayout_2->addWidget(label_02);

        doctorText = new QLineEdit(ConsultationDialog);
        doctorText->setObjectName("doctorText");
        doctorText->setEnabled(false);
        doctorText->setFont(font);

        horizontalLayout_2->addWidget(doctorText);

        doctorButton = new QPushButton(ConsultationDialog);
        doctorButton->setObjectName("doctorButton");
        doctorButton->setMaximumSize(QSize(28, 24));
        doctorButton->setFont(font);

        horizontalLayout_2->addWidget(doctorButton);


        gridLayout_3->addLayout(horizontalLayout_2, 0, 2, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_03 = new QLabel(ConsultationDialog);
        label_03->setObjectName("label_03");
        label_03->setFont(font);

        horizontalLayout_3->addWidget(label_03);

        patientText = new QLineEdit(ConsultationDialog);
        patientText->setObjectName("patientText");
        patientText->setEnabled(false);
        patientText->setMinimumSize(QSize(375, 0));
        patientText->setFont(font);

        horizontalLayout_3->addWidget(patientText);

        patientButton = new QPushButton(ConsultationDialog);
        patientButton->setObjectName("patientButton");
        patientButton->setMaximumSize(QSize(28, 24));
        patientButton->setFont(font);

        horizontalLayout_3->addWidget(patientButton);


        horizontalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_04 = new QLabel(ConsultationDialog);
        label_04->setObjectName("label_04");
        label_04->setFont(font);

        horizontalLayout_4->addWidget(label_04);

        nssText = new QLineEdit(ConsultationDialog);
        nssText->setObjectName("nssText");
        nssText->setEnabled(false);
        nssText->setMinimumSize(QSize(150, 0));
        nssText->setFont(font);

        horizontalLayout_4->addWidget(nssText);


        horizontalLayout_5->addLayout(horizontalLayout_4);


        gridLayout_3->addLayout(horizontalLayout_5, 1, 2, 1, 1);

        line = new QFrame(ConsultationDialog);
        line->setObjectName("line");
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line, 2, 0, 1, 3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label = new QLabel(ConsultationDialog);
        label->setObjectName("label");
        label->setFont(font);

        horizontalLayout_6->addWidget(label);

        diagnosisCodeText = new QLineEdit(ConsultationDialog);
        diagnosisCodeText->setObjectName("diagnosisCodeText");
        diagnosisCodeText->setEnabled(false);
        diagnosisCodeText->setFont(font);

        horizontalLayout_6->addWidget(diagnosisCodeText);

        diagnosisButton = new QPushButton(ConsultationDialog);
        diagnosisButton->setObjectName("diagnosisButton");
        diagnosisButton->setMaximumSize(QSize(28, 24));
        diagnosisButton->setFont(font);

        horizontalLayout_6->addWidget(diagnosisButton);


        gridLayout_3->addLayout(horizontalLayout_6, 3, 0, 1, 2);

        gridMedicine = new QGridLayout();
        gridMedicine->setObjectName("gridMedicine");
        medicine3Edit = new QLineEdit(ConsultationDialog);
        medicine3Edit->setObjectName("medicine3Edit");
        medicine3Edit->setEnabled(false);
        medicine3Edit->setFont(font);

        gridMedicine->addWidget(medicine3Edit, 2, 1, 1, 1);

        medicine1Edit = new QLineEdit(ConsultationDialog);
        medicine1Edit->setObjectName("medicine1Edit");
        medicine1Edit->setEnabled(false);
        medicine1Edit->setFont(font);

        gridMedicine->addWidget(medicine1Edit, 0, 1, 1, 1);

        label_07 = new QLabel(ConsultationDialog);
        label_07->setObjectName("label_07");
        label_07->setFont(font);

        gridMedicine->addWidget(label_07, 0, 0, 1, 1);

        medicine2Edit = new QLineEdit(ConsultationDialog);
        medicine2Edit->setObjectName("medicine2Edit");
        medicine2Edit->setEnabled(false);
        medicine2Edit->setFont(font);

        gridMedicine->addWidget(medicine2Edit, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridMedicine->addItem(verticalSpacer, 3, 1, 1, 1);

        medicine1Button = new QPushButton(ConsultationDialog);
        medicine1Button->setObjectName("medicine1Button");
        medicine1Button->setMaximumSize(QSize(28, 24));

        gridMedicine->addWidget(medicine1Button, 0, 2, 1, 1);

        medicine2Button = new QPushButton(ConsultationDialog);
        medicine2Button->setObjectName("medicine2Button");
        medicine2Button->setMaximumSize(QSize(28, 24));

        gridMedicine->addWidget(medicine2Button, 1, 2, 1, 1);

        medicine3Button = new QPushButton(ConsultationDialog);
        medicine3Button->setObjectName("medicine3Button");
        medicine3Button->setMaximumSize(QSize(28, 24));

        gridMedicine->addWidget(medicine3Button, 2, 2, 1, 1);


        gridLayout_3->addLayout(gridMedicine, 3, 2, 2, 1);

        buttonBox = new QDialogButtonBox(ConsultationDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setFont(font);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_3->addWidget(buttonBox, 5, 2, 1, 1);

        gridDiagnosis = new QGridLayout();
        gridDiagnosis->setObjectName("gridDiagnosis");
        label_05 = new QLabel(ConsultationDialog);
        label_05->setObjectName("label_05");
        label_05->setFont(font);

        gridDiagnosis->addWidget(label_05, 0, 0, 1, 1);

        label_06 = new QLabel(ConsultationDialog);
        label_06->setObjectName("label_06");
        label_06->setFont(font);

        gridDiagnosis->addWidget(label_06, 0, 1, 1, 1);

        diagnosisTextBrowser = new QTextBrowser(ConsultationDialog);
        diagnosisTextBrowser->setObjectName("diagnosisTextBrowser");
        diagnosisTextBrowser->setEnabled(false);
        diagnosisTextBrowser->setMinimumSize(QSize(250, 0));
        diagnosisTextBrowser->setFont(font);
        diagnosisTextBrowser->setFocusPolicy(Qt::NoFocus);
        diagnosisTextBrowser->setTextInteractionFlags(Qt::NoTextInteraction);

        gridDiagnosis->addWidget(diagnosisTextBrowser, 1, 0, 1, 1);

        indicationsTextBrowser = new QTextBrowser(ConsultationDialog);
        indicationsTextBrowser->setObjectName("indicationsTextBrowser");
        indicationsTextBrowser->setEnabled(false);
        indicationsTextBrowser->setMinimumSize(QSize(250, 0));
        indicationsTextBrowser->setFont(font);
        indicationsTextBrowser->setFocusPolicy(Qt::NoFocus);

        gridDiagnosis->addWidget(indicationsTextBrowser, 1, 1, 1, 1);


        gridLayout_3->addLayout(gridDiagnosis, 4, 0, 1, 2);

        QWidget::setTabOrder(dateTimeEdit, doctorText);
        QWidget::setTabOrder(doctorText, doctorButton);
        QWidget::setTabOrder(doctorButton, patientText);
        QWidget::setTabOrder(patientText, patientButton);
        QWidget::setTabOrder(patientButton, nssText);
        QWidget::setTabOrder(nssText, diagnosisCodeText);
        QWidget::setTabOrder(diagnosisCodeText, diagnosisButton);
        QWidget::setTabOrder(diagnosisButton, diagnosisTextBrowser);
        QWidget::setTabOrder(diagnosisTextBrowser, indicationsTextBrowser);
        QWidget::setTabOrder(indicationsTextBrowser, medicine1Edit);
        QWidget::setTabOrder(medicine1Edit, medicine1Button);
        QWidget::setTabOrder(medicine1Button, medicine2Edit);
        QWidget::setTabOrder(medicine2Edit, medicine2Button);
        QWidget::setTabOrder(medicine2Button, medicine3Edit);
        QWidget::setTabOrder(medicine3Edit, medicine3Button);

        retranslateUi(ConsultationDialog);

        QMetaObject::connectSlotsByName(ConsultationDialog);
    } // setupUi

    void retranslateUi(QWidget *ConsultationDialog)
    {
        ConsultationDialog->setWindowTitle(QCoreApplication::translate("ConsultationDialog", "Form", nullptr));
        label_01->setText(QCoreApplication::translate("ConsultationDialog", "Fecha:", nullptr));
        dateTimeEdit->setDisplayFormat(QCoreApplication::translate("ConsultationDialog", "dd/MM/yyyy hh:mm", nullptr));
        label_02->setText(QCoreApplication::translate("ConsultationDialog", "Medico:", nullptr));
        doctorButton->setText(QCoreApplication::translate("ConsultationDialog", "...", nullptr));
        label_03->setText(QCoreApplication::translate("ConsultationDialog", "Paciente:", nullptr));
        patientButton->setText(QCoreApplication::translate("ConsultationDialog", "...", nullptr));
        label_04->setText(QCoreApplication::translate("ConsultationDialog", "NSS:", nullptr));
        label->setText(QCoreApplication::translate("ConsultationDialog", "C\303\263digo de Di\303\241gnostico: ", nullptr));
        diagnosisButton->setText(QCoreApplication::translate("ConsultationDialog", "...", nullptr));
        label_07->setText(QCoreApplication::translate("ConsultationDialog", "Medicamentos:", nullptr));
        medicine1Button->setText(QCoreApplication::translate("ConsultationDialog", "...", nullptr));
        medicine2Button->setText(QCoreApplication::translate("ConsultationDialog", "...", nullptr));
        medicine3Button->setText(QCoreApplication::translate("ConsultationDialog", "...", nullptr));
        label_05->setText(QCoreApplication::translate("ConsultationDialog", "Descripci\303\263n de Diagn\303\263stico:", nullptr));
        label_06->setText(QCoreApplication::translate("ConsultationDialog", "Indicaciones:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConsultationDialog: public Ui_ConsultationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSULTATIONDIALOG_H
