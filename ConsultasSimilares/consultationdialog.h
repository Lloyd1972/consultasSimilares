#ifndef CONSULTATIONDIALOG_H
#define CONSULTATIONDIALOG_H

#include <vector>

#include <QWidget>
#include <QTableWidget>

#include "consultation.h"
#include "ui_consultationdialog.h"
#include "tabledialog.h"

#include "dataEntryDialog.h"
#include "compresseddata.h"

namespace Ui {
class ConsultationDialog;
}

class ConsultationDialog : public DataEntryDialog<Consultation> {
    Q_OBJECT

private:
    Ui::ConsultationDialog *ui;
    unsigned int mode;
    Consultation data;
    std::vector<QTableWidget*> tables;
    CompressedData comData;

    void activateOKButton();
    void setDataInDialog();
public:
    ConsultationDialog(const Consultation &cons, const unsigned int &m, const CompressedData &cd, QWidget *parent = nullptr);
    ~ConsultationDialog();

    template <class T>
    void showTable(const int &button);

    void selectDoctor();
    void selectPatient();
    void selectDiagnosis();
    void selectMedicine1();
    void selectMedicine2();
    void selectMedicine3();

    void setData(const Consultation &cons);
    Consultation getData() const;
};

#endif // CONSULTATIONDIALOG_H
