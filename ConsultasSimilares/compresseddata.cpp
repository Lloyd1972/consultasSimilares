#include "compresseddata.h"

CompressedData::CompressedData() { }

Doctor CompressedData::getDoctor() const {
    return doctor;
}

Patient CompressedData::getPatient() const {
    return patient;
}

Diagnosis CompressedData::getDiagnosis() const {
    return diagnosis;
}

Medicine CompressedData::getMedicine1() const {
    return medicine1;
}

Medicine CompressedData::getMedicine2() const {
    return medicine2;
}

Medicine CompressedData::getMedicine3() const {
    return medicine3;
}

void CompressedData::setDoctor(const Doctor &doc) {
    doctor = doc;
}

void CompressedData::setPatient(const Patient &pat) {
    patient = pat;
}

void CompressedData::setDiagnosis(const Diagnosis &diag) {
    diagnosis = diag;
}

void CompressedData::setMedicine1(const Medicine &med) {
    medicine1 = med;
}

void CompressedData::setMedicine2(const Medicine &med) {
    medicine2 = med;
}

void CompressedData::setMedicine3(const Medicine &med) {
    medicine3 = med;
}
