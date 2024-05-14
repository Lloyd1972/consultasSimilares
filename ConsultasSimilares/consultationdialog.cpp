#include "consultationdialog.h"
using namespace std;

void ConsultationDialog::activateOKButton() {
    // Al no tener ningún elemento en el cual el usuario pueda escribir caráctares más a aparte de la fecha y hr
    // Se ignoran las funciones que checan la existencia de '*' o '#' para activar el botón
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(!ui->doctorText->text().isEmpty() &&
                                                            !ui->patientText->text().isEmpty() &&
                                                            !ui->diagnosisCodeText->text().isEmpty() &&
                                                            !ui->medicine1Edit->text().isEmpty());
}

void ConsultationDialog::setDataInDialog() {
    QString title;

    switch(mode) {
    case 0: {
        title = "Consulta " + data.getDate().toString("dd/MM/yyyy ") + data.getHour().toString("hh:mm.");
        ui->buttonBox->setStandardButtons(QDialogButtonBox::Ok);
    } break;
    case 1: title = "Agregar consulta."; break;
    case 2: title = "Modificar consulta " + data.getDate().toString("dd/MM/yyyy ") + data.getHour().toString("hh:mm."); break;
    }
    setWindowTitle(title);

    // Establecer los campos de texto y habilitar/deshabilitar según el modo
    ui->dateTimeEdit->setDate(mode != 1 ? data.getDate() : QDate::currentDate());
    ui->dateTimeEdit->setTime(mode != 1 ? data.getHour() : QTime::currentTime());

    ui->doctorText->setText(mode != 1 ? comData.getDoctor().getName().toString() : "");

    ui->patientText->setText(mode != 1 ? comData.getPatient().getName().toString() : "");
    ui->nssText->setText(mode != 1 ? comData.getPatient().getCode() : "");

    ui->diagnosisCodeText->setText(mode != 1 ? comData.getDiagnosis().getCode() : "");
    ui->diagnosisTextBrowser->setText(mode != 1 ? comData.getDiagnosis().getDescription() : "");
    ui->indicationsTextBrowser->setText(mode != 1 ? comData.getDiagnosis().getIndications() : "");

    ui->medicine1Edit->setText(mode != 1 ? comData.getMedicine1().getName() : "");
    ui->medicine2Edit->setText(mode != 1 ? comData.getMedicine2().getName() : "");
    ui->medicine3Edit->setText(mode != 1 ? comData.getMedicine3().getName() : "");

    ui->dateTimeEdit->setEnabled(mode != 0);
    ui->dateTimeEdit->setCalendarPopup(mode != 0);

    ui->doctorButton->setVisible(mode == 1 || ui->doctorText->text() == ", ");
    ui->patientButton->setVisible(mode == 1 || ui->patientText->text() == ", ");
    ui->diagnosisButton->setVisible(mode != 0);
    ui->medicine1Button->setVisible(mode != 0);
    ui->medicine2Button->setVisible(mode != 0);
    ui->medicine3Button->setVisible(mode != 0);

    // Configurar los botones Aceptar/Cancelar
    ui->buttonBox->setStandardButtons(mode == 0 ? QDialogButtonBox::Ok : QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(mode != 1);

    // Establecer el enfoque en el campo de fecha
    ui->dateTimeEdit->setFocus();
}

ConsultationDialog::ConsultationDialog(const Consultation&cons, const unsigned int&m, const CompressedData &cd, QWidget *parent) :
    DataEntryDialog<Consultation>(parent), ui(new Ui::ConsultationDialog), data(cons), mode(m), comData(cd) {
    ui->setupUi(this);

    setDataInDialog();

    // Conectar las señales Aceptar/Cancelar a las ranuras correspondientes
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &ConsultationDialog::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &ConsultationDialog::reject);

    connect(ui->doctorButton, &QPushButton::pressed, this, &ConsultationDialog::selectDoctor);
    connect(ui->patientButton, &QPushButton::pressed, this, &ConsultationDialog::selectPatient);
    connect(ui->medicine1Button, &QPushButton::pressed, this, &ConsultationDialog::selectMedicine1);
    connect(ui->medicine2Button, &QPushButton::pressed, this, &ConsultationDialog::selectMedicine2);
    connect(ui->medicine3Button, &QPushButton::pressed, this, &ConsultationDialog::selectMedicine3);
    connect(ui->diagnosisButton, &QPushButton::pressed, this, &ConsultationDialog::selectDiagnosis);

    connect(ui->doctorText, &QLineEdit::textChanged, this, &ConsultationDialog::activateOKButton);
    connect(ui->patientText, &QLineEdit::textChanged, this, &ConsultationDialog::activateOKButton);
    connect(ui->diagnosisCodeText, &QLineEdit::textChanged, this, &ConsultationDialog::activateOKButton);
    connect(ui->medicine1Edit, &QLineEdit::textChanged, this, &ConsultationDialog::activateOKButton);
    connect(ui->medicine2Edit, &QLineEdit::textChanged, this, &ConsultationDialog::activateOKButton);
    connect(ui->medicine3Edit, &QLineEdit::textChanged, this, &ConsultationDialog::activateOKButton);
}

