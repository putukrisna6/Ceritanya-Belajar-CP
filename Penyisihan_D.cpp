#include <bits/stdc++.h>

using namespace std;

int a[100010], b[100010];

int main() {
    int T;
    cin >> T;

    int v[100010];
    int c[100010];

    for (int j = 0; j < T; j++) {
        int N;
        cin >> N;

        int flag = 0;
        memset(v, 0, sizeof(v));

        for (int i = 1; i <= N; i++) {
            cin >> a[i];
            v[a[i]] = 1;

            if (v[a[i]] > 1) {
                flag = 1;
            }
        }
        if (v[1] == 0) flag = 1;
        int total = 1;

        for (int i = 1; i <= N; i++) {
            c[total++] = a[i];

            while (v[a[i]]) {
                a[i]++;
                if (a[i] > 2 * N) flag = 1;
            }

            c[total++] = a[i];
            v[a[i]] = 1;
        }

        if (flag) {
            cout << -1 << endl;
            continue;
        }
        for (int i = 1; i <= 2 * N; i++) {
            cout << c[i] << " ";
        }
        cout << endl;
    }


    return 0;
}