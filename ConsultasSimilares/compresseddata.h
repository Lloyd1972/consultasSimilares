#ifndef COMPRESSEDDATA_H
#define COMPRESSEDDATA_H

#include "doctor.h"
#include "patient.h"
#include "diagnosis.h"
#include "medicine.h"

class CompressedData {
private:
    Doctor doctor;
    Patient patient;
    Diagnosis diagnosis;
    Medicine medicine1;
    Medicine medicine2;
    Medicine medicine3;
public:
    CompressedData();

    Doctor getDoctor() const;
    Patient getPatient() const;
    Diagnosis getDiagnosis() const;
    Medicine getMedicine1() const;
    Medicine getMedicine2() const;
    Medicine getMedicine3() const;

    void setDoctor(const Doctor &doc);
    void setPatient(const Patient &pat);
    void setDiagnosis(const Diagnosis &diag);
    void setMedicine1(const Medicine &med);
    void setMedicine2(const Medicine &med);
    void setMedicine3(const Medicine &med);
};

#endif // COMPRESSEDDATA_H
