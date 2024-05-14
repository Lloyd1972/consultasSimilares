#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QFileDialog>
#include <QDialog>
#include <QFlags>
#include <Qt>

#include <stdlib.h>
#include <iostream>

#include "consultation.h"

#include "doctordialog.h"
#include "patientdialog.h"
#include "diagnosisdialog.h"
#include "medicinedialog.h"
#include "consultationdialog.h"
#include "searchdialog.h"

#include "doctorfile.h"
#include "patientfile.h"
#include "diagnosisfile.h"
#include "medicinefile.h"
#include "consultationfile.h"
#include "compresseddata.h"

#include "dataEntryDialog.h"
#include "compresseddata.h"

#include "./ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    DoctorFile docFile;
    PatientFile patFile;
    DiagnosisFile diagFile;
    MedicineFile medFile;
    ConsultationFile consFile;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setCellItems(QTableWidget *table, const int& row, const int& col, QTableWidgetItem *item, const QFlags<Qt::AlignmentFlag> &alignment = Qt::AlignHCenter | Qt::AlignVCenter);
    void mainIndex();

    template <typename T>
    void showDialog(const std::string&action, const T&data = T());

    template <typename T>
    void showItemFromTable(const int& row, const int& col);

    template <typename T>
    void addItem();

    template <typename T>
    void modifyItem();

    template <typename T>
    void removeItem();

    template <typename T>
    void searchData();

    template <typename T>
    void updateConsults(const T& data);

    template <typename T>
    T retrieveData();

    template <typename T>
    void showMessage(const bool& checked = true);

    QFlags<Qt::AlignmentFlag> getAlignment(const int& col, const int& index);
    void activateDoctorButtons(const int& row, const int& col);
    void activatePatientButtons(const int& row, const int& col);
    void activateDiagnosisButtons(const int& row, const int& col);
    void activateMedicineButtons(const int& row, const int& col);
    void activateConsultationButtons(const int& row, const int& col);

    void activateSearchButtons();

    template <typename T>
    void fillTable(const list<Tuple<T>> &list, QTableWidget *table);

    template <typename T>
    void addRow(QTableWidget* table, const T &data, const int &row);

    template <typename T>
    std::vector<QString> getStrings(const T& data);

    template <typename T>
    void addRow(QTableWidget* table, const Tuple<T> &data, const int &row);

    template <typename T>
    std::vector<QString> getStrings(const Tuple<T> &data);

    void importData();
    void exportData();
};
#endif // MAINWINDOW_H
