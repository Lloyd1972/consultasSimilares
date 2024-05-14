#ifndef MEDICINE_H
#define MEDICINE_H

#include <QString>

#include <string>
#include <fstream>

class Medicine {
private:
    QString code;
    QString name;
public:
    Medicine();
    Medicine(const Medicine &m);
    Medicine(const QString &c, const QString &n);

    QString getCode() const;
    QString getName() const;

    QString toString() const;

    void setCode(const QString &c);
    void setName(const QString &n);

    Medicine& operator = (const Medicine &m);

    bool operator == (const Medicine &m);
    bool operator != (const Medicine &m);
    bool operator < (const Medicine &m);
    bool operator <= (const Medicine &m);
    bool operator > (const Medicine &m);
    bool operator >= (const Medicine &m);

    friend std::istream& operator >> (std::istream &is, Medicine &m);
    friend std::ostream& operator << (std::ostream &os, const Medicine &m);

    QString serialize();
    void deserialize(const QString &serial);
};

#endif // MEDICINE_H
