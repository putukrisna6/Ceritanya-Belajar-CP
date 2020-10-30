#include <bits/stdc++.h>
#include <string>
using namespace std;

// No. 1: The secret of stone cave

// Constraints
// 1 ≤ K ≤ 100000
// 1 ≤ N ≤ 100000
// 0 ≤ Xi ≤ 100
// max sum of X = 10^2 * 10^5 = 10^7


int main() {
    int n, val, k; // variables to store input
    long long sum = 0; // variable to store sum of X
    vector<int> v; // vector to store Xi
    cin >> n; // get n
    while(n--) {
        cin >> val;
        v.push_back(val); // store Xi to vector "v"
    }
    sort(v.begin(), v.end(), greater<int>()); // sort vector "v" in descending order
    cin >> k; // get k
    for(int i = 0; i < k; i++) // sum of k highest Xi
        sum += v[i];
    cout << sum << endl; // output sum
}
