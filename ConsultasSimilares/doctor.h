#ifndef DOCTOR_H
#define DOCTOR_H

#include <QTime>
#include <QString>

#include <string>
#include <fstream>

#include "name.h"

class Doctor {
private:
    QString code;
    QString cedule;
    Name name;
    QTime entryHour;
    QTime leaveHour;
public:
    Doctor();
    Doctor(const Doctor &d);

    QString getCode() const;
    QString getCedule() const;
    Name getName() const;
    QTime getEntryHour() const;
    QTime getLeaveHour() const;

    QString toString() const;

    void setCode(const QString &c);
    void setCedule(const QString &c);
    void setName(const Name &n);
    void setEntryHour(const QTime &eh);
    void setLeaveHour(const QTime &lh);

    Doctor& operator = (const Doctor &d);

    bool operator == (const Doctor &d);
    bool operator != (const Doctor &d);
    bool operator < (const Doctor &d);
    bool operator <= (const Doctor &d);
    bool operator > (const Doctor &d);
    bool operator >= (const Doctor &d);

    friend std::istream& operator >> (std::istream &is, Doctor &d);
    friend std::ostream& operator << (std::ostream &os, const Doctor &d);

    QString serialize();
    void deserialize(const QString &serial);
};

#endif // DOCTOR_H
