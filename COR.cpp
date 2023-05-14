#include "COR.h"
COR::COR() {
    files.resize(0);
    totalcountoflines = 0;

}
COR::COR(int numFiles) {
    files.resize(numFiles);
    totalcountoflines = 0;
}

void COR::addFile(const string& filename, int index) {
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


string COR::getLineFromFile(int fileIndex, int lineIndex) {
    vector<string> allLines;  

    for (FL* file : files) {
        if (file) {
            vector<string> contents = file->getContents();
            allLines.insert(allLines.end(), contents.begin(), contents.end());
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



