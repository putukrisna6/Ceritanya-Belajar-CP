#include <bits/stdc++.h>

using namespace std;

// Complete the extraLongFactorials function below.
void extraLongFactorials(int n) {
    int result[500];
    int size = 1;
    result[0]=1;
    for (int i=2;i<=n;i++)
    {
        int carry = 0;
        for (int j=0;j<size;j++)
        {
            int hasil = result[j]* i + carry;
            result[j] = hasil % 10;
            carry = hasil/10 ;
        }
        while (carry!=0)
        {
            result[size] = carry % 10;
            carry = carry / 10 ;
            size++;
        }
    }
    for (int k=size-1; k>=0; k--) 
        cout << result[k];
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    extraLongFactorials(n);

    return 0;
}
