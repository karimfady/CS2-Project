#pragma once
#include <vector>
#include "FL.h"
#include <iostream>
using namespace std;
class COR{
private:
    vector<FL*> files;
    int totalcountoflines;

public:
    COR();
    COR(int numFiles);
    void addFile(const string& filename, int index);
    void readFiles();
    string getLineFromFile(int fileIndex, int lineIndex);
    int getSize();
    FL* getFile(int fileIndex);
};

