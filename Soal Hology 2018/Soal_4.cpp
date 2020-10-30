#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

void solve()
{
	// Scan melody
    int xn;
    cin >> xn;
    int note[xn];
    for (int i = 0; i < xn; i++)
    {
        int temp;
        cin >> temp;
        note[i] = temp;
    }
    // Use to calculate diff in melody, cause the only thing that matters is the diff
    for (int i = 0; i < xn; i++)
    {
        note[i] -= note[i + 1];
    }
    int n, x;
    cin >> n;
    // testcase
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        int song[x];
        for (int i = 0; i < x; i++)
        {
            int temp;
            cin >> temp;
            song[i] = temp;
        }
        //this works by just checking the entire array linearly, then breaks if there's the melody pattern after x amount of checks
        // do uncomment my checks below for better understanding
        int index = 0;
        for (int i = 0; i < x; i++)
        {
        	//cout << i << " " << note[index] << endl;
            if (song[i] - song[i + 1] == note[index])
            {
            	
                index++;
                if (index == xn-1)
                {
                    cout << i + 2 - xn << endl;
                    break;
                }
            }
            else
            {
            	//cout << "A";
                index = 0;
                if (i==x-1)
                {
                	cout << "Not Found"<<endl;
				}
            }
        }
    }
}

int main()
{
    solve();
}
