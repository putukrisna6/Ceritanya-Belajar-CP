#include <bits/stdc++.h>

using namespace std;

bool checkIfNotNum(char a) {
    return a >= 97 && a <= 122;
}

int main() {
    char s[400];

    scanf("%s", s);
    int len = strlen(s);
    int mod;

    for (int i = 0; i < len; i++) {
        if (!checkIfNotNum(s[i])) {
            mod = s[i] - 48;
            break;
        }
    }
    for (int i = 0; i < len; i++) {
        if (!checkIfNotNum(s[i])) {
            continue;
        }
        char ans = s[i] + (24 * mod);
        if(!checkIfNotNum(ans)) {
            ans -= (26 * mod);
        }
        cout << ans;
    }
    cout << endl;

    return 0;
}