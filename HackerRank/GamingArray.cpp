#include <bits/stdc++.h> 

using namespace std;

int main() {
    //number of games and size of each array(s)
    int g, n;

    cin >> g;
    for (int i = 0; i < g; i++) {
        cin >> n;
        vector<int> arr;
        int nums;
        for (int j = 0; j < n; j++) {
            cin >> nums;
            arr.push_back(nums);
        }

        stack<int> s;
        for (int x : arr) {
            if (!s.empty() && s.top() > x) continue;
            s.push(x);
        }

        if (s.size() % 2 == 0) cout << "ANDY" << endl;
        else cout << "BOB" << endl;
    }
}
