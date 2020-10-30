#include <iostream>
#include <algorithm>

using namespace std;

void check(string s) {
    bool val = next_permutation(s.begin(), s.end());

    if (val == false) cout << "no answer" << endl; 
    else cout << s << endl; 

    return;
}

int main() { 
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        string s;
        cin >> s;
        check(s);
    }
    
    return 0; 
} 
