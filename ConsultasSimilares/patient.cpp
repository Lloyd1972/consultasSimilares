#include "patient.h"
using namespace std;

Patient::Patient() { }

Patient::Patient(const Patient &p) {
    *this = p;
}

QString Patient::getCode() const {
    return nss;
}

Name Patient::getName() const {
    return name;
}

QDate Patient::getBirthDate() const {
    return birthDate;
}

Address Patient::getAddress() const {
    return address;
}

QString Patient::getPhone() const {
    return phone;
}

QString Patient::toString() const {
    return (nss +
            name.toString() +
            birthDate.toString("hh:mm") +
            address.toComparingString() +
            phone);
}

void Patient::setCode(const QString &n) {
    nss = n;
}

void Patient::setName(const Name &n) {
    name = n;
}

void Patient::setBirthDate(const QDate &bd) {
    birthDate = bd;
}

void Patient::setAddress(const Address &a) {
    address = a;
}

void Patient::setPhone(const QString &p) {
    phone = p;
}

Patient& Patient::operator=(const Patient &p) {
    nss = p.nss;
    name = p.name;
    birthDate = p.birthDate;
    address = p.address;
    phone = p.phone;

    return *this;
}

bool Patient::operator==(const Patient &p) {
    return toString() == p.toString();
}

bool Patient::operator!=(const Patient &p) {
    return !(*this == p);
}

bool Patient::operator<(const Patient &p) {
    return toString() < p.toString();
}

bool Patient::operator<=(const Patient &p) {
    return *this < p || *this == p;
}

bool Patient::operator>(const Patient &p) {
    return !(*this <= p);
}

bool Patient::operator>=(const Patient &p) {
    return !(*this < p);
}

istream& operator >> (istream &is, Patient &p) {
    string readingStr;

    getline(is, readingStr, '*'); // NSS del Paciente
    p.nss = QString::fromStdString(readingStr);

    is >> p.name; // Nombre

    getline(is, readingStr, '*'); // Fecha de Nacimiento
    p.birthDate = QDate::fromString(QString::fromStdString(readingStr), "dd/MM/yyyy");

    is >> p.address; // Domicilio

    getline(is, readingStr, '*'); // Teléfono
    p.phone = QString::fromStdString(readingStr);

    return is;
}

ostream& operator << (ostream &os, const Patient &p) {
    os << p.nss.toStdString() << "*"
       << p.name << "*"
       << p.birthDate.toString("dd/MM/yyyy").toStdString() << "*"
       << p.address << "*"
       << p.phone.toStdString() << "*";

    return os;
}
