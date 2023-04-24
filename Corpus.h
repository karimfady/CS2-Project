#pragma once
#include"File.h"
using namespace std;
class Corpus {
protected:
    File* files;
    int numofiles;
public:
    Corpus(int n);
    void addfile(string fname, int i);
    void readfiles();
    string readline(string fname);
};