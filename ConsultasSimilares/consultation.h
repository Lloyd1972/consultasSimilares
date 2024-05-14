#ifndef CONSULTATION_H
#define CONSULTATION_H

#include <QDate>
#include <QTime>
#include <QString>

#include <fstream>

class Consultation {
private:
    QDate date;
    QTime hour;
    QString doctorCode;
    QString patientNSS;
    QString diagnosisCode;
    QString medicine1Code;
    QString medicine2Code;
    QString medicine3Code;
public:
    Consultation();
    Consultation(const Consultation &c);

    QDate getDate() const;
    QTime getHour() const;
    QString getDoctorCode() const;
    QString getPatientNSS() const;
    QString getDiagnosisCode() const;
    QString getMedicine1Code() const;
    QString getMedicine2Code() const;
    QString getMedicine3Code() const;

    QString toString() const;

    void setDate(const QDate &d);
    void setHour(const QTime &h);
    void setDoctorCode(const QString &dc);
    void setPatientNSS(const QString &pn);
    void setDiagnosisCode(const QString &dc);
    void setMedicine1Code(const QString &mc);
    void setMedicine2Code(const QString &mc);
    void setMedicine3Code(const QString &mc);

    Consultation& operator = (const Consultation &c);

    bool operator == (const Consultation &c);
    bool operator != (const Consultation &c);
    bool operator < (const Consultation &c);
    bool operator <= (const Consultation &c);
    bool operator > (const Consultation &c);
    bool operator >= (const Consultation &c);

    friend std::istream& operator >> (std::istream &is, Consultation &c);
    friend std::ostream& operator << (std::ostream &os, const Consultation &c);

    QString serialize();
    void deserialize(const QString &serial);
};

#endif // CONSULTATION_H
