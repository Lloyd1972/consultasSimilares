#ifndef CONSULTATIONFILE_H
#define CONSULTATIONFILE_H

#include <QCoreApplication>

#include <fstream>
#include <string>
#include <list>

#include "consultation.h"

#include "dataEntryFile.h"

class ConsultationFile : public DataEntryFile<Consultation> {
private:
    std::fstream dataFile;

    std::string fileName;

    std::list<Tuple<Consultation>> idxList;

    void fileToList();
    void listToFile();
    Tuple<Consultation> sstringToTuple(std::stringstream &ss);
public:
    ConsultationFile(const std::string&fName = "consFile");
    ~ConsultationFile();

    void setFileName(const std::string &fName);

    bool addRecord(const Consultation &c, QWidget* parent, const bool &import = false) override;
    void modifyRecord(const Consultation &oldData, const Consultation &newData) override;
    void delRecord(const int &pos) override;
    void delRecord(const Consultation &data) override;
    int findRecord(const Consultation &c) override;
    int findRecord(const std::string &code) override;
    int findRecordByName(const std::string &name) override;
    Consultation retrieveRecord(const int &pos) override;
    void clearRecord();

    int getSize() const override;
    std::list<Tuple<Consultation>> getList();
    int getLastIndex() const;

    void reindex();
};

#endif // CONSULTATIONFILE_H
