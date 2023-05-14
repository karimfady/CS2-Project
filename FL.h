#pragma once
#include <string>
#include <vector>

using namespace std;

class FL {
private:
    int count;
    string filename;
    string filevar;
    vector<string> contents;

public:
    FL();
    FL(string fname);
    void openfile(string fname);
    void readfile(string fname);
    int getcountss(string fname);
    string getfilename();
    vector<string>& getContents();
};



