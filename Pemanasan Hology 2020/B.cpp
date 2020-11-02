#include<bits/stdc++.h>
using namespace std;

int solve(int n, int m, int count, int prevN, int *result) { // unfinished use void
    if(n == prevN - 2)
        count += 2;
    if(n == prevN - 1)
        count += 1;

    if(n == 0 || n == 1) {
        count += 1;
        if(count % m == 0)
            *result += 1;
        cout << count << endl;
        return 1;
    }

    else if(n == 2) {
        count += 2;
        if(count % m == 0)
            *result += 1;
        return 2;
    }

    else {
        prevN = n;
        return solve(n - 2, m, count, prevN, result) + solve(n - 1, m, count, prevN, result);
    }

}

int main() {
    int n, m, result = 0;
    cin >> n >> m;
    solve(n, m, 0, n, &result);
    if(result)
        cout << result << endl;
    else
        cout << "-1" << endl;
}
