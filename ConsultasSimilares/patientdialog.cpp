#include "patientdialog.h"
using namespace std;

void PatientDialog::activateOKButton() {
    QString code(ui->nssTextEdit->text());
    QString lastName(ui->lastNameTextEdit->text());
    QString firstName(ui->firstNameTextEdit->text());
    QString phone(ui->phoneTextEdit->text());

    QString street(ui->streetTextEdit->text());
    QString number(ui->numberTextEdit->text());
    QString postalCode(ui->postalCodeTextEdit->text());
    QString colony(ui->colonyTextEdit->text());
    QString town(ui->townTextEdit->text());

    bool itHasUnvalidChar = !(code.contains('*') ||
                              lastName.contains('*') ||
                              firstName.contains('*') ||
                              phone.contains('*') ||
                              street.contains('*') ||
                              number.contains('*') ||
                              postalCode.contains('*') ||
                              colony.contains('*') ||
                              town.contains('*') ||
                              code.contains('#') ||
                              lastName.contains('#') ||
                              firstName.contains('#') ||
                              phone.contains('#') ||
                              street.contains('#') ||
                              number.contains('#') ||
                              postalCode.contains('#') ||
                              colony.contains('#') ||
                              town.contains('#'));

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(!code.isEmpty() &&
                                                            !lastName.isEmpty() &&
                                                            !firstName.isEmpty() &&
                                                            !phone.isEmpty() &&
                                                            !street.isEmpty() &&
                                                            !number.isEmpty() &&
                                                            !postalCode.isEmpty() &&
                                                            !colony.isEmpty() &&
                                                            !town.isEmpty() &&
                                                            itHasUnvalidChar);
}

void PatientDialog::setDataInDialog() {
    QString title;

    switch(mode) {
    case 0: {
        title = "Paciente \"" + data.getName().toString() + "\".";
        ui->buttonBox->setStandardButtons(QDialogButtonBox::Ok);
    } break;
    case 1: title = "Agregar paciente."; break;
    case 2: title = "Modificar paciente \"" + data.getName().toString() + "\"."; break;
    }

    setWindowTitle(title);

    ui->nssTextEdit->setText(mode != 1 ? data.getCode() : "");
    ui->birthDateEdit->setDate(mode != 1 ? data.getBirthDate() : QDate::currentDate());
    ui->lastNameTextEdit->setText(mode != 1 ? data.getName().getLast() : "");
    ui->firstNameTextEdit->setText(mode != 1 ? data.getName().getFirst() : "");
    ui->phoneTextEdit->setText(mode != 1 ? data.getPhone() : "");

    ui->streetTextEdit->setText(mode != 1 ? data.getAddress().getStreet() : "");
    ui->numberTextEdit->setText(mode != 1 ? data.getAddress().getNumber() : "");
    ui->postalCodeTextEdit->setText(mode != 1 ? data.getAddress().getPostalCode() : "");
    ui->colonyTextEdit->setText(mode != 1 ? data.getAddress().getColony() : "");
    ui->townTextEdit->setText(mode != 1 ? data.getAddress().getTown() : "");

    ui->nssTextEdit->setEnabled(mode != 0);
    ui->birthDateEdit->setEnabled(mode != 0);
    ui->lastNameTextEdit->setEnabled(mode != 0);
    ui->firstNameTextEdit->setEnabled(mode != 0);
    ui->phoneTextEdit->setEnabled(mode != 0);

    ui->streetTextEdit->setEnabled(mode != 0);
    ui->numberTextEdit->setEnabled(mode != 0);
    ui->postalCodeTextEdit->setEnabled(mode != 0);
    ui->colonyTextEdit->setEnabled(mode != 0);
    ui->townTextEdit->setEnabled(mode != 0);

    ui->birthDateEdit->setCalendarPopup(mode != 0);

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(mode != 1);

    ui->nssTextEdit->setFocus();
}

PatientDialog::PatientDialog(const Patient &pat, const unsigned int &m, QWidget *parent) : DataEntryDialog<Patient>(parent), ui(new Ui::PatientDialog), data(pat), mode(m) {
    ui->setupUi(this);

    ui->buttonBox->button(QDialogButtonBox::Ok)->setText(mode != 0 ?  "Guardar" : "OK");
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("Cancelar");

    setDataInDialog();

    // Conectar las señales Aceptar/Cancelar a las ranuras correspondientes
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &PatientDialog::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &PatientDialog::reject);

    connect(ui->nssTextEdit, &QLineEdit::textEdited, this, &PatientDialog::activateOKButton);
    connect(ui->lastNameTextEdit, &QLineEdit::textEdited, this, &PatientDialog::activateOKButton);
    connect(ui->firstNameTextEdit, &QLineEdit::textEdited, this, &PatientDialog::activateOKButton);
    connect(ui->phoneTextEdit, &QLineEdit::textEdited, this, &PatientDialog::activateOKButton);

    connect(ui->streetTextEdit, &QLineEdit::textEdited, this, &PatientDialog::activateOKButton);
    connect(ui->numberTextEdit, &QLineEdit::textEdited, this, &PatientDialog::activateOKButton);
    connect(ui->postalCodeTextEdit, &QLineEdit::textEdited, this, &PatientDialog::activateOKButton);
    connect(ui->colonyTextEdit, &QLineEdit::textEdited, this, &PatientDialog::activateOKButton);
    connect(ui->townTextEdit, &QLineEdit::textEdited, this, &PatientDialog::activateOKButton);
}

PatientDialog::~PatientDialog() {
    delete ui;
}

void PatientDialog::setData(const Patient &pat) {
    data = pat;

    setDataInDialog();
}

Patient PatientDialog::getData() const {
    Patient data;
    Address addr;
    QString last(ui->lastNameTextEdit->text());
    QString first(ui->firstNameTextEdit->text());

    data.setCode(ui->nssTextEdit->text());
    data.setBirthDate(ui->birthDateEdit->date());
    data.setName(Name(last, first));
    data.setPhone(ui->phoneTextEdit->text());

    addr.setStreet(ui->streetTextEdit->text());
    addr.setNumber(ui->numberTextEdit->text());
    addr.setPostalCode(ui->postalCodeTextEdit->text());
    addr.setColony(ui->colonyTextEdit->text());
    addr.setTown(ui->townTextEdit->text());

    data.setAddress(addr);

    return data;
}
