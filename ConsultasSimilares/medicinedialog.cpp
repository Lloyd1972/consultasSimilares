#include "medicinedialog.h"
using namespace std;

void MedicineDialog::activateOKButton() {
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(!ui->codeTextEdit->text().isEmpty() &&
                                                            !ui->nameTextEdit->text().isEmpty() &&
                                                            !(ui->codeTextEdit->text().contains('*') ||
                                                              ui->nameTextEdit->text().contains('*') ||
                                                              ui->codeTextEdit->text().contains('#') ||
                                                              ui->nameTextEdit->text().contains('#')));
}

void MedicineDialog::setDataInDialog() {
    QString title;

    switch(mode) {
        case 0: {
            title = "Medicamento " + data.getCode() + ".";
            ui->buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        } break;
        case 1: {
            title = "Agregar medicamento.";
        } break;
        default: {
            title = "Modificar medicamento '"  + data.getName() + "'.";
        } break;
    }
    setWindowTitle(title);

    // Establecer los campos de texto y habilitar/deshabilitar según el modo
    ui->codeTextEdit->setText(mode != 1 ? data.getCode() : "");
    ui->nameTextEdit->setText(mode != 1 ? data.getName() : "");

    ui->codeTextEdit->setEnabled(mode != 0);
    ui->nameTextEdit->setEnabled(mode != 0);

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(mode != 1);

    // Establecer el enfoque en el campo de código
    ui->codeTextEdit->setFocus();
}

MedicineDialog::MedicineDialog(const Medicine& med, const unsigned int&m, QWidget *parent) : DataEntryDialog<Medicine>(parent), ui(new Ui::MedicineDialog), data(med), mode(m) {
    ui->setupUi(this);

    ui->buttonBox->button(QDialogButtonBox::Ok)->setText(mode != 0 ?  "Guardar" : "OK");
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("Cancelar");

    setDataInDialog();

    // Conectar las señales Aceptar/Cancelar a las ranuras correspondientes
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &MedicineDialog::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &MedicineDialog::reject);

    connect(ui->codeTextEdit, &QLineEdit::textEdited, this, &MedicineDialog::activateOKButton);
    connect(ui->nameTextEdit, &QLineEdit::textEdited, this, &MedicineDialog::activateOKButton);
}

MedicineDialog::~MedicineDialog() {
    delete ui;
}

void MedicineDialog::setData(const Medicine &med) {
    data = med;

    setDataInDialog();
}

Medicine MedicineDialog::getData() const {
    QString code = ui->codeTextEdit->text();
    QString name = ui->nameTextEdit->text();

    return Medicine(code, name);
}
