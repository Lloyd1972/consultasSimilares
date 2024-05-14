/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionImportar_Respaldo;
    QAction *actionExportar_respaldo;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QWidget *widget_3;
    QGridLayout *gridLayout_4;
    QPushButton *iconMenuButton;
    QVBoxLayout *verticalLayout;
    QPushButton *doctorIcon;
    QPushButton *patientIcon;
    QPushButton *diagnosisIcon;
    QPushButton *medicineIcon;
    QPushButton *consultationIcon;
    QSpacerItem *verticalSpacer_4;
    QWidget *widget_2;
    QGridLayout *gridLayout_3;
    QStackedWidget *stackedWidget;
    QWidget *P0Start;
    QGridLayout *gridLayout_5;
    QLabel *label_5;
    QLabel *label_4;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QWidget *P1Doctor;
    QGridLayout *gridLayout_6;
    QTableWidget *doctorTable;
    QWidget *widget_4;
    QGridLayout *gridLayout_11;
    QSpacerItem *horizontalSpacer;
    QPushButton *removeDoctorButton;
    QPushButton *searchDoctorButton;
    QPushButton *modifyDoctorButton;
    QPushButton *addDoctorButton;
    QWidget *P2Patient;
    QGridLayout *gridLayout_7;
    QWidget *widget_5;
    QGridLayout *gridLayout_12;
    QPushButton *modifyPatientButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *searchPatientButton;
    QPushButton *removePatientButton;
    QPushButton *addPatientButton;
    QTableWidget *patientTable;
    QWidget *P3Diagnosis;
    QGridLayout *gridLayout_8;
    QWidget *widget_6;
    QGridLayout *gridLayout_13;
    QPushButton *addDiagnosisButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *modifyDiagnosisButton;
    QPushButton *searchDiagnosisButton;
    QPushButton *removeDiagnosisButton;
    QTableWidget *diagnosisTable;
    QWidget *P4Medicine;
    QGridLayout *gridLayout_9;
    QWidget *widget_7;
    QGridLayout *gridLayout_14;
    QPushButton *searchMedicineButton;
    QPushButton *modifyMedicineButton;
    QPushButton *removeMedicineButton;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *addMedicineButton;
    QTableWidget *medicineTable;
    QWidget *P5Consultation;
    QGridLayout *gridLayout_10;
    QWidget *widget_8;
    QGridLayout *gridLayout_15;
    QPushButton *modifyConsultationButton;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *removeConsultationButton;
    QPushButton *addConsultationButton;
    QTableWidget *consultationTable;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_2;
    QPushButton *doctorButton;
    QPushButton *patientButton;
    QPushButton *diagnosisButton;
    QPushButton *medicineButton;
    QPushButton *consultationButton;
    QPushButton *menuButton;
    QProgressBar *progressBar;
    QMenuBar *menubar;
    QMenu *menuArchivo;
    QStatusBar *statusBar;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1280, 800);
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(12);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/Icons/dr-simi-farmacias-similares-logo-svg-vector.svg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionImportar_Respaldo = new QAction(MainWindow);
        actionImportar_Respaldo->setObjectName("actionImportar_Respaldo");
        actionExportar_respaldo = new QAction(MainWindow);
        actionExportar_respaldo->setObjectName("actionExportar_respaldo");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName("widget_3");
        widget_3->setSizeIncrement(QSize(30, 30));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: #313a46; width:50px;"));
        gridLayout_4 = new QGridLayout(widget_3);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        iconMenuButton = new QPushButton(widget_3);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName("buttonGroup");
        buttonGroup->addButton(iconMenuButton);
        iconMenuButton->setObjectName("iconMenuButton");
        iconMenuButton->setMinimumSize(QSize(60, 0));
        iconMenuButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"	border-radius: 3px;\n"
