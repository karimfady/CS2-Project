#ifndef RabinKarp_h
#define RabinKarp_h
#include "Hash.h"
#include "PlagiarismCheck"
#include "Brute"
class RabinKarp:protected Hash:protected PlagiraismCheck:protected Brute
{
protected:
    int HashRK;
public:
    RabinKarp(int hashValue);
    int *match(char *patterns,char *compare);
    int calcHash(string *chr);
};

#endif
