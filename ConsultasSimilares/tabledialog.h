#ifndef TABLEDIALOG_H
#define TABLEDIALOG_H

#include <list>
#include <vector>

#include <QDialog>
#include <QFont>

#include "ui_tabledialog.h"

#include "doctorfile.h"
#include "patientfile.h"
#include "diagnosisfile.h"
#include "medicinefile.h"

namespace Ui {
class TableDialog;
}

template <typename T>
class TableDialog : public QDialog {
private:
    Ui::TableDialog *ui;
    std::list<Tuple<T>> data;

public:
    TableDialog(const QString &title, QWidget *parent = nullptr);
    ~TableDialog();

    vector<QString> getSelectedData() const;
    void setTableCellItems(const int&row, const int&col, QTableWidgetItem *item, const QFlags<Qt::AlignmentFlag>&alignment);
    QFlags<Qt::AlignmentFlag> getAlignment(const int &col, const int &type);
};

#endif // TABLEDIALOG_H
using namespace std;

template <typename T>
TableDialog<T>::TableDialog(const QString&title, QWidget *parent) : QDialog(parent), ui(new Ui::TableDialog){
    ui->setupUi(this);

    setWindowTitle(title);

    list<Tuple<T>> list = {};
    vector<QString> headers;
    QFont font("Arial", 16, QFont::Bold);

    if constexpr(is_same_v<T, Doctor>) {
        headers = {"Código", "Apellidos", "Nombre(s)", "Cedula", "Entrada", "Salida"};

        DoctorFile docFile;
        list = docFile.getList();
    } else if constexpr(is_same_v<T, Patient>) {
        headers = {"NSS", "Apellidos", "Nombre(s)", "Fecha de Nac.", "Domicilio", "Teléfono"};

        PatientFile patFile;
        list = patFile.getList();
    } else if constexpr(is_same_v<T, Diagnosis>) {
        headers = {"Código", "Descripción", "Indicaciones"};

        DiagnosisFile diagFile;
        list = diagFile.getList();
    } else if constexpr(is_same_v<T, Medicine>) {
        headers = {"Código", "Nombre"};

        MedicineFile medFile;
        list = medFile.getList();
    }

    ui->selectionTable->setRowCount(list.size());
    ui->selectionTable->setColumnCount(headers.size());

    for(int col = 0; col < headers.size(); col++) {
        QTableWidgetItem *headerItem(new QTableWidgetItem(headers[col]));
        headerItem->setFont(font);

        ui->selectionTable->setHorizontalHeaderItem(col, headerItem);
    }
    QCoreApplication::processEvents();

    int row(0);
    for(auto &it : list) {
        if constexpr(is_same_v<T, Doctor>) {
            setTableCellItems(row, 0, new QTableWidgetItem(it.getData().getCode()), getAlignment(0, 1));
            setTableCellItems(row, 1, new QTableWidgetItem(it.getData().getName().getLast()), getAlignment(1, 1));
            setTableCellItems(row, 2, new QTableWidgetItem(it.getData().getName().getFirst()), getAlignment(2, 1));
            setTableCellItems(row, 3, new QTableWidgetItem(it.getData().getCedule()), getAlignment(3, 1));
            setTableCellItems(row, 4, new QTableWidgetItem(it.getData().getEntryHour().toString("hh:mm")), getAlignment(4, 1));
            setTableCellItems(row, 5, new QTableWidgetItem(it.getData().getLeaveHour().toString("hh:mm")), getAlignment(5, 1));
        } else if constexpr(is_same_v<T, Patient>) {
            setTableCellItems(row, 0, new QTableWidgetItem(it.getData().getCode()), getAlignment(0, 2));
            setTableCellItems(row, 1, new QTableWidgetItem(it.getData().getName().getLast()), getAlignment(1, 2));
            setTableCellItems(row, 2, new QTableWidgetItem(it.getData().getName().getFirst()), getAlignment(2, 2));
            setTableCellItems(row, 3, new QTableWidgetItem(it.getData().getBirthDate().toString("dd/MM/yyyy")), getAlignment(3, 2));
            setTableCellItems(row, 4, new QTableWidgetItem(it.getData().getAddress().toString()), getAlignment(4, 2));
            setTableCellItems(row, 5, new QTableWidgetItem(it.getData().getPhone()), getAlignment(5, 2));
        } else if constexpr(is_same_v<T, Diagnosis>) {
            setTableCellItems(row, 0, new QTableWidgetItem(it.getData().getCode()), getAlignment(0, 3));
            setTableCellItems(row, 1, new QTableWidgetItem(it.getData().getDescription()), getAlignment(1, 3));
            setTableCellItems(row, 2, new QTableWidgetItem(it.getData().getIndications()), getAlignment(2, 3));
        } else if constexpr(is_same_v<T, Medicine>) {
            setTableCellItems(row, 0, new QTableWidgetItem(it.getData().getCode()), getAlignment(0, 4));
            setTableCellItems(row, 1, new QTableWidgetItem(it.getData().getName()), getAlignment(1, 4));
        }
        QCoreApplication::processEvents();
        row++;
    }

    connect(ui->selectionTable, &QTableWidget::doubleClicked, this, &TableDialog::accept);
    connect(ui->selectionTable, &QTableWidget::itemActivated, this, &TableDialog::accept);

    ui->selectionTable->setCurrentCell(0, 0);
    ui->selectionTable->resizeColumnsToContents();

}

template <typename T>
TableDialog<T>::~TableDialog() {
    delete ui;
}

template <typename T>
vector<QString> TableDialog<T>::getSelectedData() const {
    vector<QString> itemVector;

    int curRow = ui->selectionTable->currentRow();
    int colCount = ui->selectionTable->columnCount();

    QString text;
    for(int col = 0; col < colCount; col++) {
        text = ui->selectionTable->item(curRow, col)->text();
        itemVector.push_back(text);
    }

    return itemVector;
}

template <typename T>
void TableDialog<T>::setTableCellItems(const int& row, const int& col, QTableWidgetItem* item, const QFlags<Qt::AlignmentFlag>& alignment) {
    item->setTextAlignment(alignment);
    item->setFont(QFont("Arial", 14));
    ui->selectionTable->setItem(row, col, item);
}

template <typename T>
QFlags<Qt::AlignmentFlag> TableDialog<T>::getAlignment(const int &col, const int &type) {
    switch(type) {
    case 1: return (col == 1 || col == 2) ? Qt::AlignLeft : Qt::AlignHCenter | Qt::AlignVCenter;
    case 2: return (col == 1 || col == 2 || col == 4) ? Qt::AlignLeft : Qt::AlignHCenter | Qt::AlignVCenter;
    case 3: //Avanza al caso 4 ya que es el mismo.
    case 4: return (col == 0) ? Qt::AlignHCenter | Qt::AlignVCenter : Qt::AlignLeft;
    default: return Qt::AlignHCenter | Qt::AlignVCenter;
    }
}
