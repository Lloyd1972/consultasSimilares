#ifndef DIAGNOSISFILE_H
#define DIAGNOSISFILE_H

#include <sstream>
#include <fstream>
#include <string>
#include <list>

#include "diagnosis.h"

#include "dataEntryFile.h"

class DiagnosisFile : public DataEntryFile<Diagnosis> {
private:
    std::fstream dataFile;

    std::string fileName;

    std::list<Tuple<Diagnosis>> idxList;
    std::list<Tuple<QString>> idxCodeList;
    std::list<Tuple<QString>> idxDescList;

    void fileToList();
    void listToFile();
    Tuple<Diagnosis> sstringToTuple(std::stringstream &ss);
public:
    DiagnosisFile(const std::string &fName = "diagFile");
    ~DiagnosisFile();

    void setFileName(const std::string &fName);

    bool addRecord(const Diagnosis &d, QWidget* parent, const bool &import = false) override;
    void modifyRecord(const Diagnosis &oldData, const Diagnosis &newData) override;
    void delRecord(const int &pos) override;
    void delRecord(const Diagnosis &data) override;
    int findRecord(const Diagnosis &d) override;
    int findRecord(const std::string &code) override;
    int findRecordByName(const std::string &desc) override;
    Diagnosis retrieveRecord(const int &pos) override;
    void clearRecord();

    int getSize() const override;
    std::list<Tuple<Diagnosis>> getList();

    void reindex();
};

#endif // DIAGNOSISFILE_H
