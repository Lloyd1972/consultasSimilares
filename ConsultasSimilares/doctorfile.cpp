#include "doctorfile.h"
using namespace std;

void DoctorFile::fileToList() {
    string readingStr;

    dataFile.clear();
    dataFile.seekg(0);
    while(dataFile.peek() != EOF) {
        getline(dataFile, readingStr, '#');
        if(readingStr.empty()) {
            continue;
        }

        stringstream ss(readingStr);
        Tuple<Doctor> data = sstringToTuple(ss);

        // Si el índice es válido, agregarlo a idxList
        if(data.getIndex() != -1) {
            idxList.push_back(data);
            QString code(data.getData().getCode());
            QString name(data.getData().getName().toString());

            auto it = idxCodeList.begin();
            while (it != idxCodeList.end() && code > it->getData()) {
                ++it;
            }
            idxCodeList.insert(it, Tuple<QString>(data.getIndex(), code));

            auto itName = idxNameList.begin();
            while(itName != idxNameList.end() && name > itName->getData()) {
                ++itName;
            }
            idxNameList.insert(itName, Tuple<QString>(data.getIndex(), name));
        }
    }
}

void DoctorFile::listToFile() {
    // Reiniciar el puntero de lectura/escritura al inicio del archivo
    dataFile.close();
    dataFile.open(fileName, ios::out | ios::trunc);

    if(!dataFile.is_open()) {
        dataFile.close();
        dataFile.open(fileName, ios::in | ios::app);
        return;
    }

    dataFile.clear();
    dataFile.seekg(0);
    // Iterar sobre la lista de diágnosticos y escribir cada uno en el archivo
    for (const auto &it : idxList) {
        dataFile << "1*" << it << "#";
    }

    dataFile.close();
    dataFile.open(fileName, ios::in | ios::app);
}

Tuple<Doctor> DoctorFile::sstringToTuple(stringstream &ss) {
    string readingStr;
    Doctor data;

    getline(ss, readingStr, '*'); // Validador
    int validator(stoi(readingStr));

    if (validator == 0) {
        return Tuple<Doctor>(-1, Doctor());
    }

    getline(ss, readingStr, '*'); // Indice
    int index = stoi(readingStr);

    ss >> data;

    return Tuple<Doctor>(index, data);
}

DoctorFile::DoctorFile(const string&fName) : fileName(fName + ".data") {
    // Abrimos el archivo de datos en modo de lectura y escritura
    dataFile.open(fileName, ios::in | ios::app);

    // Si el archivo no existe, lo creamos
    if (!dataFile) {
        dataFile.open(fileName, ios::app);
        dataFile.close();
        dataFile.open(fileName, ios::in | ios::app);
    }

    fileToList();
    if (!dataFile.is_open()) {
        reindex();
    }
}

DoctorFile::~DoctorFile() {
    reindex();
    dataFile.close();
}

void DoctorFile::setFileName(const string &fName) {
    fileName = fName + ".data";

    dataFile.close();
    dataFile.open(fileName, ios::in | ios::out);
}

bool DoctorFile::addRecord(const Doctor &d, QWidget *parent, const bool &import) {
    dataFile.clear();
    dataFile.seekp(0, ios::end);

    int pos(dataFile.tellp());
    Tuple<Doctor> tup(pos, d);
    QString code(d.getCode());
    QString name(d.getName().toString());

    if(findRecord(code.toStdString()) != -1) {
        if(!import) {
            QMessageBox::warning(parent, "Advertencia", "¡Elemento repetido!");
        }
        return false;
    }

    dataFile << "1*" << tup << "#";

    idxList.push_back(tup);

    auto it = idxCodeList.begin();
    while (it != idxCodeList.end() && code > it->getData()) {
        ++it;
    }
    idxCodeList.insert(it, Tuple<QString>(pos, code));

    auto itName = idxNameList.begin();
    while(itName != idxNameList.end() && name > itName->getData()) {
        ++itName;
    }
    idxNameList.insert(itName, Tuple<QString>(pos, name));

    return true;
}

void DoctorFile::modifyRecord(const Doctor &oldData, const Doctor &newData) {
    // Encontrar la posición de oldData en el archivo de datos
    int pos = findRecord(oldData);

    if (pos == -1) {
        return;
    }

    // Actualizar idxList con el nuevo registro
    for (auto it = idxList.begin(); it != idxList.end(); ++it) {
        if (it->getData() == oldData) {
            it->setData(newData);

            listToFile();
            reindex();
            break;
        }
    }

    for (auto it = idxCodeList.begin(); it != idxCodeList.end(); ++it) {
        if (it->getData() == oldData.getCode()) {
            it->setData(newData.getCode());
            break;
        }
    }

    for (auto it = idxNameList.begin(); it != idxNameList.end(); ++it) {
        if (it->getData() == oldData.getName().toString()) {
            it->setData(newData.getName().toString());
            break;
        }
    }

    listToFile();
    reindex();
}

