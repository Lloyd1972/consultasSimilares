/********************************************************************************
** Form generated from reading UI file 'diagnosisdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIAGNOSISDIALOG_H
#define UI_DIAGNOSISDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DiagnosisDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_01;
    QLineEdit *codeTextEdit;
    QVBoxLayout *verticalLayout;
    QLabel *label_02;
    QTextEdit *descriptionTextEdit;
    QDialogButtonBox *buttonBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_03;
    QTextEdit *indicationsTextEdit;

    void setupUi(QWidget *DiagnosisDialog)
    {
        if (DiagnosisDialog->objectName().isEmpty())
            DiagnosisDialog->setObjectName("DiagnosisDialog");
        DiagnosisDialog->resize(658, 356);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/Icons/dr-simi-farmacias-similares-logo-svg-vector.svg"), QSize(), QIcon::Normal, QIcon::Off);
        DiagnosisDialog->setWindowIcon(icon);
        DiagnosisDialog->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: #ffffff;\n"
"	color: #000000\n"
"}"));
        gridLayout = new QGridLayout(DiagnosisDialog);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_01 = new QLabel(DiagnosisDialog);
        label_01->setObjectName("label_01");
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(12);
        label_01->setFont(font);

        horizontalLayout->addWidget(label_01);

        codeTextEdit = new QLineEdit(DiagnosisDialog);
        codeTextEdit->setObjectName("codeTextEdit");
        codeTextEdit->setMinimumSize(QSize(150, 0));
        codeTextEdit->setFont(font);

        horizontalLayout->addWidget(codeTextEdit);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_02 = new QLabel(DiagnosisDialog);
        label_02->setObjectName("label_02");
        label_02->setFont(font);

        verticalLayout->addWidget(label_02);

        descriptionTextEdit = new QTextEdit(DiagnosisDialog);
        descriptionTextEdit->setObjectName("descriptionTextEdit");
        descriptionTextEdit->setFont(font);

        verticalLayout->addWidget(descriptionTextEdit);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(DiagnosisDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setFont(font);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_03 = new QLabel(DiagnosisDialog);
        label_03->setObjectName("label_03");
        label_03->setFont(font);

        verticalLayout_2->addWidget(label_03);

        indicationsTextEdit = new QTextEdit(DiagnosisDialog);
        indicationsTextEdit->setObjectName("indicationsTextEdit");
        indicationsTextEdit->setFont(font);

        verticalLayout_2->addWidget(indicationsTextEdit);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 2, 1);

        QWidget::setTabOrder(codeTextEdit, descriptionTextEdit);
        QWidget::setTabOrder(descriptionTextEdit, indicationsTextEdit);

        retranslateUi(DiagnosisDialog);

        QMetaObject::connectSlotsByName(DiagnosisDialog);
    } // setupUi

    void retranslateUi(QWidget *DiagnosisDialog)
    {
        label_01->setText(QCoreApplication::translate("DiagnosisDialog", "C\303\263digo:", nullptr));
        label_02->setText(QCoreApplication::translate("DiagnosisDialog", "Descripci\303\263n:", nullptr));
        label_03->setText(QCoreApplication::translate("DiagnosisDialog", "Indicaciones:", nullptr));
        (void)DiagnosisDialog;
    } // retranslateUi

};

namespace Ui {
    class DiagnosisDialog: public Ui_DiagnosisDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIAGNOSISDIALOG_H
