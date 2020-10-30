#include <bits/stdc++.h>

using namespace std;

/*  the idea is to use maps to swap out the chars
*   result is printed char by char
*
*   potential problems is the need for two EOFs instead of (what I think it is supposed to be), 1 EOF
*
*   potential solution is to receive the whole key,value pair as a whole string and process it as such
*   or somehow I can hack that weird scanf shits
*/

int main() {
    map<char, char> m;
    string ans = "", que;

    int i = 0;
    char a, b;
    while(scanf("%c,%c", &a, &b) != EOF ) {
        m[a] = b;
    }

    getline(cin, que);

    for (char c : que) {
        if (c == ' ') {
            cout << c;
            continue;
        }
        else if (m.find(c) == m.end()) {
            cout << c;
            continue;
        }
        cout << m.find(c)->second;
    }
   
    return 0;
}
