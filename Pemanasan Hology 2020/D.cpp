#include<bits/stdc++.h>
using namespace std;

bool isFirstAscending(vector<pair<int, char>> &v, int n) {
    for(int i = 0; i < n - 1; i++) {
        if(v[i].first > v[i + 1].first)
            return false;
    }
    return true;
}

bool isSecondAscending(vector<pair<int, char>> &v, int n) {
    for(int i = 0; i < n - 1; i++) {
        if(v[i].second > v[i + 1].second)
            return false;
    }
    return true;
}

bool check(vector<pair<int, char>> &v, int n) {
    if(isFirstAscending(v, n) || isSecondAscending(v, n))
        return false;
    else
        return true;
}

void permutation(vector<pair<int, char>> &v, int i, int n, int *countP) {
    if(i == n - 1) {
        if(check(v, n))
            *countP += 1;
        return;
    }
    for(int j = i; j < n; j++) {
        v[i].swap(v[j]);
        permutation(v, i + 1, n, countP);
        v[i].swap(v[j]);
    }
}

int main() {
    vector<pair<int, char>> v;
    int n, countP = 0, first, second;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> first >> second;
        v.push_back(make_pair(first, second));
    }
    permutation(v, 0, n, &countP);
    cout << countP % 998244353 << endl;
}
