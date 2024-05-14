#include "doctordialog.h"
using namespace std;

void DoctorDialog::activateOKButton() {
    QString code(ui->codeTextEdit->text());
    QString cedule(ui->ceduleTextEdit->text());
    QString lastName(ui->lastNameTextEdit->text());
    QString firstName(ui->firstNameTextEdit->text());

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(!code.isEmpty() &&
                                                            !cedule.isEmpty() &&
                                                            !lastName.isEmpty() &&
                                                            !firstName.isEmpty() &&
                                                            !(code.contains('*') ||
                                                              cedule.contains('*') ||
                                                              lastName.contains('*') ||
                                                              firstName.contains('*') ||
                                                              code.contains('#') ||
                                                              cedule.contains('#') ||
                                                              lastName.contains('#') ||
                                                              firstName.contains('#')));
}

void DoctorDialog::setDataInDialog() {
    QString title;

    switch(mode) {
    case 0: {
        title = "Doctor \"" + data.getName().toString() + "\".";
        ui->buttonBox->setStandardButtons(QDialogButtonBox::Ok);
    } break;
    case 1: title = "Agregar doctor."; break;
    case 2: title = "Modificar doctor \""  + data.getName().toString() + "\"."; break;
    }
    setWindowTitle(title);

    // Se guarda solo el valor «hora» de la hora actual, no todo el conjunto de la hr actual
    QTime time;
    time.setHMS(QTime::currentTime().hour(), 0, 0);

    // Establecer los campos de texto y habilitar/deshabilitar según el modo
    ui->codeTextEdit->setText(mode != 1 ? data.getCode() : "");
    ui->ceduleTextEdit->setText(mode != 1 ? data.getCedule() : "");
    ui->lastNameTextEdit->setText(mode != 1 ? data.getName().getLast() : "");
    ui->firstNameTextEdit->setText(mode != 1 ? data.getName().getFirst() : "");
    ui->entryTimeEdit->setTime(mode != 1 ? data.getEntryHour() : time);

    time.setHMS(time.hour() + 8, 0, 0); // Agregar 8 hrs laborales
    ui->leaveTimeEdit->setTime(mode != 1 ? data.getLeaveHour() : time);

    ui->codeTextEdit->setEnabled(mode != 0);
    ui->ceduleTextEdit->setEnabled(mode != 0);
    ui->lastNameTextEdit->setEnabled(mode != 0);
    ui->firstNameTextEdit->setEnabled(mode != 0);
    ui->entryTimeEdit->setEnabled(mode != 0);
    ui->leaveTimeEdit->setEnabled(mode != 0);

    ui->entryTimeEdit->setButtonSymbols(mode != 0 ? QAbstractSpinBox::UpDownArrows : QAbstractSpinBox::NoButtons);
    ui->leaveTimeEdit->setButtonSymbols(mode != 0 ? QAbstractSpinBox::UpDownArrows : QAbstractSpinBox::NoButtons);

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(mode != 1);

    // Establecer el enfoque en el campo de código
    ui->codeTextEdit->setFocus();
}

DoctorDialog::DoctorDialog(const Doctor&doc, const unsigned int&m, QWidget *parent) : DataEntryDialog<Doctor>(parent), ui(new Ui::DoctorDialog), data(doc), mode(m) {
    ui->setupUi(this);

    ui->buttonBox->button(QDialogButtonBox::Ok)->setText(mode != 0 ?  "Guardar" : "OK");
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("Cancelar");

    setDataInDialog();

    // Conectar las señales Aceptar/Cancelar a las ranuras correspondientes
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &DoctorDialog::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &DoctorDialog::reject);

    connect(ui->codeTextEdit, &QLineEdit::textEdited, this, &DoctorDialog::activateOKButton);
    connect(ui->ceduleTextEdit, &QLineEdit::textChanged, this, &DoctorDialog::activateOKButton);
    connect(ui->lastNameTextEdit, &QLineEdit::textChanged, this, &DoctorDialog::activateOKButton);
    connect(ui->firstNameTextEdit, &QLineEdit::textChanged, this, &DoctorDialog::activateOKButton);
}

DoctorDialog::~DoctorDialog() {
    delete ui;
}

void DoctorDialog::setData(const Doctor &doc) {
    data = doc;

    setDataInDialog();
}

Doctor DoctorDialog::getData() const {
    Doctor data;
    QString last(ui->lastNameTextEdit->text());
    QString first(ui->firstNameTextEdit->text());

    data.setCode(ui->codeTextEdit->text());
    data.setCedule(ui->ceduleTextEdit->text());
    data.setName(Name(last, first));
    data.setEntryHour(ui->entryTimeEdit->time());
    data.setLeaveHour(ui->leaveTimeEdit->time());

    return data;
}
