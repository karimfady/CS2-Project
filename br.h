#pragma once
#include "BR.h"
#include "HM.h"
#include <iostream>
#include <QString>
using namespace std;
class  BR : public HM {
private:
    int occur;
public:
    static int bruteForceSearch( QString& line, QString& check);
};
