#ifndef DOCTORFILE_H
#define DOCTORFILE_H

#include <QMessageBox>

#include <sstream>
#include <fstream>
#include <string>
#include <list>

#include <iostream>

#include "doctor.h"
#include "dataEntryFile.h"

class DoctorFile : public DataEntryFile<Doctor> {
private:
    std::fstream dataFile;

    std::string fileName;

    std::list<Tuple<Doctor>> idxList;
    std::list<Tuple<QString>> idxCodeList;
    std::list<Tuple<QString>> idxNameList;

    void fileToList();
    void listToFile();
    Tuple<Doctor> sstringToTuple(std::stringstream &ss);
public:
    DoctorFile(const std::string&fName = "docFile");
    ~DoctorFile();

    void setFileName(const std::string &fName);

    bool addRecord(const Doctor &d, QWidget* parent, const bool &import = false) override;
    void modifyRecord(const Doctor &oldData, const Doctor &newData) override;
    void delRecord(const int &pos) override;
    void delRecord(const Doctor &data) override;
    int findRecord(const Doctor &d) override;
    int findRecord(const std::string &code) override;
    int findRecordByName(const std::string &name) override;
    Doctor retrieveRecord(const int &pos) override;
    void clearRecord();

    int getSize() const override;
    std::list<Tuple<Doctor>> getList();

    void reindex();
};

#endif // DOCTORFILE_H
