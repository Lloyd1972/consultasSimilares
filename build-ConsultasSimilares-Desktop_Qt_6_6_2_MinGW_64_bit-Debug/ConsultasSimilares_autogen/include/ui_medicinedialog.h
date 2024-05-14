/********************************************************************************
** Form generated from reading UI file 'medicinedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDICINEDIALOG_H
#define UI_MEDICINEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MedicineDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_01;
    QLineEdit *codeTextEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_02;
    QLineEdit *nameTextEdit;
    QDialogButtonBox *buttonBox;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *MedicineDialog)
    {
        if (MedicineDialog->objectName().isEmpty())
            MedicineDialog->setObjectName("MedicineDialog");
        MedicineDialog->resize(488, 159);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/Icons/dr-simi-farmacias-similares-logo-svg-vector.svg"), QSize(), QIcon::Normal, QIcon::Off);
        MedicineDialog->setWindowIcon(icon);
        MedicineDialog->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: #ffffff;\n"
"	color: #000000\n"
"}"));
        gridLayout = new QGridLayout(MedicineDialog);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_01 = new QLabel(MedicineDialog);
        label_01->setObjectName("label_01");
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(12);
        label_01->setFont(font);

        horizontalLayout->addWidget(label_01);

        codeTextEdit = new QLineEdit(MedicineDialog);
        codeTextEdit->setObjectName("codeTextEdit");
        codeTextEdit->setMinimumSize(QSize(150, 0));
        codeTextEdit->setFont(font);

        horizontalLayout->addWidget(codeTextEdit);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_02 = new QLabel(MedicineDialog);
        label_02->setObjectName("label_02");
        label_02->setFont(font);

        horizontalLayout_2->addWidget(label_02);

        nameTextEdit = new QLineEdit(MedicineDialog);
        nameTextEdit->setObjectName("nameTextEdit");
        nameTextEdit->setMinimumSize(QSize(400, 0));
        nameTextEdit->setFont(font);

        horizontalLayout_2->addWidget(nameTextEdit);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(MedicineDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setFont(font);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);

        QWidget::setTabOrder(codeTextEdit, nameTextEdit);

        retranslateUi(MedicineDialog);

        QMetaObject::connectSlotsByName(MedicineDialog);
    } // setupUi

    void retranslateUi(QWidget *MedicineDialog)
    {
        MedicineDialog->setWindowTitle(QCoreApplication::translate("MedicineDialog", "Form", nullptr));
        label_01->setText(QCoreApplication::translate("MedicineDialog", "C\303\263digo:", nullptr));
        label_02->setText(QCoreApplication::translate("MedicineDialog", "Nombre:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MedicineDialog: public Ui_MedicineDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDICINEDIALOG_H
