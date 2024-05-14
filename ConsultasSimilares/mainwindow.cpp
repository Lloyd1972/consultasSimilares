#include "mainwindow.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->iconMenuButton->setChecked(true);
    ui->statusBar->addPermanentWidget(new QLabel("© 2023-2024 Consultas Similares. Todos los derechos reservados."));
    ui->progressBar->setVisible(false);
    //ui->menubar->setVisible(false);

    QCoreApplication::processEvents();

    vector<tuple<vector<int>, QTableWidget*>> headerTableTuple {
        {{130, 220, 220, 130, 95, 95}, ui->doctorTable},    //doctorHeaderWidth
        {{150, 220, 220, 155, 300, 140}, ui->patientTable}, //patientHeaderWidth
        {{85, 500, 650}, ui->diagnosisTable},               //diagnosisHeaderWidth
        {{120, 500}, ui->medicineTable},                    //medicineHeaderWidth
        {{130, 90, 375, 375, 0}, ui->consultationTable}        //consultationHeaderWidth
    };

    for(const auto &tup : headerTableTuple) {
        const vector<int> &currentHeaderWidth(get<0>(tup));
        QTableWidget *currentTable(get<1>(tup));

        for(int col = 0; col < currentHeaderWidth.size(); col++){
            currentTable->setColumnWidth(col, currentHeaderWidth[col]);
        }
    }

    ui->doctorTable->setRowCount(0);
    ui->patientTable->setRowCount(0);
    ui->diagnosisTable->setRowCount(0);
    ui->medicineTable->setRowCount(0);
    ui->consultationTable->setRowCount(0);

    fillTable<Doctor>(docFile.getList(), ui->doctorTable);
    fillTable<Patient>(patFile.getList(), ui->patientTable);
    fillTable<Diagnosis>(diagFile.getList(), ui->diagnosisTable);
    fillTable<Medicine>(medFile.getList(), ui->medicineTable);
    fillTable<Consultation>(consFile.getList(), ui->consultationTable);

    list<QPushButton*> buttons = {ui->doctorButton, ui->patientButton, ui->diagnosisButton, ui->medicineButton, ui->consultationButton, ui->doctorIcon, ui->patientIcon, ui->diagnosisIcon, ui->medicineIcon, ui->consultationIcon};

    for (QPushButton *button : buttons) {
        QObject::connect(button, &QPushButton::toggled, this, &MainWindow::mainIndex);
    }

    activateSearchButtons();

    connect(ui->doctorTable, &QTableWidget::cellClicked, this, &MainWindow::activateDoctorButtons);
    connect(ui->doctorTable, &QTableWidget::cellDoubleClicked, this, &MainWindow::showItemFromTable<Doctor>);
    connect(ui->addDoctorButton, &QPushButton::pressed, this, &MainWindow::addItem<Doctor>);
    connect(ui->modifyDoctorButton, &QPushButton::pressed, this, &MainWindow::modifyItem<Doctor>);
    connect(ui->removeDoctorButton, &QPushButton::pressed, this, &MainWindow::removeItem<Doctor>);
    connect(ui->searchDoctorButton, &QPushButton::pressed, this, &MainWindow::searchData<Doctor>);

    connect(ui->patientTable, &QTableWidget::cellClicked, this, &MainWindow::activatePatientButtons);
    connect(ui->patientTable, &QTableWidget::cellDoubleClicked, this, &MainWindow::showItemFromTable<Patient>);
    connect(ui->addPatientButton, &QPushButton::pressed, this, &MainWindow::addItem<Patient>);
    connect(ui->modifyPatientButton, &QPushButton::pressed, this, &MainWindow::modifyItem<Patient>);
    connect(ui->removePatientButton, &QPushButton::pressed, this, &MainWindow::removeItem<Patient>);
    connect(ui->searchPatientButton, &QPushButton::pressed, this, &MainWindow::searchData<Patient>);

    connect(ui->diagnosisTable, &QTableWidget::cellClicked, this, &MainWindow::activateDiagnosisButtons);
    connect(ui->diagnosisTable, &QTableWidget::cellDoubleClicked, this, &MainWindow::showItemFromTable<Diagnosis>);
    connect(ui->addDiagnosisButton, &QPushButton::pressed, this, &MainWindow::addItem<Diagnosis>);
    connect(ui->modifyDiagnosisButton, &QPushButton::pressed, this, &MainWindow::modifyItem<Diagnosis>);
    connect(ui->removeDiagnosisButton, &QPushButton::pressed, this, &MainWindow::removeItem<Diagnosis>);
    connect(ui->searchDiagnosisButton, &QPushButton::pressed, this, &MainWindow::searchData<Diagnosis>);

    connect(ui->medicineTable, &QTableWidget::cellClicked, this, &MainWindow::activateMedicineButtons);
    connect(ui->medicineTable, &QTableWidget::cellDoubleClicked, this, &MainWindow::showItemFromTable<Medicine>);
    connect(ui->addMedicineButton, &QPushButton::pressed, this, &MainWindow::addItem<Medicine>);
    connect(ui->modifyMedicineButton, &QPushButton::pressed, this, &MainWindow::modifyItem<Medicine>);
    connect(ui->removeMedicineButton, &QPushButton::pressed, this, &MainWindow::removeItem<Medicine>);
    connect(ui->searchMedicineButton, &QPushButton::pressed, this, &MainWindow::searchData<Medicine>);

    connect(ui->consultationTable, &QTableWidget::cellClicked, this, &MainWindow::activateConsultationButtons);
    connect(ui->consultationTable, &QTableWidget::cellDoubleClicked, this, &MainWindow::showItemFromTable<Consultation>);
    connect(ui->addConsultationButton, &QPushButton::pressed, this, &MainWindow::addItem<Consultation>);
    connect(ui->modifyConsultationButton, &QPushButton::pressed, this, &MainWindow::modifyItem<Consultation>);
    connect(ui->removeConsultationButton, &QPushButton::pressed, this, &MainWindow::removeItem<Consultation>);

    connect(ui->doctorButton, &QPushButton::toggled, this, &MainWindow::showMessage<Doctor>);
    connect(ui->patientButton, &QPushButton::toggled, this, &MainWindow::showMessage<Patient>);
    connect(ui->diagnosisButton, &QPushButton::toggled, this, &MainWindow::showMessage<Diagnosis>);
    connect(ui->medicineButton, &QPushButton::toggled, this, &MainWindow::showMessage<Medicine>);
    connect(ui->consultationButton, &QPushButton::toggled, this, &MainWindow::showMessage<Consultation>);

    connect(ui->actionImportar_Respaldo, &QAction::triggered, this, &MainWindow::importData);
    connect(ui->actionExportar_respaldo, &QAction::triggered, this, &MainWindow::exportData);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setCellItems(QTableWidget *table, const int &row, const int &col, QTableWidgetItem *item, const QFlags<Qt::AlignmentFlag> &alignment) {
    item->setTextAlignment(alignment);
    item->setFont(QFont("Arial", 14));
    table->setItem(row, col, item);
}

