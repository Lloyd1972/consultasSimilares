/********************************************************************************
** Form generated from reading UI file 'doctordialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCTORDIALOG_H
#define UI_DOCTORDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DoctorDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *firstNameTextEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *codeTextEdit;
    QDialogButtonBox *buttonBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lastNameTextEdit;
    QFrame *line;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QTimeEdit *leaveTimeEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QTimeEdit *entryTimeEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *ceduleTextEdit;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *DoctorDialog)
    {
        if (DoctorDialog->objectName().isEmpty())
            DoctorDialog->setObjectName("DoctorDialog");
        DoctorDialog->setWindowModality(Qt::WindowModal);
        DoctorDialog->resize(843, 165);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/Icons/dr-simi-farmacias-similares-logo-svg-vector.svg"), QSize(), QIcon::Normal, QIcon::Off);
        DoctorDialog->setWindowIcon(icon);
        DoctorDialog->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: #ffffff;\n"
"	color: #000000\n"
"}"));
        gridLayout = new QGridLayout(DoctorDialog);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_4 = new QLabel(DoctorDialog);
        label_4->setObjectName("label_4");
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(12);
        label_4->setFont(font);

        horizontalLayout_4->addWidget(label_4);

        firstNameTextEdit = new QLineEdit(DoctorDialog);
        firstNameTextEdit->setObjectName("firstNameTextEdit");
        firstNameTextEdit->setMinimumSize(QSize(220, 0));
        firstNameTextEdit->setFont(font);

        horizontalLayout_4->addWidget(firstNameTextEdit);


        gridLayout->addLayout(horizontalLayout_4, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(DoctorDialog);
        label->setObjectName("label");
        label->setFont(font);

        horizontalLayout->addWidget(label);

        codeTextEdit = new QLineEdit(DoctorDialog);
        codeTextEdit->setObjectName("codeTextEdit");
        codeTextEdit->setMinimumSize(QSize(130, 0));
        codeTextEdit->setFont(font);

        horizontalLayout->addWidget(codeTextEdit);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(DoctorDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setFont(font);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 3, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(DoctorDialog);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        lastNameTextEdit = new QLineEdit(DoctorDialog);
        lastNameTextEdit->setObjectName("lastNameTextEdit");
        lastNameTextEdit->setMinimumSize(QSize(220, 0));
        lastNameTextEdit->setFont(font);

        horizontalLayout_3->addWidget(lastNameTextEdit);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        line = new QFrame(DoctorDialog);
        line->setObjectName("line");
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 2, 2, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_6 = new QLabel(DoctorDialog);
        label_6->setObjectName("label_6");
        label_6->setFont(font);

        horizontalLayout_6->addWidget(label_6);

        leaveTimeEdit = new QTimeEdit(DoctorDialog);
        leaveTimeEdit->setObjectName("leaveTimeEdit");
        leaveTimeEdit->setFont(font);

        horizontalLayout_6->addWidget(leaveTimeEdit);


        gridLayout->addLayout(horizontalLayout_6, 1, 3, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_5 = new QLabel(DoctorDialog);
        label_5->setObjectName("label_5");
        label_5->setFont(font);

        horizontalLayout_5->addWidget(label_5);

        entryTimeEdit = new QTimeEdit(DoctorDialog);
        entryTimeEdit->setObjectName("entryTimeEdit");
        entryTimeEdit->setFont(font);

        horizontalLayout_5->addWidget(entryTimeEdit);


        gridLayout->addLayout(horizontalLayout_5, 0, 3, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(DoctorDialog);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        ceduleTextEdit = new QLineEdit(DoctorDialog);
        ceduleTextEdit->setObjectName("ceduleTextEdit");
        ceduleTextEdit->setMinimumSize(QSize(130, 0));
        ceduleTextEdit->setFont(font);

        horizontalLayout_2->addWidget(ceduleTextEdit);


        gridLayout->addLayout(horizontalLayout_2, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 3, 1, 1);

        QWidget::setTabOrder(codeTextEdit, ceduleTextEdit);
        QWidget::setTabOrder(ceduleTextEdit, lastNameTextEdit);
        QWidget::setTabOrder(lastNameTextEdit, firstNameTextEdit);
        QWidget::setTabOrder(firstNameTextEdit, entryTimeEdit);
        QWidget::setTabOrder(entryTimeEdit, leaveTimeEdit);

        retranslateUi(DoctorDialog);

        QMetaObject::connectSlotsByName(DoctorDialog);
    } // setupUi

    void retranslateUi(QWidget *DoctorDialog)
    {
        DoctorDialog->setWindowTitle(QCoreApplication::translate("DoctorDialog", "Form", nullptr));
        label_4->setText(QCoreApplication::translate("DoctorDialog", "Nombre(s):", nullptr));
        label->setText(QCoreApplication::translate("DoctorDialog", "C\303\263digo:", nullptr));
        label_3->setText(QCoreApplication::translate("DoctorDialog", "Apellidos:", nullptr));
        label_6->setText(QCoreApplication::translate("DoctorDialog", "Hora de Salida:", nullptr));
        leaveTimeEdit->setDisplayFormat(QCoreApplication::translate("DoctorDialog", "hh:mm", nullptr));
        label_5->setText(QCoreApplication::translate("DoctorDialog", "Hora de Entrada:", nullptr));
        entryTimeEdit->setDisplayFormat(QCoreApplication::translate("DoctorDialog", "hh:mm", nullptr));
        label_2->setText(QCoreApplication::translate("DoctorDialog", "Cedula:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DoctorDialog: public Ui_DoctorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCTORDIALOG_H
