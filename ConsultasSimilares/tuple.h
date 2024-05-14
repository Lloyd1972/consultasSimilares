#ifndef TUPLE_H
#define TUPLE_H

#include <sstream>
#include <fstream>

template <class T>
class Tuple {
private:
    int index;
    T data;
public:
    Tuple();
    Tuple(const Tuple &t);
    Tuple(const int &idx, const T &d);

    int getIndex() const;
    T getData() const;

    void setIndex(const int &idx);
    void setData(const T &d);

    Tuple& operator = (const Tuple &t);

    bool operator == (const Tuple &t);
    bool operator != (const Tuple &t);
    bool operator < (const Tuple &t);
    bool operator <= (const Tuple &t);
    bool operator > (const Tuple &t);
    bool operator >= (const Tuple &t);

    bool operator == (const T &t);
    bool operator != (const T &t);
    bool operator < (const T &t);
    bool operator <= (const T &t);
    bool operator > (const T &t);
    bool operator >= (const T &t);

    // friend std::ostream& operator << (std::ostream &os, const Tuple<T> &t);
    // friend std::istream& operator >> (std::istream &is, Tuple<T> &t);
};

#endif // TUPLE_H

using namespace std;

template <class T>
Tuple<T>::Tuple() : index(-1), data(T()) { }

template <class T>
Tuple<T>::Tuple(const Tuple &t) : index(t.index), data(t.data) { }

template <class T>
Tuple<T>::Tuple(const int &i, const T &d) : index(i), data(d) { }

template <class T>
int Tuple<T>::getIndex() const {
    return index;
}

template <class T>
T Tuple<T>::getData() const {
    return data;
}

template <class T>
void Tuple<T>::setIndex(const int &idx) {
    index = idx;
}

template <class T>
void Tuple<T>::setData(const T &d) {
    data = d;
}

template <class T>
Tuple<T>& Tuple<T>::operator=(const Tuple &t) {
    index = t.index;
    data = t.data;

    return *this;
}

template <class T>
bool Tuple<T>::operator==(const Tuple &t) {
    return index == t.index;
}

template <class T>
bool Tuple<T>::operator!=(const Tuple &t) {
    return !(*this == t);
}

template <class T>
bool Tuple<T>::operator<(const Tuple &t) {
    return index < t.index;
}

template <class T>
bool Tuple<T>::operator<=(const Tuple &t) {
    return index < t.index || index == t.index;
}

template <class T>
bool Tuple<T>::operator>(const Tuple &t) {
    return !(*this <= t);
}

template <class T>
bool Tuple<T>::operator>=(const Tuple &t) {
    return !(*this < t);
}

template <class T>
bool Tuple<T>::operator==(const T &t) {
    return data == t;
}

template <class T>
bool Tuple<T>::operator!=(const T &t) {
    return data != t;
}

template <class T>
bool Tuple<T>::operator<(const T &t) {
    return data < t;
}

template <class T>
bool Tuple<T>::operator<=(const T &t) {
    return data < t || data == t;
}

template <class T>
bool Tuple<T>::operator>(const T &t) {
    return data > t;
}

template <class T>
bool Tuple<T>::operator>=(const T &t) {
    return data >= t;
}

template <typename T>
std::ostream& operator << (std::ostream &os, const Tuple<T> &t) {
    os << t.getIndex() << "*"
       << t.getData();

    return os;
}

template <typename T>
std::istream& operator >> (std::istream &is, Tuple<T> &t) {
    std::string readingStr;

    // Recupera una tupla completa
    getline(is, readingStr, '#');
    if(readingStr.empty()){
        return is;
    }

    std::stringstream ss(readingStr);

    // Divide la tupla encontrada en partes
    getline(ss, readingStr, '*');
    t.index = stoi(readingStr);

    ss >> t.data;

    return is;
}
