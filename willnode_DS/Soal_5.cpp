#include <bits/stdc++.h>

#define PAIR pair<string, int>


using namespace std;

PAIR decToFlippedBinary(unsigned long long X) {
    PAIR result;
    result.first = "";

    int length = 0, initialZeroes = 0;
    bool notZero = false;
    while (X > 0) {
        result.first += to_string(X % 2);
        if (X % 2 == 0 && !notZero) {
            initialZeroes++;
        }
        else if (X % 2 == 1 && !notZero) {
            notZero = true;
        }
        X /= 2;
        length++;
    }
    if (initialZeroes > 0) {
        result.first.erase(0, initialZeroes);
    }

    result.second = length - initialZeroes;

    return result;
}

unsigned long long longestPalSubstr(string str, int length) {
    int maxLength = 1;
    int low, high, start = 0;

    for (int i = length - 2; i > 1; --i) {
        low = i - 1;
        high = i;

        while (low >= 0 && high < length && str[low] == str[high]) {
            if (high - low + 1 > maxLength) {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }

        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < length && str[low] == str[high]) {
            if (high - low + 1 > maxLength) {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
    }
    int newLow = start, newHigh = start + maxLength - 1;
    unsigned long long dec_value = 0;
    int base = 1;

    for (int i = newHigh; i >= newLow; --i) {
        dec_value += (str[i] - 48) * base;
        base *= 2;
    }
    return dec_value;
    
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        unsigned long long X;
        cin >> X;
        if (X != 0) {
            PAIR processed = decToFlippedBinary(X);
            cout << longestPalSubstr(processed.first, processed.second) << endl;
        }
        else cout << 0;
    }


    return 0;
}