void MainWindow::mainIndex() {
    map<QPushButton*, int> buttonMap = {
        {ui->doctorButton, 1},
        {ui->patientButton, 2},
        {ui->diagnosisButton, 3},
        {ui->medicineButton, 4},
        {ui->consultationButton, 5}
    };

    int index = 1;

    for (auto &pair : buttonMap) {
        if (pair.first->isChecked()) {
            index = pair.second;
            break;
        }
    }

    ui->stackedWidget->setCurrentIndex(index);
}

template <typename T>
void MainWindow::showDialog(const string &action, const T &data) {
    // En el caso de que se busque mostrar el modo será 0,
    // Sino sera 1 si es para añadir o 2 para modificar
    int mode(action == "Show" ? 0 : action == "Add" ? 1 : 2);
    DataEntryDialog<T> *window(nullptr);
    DataEntryFile<T> *file;
    QTableWidget *table;

    if constexpr (is_same_v<T, Doctor>) { // Doctor
        window = new DoctorDialog(data, mode, this);
        file = &docFile;
        table = ui->doctorTable;
    } else if constexpr (is_same_v<T, Patient>) { // Paciente
        window = new PatientDialog(data, mode, this);
        file = &patFile;
        table = ui->patientTable;
    } else if constexpr (is_same_v<T, Diagnosis>) { // Diágnosticos
        window = new DiagnosisDialog(data, mode, this);
        file = &diagFile;
        table = ui->diagnosisTable;
    } else if constexpr (is_same_v<T, Medicine>) { // Medicamentos
        window = new MedicineDialog(data, mode, this);
        file = &medFile;
        table = ui->medicineTable;
    } else if constexpr (is_same_v<T, Consultation>) { // Consultas
        CompressedData cd;
        if (mode != 1) {
            cd.setDoctor(docFile.retrieveRecord(docFile.findRecord(data.getDoctorCode().toStdString())));
            cd.setPatient(patFile.retrieveRecord(patFile.findRecord(data.getPatientNSS().toStdString())));
            cd.setDiagnosis(diagFile.retrieveRecord(diagFile.findRecord(data.getDiagnosisCode().toStdString())));
            cd.setMedicine1(medFile.retrieveRecord(medFile.findRecord(data.getMedicine1Code().toStdString())));

            if(!data.getMedicine2Code().isEmpty()) {
                cd.setMedicine2(medFile.retrieveRecord(medFile.findRecord(data.getMedicine2Code().toStdString())));
            }

            if(!data.getMedicine3Code().isEmpty()) {
                cd.setMedicine3(medFile.retrieveRecord(medFile.findRecord(data.getMedicine3Code().toStdString())));
            }
        }

        window = new ConsultationDialog(data, mode, cd, this);
        file = &consFile;
        table = ui->consultationTable;
    }

    if (window->exec() == QDialog::Accepted && mode != 0) {
        T newData(window->getData());
        int row;

        if constexpr (is_same_v<T, Consultation>) {
            QString docName(newData.getDoctorCode());
            QString med1Name(newData.getMedicine1Code());
            QString med2Name(newData.getMedicine2Code());
            QString med3Name(newData.getMedicine3Code());

            newData.setDoctorCode(docFile.retrieveRecord(docFile.findRecordByName(docName.toStdString())).getCode());
            newData.setMedicine1Code(medFile.retrieveRecord(medFile.findRecordByName(med1Name.toStdString())).getCode());

            if(!med2Name.isEmpty()) {
                newData.setMedicine2Code(medFile.retrieveRecord(medFile.findRecordByName(med2Name.toStdString())).getCode());
            }

            if(!med3Name.isEmpty()) {
                newData.setMedicine3Code(medFile.retrieveRecord(medFile.findRecordByName(med3Name.toStdString())).getCode());
            }
        }

        if(mode == 1) {
            try {
                row = table->rowCount();

                if (file->addRecord(newData, this)) {
                    //Si el elemento se ingresa al archivo, entonces agregará la fila a la UI
                    if constexpr(!is_same_v<T, Consultation>) {
                        addRow<T>(table, newData, row);
                    } else {
                        addRow<T>(table, Tuple<T>(consFile.getLastIndex(), newData), row);
                    }
                }
            } catch (...) {
                QMessageBox::critical(this, "Error", "Error al agregar datos.");
            }
        } else if(mode == 2) {
            try {
                row = table->currentRow();
                int idx(ui->consultationTable->item(row, 4)->text().toInt());
                file->modifyRecord(data, newData);
                table->removeRow(row);

                if constexpr(!is_same_v<T, Consultation>) {
                    addRow<T>(table, newData, row);
                } else {
                    addRow<T>(table, Tuple<T>(idx, newData), row);

                    if(row != ui->consultationTable->rowCount()) {
                        list<Tuple<Consultation>> list(consFile.getList());

                        int r(0);
                        for(auto &it : list) {
                            int index(it.getIndex());
                            QString item(QString::number(index));
                            if(index >= idx) {
                                setCellItems(ui->consultationTable, r, 4, new QTableWidgetItem(item), Qt::AlignLeft);
                            }
                            QCoreApplication::processEvents();
                            r++;
                        }
                    }
                }
                table->setCurrentCell(row, 0);
            } catch (...) {
                QMessageBox::critical(this, "Error", "Error al modificar datos.");
            }
        }
    }
    delete window;
    showMessage<T>();
}

