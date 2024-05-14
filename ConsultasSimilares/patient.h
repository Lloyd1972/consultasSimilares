#ifndef PATIENT_H
#define PATIENT_H

#include <QString>
#include <QDate>

#include <string>
#include <fstream>

#include "address.h"
#include "name.h"

class Patient {
private:
    QString nss;
    Name name;
    QDate birthDate;
    Address address;
    QString phone;
public:
    Patient();
    Patient(const Patient &p);

    QString getCode() const;
    Name getName() const;
    QDate getBirthDate() const;
    Address getAddress() const;
    QString getPhone() const;

    QString toString() const;

    void setCode(const QString &n);
    void setName(const Name &n);
    void setBirthDate(const QDate &bd);
    void setAddress(const Address &a);
    void setPhone(const QString &p);

    Patient& operator = (const Patient &p);

    bool operator == (const Patient &p);
    bool operator != (const Patient &p);
    bool operator < (const Patient &p);
    bool operator <= (const Patient &p);
    bool operator > (const Patient &p);
    bool operator >= (const Patient &p);

    friend std::istream& operator >> (std::istream &is, Patient &p);
    friend std::ostream& operator << (std::ostream &os, const Patient &p);

    QString serialize();
    void deserialize(const QString &serial);
};

#endif // PATIENT_H
