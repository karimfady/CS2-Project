#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class RBK {
private:
        int occur = 0;
public:
    const int mod = 1e9 + 9;
    const int prime = 31;

    int pwr(int n, int r) {
        int res = 1;
        while (r > 0) {
            if (r & 1) {
                res = (res * n) % mod;
            }
            n = (n * n) % mod;
            r /= 2;
        }
        return res;
    }

    int modInverse(int n) {
        int ans = pwr(n, mod - 2);
        return ans;
    }

     void rabinkarp(string s, string p) {
        int hash_p = 0;
        int n = s.length();
        int m = p.length();
        int mul = 1;

        for (int i = 0; i < m; i++) {
            hash_p += (p[i] - 'a' + 1) * mul, hash_p %= mod;
            mul *= prime, mul %= mod;
        }

        int hash_s = 0, j = 0;
        mul = 1;
        int modI = modInverse(prime);

        for (int i = 0; i < n; i++) {
            if (i < m) {
                hash_s += (s[i] - 'a' + 1) * mul, hash_s %= mod;
                if (i + 1 < m) mul *= prime, mul %= mod;
            }
            else {
                hash_s -= (s[j++] - 'a' + 1);
                hash_s *= modI, hash_s %= mod;
                hash_s += (s[i] - 'a' + 1) * mul, hash_s %= mod;
            }

            if (hash_s == hash_p) {
                occur++;
            }
        } 
    }
     int getoccur() {
         return occur;
     }

};