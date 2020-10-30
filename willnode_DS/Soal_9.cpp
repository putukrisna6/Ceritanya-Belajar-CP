#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

int solve(int n, int k)
{
    if (k == 1 || k == 0)
    {
        return k;
    }
    if (n == 1)
    {
        return k;
    }
    int floor = INT_MAX;
    int result;
    for (int i = 1; i <= k; i++)
    {
    	// solve (n-1,i-1) solves the case jika eggnya pecah 1 dari paling bawah ke atas.
    	// solve (n,k-i) solves dari atas kebawah kalo ga pecah
        result = max(solve(n-1,i-1), solve(n,k-i));
		if (result < floor)
            floor = result;
    }
    return floor + 1;
}

int main()
{
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        int egg = 2;
        int floor;
        cin >> floor;
        int height = solve(egg,floor);
        cout << height << endl;
    }
}
