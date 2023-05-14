#pragma once
#include "COR.h"

class PL {
private:
    COR corpus;
    double percentage;
    int matchingCount;
    int totaloffile;
    int timetaken;

public:
    PL(COR& corpus) : corpus(corpus), percentage(0.0), matchingCount(0), totaloffile(0),timetaken(0) {}
    int gettimetaken();
    double compareUsingBruteForce(string filename);
    double compareUsingRabinKarp(string filename);
    double calculatePercentage();
    vector<string> extractWords( const string& line);

    
};


