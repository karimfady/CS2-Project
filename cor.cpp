#include "COR.h"
#include <QVector>
COR::COR() {
    files.resize(0);
    totalcountoflines = 0;

}
void COR::setNumOfFiles(int i) {
    files.resize(i);
    totalcountoflines = 0;
}

void COR::addFile(QString& filename, int index) {
    FL* file = new FL(filename);
        file->readfile(file->getfilename());
      //  files[index] = file;
    files[index] = new FL(filename);

}

void COR::readFiles() {
    for (int i = 0; i < files.size(); ++i) {
        FL* file = files[i];
        if (file) {
            file->readfile(file->getfilename());

        }
    }
}


int COR::getSize() {
    int totalCount = 0;
    for (FL* file : files) {
        if (file) {
            totalCount += file->getcountss(file->getfilename());
        }
    }
    return totalCount;
}


QString COR::getLineFromFile(int lineIndex) {
    QVector<QString> allLines;

    for (FL* file : files) {
        if (file) {
            QVector<QString> contents = file->getContents();
            allLines.append(contents);///////////////////////////////////////////////
        }
    }

    if (lineIndex >= 0 && lineIndex < allLines.size()) {
        return allLines[lineIndex];
    }

    return "";
}

FL* COR::getFile(int fileIndex) {
    if (fileIndex >= 0 && fileIndex < files.size()) {
        return files[fileIndex];
    }
    return nullptr;
}


