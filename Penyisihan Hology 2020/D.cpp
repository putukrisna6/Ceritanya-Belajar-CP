#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    int check[n];
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        int divisor[n] ;
		divisor[0]= arr[i];
		int divelem = 1;
        int rn = 1;
        for (int j = i + 1; j < n; j++)
        {
        	int flag = 1;
            for (int k=0;k<divelem;k++)
            {
            	if (arr[j] % divisor[k] != 0)
	            {
	                flag = 0;
	            }
	            if (flag == 1)
	            {
	            	divisor[divelem] = arr[j] ;
	            	divelem++;
	                rn++;
				}
			}
        }
        cout << endl;
        if (rn > count)
        {
            count++;
        }
    }
    cout << count << endl;
}

int main()
{
    solve();
}
