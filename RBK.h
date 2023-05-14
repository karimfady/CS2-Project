#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class RBK {

public:
    static int search(const string& pat, const string& txt) {
        int M = pat.length();
        int N = txt.length();
        int i, j;
        int p = 0;
        int t = 0;
        int h = 1;

        const int q = 53; 

        for (i = 0; i < M - 1; i++)
            h = (h * 128) % q; 
        for (i = 0; i < M; i++) {
            p = (128 * p + pat[i]) % q;
            t = (128 * t + txt[i]) % q;
        }

        int occurrences = 0;

        for (i = 0; i <= N - M; i++) {
            if (p == t) {
                for (j = 0; j < M; j++) {
                    if (txt[i + j] != pat[j])
                        break;
                }
                if (j == M)
                    occurrences++;
            }

            if (i < N - M) {
                t = (128 * (t - txt[i] * h) + txt[i + M]) % q;
                if (t < 0)
                    t = (t + q);
            }
        }

        return occurrences;
    }

};


