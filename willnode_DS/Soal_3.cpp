#include <bits/stdc++.h>

using namespace std;

/*  basically you shift the chars by a factor
*   that factor is 24 times the single number there
*   for example 1abc, a is shifted by 24 * 1
*   if the result of that shift push the char out of lower case letter ASCII, just make it cycle back
*
*   there should not be any potential problem with this
*/

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
