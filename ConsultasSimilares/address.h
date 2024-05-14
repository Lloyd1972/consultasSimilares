#ifndef ADDRESS_H
#define ADDRESS_H

#include <QString>

#include <fstream>

class Address {
private:
    QString street;
    QString number;
    QString postalCode;
    QString colony;
    QString town;
public:
    Address();
    Address(const Address &a);
    QString getStreet() const;
    QString getNumber() const;
    QString getPostalCode() const;
    QString getColony() const;
    QString getTown() const;

    QString toString() const;
    QString toComparingString() const;

    void setStreet(const QString &s);
    void setNumber(const QString &n);
    void setPostalCode(const QString &pc);
    void setColony(const QString &c);
    void setTown(const QString &t);

    Address& operator = (const Address &a);

    bool operator == (const Address &a);
    bool operator != (const Address &a);
    bool operator < (const Address &a);
    bool operator <= (const Address &a);
    bool operator > (const Address &a);
    bool operator >= (const Address &a);

    friend std::istream& operator >> (std::istream &is, Address &a);
    friend std::ostream& operator << (std::ostream &os, const Address &a);

    QString serialize();
    void deserialize(const QString &serial);
};

#endif // ADDRESS_H
