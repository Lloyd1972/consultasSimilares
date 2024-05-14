#include "diagnosisfile.h"
using namespace std;

void DiagnosisFile::fileToList() {
    string readingStr;

    dataFile.clear();
    dataFile.seekg(0);
    while(dataFile.peek() != EOF) {
        getline(dataFile, readingStr, '#');
        if(readingStr.empty()) {
            continue;
        }

        stringstream ss(readingStr);
        Tuple<Diagnosis> data = sstringToTuple(ss);

        // Si el índice es válido, agregarlo a idxList
        if(data.getIndex() != -1) {
            idxList.push_back(data);
            QString code(data.getData().getCode());
            QString desc(data.getData().getDescription());

            auto it = idxCodeList.begin();
            while (it != idxCodeList.end() && code > it->getData()) {
                ++it;
            }
            idxCodeList.insert(it, Tuple<QString>(data.getIndex(), code));

            auto itDesc = idxDescList.begin();
            while(itDesc != idxDescList.end() && desc > itDesc->getData()) {
                ++itDesc;
            }
            idxDescList.insert(itDesc, Tuple<QString>(data.getIndex(), desc));
        }
    }
}

void DiagnosisFile::listToFile() {
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

Tuple<Diagnosis> DiagnosisFile::sstringToTuple(stringstream &ss) {
    string readingStr;
    Diagnosis data;

    getline(ss, readingStr, '*'); // Validador
    int validator(stoi(readingStr));

    if (validator == 0) {
        return Tuple<Diagnosis>(-1, Diagnosis());
    }

    getline(ss, readingStr, '*'); // Indice
    int index = stoi(readingStr);

    ss >> data;

    return Tuple<Diagnosis>(index, data);
}

DiagnosisFile::DiagnosisFile(const string &fName) : fileName(fName + ".data") {
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

DiagnosisFile::~DiagnosisFile() {
    reindex();
    dataFile.close();
}

void DiagnosisFile::setFileName(const string &fName) {
    fileName = fName + ".data";

    dataFile.close();
    dataFile.open(fileName, ios::in | ios::out);
}

bool DiagnosisFile::addRecord(const Diagnosis &d, QWidget* parent, const bool &import) {
    dataFile.clear();
    dataFile.seekp(0, ios::end);

    int pos(dataFile.tellp());
    Tuple<Diagnosis> tup(pos, d);
    QString code(d.getCode());
    QString desc(d.getDescription());

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

    auto itDesc = idxDescList.begin();
    while(itDesc != idxDescList.end() && desc > itDesc->getData()) {
        ++itDesc;
    }
    idxDescList.insert(itDesc, Tuple<QString>(pos, desc));

    return true;
}

void DiagnosisFile::modifyRecord(const Diagnosis &oldData, const Diagnosis &newData) {
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

    for (auto it = idxDescList.begin(); it != idxDescList.end(); ++it) {
        if (it->getData() == oldData.getDescription()) {
            it->setData(newData.getDescription());
            break;
        }
    }

    listToFile();
    reindex();
}

void DiagnosisFile::delRecord(const int &pos) {
    dataFile.close();
    dataFile.open(fileName, ios::in | ios::out);

    dataFile.seekp(pos);
    dataFile.seekp(0, ios::cur);
    dataFile << "0";
    Diagnosis data = retrieveRecord(pos);
    idxList.remove(Tuple<Diagnosis>(pos, data));
    idxCodeList.remove(Tuple<QString>(pos, data.getCode()));
    idxDescList.remove(Tuple<QString>(pos, data.getDescription()));

    dataFile.close();
    dataFile.open(fileName, ios::in | ios::app);
}

void DiagnosisFile::delRecord(const Diagnosis &data) {
    dataFile.close();
    dataFile.open(fileName, ios::in | ios::out);

    int pos = findRecord(data);

    dataFile.seekp(pos);
    dataFile << '0';
    idxList.remove(Tuple<Diagnosis>(pos, data));
    idxCodeList.remove(Tuple<QString>(pos, data.getCode()));
    idxDescList.remove(Tuple<QString>(pos, data.getDescription()));

    dataFile.close();
    dataFile.open(fileName, ios::in | ios::app);
}

int DiagnosisFile::findRecord(const Diagnosis &d) {
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

int DiagnosisFile::findRecord(const string &code) {
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


int DiagnosisFile::findRecordByName(const string &desc) {
    // Realizamos una búsqueda binaria en idxDescList
    auto begin = idxDescList.begin();
    auto end = idxDescList.end();

    while (begin != end) {
        auto mid = next(begin, distance(begin, end) / 2);
        if (mid->getData().toStdString() == desc) {
            return mid->getIndex(); // Devolvemos la posición del registro
        } else if (mid->getData().toStdString() < desc) {
            begin = next(mid);
        } else {
            end = mid;
        }
    }

    return -1; // Si no se encuentra, devolvemos -1
}

Diagnosis DiagnosisFile::retrieveRecord(const int &pos) {
    dataFile.clear();
    dataFile.seekp(pos, ios::beg); // Ir al principio de la posición establecida

    string readingStr;

    // Recupera una tupla completa
    getline(dataFile, readingStr, '#');

    if(readingStr.empty()){
        return Diagnosis();
    }

    Tuple<Diagnosis> tup;

    stringstream ss(readingStr);

    tup = sstringToTuple(ss);

    return tup.getData();
}

void DiagnosisFile::clearRecord() {
    // Limpiamos todos los registros del archivo de datos
    dataFile.close();
    ofstream clearFile(fileName, ios::trunc);
    clearFile.close();
    dataFile.open(fileName, ios::in | ios::app | ios::binary);

    // Limpiamos las listas
    idxList.clear();
    idxCodeList.clear();
    idxDescList.clear();
}

int DiagnosisFile::getSize() const {
    return idxCodeList.size();
}

list<Tuple<Diagnosis>> DiagnosisFile::getList() {
    dataFile.clear();
    dataFile.seekg(0);

    string readingStr;
    list<Tuple<Diagnosis>> diagList;

    while(dataFile.peek() != EOF) {
        getline(dataFile, readingStr, '#');
        stringstream ss(readingStr);
        Tuple<Diagnosis> tup(sstringToTuple(ss));
        diagList.push_back(tup);
    }

    return diagList;
}

void DiagnosisFile::reindex() {
    idxList.clear();
    idxCodeList.clear();
    idxDescList.clear();

    dataFile.clear();
    dataFile.seekp(0);

    string line;
    int pos(0);
    Tuple<Diagnosis> diagTuple;

    while (dataFile.peek() != EOF) {
        pos = dataFile.tellp();
        getline(dataFile, line, '#');

        stringstream ss(line);
        diagTuple = sstringToTuple(ss);
        if(diagTuple.getIndex() == -1) {
            continue;
        }
        QString code(diagTuple.getData().getCode());
        QString desc(diagTuple.getData().getDescription());

        diagTuple.setIndex(pos);

        idxList.push_back(diagTuple);

        auto it = idxCodeList.begin();
        while (it != idxCodeList.end() && code > it->getData()) {
            ++it;
        }
        idxCodeList.insert(it, Tuple<QString>(pos, code));

        auto itName = idxDescList.begin();
        while(itName != idxDescList.end() && desc > itName->getData()) {
            ++itName;
        }
        idxDescList.insert(itName, Tuple<QString>(pos, desc));
    }

    listToFile();
}
