#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

void solve()
{
    string input;
    getline(cin, input);
    //cout << input.size();
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == 'a' || input[i] == 'e' || input[i] == 'o' || input[i] == 'u')
        {
            input[i] = 'i';
        }
        if (input[i] == 'A' || input[i] == 'E' || input[i] == 'O' || input[i] == 'U')
        {
            input[i] = 'I';
        }
    }
    cout << input << endl;
}

int main()
{
    solve();
}