template <typename T>
void MainWindow::showItemFromTable(const int &row, const int &col) {
    showDialog("Show", retrieveData<T>());
}

template <typename T>
void MainWindow::addItem() {
    showDialog("Add", T());
}

template <typename T>
void MainWindow::modifyItem() {
    showDialog("Modify", retrieveData<T>());
}

template <typename T>
void MainWindow::removeItem() {
    DataEntryFile<T> *file;
    T data(retrieveData<T>());
    QTableWidget *table(nullptr);
    QString title;
    QString text;
    int row(0);

    if constexpr (is_same_v<T, Doctor>) { // Doctor
        file = &docFile;
        table = ui->doctorTable;
        title = "Eliminar Doctor.";
        text = "¿Desea eliminar al doctor \"" + data.getName().toString() + "\"?";
    } else if constexpr (is_same_v<T, Patient>) { // Paciente
        file = &patFile;
        table = ui->patientTable;
        title = "Eliminar Paciente.";
        text = "¿Desea eliminar al paciente \"" + data.getName().toString() + "\"?";
    } else if constexpr (is_same_v<T, Diagnosis>) { // Diágnosticos
        file = &diagFile;
        table = ui->diagnosisTable;
        title = "Eliminar Diágnostico.";
        text = "¿Desea eliminar el diágnostico \"" + data.getCode() + "\"?";
    } else if constexpr (is_same_v<T, Medicine>) {
        file = &medFile;
        table = ui->medicineTable;
        title = "Eliminar Medicamento.";
        text = "¿Desea eliminar el medicamento \"" + data.getName() + "\"?";
    } else if constexpr (is_same_v<T, Consultation>) { // Consultas
        file = &consFile;
        table = ui->consultationTable;
        title = "Eliminar Consulta.";
        text = "¿Desea eliminar la consulta?";
    }

    row = table->currentRow();

    if (QMessageBox::question(this, title, text) == QMessageBox::Yes) {
        file->delRecord(data);
        table->removeRow(row);
        activateSearchButtons();
        if constexpr (is_same_v<T, Doctor>) {
            activateDoctorButtons(0, 0);
        } else if constexpr (is_same_v<T, Patient>) {
            activatePatientButtons(0, 0);
        } else if constexpr (is_same_v<T, Diagnosis>) {
            activateDiagnosisButtons(0, 0);
        } else if constexpr (is_same_v<T, Medicine>) {
            activateMedicineButtons(0, 0);
        } else if constexpr (is_same_v<T, Consultation>) {
            activateConsultationButtons(0, 0);
        }
    }

    showMessage<T>();
}

