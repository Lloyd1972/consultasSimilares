#include "consultationfile.h"
using namespace std;

void ConsultationFile::fileToList() {
    string readingStr;

    dataFile.clear();
    dataFile.seekg(0);
    while(dataFile.peek() != EOF) {
        getline(dataFile, readingStr, '#');
        if(readingStr.empty()) {
            continue;
        }

        stringstream ss(readingStr);
        Tuple<Consultation> data = sstringToTuple(ss);

        // Si el índice es válido, agregarlo a idxList
        if(data.getIndex() != -1) {
            idxList.push_back(data);
        }
    }
}

void ConsultationFile::listToFile() {
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

    // Iterar sobre la lista de consultas y escribir cada uno en el archivo
    for (const auto &it : idxList) {
        dataFile << "1*" << it
                 << it.getData().getDoctorCode().toStdString() << "*"
                 << it.getData().getPatientNSS().toStdString() << "*"
                 << it.getData().getDiagnosisCode().toStdString() << "*"
                 << it.getData().getMedicine1Code().toStdString() << "*"
                 << it.getData().getMedicine2Code().toStdString() << "*"
                 << it.getData().getMedicine3Code().toStdString() << "#";
    }

    dataFile.close();
    dataFile.open(fileName, ios::in | ios::app);
}

Tuple<Consultation> ConsultationFile::sstringToTuple(stringstream &ss) {
    string readingStr;
    Consultation data;

    getline(ss, readingStr, '*'); // Validador
    int validator(stoi(readingStr));

    if (validator == 0) {
        return Tuple<Consultation>(-1, Consultation());
    }

    getline(ss, readingStr, '*'); // Indice
    int index = stoi(readingStr);

    ss >> data;

    getline(ss, readingStr, '*');
    data.setDoctorCode(QString::fromStdString(readingStr)); // Código del doctor

    getline(ss, readingStr, '*');
    data.setPatientNSS(QString::fromStdString(readingStr)); // NSS del paciente

    getline(ss, readingStr, '*');
    data.setDiagnosisCode(QString::fromStdString(readingStr)); // Código del diágnostico

    getline(ss, readingStr, '*');
    data.setMedicine1Code(QString::fromStdString(readingStr)); // Código del medicamento 1

    getline(ss, readingStr, '*');
    data.setMedicine2Code(QString::fromStdString(readingStr)); // Código del medicamento 2

    getline(ss, readingStr);
    data.setMedicine3Code(QString::fromStdString(readingStr)); // Código del medicamento 3

    return Tuple<Consultation>(index, data);
}

ConsultationFile::ConsultationFile(const string &fName) : fileName(fName + ".data") {
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

ConsultationFile::~ConsultationFile() {
    reindex();
    dataFile.close();
}

void ConsultationFile::setFileName(const string &fName) {
    fileName = fName + ".data";

    dataFile.close();
    dataFile.open(fileName, ios::in | ios::out);
}

bool ConsultationFile::addRecord(const Consultation &d, QWidget *parent, const bool &import) {
    dataFile.clear();
    dataFile.seekp(0, ios::end);

    int pos(dataFile.tellp());
    Tuple<Consultation> tup(pos, d);

    dataFile << "1*" << tup
             << d.getDoctorCode().toStdString() << "*"
             << d.getPatientNSS().toStdString() << "*"
             << d.getDiagnosisCode().toStdString() << "*"
             << d.getMedicine1Code().toStdString() << "*"
             << d.getMedicine2Code().toStdString() << "*"
             << d.getMedicine3Code().toStdString() << "#";

    idxList.push_back(tup);
    return true;
}

void ConsultationFile::modifyRecord(const Consultation &oldData, const Consultation &newData) {
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
            return;
        }
        QCoreApplication::processEvents();
    }
}

void ConsultationFile::delRecord(const int &pos) {
    dataFile.close();
    dataFile.open(fileName, ios::in | ios::out);

    dataFile.seekp(pos);
    dataFile.seekp(0, ios::cur);
    dataFile << "0";
    idxList.remove(Tuple<Consultation>(pos, retrieveRecord(pos)));

    dataFile.close();
    dataFile.open(fileName, ios::in | ios::app);
}

void ConsultationFile::delRecord(const Consultation &data) {
    dataFile.close();
    dataFile.open(fileName, ios::in | ios::out);

    int pos = findRecord(data);

    dataFile.seekp(pos);
    dataFile << '0';
    idxList.remove(Tuple<Consultation>(pos, data));

    dataFile.close();
    dataFile.open(fileName, ios::in | ios::app);
}

int ConsultationFile::findRecord(const Consultation &c) {
    // Buscamos el registro en el índice por código
    for (const auto &tuple : idxList) {
        if (tuple.getData() == c) {
            return tuple.getIndex(); // Devolvemos la posición del registro
        }
    }
    return -1; // Si no se encuentra, devolvemos -1
}

int ConsultationFile::findRecord(const string &code) {
    return -1;
}

int ConsultationFile::findRecordByName(const string &name) {
    return -1;
}

Consultation ConsultationFile::retrieveRecord(const int &pos) {
    dataFile.clear();
    dataFile.seekp(pos, ios::beg); // Ir al principio de la posición establecida

    string readingStr;

    // Recupera una tupla completa
    getline(dataFile, readingStr, '#');

    if(readingStr.empty()){
        return Consultation();
    }

    Tuple<Consultation> tup;

    stringstream ss(readingStr);

    tup = sstringToTuple(ss);

    return tup.getData();
}

void ConsultationFile::clearRecord() {
    // Limpiamos todos los registros del archivo de datos
    dataFile.close();
    ofstream clearFile(fileName, ios::trunc);
    clearFile.close();
    dataFile.open(fileName, ios::in | ios::app | ios::binary);

    // Limpiamos las listas
    idxList.clear();
}

int ConsultationFile::getSize() const {
    return idxList.size();
}

list<Tuple<Consultation>> ConsultationFile::getList() {
    return idxList;
}

int ConsultationFile::getLastIndex() const {
    return idxList.back().getIndex();
}

void ConsultationFile::reindex() {
    idxList.clear();

    dataFile.clear();
    dataFile.seekp(0);

    string line;
    int pos(0);
    Tuple<Consultation> consTuple;

    while (dataFile.peek() != EOF) {
        pos = dataFile.tellp();
        getline(dataFile, line, '#');

        stringstream ss(line);
        consTuple = sstringToTuple(ss);
        if(consTuple.getIndex() == -1) {
            continue;
        }

        consTuple.setIndex(pos);

        idxList.push_back(consTuple);
    }

    listToFile();
}
