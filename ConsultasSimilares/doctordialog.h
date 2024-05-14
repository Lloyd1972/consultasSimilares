#ifndef DOCTORDIALOG_H
#define DOCTORDIALOG_H

#include <QDialog>
#include <QWidget>
#include <QString>
#include <QTime>
#include <QLineEdit>
#include <QPushButton>

#include "doctor.h"
#include "dataEntryDialog.h"
#include "ui_doctordialog.h"

namespace Ui {
class DoctorDialog;
}

class DoctorDialog : public DataEntryDialog<Doctor> {
    Q_OBJECT

private:
    Ui::DoctorDialog *ui;
    unsigned int mode;
    Doctor data;

    void activateOKButton();
    void setDataInDialog();

public:
    DoctorDialog(const Doctor &doc, const unsigned int &m, QWidget *parent = nullptr);
    ~DoctorDialog();

    void setData(const Doctor &doc);
    Doctor getData() const;
};

#endif // DOCTORDIALOG_H
