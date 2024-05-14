#ifndef DIAGNOSIS_H
#define DIAGNOSIS_H

#include <QString>

#include <string>
#include <fstream>

class Diagnosis {
private:
    QString code;
    QString description;
    QString indications;
public:
    Diagnosis();
    Diagnosis(const Diagnosis&d);

    QString getCode() const;
    QString getDescription() const;
    QString getIndications() const;

    QString toString() const;

    void setCode(const QString &c);
    void setDescription(const QString &d);
    void setIndications(const QString &i);

    Diagnosis& operator = (const Diagnosis &d);

    bool operator == (const Diagnosis &d);
    bool operator != (const Diagnosis &d);
    bool operator < (const Diagnosis &d);
    bool operator <= (const Diagnosis &d);
    bool operator > (const Diagnosis &d);
    bool operator >= (const Diagnosis &d);

    friend std::istream& operator >> (std::istream &is, Diagnosis &d);
    friend std::ostream& operator << (std::ostream &os, const Diagnosis &d);

    QString serialize();
    void deserialize(const QString &serial);
};

#endif // DIAGNOSIS_H
