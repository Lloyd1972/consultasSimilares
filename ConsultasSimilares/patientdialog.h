#ifndef PATIENTDIALOG_H
#define PATIENTDIALOG_H

#include <QDialog>
#include <QWidget>
#include <QString>
#include <QDate>
#include <QLineEdit>
#include <QPushButton>

#include "patient.h"
#include "dataEntryDialog.h"
#include "ui_patientdialog.h"

namespace Ui {
class PatientDialog;
}

class PatientDialog : public DataEntryDialog<Patient> {
    Q_OBJECT

private:
    Ui::PatientDialog *ui;
    unsigned int mode;
    Patient data;

    void activateOKButton();
    void setDataInDialog();

public:
    PatientDialog(const Patient &pat,const unsigned int &m, QWidget *parent = nullptr);
    ~PatientDialog();

    void setData(const Patient &pat);
    Patient getData() const;
};

#endif // PATIENTDIALOG_H
