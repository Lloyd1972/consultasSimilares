#include "patientfile.h"
using namespace std;

void PatientFile::fileToList() {
    string readingStr;

    dataFile.clear();
    dataFile.seekg(0);
    while(dataFile.peek() != EOF) {
        getline(dataFile, readingStr, '#');
        if(readingStr.empty()) {
            continue;
        }

        stringstream ss(readingStr);
        Tuple<Patient> data = sstringToTuple(ss);

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

void PatientFile::listToFile() {
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

Tuple<Patient> PatientFile::sstringToTuple(stringstream &ss) {
    string readingStr;
    Patient data;

    getline(ss, readingStr, '*'); // Validador
    int validator(stoi(readingStr));

    if (validator == 0) {
        return Tuple<Patient>(-1, Patient());
    }

    getline(ss, readingStr, '*'); // Indice
    int index = stoi(readingStr);

    ss >> data;

    return Tuple<Patient>(index, data);
}

PatientFile::PatientFile(const string&fName) : fileName(fName + ".data") {
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

PatientFile::~PatientFile() {
    reindex();
    dataFile.close();
}

void PatientFile::setFileName(const string &fName) {
    fileName = fName + ".data";

    dataFile.close();
    dataFile.open(fileName, ios::in | ios::out);
}

bool PatientFile::addRecord(const Patient &p, QWidget *parent, const bool &import) {
    dataFile.clear();
    dataFile.seekp(0, ios::end);

    int pos(dataFile.tellp());
    Tuple<Patient> tup(pos, p);
    QString code(p.getCode());
    QString name(p.getName().toString());

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

void PatientFile::modifyRecord(const Patient &oldData, const Patient &newData) {
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

void PatientFile::delRecord(const int &pos) {
    dataFile.close();
    dataFile.open(fileName, ios::in | ios::out);

    dataFile.seekp(pos);
    dataFile.seekp(0, ios::cur);
    dataFile << "0";
    Patient data = retrieveRecord(pos);
    idxList.remove(Tuple<Patient>(pos, data));
    idxCodeList.remove(Tuple<QString>(pos, data.getCode()));
    idxNameList.remove(Tuple<QString>(pos, data.getName().toString()));

    dataFile.close();
    dataFile.open(fileName, ios::in | ios::app);
}

void PatientFile::delRecord(const Patient &data) {
    dataFile.close();
    dataFile.open(fileName, ios::in | ios::out);

    int pos = findRecord(data);

    dataFile.seekp(pos);
    dataFile << '0';
    idxList.remove(Tuple<Patient>(pos, data));
    idxCodeList.remove(Tuple<QString>(pos, data.getCode()));
    idxNameList.remove(Tuple<QString>(pos, data.getName().toString()));

    dataFile.close();
    dataFile.open(fileName, ios::in | ios::app);
}

int PatientFile::findRecord(const Patient &p) {
    // Realizamos una búsqueda binaria en idxCodeList
    auto begin = idxCodeList.begin();
    auto end = idxCodeList.end();

    while (begin != end) {
        auto mid = next(begin, distance(begin, end) / 2);
        if (mid->getData() == p.getCode()) {
            return mid->getIndex(); // Devolvemos la posición del registro
        } else if (mid->getData() < p.getCode()) {
            begin = next(mid);
        } else {
            end = mid;
        }
    }

    return -1; // Si no se encuentra, devolvemos -1
}

int PatientFile::findRecord(const string &code) {
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

int PatientFile::findRecordByName(const string &name) {
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

Patient PatientFile::retrieveRecord(const int &pos) {
    dataFile.clear();
    dataFile.seekp(pos, ios::beg); // Ir al principio de la posición establecida

    string readingStr;

    // Recupera una tupla completa
    getline(dataFile, readingStr, '#');

    if(readingStr.empty()){
        return Patient();
    }

    Patient data;

    stringstream ss(readingStr);
    getline(ss, readingStr, '*'); // Validador
    getline(ss, readingStr, '*'); // Indice
    ss >> data;

    return data;
}

void PatientFile::clearRecord() {
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

int PatientFile::getSize() const {
    return idxList.size();
}

list<Tuple<Patient>> PatientFile::getList() {
    dataFile.clear();
    dataFile.seekg(0);

    string readingStr;
    list<Tuple<Patient>> patList;

    while(dataFile.peek() != EOF) {
        getline(dataFile, readingStr, '#');
        stringstream ss(readingStr);
        Tuple<Patient> tup(sstringToTuple(ss));
        patList.push_back(tup);
    }

    return patList;
}

void PatientFile::reindex() {
    idxList.clear();
    idxCodeList.clear();
    idxNameList.clear();

    dataFile.clear();
    dataFile.seekp(0);

    string line;
    int pos(0);
    Tuple<Patient> docTuple;

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
