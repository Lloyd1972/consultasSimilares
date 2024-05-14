/********************************************************************************
** Form generated from reading UI file 'tabledialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLEDIALOG_H
#define UI_TABLEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TableDialog
{
public:
    QGridLayout *gridLayout;
    QTableWidget *selectionTable;

    void setupUi(QWidget *TableDialog)
    {
        if (TableDialog->objectName().isEmpty())
            TableDialog->setObjectName("TableDialog");
        TableDialog->resize(709, 264);
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(12);
        TableDialog->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/Icons/dr-simi-farmacias-similares-logo-svg-vector.svg"), QSize(), QIcon::Normal, QIcon::Off);
        TableDialog->setWindowIcon(icon);
        gridLayout = new QGridLayout(TableDialog);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        selectionTable = new QTableWidget(TableDialog);
        selectionTable->setObjectName("selectionTable");
        selectionTable->setStyleSheet(QString::fromUtf8("QTableWidget{\n"
"	gridline-color: #000000;\n"
"    color: #000000;\n"
"	background-color: #FFFFFF;\n"
"}\n"
"QTableWidget::item:alternate{\n"
"    background-color: #CDCEEF;\n"
"	color: #000000;\n"
"}\n"
"QTableWidget::item{\n"
"    background-color: #E5F6FE;\n"
"	color: #000000;\n"
"}\n"
"QTableWidget::item:selected {\n"
"    background-color: #8F90DA;\n"
"	color: #000000;\n"
"}"));
        selectionTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        selectionTable->setAlternatingRowColors(true);
        selectionTable->setSelectionMode(QAbstractItemView::SingleSelection);
        selectionTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        selectionTable->verticalHeader()->setVisible(false);
        selectionTable->verticalHeader()->setMinimumSectionSize(15);
        selectionTable->verticalHeader()->setDefaultSectionSize(20);

        gridLayout->addWidget(selectionTable, 0, 0, 1, 1);


        retranslateUi(TableDialog);

        QMetaObject::connectSlotsByName(TableDialog);
    } // setupUi

    void retranslateUi(QWidget *TableDialog)
    {
        TableDialog->setWindowTitle(QCoreApplication::translate("TableDialog", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TableDialog: public Ui_TableDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEDIALOG_H
