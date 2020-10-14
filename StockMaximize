#include <bits/stdc++.h>

using namespace std;

long stockmax(vector<int> prices, int predicted) {
    long profit = 0;
    int currMax = 0;

    for (int i = predicted - 1; i >= 0; i--) {
        if (prices[i] >= currMax) currMax = prices[i];
        profit += currMax - prices[i];
    }
    return profit;
}

int main() {
    int t; //num of test cases
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n; //num of predicted stock prices
        vector<int> prices;
        cin >> n;

        for (int j = 0; j < n; j++) {
            int nums;
            cin >> nums;
            prices.push_back(nums);
        }

        cout << stockmax(prices, n) << endl;
    }

    return 0;
}