template <typename T>
void MainWindow::searchData() {
    QString title;
    DataEntryFile<T> *file;
    int type(0);

    if constexpr (is_same_v<T, Doctor>) { // Doctores
        title = "Buscar un Doctor";
        file = &docFile;
        type = 1;
    } else if constexpr (is_same_v<T, Patient>) { // Paciente
        title = "Buscar un Paciente";
        file = &patFile;
        type = 2;
    } else if constexpr (is_same_v<T, Diagnosis>) { // Diágnosticos
        title = "Buscar un Diágnostico";
        file = &diagFile;
        type = 3;
    } else if constexpr (is_same_v<T, Medicine>) { // Medicamentos
        title = "Buscar un Medicamento";
        file = &medFile;
        type = 4;
    }

    SearchDialog searchWindow(title, type, this);
    if(searchWindow.exec() == QDialog::Accepted) {
        QString searchString(searchWindow.getData());
        T data;

        // Recupera la posición del dato dependiendo el método de busqueda
        int pos(searchWindow.getFormat() ? file->findRecord(searchString.toStdString()) : file->findRecordByName(searchString.toStdString()));

        if(pos == -1) {
            QMessageBox::warning(this, "Test", "'" + searchString + "' no fue encontrado.");
            return;
        }

        data = file->retrieveRecord(pos);
        showDialog("Modify", data);
    }
}

