#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;
    int ok = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (temp <= 0)
        {
            ok++;
        }
    }
    if (ok >= k)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}

int main()
{
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
}