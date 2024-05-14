#ifndef PATIENTFILE_H
#define PATIENTFILE_H

#include <sstream>
#include <fstream>
#include <string>
#include <list>

#include "patient.h"
#include "dataEntryFile.h"

class PatientFile : public DataEntryFile<Patient> {
private:
    std::fstream dataFile;

    std::string fileName;

    std::list<Tuple<Patient>> idxList;
    std::list<Tuple<QString>> idxCodeList;
    std::list<Tuple<QString>> idxNameList;

    void fileToList();
    void listToFile();
    Tuple<Patient> sstringToTuple(std::stringstream &ss);
public:
    PatientFile(const std::string&fName = "patFile");
    ~PatientFile();

    void setFileName(const std::string &fName);

    bool addRecord(const Patient &p, QWidget* parent, const bool &import = false) override;
    void modifyRecord(const Patient &oldData, const Patient &newData) override;
    void delRecord(const int &pos) override;
    void delRecord(const Patient &pata) override;
    int findRecord(const Patient &p) override;
    int findRecord(const std::string &code) override;
    int findRecordByName(const std::string &name) override;
    Patient retrieveRecord(const int &pos) override;
    void clearRecord();

    int getSize() const override;
    std::list<Tuple<Patient>> getList();

    void reindex();
};

#endif // PATIENTFILE_H