ConsultationDialog::~ConsultationDialog() {
    delete ui;
}

template <class T>
void ConsultationDialog::showTable(const int &button) {
    TableDialog<T> win("Seleccione un Doctor.", this);

    QCoreApplication::processEvents();
    if(win.exec() == QDialog::Accepted) {
        QCoreApplication::processEvents();
        vector<QString> itemElements(win.getSelectedData());

        switch(button) {
        case 1: ui->doctorText->setText(itemElements[1] + ", " + itemElements[2]); break;
        case 2: {
            ui->patientText->setText(itemElements[1] + ", " + itemElements[2]);
            ui->nssText->setText(itemElements[0]);
        } break;
        case 3: {
            ui->diagnosisCodeText->setText(itemElements[0]);
            ui->diagnosisTextBrowser->setText(itemElements[1]);
            ui->indicationsTextBrowser->setText(itemElements[2]);
        } break;
        case 4: {
            QString result(itemElements[1]);
            if(result != ui->medicine2Edit->text() &&
                result != ui->medicine3Edit->text()) {
                ui->medicine1Edit->setText(result);
            }
        } break;
        case 5: {
            QString result(itemElements[1]);
            if(ui->medicine1Edit->text().isEmpty()) {
                ui->medicine1Edit->setText(result);
                break;
            }

            if(result != ui->medicine1Edit->text() &&
                result != ui->medicine3Edit->text()) {
                ui->medicine2Edit->setText(result);
            }
        } break;
        case 6: {
            QString result(itemElements[1]);
            if(ui->medicine1Edit->text().isEmpty()) {
                ui->medicine1Edit->setText(result);
                break;
            }

            if(ui->medicine2Edit->text().isEmpty()) {
                ui->medicine2Edit->setText(result);
                break;
            }

            if(result != ui->medicine1Edit->text() &&
                result != ui->medicine2Edit->text()) {
                ui->medicine3Edit->setText(result);
            }
        } break;
        }
    }
}

void ConsultationDialog::selectDoctor() {
    showTable<Doctor>(1);
}

void ConsultationDialog::selectPatient() {
    showTable<Patient>(2);
}

void ConsultationDialog::selectDiagnosis() {
    showTable<Diagnosis>(3);
}

void ConsultationDialog::selectMedicine1() {
    showTable<Medicine>(4);
}

void ConsultationDialog::selectMedicine2() {
    showTable<Medicine>(5);
}

void ConsultationDialog::selectMedicine3() {
    showTable<Medicine>(6);
}

Consultation ConsultationDialog::getData() const {
    Consultation data;

    data.setDate(ui->dateTimeEdit->date());
    data.setHour(ui->dateTimeEdit->time());

    data.setDoctorCode(ui->doctorText->text());
    data.setPatientNSS(ui->nssText->text());
    data.setDiagnosisCode(ui->diagnosisCodeText->text());
    data.setMedicine1Code(ui->medicine1Edit->text());
    data.setMedicine2Code(ui->medicine2Edit->text());
    data.setMedicine3Code(ui->medicine3Edit->text());

    return data;
}
