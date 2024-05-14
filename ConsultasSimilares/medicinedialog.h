#ifndef MEDICINEDIALOG_H
#define MEDICINEDIALOG_H

#include <QDialog>
#include <QString>
#include <QLineEdit>
#include <QPushButton>

#include "medicine.h"
#include "dataEntryDialog.h"
#include "ui_medicinedialog.h"

namespace Ui {
class MedicineDialog;
}

class MedicineDialog : public DataEntryDialog<Medicine> {
    Q_OBJECT

private:
    Ui::MedicineDialog *ui;
    unsigned int mode;
    Medicine data;

    void activateOKButton();
    void setDataInDialog();
public:
    MedicineDialog(const Medicine &med, const unsigned int &m, QWidget *parent = nullptr);
    ~MedicineDialog();

    void setData(const Medicine &med);
    Medicine getData() const;
};

#endif // MEDICINEDIALOG_H
