#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr;

    int nums;
    for (int i = 0; i < n; i++) {
        cin >> nums;
        arr.push_back(nums);
    }

    sort (arr.begin(), arr.end());

    int i = 0, j = 1, count = 0;
    while (j < n) {
        int diff = arr[j] - arr[i];

        if (diff == k) {
            count++;
            j++;
        }
        else if (diff > k) i++;
        else if (diff < k) j++;
    }

    cout << count << endl;

    return 0;
}
