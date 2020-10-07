#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// Complete the isValid function below.
bool isValid(string s) {
    vector<int> count(26, 0);

    for (auto c : s) count[c - 97]++;
    sort(count.begin(), count.end());

    int i = 0;
    while(!count[i]) i++;

    int lowest = count[i], highest = count[25];
    if (lowest == highest) return true;
    else{
        // remove one letter at higher frequency or the lower frequency 
        if(((highest - lowest == 1) && (highest > count[24])) ||
            (lowest == 1) && (count[i+1] == highest))
            return true;
    }
    return false;
}

int main() {
    string s;
    cin >> s;
    if (isValid(s)) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
