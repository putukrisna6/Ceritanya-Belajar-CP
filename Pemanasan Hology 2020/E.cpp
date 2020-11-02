#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int k = 0;
            while(true) {
                if(i == k || i == n - (k + 1) || j == k || j == m - (k + 1)) {
                    cout << 2 * k;
                    break;
                }
                k++;
            }
            if(j < m - 1)
                cout << " ";
        }
        cout << endl;
    }
}
