/********************************************************************************
** Form generated from reading UI file 'searchdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHDIALOG_H
#define UI_SEARCHDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QDialogButtonBox *buttonBox;
    QLineEdit *searchingLineEdit;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QRadioButton *codeRadioButton;
    QRadioButton *nameRadioButton;
    QButtonGroup *selectionGroup;

    void setupUi(QWidget *SearchDialog)
    {
        if (SearchDialog->objectName().isEmpty())
            SearchDialog->setObjectName("SearchDialog");
        SearchDialog->resize(655, 110);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/Icons/dr-simi-farmacias-similares-logo-svg-vector.svg"), QSize(), QIcon::Normal, QIcon::Off);
        SearchDialog->setWindowIcon(icon);
        gridLayout = new QGridLayout(SearchDialog);
        gridLayout->setObjectName("gridLayout");
        label_2 = new QLabel(SearchDialog);
        label_2->setObjectName("label_2");
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(12);
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(SearchDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 1, 1, 1);

        searchingLineEdit = new QLineEdit(SearchDialog);
        searchingLineEdit->setObjectName("searchingLineEdit");
        searchingLineEdit->setFont(font);
        searchingLineEdit->setClearButtonEnabled(true);

        gridLayout->addWidget(searchingLineEdit, 0, 1, 1, 1);

        label = new QLabel(SearchDialog);
        label->setObjectName("label");
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        codeRadioButton = new QRadioButton(SearchDialog);
        selectionGroup = new QButtonGroup(SearchDialog);
        selectionGroup->setObjectName("selectionGroup");
        selectionGroup->addButton(codeRadioButton);
        codeRadioButton->setObjectName("codeRadioButton");
        codeRadioButton->setEnabled(true);
        codeRadioButton->setFont(font);
        codeRadioButton->setChecked(true);

        horizontalLayout->addWidget(codeRadioButton);

        nameRadioButton = new QRadioButton(SearchDialog);
        selectionGroup->addButton(nameRadioButton);
        nameRadioButton->setObjectName("nameRadioButton");
        nameRadioButton->setEnabled(true);
        nameRadioButton->setFont(font);

        horizontalLayout->addWidget(nameRadioButton);


        gridLayout->addLayout(horizontalLayout, 1, 1, 1, 1);


        retranslateUi(SearchDialog);

        QMetaObject::connectSlotsByName(SearchDialog);
    } // setupUi

    void retranslateUi(QWidget *SearchDialog)
    {
        SearchDialog->setWindowTitle(QCoreApplication::translate("SearchDialog", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("SearchDialog", "Buscar por:", nullptr));
        label->setText(QCoreApplication::translate("SearchDialog", "Ingrese el c\303\263digo a buscar: ", nullptr));
        codeRadioButton->setText(QCoreApplication::translate("SearchDialog", "C\303\263digo", nullptr));
        nameRadioButton->setText(QCoreApplication::translate("SearchDialog", "Nombre", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchDialog: public Ui_SearchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHDIALOG_H
