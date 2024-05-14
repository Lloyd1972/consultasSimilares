#include "address.h"
using namespace std;

Address::Address() { }

Address::Address(const Address& a) {
    *this = a;
}

QString Address::getStreet() const {
    return street;
}

QString Address::getNumber() const {
    return number;
}

QString Address::getPostalCode() const {
    return postalCode;
}

QString Address::getColony() const {
    return colony;
}

QString Address::getTown() const {
    return town;
}

QString Address::toString() const {
    return street + " #" + number;
}

QString Address::toComparingString() const {
    return (street +
            number +
            postalCode +
            colony +
            town);
}

void Address::setStreet(const QString& s) {
    street = s;
}

void Address::setNumber(const QString& n) {
    number = n;
}

void Address::setPostalCode(const QString& pc) {
    postalCode = pc;
}

void Address::setColony(const QString& c) {
    colony = c;
}

void Address::setTown(const QString& t) {
    town = t;
}

Address& Address::operator=(const Address& a) {
    street = a.street;
    number = a.number;
    postalCode = a.postalCode;
    colony = a.colony;
    town = a.town;

    return *this;
}

bool Address::operator==(const Address& a) {
    return toComparingString() == a.toComparingString();
}

bool Address::operator!=(const Address& a) {
    return !(*this == a);
}

bool Address::operator<(const Address& a) {
    return toComparingString() < a.toComparingString();
}

bool Address::operator<=(const Address& a) {
    return *this < a || *this == a;
}

bool Address::operator>(const Address& a) {
    return !(*this <= a);
}

bool Address::operator>=(const Address& a) {
    return !(*this < a);
}

istream& operator >> (istream&is, Address&a) {
    string readingStr;

    getline(is, readingStr, '*'); // Calle
    a.street = QString::fromStdString(readingStr);

    getline(is, readingStr, '*'); // Número
    a.number = QString::fromStdString(readingStr);

    getline(is, readingStr, '*'); // Colonia
    a.colony = QString::fromStdString(readingStr);

    getline(is, readingStr, '*'); // Código Postal
    a.postalCode = QString::fromStdString(readingStr);

    getline(is, readingStr, '*'); // Ciudad
    a.town = QString::fromStdString(readingStr);

    return is;
}

ostream& operator<<(ostream &os, const Address &a) {
    os << a.street.toStdString() << "*";
    os << a.number.toStdString() << "*";
    os << a.colony.toStdString() << "*";
    os << a.postalCode.toStdString() << "*";
    os << a.town.toStdString();

    return os;
}
