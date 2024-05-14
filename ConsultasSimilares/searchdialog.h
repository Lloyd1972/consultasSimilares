#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>
#include <QWidget>
#include <QButtonGroup>
#include <QPushButton>

#include "ui_searchdialog.h"

namespace Ui {
class SearchDialog;
}

class SearchDialog : public QDialog {
    Q_OBJECT

private:
    int type;
    QString option1;
    QString option2;
    QString article1;
    QString article2;
    Ui::SearchDialog *ui;

    void selectOptions();
public:
    SearchDialog(const QString &title, const int &t, QWidget *parent = nullptr);
    ~SearchDialog();

    void changeLabelText();
    QString getData() const;
    bool getFormat() const;
};

#endif // SEARCHDIALOG_H
