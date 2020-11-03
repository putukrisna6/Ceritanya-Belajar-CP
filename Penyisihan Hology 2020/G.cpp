#include <bits/stdc++.h>
using namespace std;

void solve(vector<pair<int, int>> &v, int m, int n)
{
    int j;
    for (int i = 0; i < m; i++)
    {
        if (v[i].first < v[i].second && v[i].first >= 1 && v[i].second >= 1 && v[i].second <= n && v[i].first <= n) 
        {
            for (j = 0; j < m; j++)
            {
                if (i == j)
                    continue;
                if (((v[j].first != v[i].first && v[j].first != v[i].second) && (v[j].second != v[i].first && v[j].second != v[i].second)))
                    break;
            }
            if (j == m)
            {
                cout << "YA" << endl;
                return;
            }
        }
    }
    cout << "TIDAK" << endl;
}

int main()
{
    int n, m, a, b;
    bool flag = false;
    vector<pair<int, int>> v;

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        v.push_back(make_pair(a, b));
        if (a < b && a >= 1 && b >= 1 && b <= n)
            flag = true;
    }
    if (!flag)
    {
        cout << "TIDAK" << endl;
        return 0;
    }
    solve(v, m, n);
}
