#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

int gcd(int a, int b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}

void solve()
{
    int n, m;
    cin >> n >> m;
  	//cout << gcd (n,m);
    if (n!=m)
    cout << n + m - gcd(n, m) + 2*(gcd(n, m)-1) << endl;
    else 
    cout << n + (n-1)*2 << endl;
}

int main()
{
    solve();
}
