#pragma once
#include <string>
#include <QVector>
#include <QString>

using namespace std;

class FL {
private:
    int count;
    QString filename;
    QString filevar;
    QVector<QString> contents;

public:
    FL();
    FL(QString fname);
    void openfile(QString fname);
    void readfile(QString fname);
    int getcountss(QString fname);
    QString getfilename();
    QVector<QString>& getContents();
};

