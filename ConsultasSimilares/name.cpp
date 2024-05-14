#include "name.h"
using namespace std;

Name::Name() { }

Name::Name(const Name &n) : lastName(n.lastName), firstName(n.firstName) { }

Name::Name(const QString &last, const QString &first) : lastName(last), firstName(first) { }

QString Name::getLast() const {
    return lastName;
}

QString Name::getFirst() const {
    return firstName;
}

QString Name::toString() const {
    return lastName + ", " + firstName;
}

void Name::setLast(const QString &last) {
    lastName = last;
}

void Name::setFirst(const QString &first) {
    firstName = first;
}

Name& Name::operator=(const Name &n) {
    lastName = n.lastName;
    firstName = n.firstName;

    return *this;
}

bool Name::operator==(const Name &n) {
    return toString() == n.toString();
}

bool Name::operator!=(const Name &n) {
    return !(*this == n);
}

bool Name::operator<(const Name &n) {
    return toString() < n.toString();
}

bool Name::operator<=(const Name &n) {
    return *this < n || *this == n;
}

bool Name::operator>(const Name &n) {
    return !(*this <= n);
}

bool Name::operator>=(const Name &n) {
    return !(*this < n);
}

istream& operator >> (istream &is, Name &n) {
    string readingStr;

    getline(is, readingStr, '*'); // Apellidos
    n.lastName = QString::fromStdString(readingStr);

    getline(is, readingStr, '*'); // Nombre(s)
    n.firstName = QString::fromStdString(readingStr);

    return is;
}

ostream& operator << (ostream &os, const Name &n) {
    os << n.lastName.toStdString() << "*"
       << n.firstName.toStdString();

    return os;
}
