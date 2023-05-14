#include "BR.h"
#include "HM.h"
#include <iostream>
using namespace std;
int BR::bruteForceSearch(const string& line, const string& check) {
    int lineLength = line.length();
    int checkLength = check.length();

    int j = 0;
    int occur = 0;

    for (int i = 0; i <= lineLength - checkLength; ++i) {
        j = 0;
        while (j < checkLength && line[i] == check[j]) {
            i++;
            j++;
        }

        if (j == checkLength) {
            occur++;
        }
    }
    return occur;
}