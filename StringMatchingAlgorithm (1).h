#include <iostream>
#include <string>
#include <vector>
#include "Corpus.h"

using namespace std;

class StringMatchingAlgorithm 
{
public:
    virtual int match(char pattern, char compared) = 0;
};
