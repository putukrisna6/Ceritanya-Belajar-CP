#include <bits/stdc++.h>

using namespace std;

// Complete the timeInWords function below.
string timeInWords(int h, int m) {
    vector<string> table{ //table for hour and minute name
        "o' clock",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "ten",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "quarter",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen",
        "twenty",
        "twenty one",
        "twenty two",
        "twenty three",
        "twenty four",
        "twenty five",
        "twenty six",
        "twenty seven",
        "twenty eight",
        "twenty nine",
        "half"};
    if(m == 0) // h o' clock
        return table[h] + " " + table[m];
    if(m < 30 && m != 15 && m != 1) // not quarter and under 30 and not 1, not 1 --> 1 minute not 1 minutes
        return table[m] + " minutes past " + table[h];
    if(m == 1) // 1 minute
        return table[m] + " minute past " + table[h];
    if(m == 15 || m == 30) // special case quarter and half past
        return table[m] + " past " + table[h];

    if(m > 30 && m != 45) // > 30 and not quarter to
        return table[60 - m] + " minutes to " + table[h + 1];
    return table[60 - m] + " to " + table[h + 1]; // quarter to
}

int main() {

    int h;
    cin >> h;

    int m;
    cin >> m;

    string result = timeInWords(h, m);

    cout << result << "\n";

    return 0;
}
