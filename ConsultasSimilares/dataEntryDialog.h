#ifndef DATAENTRYDIALOG_H
#define DATAENTRYDIALOG_H

#include <QWidget>
#include <QDialog>

template <typename T>
class DataEntryDialog : public QDialog {
public:
    DataEntryDialog(QWidget *parent = nullptr) : QDialog(parent) {}
    virtual ~DataEntryDialog() {} // Destructor virtual

    virtual T getData() const = 0;
};

#endif // DATAENTRYDIALOG_H
