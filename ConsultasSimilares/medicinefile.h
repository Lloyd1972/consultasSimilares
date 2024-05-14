#ifndef MEDICINEFILE_H
#define MEDICINEFILE_H

#include <QCoreApplication>

#include <sstream>
#include <fstream>
#include <string>
#include <list>

#include "medicine.h"

#include "dataEntryFile.h"

class MedicineFile : public DataEntryFile<Medicine> {
private:
    std::fstream dataFile;

    std::string fileName;

    std::list<Tuple<Medicine>> idxList;
    std::list<Tuple<QString>> idxCodeList;
    std::list<Tuple<QString>> idxNameList;

    void fileToList();
    void listToFile();
    Tuple<Medicine> sstringToTuple(std::stringstream &ss);
public:
    MedicineFile(const std::string &fName = "medFile");
    ~MedicineFile();

    void setFileName(const std::string &fName);

    bool addRecord(const Medicine &m, QWidget* parent, const bool &import = false) override;
    void modifyRecord(const Medicine &oldData, const Medicine &newData) override;
    void delRecord(const int &pos) override;
    void delRecord(const Medicine &data) override;
    int findRecord(const Medicine &m) override;
    int findRecord(const std::string &code) override;
    int findRecordByName(const std::string &name) override;
    Medicine retrieveRecord(const int &pos) override;
    void clearRecord();

    int getSize() const override;
    std::list<Tuple<Medicine>> getList();

    void reindex();
    void compress();
};

#endif // MEDICINEFILE_H