template <typename T>
void MainWindow::updateConsults(const T &data) {

}

template <typename T>
T MainWindow::retrieveData() {
    T findedData;
    DataEntryFile<T> *file;
    QString code;

    if constexpr (is_same_v<T, Doctor>) { // Doctor
        code = ui->doctorTable->item(ui->doctorTable->currentRow(), 0)->text();
        file = &docFile;
    } else if constexpr (is_same_v<T, Patient>) { // Paciente
        code = ui->patientTable->item(ui->patientTable->currentRow(), 0)->text();
        file = &patFile;
    } else if constexpr (is_same_v<T, Diagnosis>) { // Diágnosticos
        code = ui->diagnosisTable->item(ui->diagnosisTable->currentRow(), 0)->text();
        file = &diagFile;
    } else if constexpr (is_same_v<T, Medicine>) { // Medicamentos
        code = ui->medicineTable->item(ui->medicineTable->currentRow(), 0)->text();
        file = &medFile;
    } else if constexpr (is_same_v<T, Consultation>) { // Consultas
        int pos(ui->consultationTable->item(ui->consultationTable->currentRow(), 4)->text().toInt());
        findedData = consFile.retrieveRecord(pos);
    }

    if constexpr (!is_same_v<T, Consultation>) {
        int pos(file->findRecord(code.toStdString()));
        findedData = file->retrieveRecord(pos);
    }

    return findedData;
}

template <typename T>
void MainWindow::showMessage(const bool &checked) {
    DataEntryFile<T> *file;

    if constexpr (is_same_v<T, Doctor>) { // Doctor
        file = &docFile;
    } else if constexpr (is_same_v<T, Patient>) { // Paciente
        file = &patFile;
    } else if constexpr (is_same_v<T, Diagnosis>) { // Diágnosticos
        file = &diagFile;
    } else if constexpr (is_same_v<T, Medicine>) { // Medicamentos
        file = &medFile;
    } else if constexpr (is_same_v<T, Consultation>) { // Consultas
        file = &consFile;
    }

    if(file) {
        int logs(file->getSize());
        ui->statusBar->showMessage(QLocale::system().toString(logs) + (logs == 1 ? " registro." : " registros."));
    }
}

QFlags<Qt::AlignmentFlag> MainWindow::getAlignment(const int &col, const int &type) {
    switch(type) {
        case 1: return (col == 1 || col == 2) ? Qt::AlignLeft : Qt::AlignHCenter | Qt::AlignVCenter;
        case 2: return (col == 1 || col == 2 || col == 4) ? Qt::AlignLeft : Qt::AlignHCenter | Qt::AlignVCenter;
        case 3: //Avanza al caso 4 ya que es el mismo.
        case 4: return (col == 0) ? Qt::AlignHCenter | Qt::AlignVCenter : Qt::AlignLeft;
        case 5: return (col < 2) ? Qt::AlignHCenter | Qt::AlignVCenter : Qt::AlignLeft;
        default: return Qt::AlignHCenter | Qt::AlignVCenter;
    }
}

void MainWindow::activateDoctorButtons(const int &row, const int &col) {
    ui->modifyDoctorButton->setEnabled(ui->doctorTable->rowCount() != 0);
    ui->removeDoctorButton->setEnabled(ui->doctorTable->rowCount() != 0);
}

void MainWindow::activatePatientButtons(const int &row, const int &col) {
    ui->modifyPatientButton->setEnabled(ui->patientTable->rowCount() != 0);
    ui->removePatientButton->setEnabled(ui->patientTable->rowCount() != 0);
}

void MainWindow::activateDiagnosisButtons(const int &row, const int &col) {
    ui->modifyDiagnosisButton->setEnabled(ui->diagnosisTable->rowCount() != 0);
    ui->removeDiagnosisButton->setEnabled(ui->diagnosisTable->rowCount() != 0);
}

