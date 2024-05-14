#include "medicine.h"
using namespace std;

Medicine::Medicine() { }

Medicine::Medicine(const Medicine &m) : code(m.code), name(m.name) { }

Medicine::Medicine(const QString &c, const QString &n) : code(c), name(n) {}

QString Medicine::getCode() const {
    return code;
}

QString Medicine::getName() const {
    return name;
}

QString Medicine::toString() const {
    return code + ", " + name;
}

void Medicine::setCode(const QString &c) {
    code = c;
}

void Medicine::setName(const QString &n) {
    name = n;
}

Medicine& Medicine::operator=(const Medicine &m) {
    code = m.getCode();
    name = m.getName();

    return *this;
}

bool Medicine::operator==(const Medicine &m) {
    return toString() == m.toString();
}

bool Medicine::operator!=(const Medicine &m) {
    return !(*this == m);
}

bool Medicine::operator<(const Medicine &m) {
    return toString() < m.toString();
}

bool Medicine::operator<=(const Medicine &m) {
    return *this < m || *this == m;
}

bool Medicine::operator>(const Medicine &m) {
    return !(*this <= m);
}

bool Medicine::operator>=(const Medicine &m) {
    return !(*this < m);
}

istream& operator >> (istream &is, Medicine&m) {
    string readingStr;

    getline(is, readingStr, '*'); // Código
    m.code = QString::fromStdString(readingStr);

    getline(is, readingStr, '*'); // Nombre de la Medicina
    m.name = QString::fromStdString(readingStr);

    return is;
}

ostream& operator << (ostream &os, const Medicine&m) {
    os << m.code.toStdString() << "*"
       << m.name.toStdString() << "*";

    return os;
}
