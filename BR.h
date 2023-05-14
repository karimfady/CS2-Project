#pragma once
#include "BR.h"
#include "HM.h"
#include <iostream>
using namespace std;
class  BR : public HM {
private:
    int occur;
public:
    static int bruteForceSearch(const string& line, const string& check);
};

