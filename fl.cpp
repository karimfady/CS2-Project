
#include <iostream>
#include <fstream>
#include <string>
#include <QFile>
#include "FL.h"
#include <QTextStream>
using namespace std;

FL::FL() {
    count = 0;
    filename = "";
    filevar = "test";
}

FL::FL(QString fname) {
    count = 0;
    filename = fname;
    filevar = "test";
}

void FL::openfile(QString fname) {
    filevar = fname;
}

void FL::readfile(QString fname) {
    openfile(fname);
    QFile file(filevar);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        cout << "Error opening file: " << fname.toStdString() << endl;
        return;
    }
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        contents.push_back(line);
    }

    file.close();
}

int FL::getcountss(QString filenames) {
    return contents.size();
}

QString FL::getfilename() {
    return filename;
}

QVector<QString>& FL::getContents() {
    return contents;
}
