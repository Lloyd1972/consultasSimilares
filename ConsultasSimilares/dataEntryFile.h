#ifndef DATAENTRYFILE_H
#define DATAENTRYFILE_H

#include <QWidget>
#include <QMessageBox>

#include <string>

#include "tuple.h"

template <typename T>
class DataEntryFile {
public:
    DataEntryFile(const std::string &fName = "") {}
    virtual ~DataEntryFile() {}

    virtual bool addRecord(const T &data, QWidget* parent, const bool &import = false) = 0;
    virtual void modifyRecord(const T &oldData, const T &newData) = 0;
    virtual void delRecord(const int &pos) = 0;
    virtual void delRecord(const T &data) = 0;
    virtual int findRecord(const T &m) = 0;
    virtual int findRecord(const std::string &code) = 0;
    virtual int findRecordByName(const std::string &name) = 0;
    virtual T retrieveRecord(const int &pos) = 0;

    virtual int getSize() const {
        return 0;
    };
};

#endif // DATAENTRYFILE_H
