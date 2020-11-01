#include <bits/stdc++.h>

using namespace std;

//can move either 1 langkah atau 2 langkah

int tangga(int numSteps, int multiples) {
    int steps = 0;
    int twos, ones = 0;
    int tempSteps, left = numSteps;
    if (numSteps % 2 == 0) {
        twos = numSteps / 2;
        tempSteps = twos;
        if (tempSteps % multiples == 0) {
            return tempSteps;
        }
    }
    else {
        twos = numSteps / 2;
        ones = 1;
        tempSteps = twos + ones;
    }

    while (tempSteps % multiples != 0) {
        if (twos > 0) twos--;
        left = numSteps - ((twos * 2) + ones);
        // cout << "left " << left << endl;
        
        while (left > 0) {
            left--;
            ones++;
        }
        tempSteps = twos + ones;
    }
    // cout << "twos " << twos << " ones " << ones << endl;
    if (twos < 0 || ones < 0) return -1;
    steps = twos + ones;

    return steps;
}

int main() {
    int n, m;
    cin >> n >> m;

    if (m > n) {
        cout << "-1" << endl;
    }
    else {
        cout << tangga(n, m) << endl;
    }

    return 0;
}