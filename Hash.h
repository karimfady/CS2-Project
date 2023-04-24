#include <iostream>
#include <vector>
#include <string>
#include "Corpus.h"
#include "StringMatchingAlgorithm.h"

using namespace std;

class Hash
{
protected:
	int mod;
	int div;
public:
	Hash() {};
	virtual int calchash(string* chr);
};
