#ifndef NAME_H
#define NAME_H

#include <QString>

#include <string>
#include <fstream>

class Name {
private:
    QString lastName;
    QString firstName;
public:
    Name();
    Name(const Name &n);
    Name(const QString &last, const QString &first);

    QString getLast() const;
    QString getFirst() const;

    QString toString() const;

    void setLast(const QString &last);
    void setFirst(const QString &first);

    Name& operator = (const Name &n);

    bool operator == (const Name &n);
    bool operator != (const Name &n);
    bool operator < (const Name &n);
    bool operator <= (const Name &n);
    bool operator > (const Name &n);
    bool operator >= (const Name &n);

    friend std::istream& operator >> (std::istream &is, Name &n);
    friend std::ostream& operator << (std::ostream &os, const Name &n);

    QString serialize();
    void deserialize(const QString &serial);
};

#endif // NAME_H
