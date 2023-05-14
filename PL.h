#pragma once
#include "COR.h"

class PL {
private:
    COR corpus;
    double percentage;
    int matchingCount;
    int totaloffile;

public:
    PL(COR& corpus) : corpus(corpus), percentage(0.0), matchingCount(0), totaloffile(0) {}

    double compareUsingBruteForce(string filename);
    double compareUsingRabinKarp(string filename);
    double calculatePercentage();
    vector<string> extractWords( const string& line);

    
};


