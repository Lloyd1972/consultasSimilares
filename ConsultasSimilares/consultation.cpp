#include "consultation.h"
using namespace std;

Consultation::Consultation() { }

Consultation::Consultation(const Consultation &c) {
    *this = c;
}

QDate Consultation::getDate() const {
    return date;
}

QTime Consultation::getHour() const {
    return hour;
}

QString Consultation::getDoctorCode() const {
    return doctorCode;
}

QString Consultation::getPatientNSS() const {
    return patientNSS;
}

QString Consultation::getDiagnosisCode() const {
    return diagnosisCode;
}

QString Consultation::getMedicine1Code() const {
    return medicine1Code;
}

QString Consultation::getMedicine2Code() const {
    return medicine2Code;
}

QString Consultation::getMedicine3Code() const {
    return medicine3Code;
}

QString Consultation::toString() const {
    QString result;

    result = date.toString("dd/MM/yyyy") +
             hour.toString("hh:mm") +
             doctorCode +
             patientNSS +
             diagnosisCode +
             medicine1Code;

    if(medicine2Code != "") {
        result += medicine2Code;
    }

    if(medicine3Code != "") {
        result += medicine3Code;
    }

    return result;
}

void Consultation::setDate(const QDate &d) {
    date = d;
}

void Consultation::setHour(const QTime &h) {
    hour = h;
}

void Consultation::setDoctorCode(const QString &dc) {
    doctorCode = dc;
}

void Consultation::setPatientNSS(const QString &pn) {
    patientNSS = pn;
}

void Consultation::setDiagnosisCode(const QString &dc) {
    diagnosisCode = dc;
}

void Consultation::setMedicine1Code(const QString &mc) {
    medicine1Code = mc;
}

void Consultation::setMedicine2Code(const QString &mc) {
    medicine2Code = mc;
}

void Consultation::setMedicine3Code(const QString &mc) {
    medicine3Code = mc;
}

Consultation& Consultation::operator=(const Consultation &c) {
    date = c.date;
    hour = c.hour;
    doctorCode = c.doctorCode;
    patientNSS = c.patientNSS;
    diagnosisCode = c.diagnosisCode;
    medicine1Code = c.medicine1Code;
    medicine2Code = c.medicine2Code;
    medicine3Code = c.medicine3Code;

    return *this;
}

bool Consultation::operator==(const Consultation &c) {
    return toString() == c.toString();
}

bool Consultation::operator!=(const Consultation &c) {
    return !(*this == c);
}

bool Consultation::operator<(const Consultation &c) {
    return toString() < c.toString();
}

bool Consultation::operator<=(const Consultation &c) {
    return *this < c || *this == c;
}

bool Consultation::operator>(const Consultation &c) {
    return !(*this <= c);
}

bool Consultation::operator>=(const Consultation &c) {
    return !(*this < c);
}

istream& operator >> (istream &is, Consultation &c) {
    string readingStr;

    getline(is, readingStr, '*'); // Fecha
    c.date = QDate::fromString(QString::fromStdString(readingStr), "dd/MM/yyyy");

    getline(is, readingStr, '*'); // Hora
    c.hour = QTime::fromString(QString::fromStdString(readingStr), "hh:mm");

    return is;
}

ostream& operator << (ostream &os, const Consultation &c) {
    os << c.date.toString("dd/MM/yyyy").toStdString() << "*"
       << c.hour.toString("hh:mm").toStdString() << "*";

    return os;
}
