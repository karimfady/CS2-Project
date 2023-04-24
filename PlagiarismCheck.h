#ifndef PlagiarismCheck_h
#define PlagiarismCheck_h
#include "Hash.h"
#include "RabinKarp"
#include "Brute"
class PlagiarismCheck:protected Hash:protected RabinKarp:protected Brute
{
protected:
    Corpus *corpus;
    Stringmatching stringmatching;
    double percentage;
    public:
    PlagiarismCheck();
    bool isPlagiarized(Corpus crps);
    double calcPlagPercent();
};

#endif
