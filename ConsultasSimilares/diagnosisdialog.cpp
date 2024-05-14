#include "diagnosisdialog.h"
using namespace std;

void DiagnosisDialog::activateOKButton() {
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(!ui->codeTextEdit->text().isEmpty() &&
                                                            !ui->descriptionTextEdit->toPlainText().isEmpty() &&
                                                            !ui->indicationsTextEdit->toPlainText().isEmpty() &&
                                                            !(ui->codeTextEdit->text().contains('*') ||
                                                             ui->descriptionTextEdit->toPlainText().contains('*') ||
                                                             ui->indicationsTextEdit->toPlainText().contains('*') ||
                                                             ui->codeTextEdit->text().contains('#') ||
                                                             ui->descriptionTextEdit->toPlainText().contains('#') ||
                                                             ui->indicationsTextEdit->toPlainText().contains('#')));
}

void DiagnosisDialog::setDataInDialog() {
    QString title;

    switch(mode) {
    case 0: {
        title = "Diágnostico " + data.getCode() + ".";
        ui->buttonBox->setStandardButtons(QDialogButtonBox::Ok);
    } break;
    case 1: title = "Agregar diágnostico."; break;
    case 2: title = "Modificar diágnostico '"  + data.getCode() + "'."; break;
    }
    setWindowTitle(title);

    // Establecer los campos de texto y habilitar/deshabilitar según el modo
    ui->codeTextEdit->setText(mode != 1 ? data.getCode() : "");
    ui->descriptionTextEdit->setText(mode != 1 ? data.getDescription() : "");
    ui->indicationsTextEdit->setText(mode != 1 ? data.getIndications() : "");

    ui->codeTextEdit->setEnabled(mode != 0);
    ui->descriptionTextEdit->setEnabled(mode != 0);
    ui->indicationsTextEdit->setEnabled(mode != 0);

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(mode != 1);

    // Establecer el enfoque en el campo de código
    ui->codeTextEdit->setFocus();
}

DiagnosisDialog::DiagnosisDialog(const Diagnosis &diag, const unsigned int &m, QWidget* parent) : DataEntryDialog<Diagnosis>(parent), ui(new Ui::DiagnosisDialog), data(diag), mode(m) {
    ui->setupUi(this);

    ui->buttonBox->button(QDialogButtonBox::Ok)->setText(mode != 0 ?  "Guardar" : "OK");
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("Cancelar");

    setDataInDialog();

    // Conectar las señales Aceptar/Cancelar a las ranuras correspondientes
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &DiagnosisDialog::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &DiagnosisDialog::reject);

    connect(ui->codeTextEdit, &QLineEdit::textEdited, this, &DiagnosisDialog::activateOKButton);
    connect(ui->descriptionTextEdit, &QTextEdit::textChanged, this, &DiagnosisDialog::activateOKButton);
    connect(ui->indicationsTextEdit, &QTextEdit::textChanged, this, &DiagnosisDialog::activateOKButton);
}

DiagnosisDialog::~DiagnosisDialog() {
    delete ui;
}

void DiagnosisDialog::setData(const Diagnosis &diag) {
    data = diag;

    setDataInDialog();
}

Diagnosis DiagnosisDialog::getData() const {
    Diagnosis data;

    data.setCode(ui->codeTextEdit->text());
    data.setDescription(ui->descriptionTextEdit->toPlainText());
    data.setIndications(ui->indicationsTextEdit->toPlainText());

    return data;
}