"	pading 8px 0 8px 15px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(86, 101, 115, 0.5);\n"
"}"));
        iconMenuButton->setIcon(icon);
        iconMenuButton->setIconSize(QSize(60, 60));
        iconMenuButton->setCheckable(true);
        iconMenuButton->setChecked(false);
        iconMenuButton->setAutoExclusive(false);

        gridLayout_4->addWidget(iconMenuButton, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        doctorIcon = new QPushButton(widget_3);
        doctorIcon->setObjectName("doctorIcon");
        doctorIcon->setMinimumSize(QSize(45, 45));
        doctorIcon->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"	border-radius: 3px;\n"
"	pading 8px 0 8px 15px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(86, 101, 115, 0.5);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/Icons/off-doctor-svgrepo-com.svg"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/icons/Icons/doctor-svgrepo-com.svg"), QSize(), QIcon::Normal, QIcon::On);
        doctorIcon->setIcon(icon1);
        doctorIcon->setIconSize(QSize(36, 36));
        doctorIcon->setCheckable(true);
        doctorIcon->setAutoExclusive(true);

        verticalLayout->addWidget(doctorIcon);

        patientIcon = new QPushButton(widget_3);
        patientIcon->setObjectName("patientIcon");
        patientIcon->setMinimumSize(QSize(45, 45));
        patientIcon->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"	border-radius: 3px;\n"
"	pading 8px 0 8px 15px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(86, 101, 115, 0.5);\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/Icons/off-users-user-svgrepo-com.svg"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/icons/Icons/users-user-svgrepo-com.svg"), QSize(), QIcon::Normal, QIcon::On);
        patientIcon->setIcon(icon2);
        patientIcon->setIconSize(QSize(36, 36));
        patientIcon->setCheckable(true);
        patientIcon->setAutoExclusive(true);

        verticalLayout->addWidget(patientIcon);

        diagnosisIcon = new QPushButton(widget_3);
        diagnosisIcon->setObjectName("diagnosisIcon");
        diagnosisIcon->setMinimumSize(QSize(45, 45));
        diagnosisIcon->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"	border-radius: 3px;\n"
"	pading 8px 0 8px 15px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(86, 101, 115, 0.5);\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/Icons/off-medical-receipt-svgrepo-com.svg"), QSize(), QIcon::Normal, QIcon::Off);
        icon3.addFile(QString::fromUtf8(":/icons/Icons/medical-receipt-svgrepo-com.svg"), QSize(), QIcon::Normal, QIcon::On);
        diagnosisIcon->setIcon(icon3);
        diagnosisIcon->setIconSize(QSize(36, 36));
        diagnosisIcon->setCheckable(true);
        diagnosisIcon->setAutoExclusive(true);

        verticalLayout->addWidget(diagnosisIcon);

        medicineIcon = new QPushButton(widget_3);
        medicineIcon->setObjectName("medicineIcon");
        medicineIcon->setMinimumSize(QSize(45, 45));
        medicineIcon->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"	border-radius: 3px;\n"
"	pading 8px 0 8px 15px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(86, 101, 115, 0.5);\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/Icons/off-medicine-svgrepo-com.svg"), QSize(), QIcon::Normal, QIcon::Off);
        icon4.addFile(QString::fromUtf8(":/icons/Icons/medicine-svgrepo-com.svg"), QSize(), QIcon::Normal, QIcon::On);
        medicineIcon->setIcon(icon4);
        medicineIcon->setIconSize(QSize(36, 36));
        medicineIcon->setCheckable(true);
        medicineIcon->setAutoExclusive(true);

        verticalLayout->addWidget(medicineIcon);

        consultationIcon = new QPushButton(widget_3);
        consultationIcon->setObjectName("consultationIcon");
        consultationIcon->setMinimumSize(QSize(45, 45));
        consultationIcon->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"	border-radius: 3px;\n"
