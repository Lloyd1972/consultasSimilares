#ifndef DIAGNOSISDIALOG_H
#define DIAGNOSISDIALOG_H

#include <QDialog>
#include <QWidget>
#include <QString>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>

#include "diagnosis.h"
#include "dataEntryDialog.h"
#include "ui_diagnosisdialog.h"

namespace Ui {
class DiagnosisDialog;
}

class DiagnosisDialog : public DataEntryDialog<Diagnosis> {
    Q_OBJECT

private:
    Ui::DiagnosisDialog *ui;
    unsigned int mode;
    Diagnosis data;

    void activateOKButton();
    void setDataInDialog();
public:
    DiagnosisDialog(const Diagnosis &diag, const unsigned int &m, QWidget *parent = nullptr);
    ~DiagnosisDialog();

    void setData(const Diagnosis &diag);
    Diagnosis getData() const;
};

#endif // DIAGNOSISDIALOG_H
