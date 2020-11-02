#include <bits/stdc++.h>

using namespace std;

#define PAIRS pair<int, int>

PAIRS digits(unsigned long long n) {
    int largest = 0; 
    int smallest = 9; 

    while (n) {
        int r = n % 10;

        largest = max(r, largest);
        smallest = min(r, smallest);

        n /= 10;
    }
    PAIRS result = make_pair(largest, smallest);
    return result;
}

map<unsigned long long, PAIRS> myMap;

unsigned long long solve(unsigned long long a, unsigned long long k) {
    PAIRS p;
    if (myMap.find(a) == myMap.end()) {
        // cout << "enter" << endl;
        p = digits(a);
        myMap[a] = p;
    }
    else p = myMap[a];

    if (p.second == 0) return a;

    unsigned long long res = p.first * p.second + a;
    if (k == 1) return res;
    return solve(res, k-1);
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        unsigned long long a, k;
        cin >> a >> k;
        if (k == 1) {
            cout << a << endl;
        }
        else cout << solve(a, k-1) << endl;
    }

    return 0;
}