"	pading 8px 0 8px 15px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(86, 101, 115, 0.5);\n"
"}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/Icons/off-electrocardiogram-svgrepo-com.svg"), QSize(), QIcon::Normal, QIcon::Off);
        icon5.addFile(QString::fromUtf8(":/icons/Icons/electrocardiogram-svgrepo-com.svg"), QSize(), QIcon::Normal, QIcon::On);
        consultationIcon->setIcon(icon5);
        consultationIcon->setIconSize(QSize(36, 36));
        consultationIcon->setCheckable(true);
        consultationIcon->setAutoExclusive(true);

        verticalLayout->addWidget(consultationIcon);


        gridLayout_4->addLayout(verticalLayout, 1, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_4->addItem(verticalSpacer_4, 2, 0, 1, 1);


        gridLayout->addWidget(widget_3, 0, 1, 1, 1);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        widget_2->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: #ffffff;\n"
"	color: #000000\n"
"}"));
        gridLayout_3 = new QGridLayout(widget_2);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(widget_2);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        P0Start = new QWidget();
        P0Start->setObjectName("P0Start");
        gridLayout_5 = new QGridLayout(P0Start);
        gridLayout_5->setObjectName("gridLayout_5");
        label_5 = new QLabel(P0Start);
        label_5->setObjectName("label_5");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(16);
        font1.setBold(true);
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);
        label_5->setWordWrap(true);

        gridLayout_5->addWidget(label_5, 2, 0, 1, 1);

        label_4 = new QLabel(P0Start);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(300, 300));
        label_4->setMaximumSize(QSize(300, 300));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/icons/Icons/dr-simi-farmacias-similares-logo-svg-vector.svg")));
        label_4->setScaledContents(true);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_4, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_5->addItem(verticalSpacer, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_5->addItem(verticalSpacer_2, 3, 0, 1, 1);

        stackedWidget->addWidget(P0Start);
        P1Doctor = new QWidget();
        P1Doctor->setObjectName("P1Doctor");
        gridLayout_6 = new QGridLayout(P1Doctor);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setObjectName("gridLayout_6");
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        doctorTable = new QTableWidget(P1Doctor);
        if (doctorTable->columnCount() < 6)
            doctorTable->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font1);
        doctorTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font1);
        doctorTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font1);
        doctorTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font1);
        doctorTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font1);
        doctorTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font1);
        doctorTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        if (doctorTable->rowCount() < 12)
            doctorTable->setRowCount(12);
        doctorTable->setObjectName("doctorTable");
        doctorTable->setFocusPolicy(Qt::ClickFocus);
        doctorTable->setStyleSheet(QString::fromUtf8("QTableWidget{\n"
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
        doctorTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        doctorTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        doctorTable->setAlternatingRowColors(true);
        doctorTable->setSelectionMode(QAbstractItemView::SingleSelection);
        doctorTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        doctorTable->setRowCount(12);
        doctorTable->horizontalHeader()->setVisible(true);
        doctorTable->horizontalHeader()->setMinimumSectionSize(15);
        doctorTable->horizontalHeader()->setDefaultSectionSize(100);
        doctorTable->verticalHeader()->setVisible(false);
        doctorTable->verticalHeader()->setMinimumSectionSize(15);
        doctorTable->verticalHeader()->setDefaultSectionSize(20);

        gridLayout_6->addWidget(doctorTable, 1, 0, 1, 1);

        widget_4 = new QWidget(P1Doctor);
        widget_4->setObjectName("widget_4");
        widget_4->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: #E1E1E1;\n"
"	color: #000000;\n"
"}"));
        gridLayout_11 = new QGridLayout(widget_4);
        gridLayout_11->setObjectName("gridLayout_11");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_11->addItem(horizontalSpacer, 0, 4, 1, 1);

        removeDoctorButton = new QPushButton(widget_4);
        removeDoctorButton->setObjectName("removeDoctorButton");
        removeDoctorButton->setEnabled(false);
        removeDoctorButton->setMinimumSize(QSize(45, 45));
        removeDoctorButton->setMaximumSize(QSize(45, 45));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/Icons/remove.svg"), QSize(), QIcon::Normal, QIcon::Off);
        removeDoctorButton->setIcon(icon6);
        removeDoctorButton->setIconSize(QSize(30, 30));

        gridLayout_11->addWidget(removeDoctorButton, 0, 2, 1, 1);

        searchDoctorButton = new QPushButton(widget_4);
        searchDoctorButton->setObjectName("searchDoctorButton");
        searchDoctorButton->setEnabled(false);
        searchDoctorButton->setMinimumSize(QSize(45, 45));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/Icons/search.svg"), QSize(), QIcon::Normal, QIcon::Off);
        searchDoctorButton->setIcon(icon7);
        searchDoctorButton->setIconSize(QSize(30, 30));

        gridLayout_11->addWidget(searchDoctorButton, 0, 3, 1, 1);

        modifyDoctorButton = new QPushButton(widget_4);
        modifyDoctorButton->setObjectName("modifyDoctorButton");
        modifyDoctorButton->setEnabled(false);
        modifyDoctorButton->setMinimumSize(QSize(45, 45));
        modifyDoctorButton->setMaximumSize(QSize(45, 45));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/Icons/modify.svg"), QSize(), QIcon::Normal, QIcon::Off);
        modifyDoctorButton->setIcon(icon8);
        modifyDoctorButton->setIconSize(QSize(30, 30));

        gridLayout_11->addWidget(modifyDoctorButton, 0, 1, 1, 1);

        addDoctorButton = new QPushButton(widget_4);
        addDoctorButton->setObjectName("addDoctorButton");
        addDoctorButton->setMinimumSize(QSize(45, 45));
        addDoctorButton->setMaximumSize(QSize(45, 45));
        addDoctorButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	pading 8px 0 8px 15px;\n"
"}"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icons/Icons/add.svg"), QSize(), QIcon::Normal, QIcon::Off);
        addDoctorButton->setIcon(icon9);
        addDoctorButton->setIconSize(QSize(30, 30));

        gridLayout_11->addWidget(addDoctorButton, 0, 0, 1, 1);


        gridLayout_6->addWidget(widget_4, 0, 0, 1, 1);

        stackedWidget->addWidget(P1Doctor);
        P2Patient = new QWidget();
        P2Patient->setObjectName("P2Patient");
        gridLayout_7 = new QGridLayout(P2Patient);
        gridLayout_7->setSpacing(0);
        gridLayout_7->setObjectName("gridLayout_7");
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        widget_5 = new QWidget(P2Patient);
        widget_5->setObjectName("widget_5");
        widget_5->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: #E1E1E1;\n"