void MainWindow::activateMedicineButtons(const int &row, const int &col) {
    ui->modifyMedicineButton->setEnabled(ui->medicineTable->rowCount() != 0);
    ui->removeMedicineButton->setEnabled(ui->medicineTable->rowCount() != 0);
}

void MainWindow::activateConsultationButtons(const int &row, const int &col) {
    ui->modifyConsultationButton->setEnabled(ui->consultationTable->rowCount() != 0);
    ui->removeConsultationButton->setEnabled(ui->consultationTable->rowCount() != 0);
}

void MainWindow::activateSearchButtons() {
    ui->searchDoctorButton->setEnabled(ui->doctorTable->rowCount() != 0);
    ui->searchPatientButton->setEnabled(ui->patientTable->rowCount() != 0);
    ui->searchDiagnosisButton->setEnabled(ui->diagnosisTable->rowCount() != 0);
    ui->searchMedicineButton->setEnabled(ui->medicineTable->rowCount() != 0);
}

template <typename T>
void MainWindow::fillTable(const list<Tuple<T>> &list, QTableWidget *table) {
    int row(table->rowCount());
    int total(list.size());
    int progValue(ui->progressBar->value());
    QString dataType;

    if(table->objectName() == "doctorTable") {
        dataType = " doctores añadidos";
    } else if(table->objectName() == "patientTable") {
        dataType = " pacientes añadidos";
    } else if(table->objectName() == "diagnosisTable") {
        dataType = " diagnosticos añadidos";
    } else if(table->objectName() == "medicineTable") {
        dataType = " medicamentos añadidos";
    } else if(table->objectName() == "consultationTable") {
        dataType = " consultas añadidas";
    } else {
        dataType = " registros añadidos";
    }

    for (const auto &tuple: list) {
        T data(tuple.getData());

        if(table->objectName() != "consultationTable") {
            addRow(table, data, row);
        } else {
            addRow(table, tuple, row);
        }

        row++;

        float progress(13.0 / total * row);
        if(ui->progressBar->value() != static_cast<int>(progress)) {
            ui->progressBar->setValue(static_cast<int>(progress) + progValue);
        }

        ui->statusBar->showMessage(QLocale::system().toString(row) + "/" + QLocale::system().toString(total) + dataType);
        QCoreApplication::processEvents();
    }
}

template <typename T>
void MainWindow::addRow(QTableWidget *table, const T &data, const int &row) {
    if (row == -1) {
        return;
    }
    vector<QString> strings(getStrings(data));

    table->insertRow(row);
    int type(0);

    if constexpr (is_same_v<T, Doctor>) {
        type = 1;
    } else if constexpr (is_same_v<T, Patient>) {
        type = 2;
    } else if constexpr (is_same_v<T, Diagnosis>) {
        type = 3;
    } else if constexpr (is_same_v<T, Medicine>) {
        type = 4;
    } else if constexpr (is_same_v<T, Consultation>) {
        type = 5;
    }

    for(int col = 0; col < strings.size(); col++) {
        setCellItems(table, row, col, new QTableWidgetItem(strings[col]), getAlignment(col, type));
    }

    activateSearchButtons();
}

template <typename T>
vector<QString> MainWindow::getStrings(const T &data) {
    vector<QString> itemsQStrings;

    if constexpr (is_same_v<T, Doctor>) {
        itemsQStrings = { // Doctor
            data.getCode(),
            data.getName().getLast(),
            data.getName().getFirst(),
            data.getCedule(),
            data.getEntryHour().toString("hh:mm"),
            data.getLeaveHour().toString("hh:mm")
        };
    } else if constexpr (is_same_v<T, Patient>) {
        itemsQStrings = { // Paciente
            data.getCode(),
            data.getName().getLast(),
            data.getName().getFirst(),
            data.getBirthDate().toString("dd/MM/yyyy"),
            data.getAddress().toString(),
            data.getPhone()
        };
    } else if constexpr (is_same_v<T, Diagnosis>) { // Diágnosticos
        itemsQStrings = {
            data.getCode(),
            data.getDescription(),
            data.getIndications()
        };
    } else if constexpr (is_same_v<T, Medicine>) { // Medicamentos
        itemsQStrings = {
            data.getCode(),
            data.getName()
        };
    } else if constexpr (is_same_v<T, Consultation>) { //Consultas
        int docPos(docFile.findRecord(data.getDoctorCode().toStdString()));
        int patPos(patFile.findRecord(data.getPatientNSS().toStdString()));

        itemsQStrings = {
            data.getDate().toString("dd/MM/yyyy"),
            data.getHour().toString("hh:mm"),
            docFile.retrieveRecord(docPos).getName().toString(),
            patFile.retrieveRecord(patPos).getName().toString()

        };
    }
    return itemsQStrings;
}

