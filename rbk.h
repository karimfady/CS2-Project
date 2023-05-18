#pragma once
#include <QString>

class RBK {
private:
    static const int prime = 101;
    static const int base = 256;

public:
    static int rkcheckPattern(QString pattern, QString text) {
        int patternLength = pattern.length();
        int textLength = text.length();

        if (patternLength > textLength) {
            return false;
        }

        int patternHash = calculateHash(pattern, patternLength);
        int textHash = calculateHash(text, patternLength);

        for (int i = 0; i <= textLength - patternLength; ++i) {
            if (patternHash == textHash && compareStrings(pattern, text, i)) {
                return true;
            }

            if (i < textLength - patternLength) {
                textHash = recalculateHash(textHash, text, i, patternLength);
            }
        }

        return false;
    }

private:
    static int calculateHash(QString str, int length) {
        int hash = 0;

        for (int i = 0; i < length; ++i) {
            hash = (hash * base + str[i].unicode()) % prime;
        }

        return hash;
    }

    static int recalculateHash(int oldHash, QString str, int oldIndex, int patternLength) {
        int newHash = (oldHash - (str[oldIndex].unicode() * power(base, patternLength - 1) % prime) + prime) % prime;
        newHash = (newHash * base + str[oldIndex + patternLength].unicode()) % prime;
        return newHash;
    }

    static bool compareStrings(QString pattern, QString text, int startIndex) {
        for (int i = 0; i < pattern.length(); ++i) {
            if (pattern[i] != text[startIndex + i]) {
                return false;
            }
        }

        return true;
    }

    static int power(int base, int exponent) {
        int result = 1;

        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = (result * base) % prime;
            }

            base = (base * base) % prime;
            exponent /= 2;
        }

        return result;
    }
};