"	color: #000000;\n"
"}"));
        gridLayout_12 = new QGridLayout(widget_5);
        gridLayout_12->setObjectName("gridLayout_12");
        modifyPatientButton = new QPushButton(widget_5);
        modifyPatientButton->setObjectName("modifyPatientButton");
        modifyPatientButton->setEnabled(false);
        modifyPatientButton->setMinimumSize(QSize(45, 45));
        modifyPatientButton->setMaximumSize(QSize(45, 45));
        modifyPatientButton->setIcon(icon8);
        modifyPatientButton->setIconSize(QSize(30, 30));

        gridLayout_12->addWidget(modifyPatientButton, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_12->addItem(horizontalSpacer_2, 0, 4, 1, 1);

        searchPatientButton = new QPushButton(widget_5);
        searchPatientButton->setObjectName("searchPatientButton");
        searchPatientButton->setEnabled(false);
        searchPatientButton->setMinimumSize(QSize(45, 45));
        searchPatientButton->setIcon(icon7);
        searchPatientButton->setIconSize(QSize(30, 30));

        gridLayout_12->addWidget(searchPatientButton, 0, 3, 1, 1);

        removePatientButton = new QPushButton(widget_5);
        removePatientButton->setObjectName("removePatientButton");
        removePatientButton->setEnabled(false);
        removePatientButton->setMinimumSize(QSize(45, 45));
        removePatientButton->setMaximumSize(QSize(45, 45));
        removePatientButton->setIcon(icon6);
        removePatientButton->setIconSize(QSize(30, 30));

        gridLayout_12->addWidget(removePatientButton, 0, 2, 1, 1);

        addPatientButton = new QPushButton(widget_5);
        addPatientButton->setObjectName("addPatientButton");
        addPatientButton->setMinimumSize(QSize(45, 45));
        addPatientButton->setMaximumSize(QSize(45, 45));
        addPatientButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	pading 8px 0 8px 15px;\n"
"}"));
        addPatientButton->setIcon(icon9);
        addPatientButton->setIconSize(QSize(30, 30));

        gridLayout_12->addWidget(addPatientButton, 0, 0, 1, 1);


        gridLayout_7->addWidget(widget_5, 0, 0, 1, 1);

        patientTable = new QTableWidget(P2Patient);
        if (patientTable->columnCount() < 6)
            patientTable->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font1);
        patientTable->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font1);
        patientTable->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font1);
        patientTable->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFont(font1);
        patientTable->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font1);
        patientTable->setHorizontalHeaderItem(4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setFont(font1);
        patientTable->setHorizontalHeaderItem(5, __qtablewidgetitem11);
        if (patientTable->rowCount() < 12)
            patientTable->setRowCount(12);
        patientTable->setObjectName("patientTable");
        patientTable->setFocusPolicy(Qt::ClickFocus);
        patientTable->setStyleSheet(QString::fromUtf8("QTableWidget{\n"
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
        patientTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        patientTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        patientTable->setAlternatingRowColors(true);
        patientTable->setSelectionMode(QAbstractItemView::SingleSelection);
        patientTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        patientTable->setRowCount(12);
        patientTable->horizontalHeader()->setVisible(true);
        patientTable->horizontalHeader()->setMinimumSectionSize(15);
        patientTable->horizontalHeader()->setDefaultSectionSize(100);
        patientTable->verticalHeader()->setVisible(false);
        patientTable->verticalHeader()->setMinimumSectionSize(15);
        patientTable->verticalHeader()->setDefaultSectionSize(20);

        gridLayout_7->addWidget(patientTable, 1, 0, 1, 1);

        stackedWidget->addWidget(P2Patient);
        P3Diagnosis = new QWidget();
        P3Diagnosis->setObjectName("P3Diagnosis");
        gridLayout_8 = new QGridLayout(P3Diagnosis);
        gridLayout_8->setSpacing(0);
        gridLayout_8->setObjectName("gridLayout_8");
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        widget_6 = new QWidget(P3Diagnosis);
        widget_6->setObjectName("widget_6");
        widget_6->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: #E1E1E1;\n"
"	color: #000000;\n"
"}"));
        gridLayout_13 = new QGridLayout(widget_6);
        gridLayout_13->setObjectName("gridLayout_13");
        addDiagnosisButton = new QPushButton(widget_6);
        addDiagnosisButton->setObjectName("addDiagnosisButton");
        addDiagnosisButton->setMinimumSize(QSize(45, 45));
        addDiagnosisButton->setMaximumSize(QSize(45, 45));
        addDiagnosisButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	pading 8px 0 8px 15px;\n"
"}"));
        QIcon icon10;
        QString iconThemeName = QString::fromUtf8("document-new");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon10 = QIcon::fromTheme(iconThemeName);
        } else {
            icon10.addFile(QString::fromUtf8(":/icons/Icons/add.svg"), QSize(), QIcon::Normal, QIcon::Off);
        }
        addDiagnosisButton->setIcon(icon10);
        addDiagnosisButton->setIconSize(QSize(30, 30));

        gridLayout_13->addWidget(addDiagnosisButton, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_13->addItem(horizontalSpacer_3, 0, 4, 1, 1);

        modifyDiagnosisButton = new QPushButton(widget_6);
        modifyDiagnosisButton->setObjectName("modifyDiagnosisButton");
        modifyDiagnosisButton->setEnabled(false);
        modifyDiagnosisButton->setMinimumSize(QSize(45, 45));
        modifyDiagnosisButton->setMaximumSize(QSize(45, 45));
        modifyDiagnosisButton->setIcon(icon8);
        modifyDiagnosisButton->setIconSize(QSize(30, 30));

        gridLayout_13->addWidget(modifyDiagnosisButton, 0, 1, 1, 1);

        searchDiagnosisButton = new QPushButton(widget_6);
        searchDiagnosisButton->setObjectName("searchDiagnosisButton");
        searchDiagnosisButton->setEnabled(false);
        searchDiagnosisButton->setMinimumSize(QSize(45, 45));
        searchDiagnosisButton->setIcon(icon7);
        searchDiagnosisButton->setIconSize(QSize(30, 30));

        gridLayout_13->addWidget(searchDiagnosisButton, 0, 3, 1, 1);

        removeDiagnosisButton = new QPushButton(widget_6);
        removeDiagnosisButton->setObjectName("removeDiagnosisButton");
        removeDiagnosisButton->setEnabled(false);
        removeDiagnosisButton->setMinimumSize(QSize(45, 45));
        removeDiagnosisButton->setMaximumSize(QSize(45, 45));
        removeDiagnosisButton->setIcon(icon6);
        removeDiagnosisButton->setIconSize(QSize(30, 30));

        gridLayout_13->addWidget(removeDiagnosisButton, 0, 2, 1, 1);


        gridLayout_8->addWidget(widget_6, 0, 0, 1, 1);

        diagnosisTable = new QTableWidget(P3Diagnosis);
        if (diagnosisTable->columnCount() < 3)
            diagnosisTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setFont(font1);
        diagnosisTable->setHorizontalHeaderItem(0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setFont(font1);
        diagnosisTable->setHorizontalHeaderItem(1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setFont(font1);
        diagnosisTable->setHorizontalHeaderItem(2, __qtablewidgetitem14);
        if (diagnosisTable->rowCount() < 12)
            diagnosisTable->setRowCount(12);
        diagnosisTable->setObjectName("diagnosisTable");
        diagnosisTable->setFocusPolicy(Qt::ClickFocus);
        diagnosisTable->setStyleSheet(QString::fromUtf8("QTableWidget{\n"
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
        diagnosisTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        diagnosisTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        diagnosisTable->setAlternatingRowColors(true);
        diagnosisTable->setSelectionMode(QAbstractItemView::SingleSelection);
        diagnosisTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        diagnosisTable->setRowCount(12);
        diagnosisTable->horizontalHeader()->setVisible(true);
        diagnosisTable->horizontalHeader()->setMinimumSectionSize(15);
        diagnosisTable->horizontalHeader()->setDefaultSectionSize(100);
        diagnosisTable->verticalHeader()->setVisible(false);
        diagnosisTable->verticalHeader()->setMinimumSectionSize(15);
        diagnosisTable->verticalHeader()->setDefaultSectionSize(20);

        gridLayout_8->addWidget(diagnosisTable, 1, 0, 1, 1);

        stackedWidget->addWidget(P3Diagnosis);
        P4Medicine = new QWidget();
        P4Medicine->setObjectName("P4Medicine");
        gridLayout_9 = new QGridLayout(P4Medicine);
        gridLayout_9->setSpacing(0);
        gridLayout_9->setObjectName("gridLayout_9");
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        widget_7 = new QWidget(P4Medicine);
        widget_7->setObjectName("widget_7");
        widget_7->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: #E1E1E1;\n"
"	color: #000000;\n"
"}"));
        gridLayout_14 = new QGridLayout(widget_7);
        gridLayout_14->setObjectName("gridLayout_14");
        searchMedicineButton = new QPushButton(widget_7);
        searchMedicineButton->setObjectName("searchMedicineButton");
        searchMedicineButton->setEnabled(false);
        searchMedicineButton->setMinimumSize(QSize(45, 45));
        searchMedicineButton->setIcon(icon7);
        searchMedicineButton->setIconSize(QSize(30, 30));

        gridLayout_14->addWidget(searchMedicineButton, 0, 3, 1, 1);

        modifyMedicineButton = new QPushButton(widget_7);
        modifyMedicineButton->setObjectName("modifyMedicineButton");
        modifyMedicineButton->setEnabled(false);
        modifyMedicineButton->setMinimumSize(QSize(45, 45));
        modifyMedicineButton->setMaximumSize(QSize(45, 45));
        modifyMedicineButton->setIcon(icon8);
        modifyMedicineButton->setIconSize(QSize(30, 30));

        gridLayout_14->addWidget(modifyMedicineButton, 0, 1, 1, 1);

        removeMedicineButton = new QPushButton(widget_7);
        removeMedicineButton->setObjectName("removeMedicineButton");
        removeMedicineButton->setEnabled(false);
        removeMedicineButton->setMinimumSize(QSize(45, 45));
        removeMedicineButton->setMaximumSize(QSize(45, 45));
        removeMedicineButton->setIcon(icon6);
        removeMedicineButton->setIconSize(QSize(30, 30));

        gridLayout_14->addWidget(removeMedicineButton, 0, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_14->addItem(horizontalSpacer_4, 0, 4, 1, 1);

        addMedicineButton = new QPushButton(widget_7);
        addMedicineButton->setObjectName("addMedicineButton");
        addMedicineButton->setMinimumSize(QSize(45, 45));
        addMedicineButton->setMaximumSize(QSize(45, 45));
        addMedicineButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	pading 8px 0 8px 15px;\n"
"}"));
        addMedicineButton->setIcon(icon9);
        addMedicineButton->setIconSize(QSize(30, 30));

        gridLayout_14->addWidget(addMedicineButton, 0, 0, 1, 1);


        gridLayout_9->addWidget(widget_7, 0, 0, 1, 1);

        medicineTable = new QTableWidget(P4Medicine);
        if (medicineTable->columnCount() < 2)
            medicineTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setFont(font1);
        medicineTable->setHorizontalHeaderItem(0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setFont(font1);
        medicineTable->setHorizontalHeaderItem(1, __qtablewidgetitem16);
        if (medicineTable->rowCount() < 12)
            medicineTable->setRowCount(12);
        medicineTable->setObjectName("medicineTable");
        medicineTable->setMinimumSize(QSize(150, 0));
        medicineTable->setFocusPolicy(Qt::ClickFocus);
        medicineTable->setStyleSheet(QString::fromUtf8("QTableWidget{\n"
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
        medicineTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        medicineTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        medicineTable->setAlternatingRowColors(true);
        medicineTable->setSelectionMode(QAbstractItemView::SingleSelection);
        medicineTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        medicineTable->setRowCount(12);
        medicineTable->horizontalHeader()->setVisible(true);
        medicineTable->horizontalHeader()->setMinimumSectionSize(15);
        medicineTable->horizontalHeader()->setDefaultSectionSize(100);
        medicineTable->verticalHeader()->setVisible(false);
        medicineTable->verticalHeader()->setMinimumSectionSize(15);
        medicineTable->verticalHeader()->setDefaultSectionSize(20);

        gridLayout_9->addWidget(medicineTable, 1, 0, 1, 1);

        stackedWidget->addWidget(P4Medicine);
        P5Consultation = new QWidget();
        P5Consultation->setObjectName("P5Consultation");
        gridLayout_10 = new QGridLayout(P5Consultation);
        gridLayout_10->setSpacing(0);
        gridLayout_10->setObjectName("gridLayout_10");
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        widget_8 = new QWidget(P5Consultation);
        widget_8->setObjectName("widget_8");
        widget_8->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: #E1E1E1;\n"
"	color: #000000;\n"
"}"));
        gridLayout_15 = new QGridLayout(widget_8);
        gridLayout_15->setObjectName("gridLayout_15");
        modifyConsultationButton = new QPushButton(widget_8);
        modifyConsultationButton->setObjectName("modifyConsultationButton");
        modifyConsultationButton->setEnabled(false);
        modifyConsultationButton->setMinimumSize(QSize(45, 45));
        modifyConsultationButton->setMaximumSize(QSize(45, 45));
        modifyConsultationButton->setIcon(icon8);
        modifyConsultationButton->setIconSize(QSize(30, 30));

        gridLayout_15->addWidget(modifyConsultationButton, 0, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_15->addItem(horizontalSpacer_5, 0, 3, 1, 1);

        removeConsultationButton = new QPushButton(widget_8);
        removeConsultationButton->setObjectName("removeConsultationButton");
        removeConsultationButton->setEnabled(false);
        removeConsultationButton->setMinimumSize(QSize(45, 45));
        removeConsultationButton->setMaximumSize(QSize(45, 45));
        removeConsultationButton->setIcon(icon6);
        removeConsultationButton->setIconSize(QSize(30, 30));

        gridLayout_15->addWidget(removeConsultationButton, 0, 2, 1, 1);

        addConsultationButton = new QPushButton(widget_8);
        addConsultationButton->setObjectName("addConsultationButton");
        addConsultationButton->setMinimumSize(QSize(45, 45));
        addConsultationButton->setMaximumSize(QSize(45, 45));
        addConsultationButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	pading 8px 0 8px 15px;\n"
"}"));
        addConsultationButton->setIcon(icon9);
        addConsultationButton->setIconSize(QSize(30, 30));

        gridLayout_15->addWidget(addConsultationButton, 0, 0, 1, 1);


        gridLayout_10->addWidget(widget_8, 0, 0, 1, 1);

        consultationTable = new QTableWidget(P5Consultation);
        if (consultationTable->columnCount() < 5)
            consultationTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setFont(font1);
        consultationTable->setHorizontalHeaderItem(0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setFont(font1);
        consultationTable->setHorizontalHeaderItem(1, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setFont(font1);
        consultationTable->setHorizontalHeaderItem(2, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setFont(font1);
        consultationTable->setHorizontalHeaderItem(3, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        consultationTable->setHorizontalHeaderItem(4, __qtablewidgetitem21);
        if (consultationTable->rowCount() < 12)
            consultationTable->setRowCount(12);
        consultationTable->setObjectName("consultationTable");
        consultationTable->setFocusPolicy(Qt::ClickFocus);
        consultationTable->setStyleSheet(QString::fromUtf8("QTableWidget{\n"
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
        consultationTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        consultationTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        consultationTable->setAlternatingRowColors(true);
        consultationTable->setSelectionMode(QAbstractItemView::SingleSelection);
        consultationTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        consultationTable->setRowCount(12);
        consultationTable->horizontalHeader()->setVisible(true);
        consultationTable->horizontalHeader()->setMinimumSectionSize(15);
        consultationTable->horizontalHeader()->setDefaultSectionSize(100);
        consultationTable->verticalHeader()->setVisible(false);
        consultationTable->verticalHeader()->setMinimumSectionSize(15);
        consultationTable->verticalHeader()->setDefaultSectionSize(20);

        gridLayout_10->addWidget(consultationTable, 1, 0, 1, 1);

        stackedWidget->addWidget(P5Consultation);

        gridLayout_3->addWidget(stackedWidget, 0, 0, 1, 1);


        gridLayout->addWidget(widget_2, 0, 2, 1, 1);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setStyleSheet(QString::fromUtf8("background-color: #313a46;"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 2, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        doctorButton = new QPushButton(widget);
        doctorButton->setObjectName("doctorButton");
        doctorButton->setMinimumSize(QSize(0, 30));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(10);
        font2.setBold(true);
        doctorButton->setFont(font2);
        doctorButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"	border-radius: 3px;\n"
"	text-align: left;\n"
"	pading 8px 0 8px 15px;\n"
"	color: rgb(120, 133, 150);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(86, 101, 115, 0.5);\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"	color: #fff;\n"
"}"));
        doctorButton->setIcon(icon1);
        doctorButton->setIconSize(QSize(25, 25));
        doctorButton->setCheckable(true);
        doctorButton->setAutoExclusive(true);

        verticalLayout_2->addWidget(doctorButton);

        patientButton = new QPushButton(widget);
        patientButton->setObjectName("patientButton");
        patientButton->setMinimumSize(QSize(0, 30));
        patientButton->setFont(font2);
        patientButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"	border-radius: 3px;\n"
"	text-align: left;\n"
"	pading 8px 0 8px 15px;\n"
"	color: rgb(120, 133, 150);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(86, 101, 115, 0.5);\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"	color: #fff;\n"
"}"));
        patientButton->setIcon(icon2);
        patientButton->setIconSize(QSize(25, 25));
        patientButton->setCheckable(true);
        patientButton->setAutoExclusive(true);

        verticalLayout_2->addWidget(patientButton);

        diagnosisButton = new QPushButton(widget);
        diagnosisButton->setObjectName("diagnosisButton");
        diagnosisButton->setMinimumSize(QSize(0, 30));
        diagnosisButton->setFont(font2);
        diagnosisButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"	border-radius: 3px;\n"
"	text-align: left;\n"
"	pading 8px 0 8px 15px;\n"
"	color: rgb(120, 133, 150);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(86, 101, 115, 0.5);\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"	color: #fff;\n"
"}"));
        diagnosisButton->setIcon(icon3);
        diagnosisButton->setIconSize(QSize(25, 25));
        diagnosisButton->setCheckable(true);
        diagnosisButton->setAutoExclusive(true);

        verticalLayout_2->addWidget(diagnosisButton);

        medicineButton = new QPushButton(widget);
        medicineButton->setObjectName("medicineButton");
        medicineButton->setMinimumSize(QSize(0, 30));
        medicineButton->setFont(font2);
        medicineButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"	border-radius: 3px;\n"
"	text-align: left;\n"
"	pading 8px 0 8px 15px;\n"
"	color: rgb(120, 133, 150);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(86, 101, 115, 0.5);\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"	color: #fff;\n"
"}"));
        medicineButton->setIcon(icon4);
        medicineButton->setIconSize(QSize(25, 25));
        medicineButton->setCheckable(true);
        medicineButton->setAutoExclusive(true);

        verticalLayout_2->addWidget(medicineButton);

        consultationButton = new QPushButton(widget);
        consultationButton->setObjectName("consultationButton");
        consultationButton->setMinimumSize(QSize(0, 30));
        consultationButton->setFont(font2);
        consultationButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"	border-radius: 3px;\n"
"	text-align: left;\n"
"	pading 8px 0 8px 15px;\n"
"	color: rgb(120, 133, 150);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(86, 101, 115, 0.5);\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"	color: #fff;\n"
"}"));
        consultationButton->setIcon(icon5);
        consultationButton->setIconSize(QSize(25, 25));
        consultationButton->setCheckable(true);
        consultationButton->setAutoExclusive(true);

        verticalLayout_2->addWidget(consultationButton);


        gridLayout_2->addLayout(verticalLayout_2, 1, 0, 1, 1);

        menuButton = new QPushButton(widget);
        buttonGroup->addButton(menuButton);
        menuButton->setObjectName("menuButton");
        menuButton->setMinimumSize(QSize(140, 0));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Arial")});
        font3.setPointSize(11);
        font3.setBold(true);
        menuButton->setFont(font3);
        menuButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"	border-radius: 3px;\n"
