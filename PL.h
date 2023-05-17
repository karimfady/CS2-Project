#pragma once
#include "COR.h"

class PL {
private:
    COR corpus;
    double rpercentage;
    double bpercentage;
    int rmatchingCount;
    int bmatchingCount;
    int rtotaloffile;
    int btotaloffile;
    int btimetaken;
    int rtimetaken;
    bool repeated;

public:
    PL(COR& corpus) : corpus(corpus), rpercentage(0.0), bpercentage(0.0), rmatchingCount(0), bmatchingCount(0),
        rtotaloffile(0), btotaloffile(0), btimetaken(0), rtimetaken(0), repeated(false) {}
    int rgettimetaken();
    int bgettimetaken();
    double compareUsingBruteForce(string filename);
    double compareUsingRabinKarp(string filename);
    double rcalculatePercentage();
    double bcalculatePercentage();
    vector<string> extractWords( const string& line);

    
};


