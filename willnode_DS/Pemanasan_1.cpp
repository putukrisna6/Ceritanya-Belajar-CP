#include <bits/stdc++.h>

using namespace std;

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