"	text-align: left;\n"
"	pading 8px 0 8px 15px;\n"
"	color: rgb(120, 133, 150);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(86, 101, 115, 0.5);\n"
"	color: #ffffff;\n"
"}"));
        menuButton->setIcon(icon);
        menuButton->setIconSize(QSize(60, 60));
        menuButton->setCheckable(true);
        menuButton->setChecked(true);
        menuButton->setAutoExclusive(false);

        gridLayout_2->addWidget(menuButton, 0, 0, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 1);

        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setValue(24);

        gridLayout->addWidget(progressBar, 1, 0, 1, 3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1280, 21));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Segoe UI")});
        font4.setPointSize(9);
        menubar->setFont(font4);
        menuArchivo = new QMenu(menubar);
        menuArchivo->setObjectName("menuArchivo");
        MainWindow->setMenuBar(menubar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        statusBar->setStyleSheet(QString::fromUtf8("background-color: #313a46;\n"
"color: #ffffff;\n"
"text-align: right;"));
        statusBar->setSizeGripEnabled(false);
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(menuButton, doctorButton);
        QWidget::setTabOrder(doctorButton, patientButton);
        QWidget::setTabOrder(patientButton, diagnosisButton);
        QWidget::setTabOrder(diagnosisButton, medicineButton);
        QWidget::setTabOrder(medicineButton, consultationButton);
        QWidget::setTabOrder(consultationButton, iconMenuButton);
        QWidget::setTabOrder(iconMenuButton, doctorIcon);
        QWidget::setTabOrder(doctorIcon, patientIcon);
        QWidget::setTabOrder(patientIcon, diagnosisIcon);
        QWidget::setTabOrder(diagnosisIcon, medicineIcon);
        QWidget::setTabOrder(medicineIcon, consultationIcon);
        QWidget::setTabOrder(consultationIcon, addDoctorButton);
        QWidget::setTabOrder(addDoctorButton, modifyDoctorButton);
        QWidget::setTabOrder(modifyDoctorButton, removeDoctorButton);
        QWidget::setTabOrder(removeDoctorButton, doctorTable);
        QWidget::setTabOrder(doctorTable, addPatientButton);
        QWidget::setTabOrder(addPatientButton, modifyPatientButton);
        QWidget::setTabOrder(modifyPatientButton, removePatientButton);
        QWidget::setTabOrder(removePatientButton, patientTable);

        menubar->addAction(menuArchivo->menuAction());
        menuArchivo->addAction(actionImportar_Respaldo);
        menuArchivo->addAction(actionExportar_respaldo);

        retranslateUi(MainWindow);
        QObject::connect(iconMenuButton, &QPushButton::toggled, widget, &QWidget::setVisible);
        QObject::connect(menuButton, &QPushButton::toggled, widget_3, &QWidget::setVisible);
        QObject::connect(doctorButton, &QPushButton::toggled, doctorIcon, &QPushButton::setChecked);
        QObject::connect(patientButton, &QPushButton::toggled, patientIcon, &QPushButton::setChecked);
        QObject::connect(diagnosisButton, &QPushButton::toggled, diagnosisIcon, &QPushButton::setChecked);
        QObject::connect(medicineButton, &QPushButton::toggled, medicineIcon, &QPushButton::setChecked);
        QObject::connect(consultationButton, &QPushButton::toggled, consultationIcon, &QPushButton::setChecked);
        QObject::connect(doctorIcon, &QPushButton::toggled, doctorButton, &QPushButton::setChecked);
        QObject::connect(patientIcon, &QPushButton::toggled, patientButton, &QPushButton::setChecked);
        QObject::connect(diagnosisIcon, &QPushButton::toggled, diagnosisButton, &QPushButton::setChecked);
        QObject::connect(medicineIcon, &QPushButton::toggled, medicineButton, &QPushButton::setChecked);
        QObject::connect(consultationIcon, &QPushButton::toggled, consultationButton, &QPushButton::setChecked);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Consultas Similares", nullptr));
        actionImportar_Respaldo->setText(QCoreApplication::translate("MainWindow", "Importar Respaldo", nullptr));
        actionExportar_respaldo->setText(QCoreApplication::translate("MainWindow", "Exportar respaldo", nullptr));
        iconMenuButton->setText(QString());
        doctorIcon->setText(QString());
        patientIcon->setText(QString());
        diagnosisIcon->setText(QString());
        medicineIcon->setText(QString());
        consultationIcon->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "Seleccione una opci\303\263n para continuar.", nullptr));
        label_4->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = doctorTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "C\303\263digo", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = doctorTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Apellidos", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = doctorTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Nombre(s)", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = doctorTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Cedula", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = doctorTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Entrada", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = doctorTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Salida", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = patientTable->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "NSS", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = patientTable->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Apellidos", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = patientTable->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Nombre(s)", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = patientTable->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Fecha de Nac.", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = patientTable->horizontalHeaderItem(4);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "Domicilio", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = patientTable->horizontalHeaderItem(5);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "Tel\303\251fono", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = diagnosisTable->horizontalHeaderItem(0);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "C\303\263digo", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = diagnosisTable->horizontalHeaderItem(1);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "Descripci\303\263n", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = diagnosisTable->horizontalHeaderItem(2);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "Indicaciones", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = medicineTable->horizontalHeaderItem(0);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "C\303\263digo", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = medicineTable->horizontalHeaderItem(1);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "Nombre", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = consultationTable->horizontalHeaderItem(0);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "Fecha", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = consultationTable->horizontalHeaderItem(1);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "Hora", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = consultationTable->horizontalHeaderItem(2);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "Medico", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = consultationTable->horizontalHeaderItem(3);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "Paciente", nullptr));
        doctorButton->setText(QCoreApplication::translate("MainWindow", "M\303\251dico", nullptr));
        patientButton->setText(QCoreApplication::translate("MainWindow", "Paciente", nullptr));
        diagnosisButton->setText(QCoreApplication::translate("MainWindow", "Diagn\303\263stico", nullptr));
        medicineButton->setText(QCoreApplication::translate("MainWindow", "Medicamento", nullptr));
        consultationButton->setText(QCoreApplication::translate("MainWindow", "Consulta", nullptr));
        menuButton->setText(QCoreApplication::translate("MainWindow", "Consultas\n"
"Similares", nullptr));
        menuArchivo->setTitle(QCoreApplication::translate("MainWindow", "Archivo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
