#pragma once
#include <QVector>
#include "FL.h"
#include <iostream>
#include <QString>
using namespace std;
class COR{
private:
    QVector<FL*> files;
    int totalcountoflines;

public:

    COR();
   void setNumOfFiles(int i);
    void addFile(QString& filename, int index);
    void readFiles();
    QString getLineFromFile( int lineIndex);
    int getSize();
    FL* getFile(int fileIndex);

};
