#include "doctor.h"
using namespace std;

Doctor::Doctor() { }

Doctor::Doctor(const Doctor &d) {
    *this = d;
}

QString Doctor::getCode() const {
    return code;
}

QString Doctor::getCedule() const {
    return cedule;
}

Name Doctor::getName() const {
    return name;
}

QTime Doctor::getEntryHour() const {
    return entryHour;
}

QTime Doctor::getLeaveHour() const {
    return leaveHour;
}

QString Doctor::toString() const {
    return (code +
            cedule +
            name.toString() +
            entryHour.toString("hh:mm") +
            leaveHour.toString("hh:mm"));
}

void Doctor::setCode(const QString &c) {
    code = c;
}

void Doctor::setCedule(const QString &c) {
    cedule = c;
}

void Doctor::setName(const Name &n) {
    name = n;
}

void Doctor::setEntryHour(const QTime &eh) {
    entryHour = eh;
}

void Doctor::setLeaveHour(const QTime &lh) {
    leaveHour = lh;
}

Doctor& Doctor::operator=(const Doctor &d) {
    code = d.code;
    cedule = d.cedule;
    name = d.name;
    entryHour = d.entryHour;
    leaveHour = d.leaveHour;

    return *this;
}

bool Doctor::operator==(const Doctor &d) {
    return toString() == d.toString();
}

bool Doctor::operator!=(const Doctor &d) {
    return !(*this == d);
}

bool Doctor::operator<(const Doctor &d) {
    return toString() < d.toString();
}

bool Doctor::operator<=(const Doctor &d) {
    return *this < d || *this == d;
}

bool Doctor::operator>(const Doctor &d) {
    return !(*this <= d);
}

bool Doctor::operator>=(const Doctor &d) {
    return !(*this < d);
}

istream& operator >> (istream &is, Doctor &d) {
    string readingStr;

    getline(is, readingStr, '*'); // Código
    d.code = QString::fromStdString(readingStr);

    is >> d.name; // Nombre

    getline(is, readingStr, '*'); // Cedula
    d.cedule = QString::fromStdString(readingStr);

    getline(is, readingStr, '*'); // Hora de entrada
    d.entryHour = QTime::fromString(QString::fromStdString(readingStr), "hh:mm");

    getline(is, readingStr, '*'); // Hora de salida
    d.leaveHour = QTime::fromString(QString::fromStdString(readingStr), "hh:mm");

    return is;
}

ostream& operator << (ostream &os, const Doctor &d) {
    os << d.code.toStdString() << "*"
       << d.name << "*"
       << d.cedule.toStdString() << "*"
       << d.entryHour.toString("hh:mm").toStdString() << "*"
       << d.leaveHour.toString("hh:mm").toStdString() << "*";

    return os;
}