void DoctorFile::delRecord(const int &pos) {
    dataFile.close();
    dataFile.open(fileName, ios::in | ios::out);

    dataFile.seekp(pos);
    dataFile.seekp(0, ios::cur);
    dataFile << "0";
    Doctor data = retrieveRecord(pos);
    idxList.remove(Tuple<Doctor>(pos, data));
    idxCodeList.remove(Tuple<QString>(pos, data.getCode()));
    idxNameList.remove(Tuple<QString>(pos, data.getName().toString()));

    dataFile.close();
    dataFile.open(fileName, ios::in | ios::app);
}

void DoctorFile::delRecord(const Doctor &data) {
    dataFile.close();
    dataFile.open(fileName, ios::in | ios::out);

    int pos = findRecord(data);

    dataFile.seekp(pos);
    dataFile << '0';
    idxList.remove(Tuple<Doctor>(pos, data));
    idxCodeList.remove(Tuple<QString>(pos, data.getCode()));
    idxNameList.remove(Tuple<QString>(pos, data.getName().toString()));

    dataFile.close();
    dataFile.open(fileName, ios::in | ios::app);
}

int DoctorFile::findRecord(const Doctor &d) {
    // Realizamos una búsqueda binaria en idxCodeList
    auto begin = idxCodeList.begin();
    auto end = idxCodeList.end();

    while (begin != end) {
        auto mid = next(begin, distance(begin, end) / 2);
        if (mid->getData() == d.getCode()) {
            return mid->getIndex(); // Devolvemos la posición del registro
        } else if (mid->getData() < d.getCode()) {
            begin = next(mid);
        } else {
            end = mid;
        }
    }

    return -1; // Si no se encuentra, devolvemos -1
}

int DoctorFile::findRecord(const string &code) {
    // Realizamos una búsqueda binaria en idxCodeList
    auto begin = idxCodeList.begin();
    auto end = idxCodeList.end();

    while (begin != end) {
        auto mid = next(begin, distance(begin, end) / 2);
        if (mid->getData().toStdString() == code) {
            return mid->getIndex(); // Devolvemos la posición del registro
        } else if (mid->getData().toStdString() < code) {
            begin = next(mid);
        } else {
            end = mid;
        }
    }

    return -1; // Si no se encuentra, devolvemos -1
}

int DoctorFile::findRecordByName(const string &name) {
    // Realizamos una búsqueda binaria en idxNameList
    auto begin = idxNameList.begin();
    auto end = idxNameList.end();

    while (begin != end) {
        auto mid = next(begin, distance(begin, end) / 2);
        if (mid->getData().toStdString() == name) {
            return mid->getIndex(); // Devolvemos la posición del registro
        } else if (mid->getData().toStdString() < name) {
            begin = next(mid);
        } else {
            end = mid;
        }
    }

    return -1; // Si no se encuentra, devolvemos -1
}

Doctor DoctorFile::retrieveRecord(const int &pos) {
    dataFile.clear();
    dataFile.seekp(pos, ios::beg); // Ir al principio de la posición establecida

    string readingStr;

    // Recupera una tupla completa
    getline(dataFile, readingStr, '#');

    if(readingStr.empty()){
        return Doctor();
    }

    Tuple<Doctor> tup;

    stringstream ss(readingStr);

    tup = sstringToTuple(ss);

    return tup.getData();
}

void DoctorFile::clearRecord() {
    // Limpiamos todos los registros del archivo de datos
    dataFile.close();
    ofstream clearFile(fileName, ios::trunc);
    clearFile.close();
    dataFile.open(fileName, ios::in | ios::app | ios::binary);

    // Limpiamos las listas
    idxList.clear();
    idxCodeList.clear();
    idxNameList.clear();
}

int DoctorFile::getSize() const {
    return idxList.size();
}

list<Tuple<Doctor>> DoctorFile::getList() {
    dataFile.clear();
    dataFile.seekg(0);

    string readingStr;
    list<Tuple<Doctor>> docList;

    while(dataFile.peek() != EOF) {
        getline(dataFile, readingStr, '#');
        stringstream ss(readingStr);
        Tuple<Doctor> tup(sstringToTuple(ss));
        docList.push_back(tup);
    }

    return docList;
}

void DoctorFile::reindex() {
    idxList.clear();
    idxCodeList.clear();
    idxNameList.clear();

    dataFile.clear();
    dataFile.seekp(0);

    string line;
    int pos(0);
    Tuple<Doctor> docTuple;

    while (dataFile.peek() != EOF) {
        pos = dataFile.tellp();
        getline(dataFile, line, '#');

        stringstream ss(line);
        docTuple = sstringToTuple(ss);
        if(docTuple.getIndex() == -1) {
            continue;
        }
        QString code(docTuple.getData().getCode());
        QString name(docTuple.getData().getName().toString());

        docTuple.setIndex(pos);

        idxList.push_back(docTuple);

        auto it = idxCodeList.begin();
        while (it != idxCodeList.end() && code > it->getData()) {
            ++it;
        }
        idxCodeList.insert(it, Tuple<QString>(pos, code));

        auto itName = idxNameList.begin();
        while(itName != idxNameList.end() && name > itName->getData()) {
            ++itName;
        }
        idxNameList.insert(itName, Tuple<QString>(pos, name));
    }

    listToFile();
}