template <typename T>
void MainWindow::addRow(QTableWidget *table, const Tuple<T> &data, const int &row) {
    if (row == -1) {
        return;
    }
    vector<QString> strings(getStrings(data));

    table->insertRow(row);
    int type(0);

    if constexpr (is_same_v<T, Consultation>) {
        type = 5;
    }

    for(int col = 0; col < strings.size(); col++) {
        setCellItems(table, row, col, new QTableWidgetItem(strings[col]), getAlignment(col, type));
    }

    activateSearchButtons();
}

template <typename T>
vector<QString> MainWindow::getStrings(const Tuple<T> &tup) {
    vector<QString> itemsQStrings;

    if constexpr (is_same_v<T, Consultation>) { //Consultas
        int docPos(docFile.findRecord(tup.getData().getDoctorCode().toStdString()));
        int patPos(patFile.findRecord(tup.getData().getPatientNSS().toStdString()));

        itemsQStrings = {
            tup.getData().getDate().toString("dd/MM/yyyy"),
            tup.getData().getHour().toString("hh:mm"),
            docFile.retrieveRecord(docPos).getName().toString(),
            patFile.retrieveRecord(patPos).getName().toString(),
            QString::number(tup.getIndex())
        };
    }
    return itemsQStrings;
}

void MainWindow::importData() {
    QString fileName = QFileDialog::getOpenFileName(this, "Abrir Archivo.", "", "Archivo de Datos(*.file);;Todos los archivos(*.*)");
    if(fileName.isEmpty()){
        QMessageBox::warning(this, "Error.", "No se pudo abrir el archivo.");
        return;
    }

    fstream file(fileName.toStdString(), ios::in);
    string readingStr;
    Consultation consult;
    Diagnosis diag;
    Doctor doc;
    Patient pat;
    Medicine med1;
    Medicine med2;
    Medicine med3;

    if(!file.is_open()){
        QMessageBox::critical(this, "Error.", "El archivo no se pudo abrir para lectura.");
        file.close();
        return;
    }

    ui->progressBar->setValue(0);
    ui->progressBar->setVisible(true);

    docFile.clearRecord();
    patFile.clearRecord();
    diagFile.clearRecord();
    medFile.clearRecord();
    consFile.clearRecord();

    ui->statusBar->showMessage("Listas vaciadas.");
    QCoreApplication::processEvents();

    ui->doctorTable->setRowCount(0);
    ui->patientTable->setRowCount(0);
    ui->diagnosisTable->setRowCount(0);
    ui->medicineTable->setRowCount(0);
    ui->consultationTable->setRowCount(0);

    ui->statusBar->showMessage("Tablas limpiadas.");
    ui->progressBar->setValue(1);
    QCoreApplication::processEvents();

    ui->statusBar->showMessage("Leyendo archivo.");
    QCoreApplication::processEvents();

    file.clear();
    file.seekg(0);
    int count(0);
    while(file.peek() != EOF) {
        getline(file, readingStr, '#');
        if(readingStr.empty()) {
            continue;
        }

        stringstream ss(readingStr);

        ss >> consult; //Fecha y hora de la Consulta
        ss >> diag; // Diagnostico
        ss >> doc; // Doctor
        ss >> pat; // Paciente
        ss >> med1; // Medicamento 1
        ss >> med2; // Medicamento 2
        ss >> med3; // Medicamento 3

        consult.setDoctorCode(doc.getCode());
        consult.setPatientNSS(pat.getCode());
        consult.setDiagnosisCode(diag.getCode());
        consult.setMedicine1Code(med1.getCode());
        consult.setMedicine2Code(med2.getCode());
        consult.setMedicine3Code(med3.getCode());

        consFile.addRecord(consult, this, true);
        diagFile.addRecord(diag, this, true);
        docFile.addRecord(doc, this, true);
        patFile.addRecord(pat, this, true);
        medFile.addRecord(med1, this, true);

        if(med2.getName() != "") {
            medFile.addRecord(med2, this, true);
        }

        if(med3.getName() != "") {
            medFile.addRecord(med3, this, true);
        }
        count++;

        ui->statusBar->showMessage(QLocale::system().toString(count) + " registros leidos.");

        // Procesar eventos periódicamente
        QCoreApplication::processEvents();
    }
    file.close();

    ui->progressBar->setValue(35);
    QCoreApplication::processEvents();

    fillTable<Doctor>(docFile.getList(), ui->doctorTable);
    ui->statusBar->showMessage("Doctores añadidos.");
    QCoreApplication::processEvents();

    fillTable<Patient>(patFile.getList(), ui->patientTable);
    ui->statusBar->showMessage("Pacientes añadidos.");
    QCoreApplication::processEvents();

    fillTable<Diagnosis>(diagFile.getList(), ui->diagnosisTable);
    ui->statusBar->showMessage("Diagnosticos añadidos.");
    QCoreApplication::processEvents();

    fillTable<Medicine>(medFile.getList(), ui->medicineTable);
    ui->statusBar->showMessage("Medicamentos añadidos.");
    QCoreApplication::processEvents();

    fillTable<Consultation>(consFile.getList(), ui->consultationTable);
    ui->statusBar->showMessage("Consultas añadidas.");
    QCoreApplication::processEvents();

    ui->progressBar->setVisible(false);
}

