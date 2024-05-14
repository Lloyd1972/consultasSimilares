#include "searchdialog.h"

void SearchDialog::selectOptions() {
    /// Types map
    // 1 = Doctor
    // 2 = Paciente
    // 3 = Diágnostico
    // 4 = Medicamento

    article1 = "el ";
    option1 = type == 2 ? "NSS" : "Código";

    article2 = type == 3 ? "la " : "el ";
    option2 = type == 3 ? "Descripción" : "Nombre";
    option2 += type == 1 || type == 2 ? " Completo" : "";

    ui->codeRadioButton->setText(option1);
    ui->nameRadioButton->setText(option2);
}

SearchDialog::SearchDialog(const QString &title, const int &t, QWidget *parent) : QDialog(parent), type(t), ui(new Ui::SearchDialog) {
    ui->setupUi(this);
    setWindowTitle(title);
    selectOptions();

    ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Buscar");
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("Cancelar");

    // Conectar las señales Aceptar/Cancelar a las ranuras correspondientes
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &SearchDialog::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &SearchDialog::reject);

    connect(ui->selectionGroup, &QButtonGroup::buttonClicked, this, &SearchDialog::changeLabelText);
}

SearchDialog::~SearchDialog() {
    delete ui;
}

void SearchDialog::changeLabelText() {
    QString text("Ingrese ");

    text += ui->codeRadioButton->isChecked() ? article1 + (type != 2 ? option1.toLower() : option1) : article2 + option2.toLower();

    ui->label->setText(text + " a buscar: ");
}

QString SearchDialog::getData() const {
    return ui->searchingLineEdit->text();
}

bool SearchDialog::getFormat() const {
    return ui->codeRadioButton->isChecked();
}
