#include "diagnosis.h"
using namespace std;

Diagnosis::Diagnosis() { }

Diagnosis::Diagnosis(const Diagnosis &d) {
    *this = d;
}

QString Diagnosis::getCode() const {
    return code;
}

QString Diagnosis::getDescription() const {
    return description;
}

QString Diagnosis::getIndications() const {
    return indications;
}

QString Diagnosis::toString() const {
    return (code +
            description +
            indications);
}

void Diagnosis::setCode(const QString &c) {
    code = c;
}

void Diagnosis::setDescription(const QString &d) {
    description = d;
}

void Diagnosis::setIndications(const QString &i) {
    indications = i;
}

Diagnosis& Diagnosis::operator=(const Diagnosis &d) {
    code = d.code;
    description = d.description;
    indications = d.indications;

    return *this;
}

bool Diagnosis::operator==(const Diagnosis &d) {
    return toString() == d.toString();
}

bool Diagnosis::operator!=(const Diagnosis &d) {
    return !(*this == d);
}

bool Diagnosis::operator<(const Diagnosis &d) {
    return toString() < d.toString();
}

bool Diagnosis::operator<=(const Diagnosis &d) {
    return *this < d || *this == d;
}

bool Diagnosis::operator>(const Diagnosis &d) {
    return !(*this <= d);
}

bool Diagnosis::operator>=(const Diagnosis &d) {
    return !(*this < d);
}

istream& operator >> (istream &is, Diagnosis &d) {
    string readingStr;

    getline(is, readingStr, '*'); // Código
    d.code = QString::fromStdString(readingStr);

    getline(is, readingStr, '*'); // Descripción
    d.description = QString::fromStdString(readingStr);

    getline(is, readingStr, '*'); // Indicaciones
    d.indications = QString::fromStdString(readingStr);

    return is;
}

ostream& operator << (ostream &os, const Diagnosis &d) {
    os << d.code.toStdString() << "*"
       << d.description.toStdString() << "*"
       << d.indications.toStdString() << "*";

    return os;
}