void MainWindow::exportData() {
    QString fileName = QFileDialog::getSaveFileName(this, "Guardar Archivo.", "", "Archivo de Datos(*.file);;Todos los archivos(*.*)");

    if(fileName.isEmpty()) {
        return;
    }

    fstream file(fileName.toStdString(), ios::out);

    if(!file.is_open()) {
        QMessageBox::critical(this, "Error.", "El archivo no se pudo abrir para escritura.");
        file.close();
        return;
    }

    ui->progressBar->setVisible(true);
    ui->progressBar->setValue(0);

    int total(consFile.getSize());
    int writedLogs(0);
    list<Tuple<Consultation>> consList(consFile.getList());
    for(auto &log : consList) {
        Consultation cons(log.getData());
        Diagnosis diag(diagFile.retrieveRecord(diagFile.findRecord(cons.getDiagnosisCode().toStdString())));
        Doctor doc(docFile.retrieveRecord(docFile.findRecord(cons.getDoctorCode().toStdString())));
        Patient pat(patFile.retrieveRecord(patFile.findRecord(cons.getPatientNSS().toStdString())));
        Medicine med1(medFile.retrieveRecord(medFile.findRecord(cons.getMedicine1Code().toStdString())));
        Medicine med2(medFile.retrieveRecord(medFile.findRecord(cons.getMedicine2Code().toStdString())));
        Medicine med3(medFile.retrieveRecord(medFile.findRecord(cons.getMedicine3Code().toStdString())));

        file << cons
             << diag
             << doc
             << pat
             << med1
             << med2
             << med3 << "#";

        writedLogs++;

        float progress(100.0 / total * writedLogs);
        if(ui->progressBar->value() != static_cast<int>(progress)) {
            ui->progressBar->setValue(static_cast<int>(progress));
        }

        ui->statusBar->showMessage(QLocale::system().toString(writedLogs) + "/" + QLocale::system().toString(total) + " registros escritos.");
        QCoreApplication::processEvents();
    }

    ui->progressBar->setVisible(false);
    file.close();

    QMessageBox::information(this, "Exportar Respaldo.", QLocale::system().toString(total) + " registros exportados.");
}
