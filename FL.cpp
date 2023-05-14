#include <iostream>
#include <fstream>
#include <string>
#include "FL.h"

using namespace std;

FL::FL() {
    count = 0;
    filename = "";
    filevar = "test";
}

FL::FL(string fname) {
    count = 0;
    filename = fname;
    filevar = "test";
}

void FL::openfile(string fname) {
    filevar = fname;
}

void FL::readfile(string fname) {
    openfile(fname);
    ifstream file(filevar);
    if (!file.is_open()) {
        cout << "Error opening file: " << fname << endl;
        return;
    }
    string line;
    int i = 0;
    while (getline(file, line)) {
        contents.push_back(line);
        i++;
    }

    file.close();

}

int FL::getcountss(string filenames) {
  
    return contents.size();
}


string FL::getfilename() {
    return filename;
}
vector<string>& FL::getContents() {
    return contents;
}


