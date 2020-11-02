#include<bits/stdc++.h>
using namespace std;



bool solveUtil(vector<int> &v, vector<int> &b, vector<int> &a, int n) {
    if(a[n - 1] == 0)
        return false;

}

void solve(vector<int> &v, vector<int> &b) {
    vector<int> a;
    for(int i = 0; i < b.length(); i++) {

    }
}

int main() {
    int t, n, val;
    vector<int> v, b;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < 2 * n; i++) {
            v.push_back(i + 1);
        }

        for(int i = 0; i < n; i++) {
            cin >> val;
            b.push_back(val);
        }



        v.clear();
        b.clear();
    }
}
