#include "medicinefile.h"
using namespace std;

void MedicineFile::fileToList() {
    string readingStr;

    dataFile.clear();
    dataFile.seekg(0);
    while(dataFile.peek() != EOF) {
        getline(dataFile, readingStr, '#');
        if(readingStr.empty()) {
            continue;
        }

        stringstream ss(readingStr);
        Tuple<Medicine> data = sstringToTuple(ss);

        // Si el índice es válido, agregarlo a idxList
        if(data.getIndex() != -1) {
            idxList.push_back(data);
            QString code(data.getData().getCode());
            QString name(data.getData().getName());

            auto it = idxCodeList.begin();
            while (it != idxCodeList.end() && code > it->getData()) {
                ++it;
            }
            idxCodeList.insert(it, Tuple<QString>(data.getIndex(), code));

            auto itN = idxNameList.begin();
            while (itN != idxNameList.end() && name > itN->getData()) {
                ++itN;
            }
            idxNameList.insert(itN, Tuple<QString>(data.getIndex(), name));
        }
    }
}

void MedicineFile::listToFile() {
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
    // Iterar sobre la lista de medicamentos y escribir cada uno en el archivo
    for (const auto& it : idxList) {
        dataFile << "1*" << it << "#";
    }

    dataFile.close();
    dataFile.open(fileName, ios::in | ios::app);
}

Tuple<Medicine> MedicineFile::sstringToTuple(stringstream &ss) {
    string readingStr;
    Medicine data;

    getline(ss, readingStr, '*'); // Validador
    int validator(stoi(readingStr));

    if (validator == 0) {
        return Tuple<Medicine>(-1, Medicine());
    }

    getline(ss, readingStr, '*'); // Indice
    int index = stoi(readingStr);

    ss >> data;

    return Tuple<Medicine>(index, data);
}

MedicineFile::MedicineFile(const string &fName) : fileName(fName + ".data") {
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

MedicineFile::~MedicineFile() {
    reindex();
    dataFile.close();
}

void MedicineFile::setFileName(const string &fName) {
    fileName = fName + ".data";

    dataFile.close();
    dataFile.open(fileName, ios::in | ios::out);
}

bool MedicineFile::addRecord(const Medicine &m, QWidget *parent, const bool &import) {
    dataFile.clear();
    dataFile.seekp(0, ios::end);

    int pos(dataFile.tellp());
    Tuple<Medicine> tup(pos, m);
    QString code(m.getCode());
    QString name(m.getName());

    if(findRecordByName(name.toStdString()) != -1) {
        if(!import) {
            QMessageBox::warning(parent, "Advertencia", "¡Elemento repetido!");
        }
        return false;
    }
    QCoreApplication::processEvents();

    dataFile << "1*" << tup << "#";

    idxList.push_back(tup);

    auto it = idxCodeList.begin();
    while (it != idxCodeList.end() && code > it->getData()) {
        ++it;
    }
    idxCodeList.insert(it, Tuple<QString>(pos, code));

    auto itN = idxNameList.begin();
    while (itN != idxNameList.end() && name > itN->getData()) {
        ++itN;
    }
    idxNameList.insert(itN, Tuple<QString>(pos, name));

    return true;
}

void MedicineFile::modifyRecord(const Medicine &oldData, const Medicine &newData) {
    // Encontrar la posición de oldData en el archivo de datos
    int pos(findRecord(oldData));

    if (pos == -1) {
        return;
    }

    // Actualizar idxList con el nuevo registro
    for (auto it = idxList.begin(); it != idxList.end(); ++it) {
        if (it->getData() == oldData) {
            it->setData(newData);
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
        if (it->getData() == oldData.getName()) {
            it->setData(newData.getName());
            break;
        }
    }

    listToFile();
    reindex();
}

void MedicineFile::delRecord(const int &pos) {
    dataFile.close();
    dataFile.open(fileName, ios::in | ios::out);

    dataFile.seekp(pos);
    dataFile.seekp(0, ios::cur);
    dataFile << "0";
    Medicine data = retrieveRecord(pos);
    idxList.remove(Tuple<Medicine>(pos, data));
    idxCodeList.remove(Tuple<QString>(pos, data.getCode()));
    idxNameList.remove(Tuple<QString>(pos, data.getName()));

    dataFile.close();
    dataFile.open(fileName, ios::in | ios::app);
}

void MedicineFile::delRecord(const Medicine &data) {
    dataFile.close();
    dataFile.open(fileName, ios::in | ios::out);

    int pos = findRecord(data);

    dataFile.seekp(pos);
    dataFile << '0';
    idxList.remove(Tuple<Medicine>(pos, data));

    dataFile.close();
    dataFile.open(fileName, ios::in | ios::app);
}

int MedicineFile::findRecord(const Medicine &m) {
    // Realizamos una búsqueda binaria en idxCodeList
    auto begin = idxCodeList.begin();
    auto end = idxCodeList.end();

    while (begin != end) {
        auto mid = next(begin, distance(begin, end) / 2);
        if (mid->getData() == m.getCode()) {
            return mid->getIndex(); // Devolvemos la posición del registro
        } else if (mid->getData() < m.getCode()) {
            begin = next(mid);
        } else {
            end = mid;
        }
    }

    return -1; // Si no se encuentra, devolvemos -1
}

int MedicineFile::findRecord(const string &code) {
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

int MedicineFile::findRecordByName(const string &name) {
    // Realizamos una búsqueda binaria en idxCodeList
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

Medicine MedicineFile::retrieveRecord(const int &pos) {
    dataFile.clear();
    dataFile.seekp(pos, ios::beg); // Ir al principio de la posición establecida

    string readingStr;

    // Recupera una tupla completa
    getline(dataFile, readingStr, '#');

    if(readingStr.empty()){
        return Medicine();
    }

    stringstream ss(readingStr);
    getline(ss, readingStr, '*'); // Validador
    getline(ss, readingStr, '*'); // Indice
    getline(ss, readingStr, '*'); // Código
    QString code = QString::fromStdString(readingStr);
    getline(ss, readingStr, '*'); // Nombre
    QString name = QString::fromStdString(readingStr);
    return Medicine(code, name);
}

void MedicineFile::clearRecord() {
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

int MedicineFile::getSize() const {
    return idxList.size();
}

list<Tuple<Medicine>> MedicineFile::getList() {
    dataFile.clear();
    dataFile.seekg(0);

    string readingStr;
    list<Tuple<Medicine>> medList;

    while(dataFile.peek() != EOF) {
        getline(dataFile, readingStr, '#');
        stringstream ss(readingStr);
        Tuple<Medicine> tup(sstringToTuple(ss));
        medList.push_back(tup);
    }

    return medList;
}

void MedicineFile::reindex() {
    idxList.clear();
    idxCodeList.clear();
    idxNameList.clear();

    dataFile.clear();
    dataFile.seekp(0);

    string line;
    int pos(0);
    Tuple<Medicine> diagTuple;

    while (dataFile.peek() != EOF) {
        pos = dataFile.tellp();
        getline(dataFile, line, '#');

        stringstream ss(line);
        diagTuple = sstringToTuple(ss);
        if(diagTuple.getIndex() == -1) {
            continue;
        }
        QString code(diagTuple.getData().getCode());
        QString name(diagTuple.getData().getName());

        diagTuple.setIndex(pos);

        idxList.push_back(diagTuple);

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
