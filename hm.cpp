#include "HM.h"
int  HM::distanceCalc( QString& str1, QString& str2) {
    distance = 0;
    int i = 0;
    while (str1[i] != '\0') {
        if (str1[i] != str2[i])
            distance++;
        i++;
    }
    return distance;
}
