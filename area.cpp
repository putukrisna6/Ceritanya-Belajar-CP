#include <bits/stdc++.h>
using namespace std;
int H, W;

int surfaceArea(vector<vector<int>> A)
{
	int Mat[H+2][W+2];
	
	for (int i = 0;i < H+2;i++)
	{
		for (int j = 0; j < W+2; j++)
        {
        	Mat[i][j] = 0;
        }
	}
	
	for (int i=1; i<= H; i++)
	{
		for (int j = 1; j <= W; j++)
        {
            Mat[i][j]=A[i-1][j-1];
        }
	}
//	for (int i = 0;i < H+2;i++)
//	{
//		for (int j = 0; j < W+2; j++)
//        {
//           cout << Mat[i][j] << " ";
//        }
//        cout << endl;
//	}
	
    int topdown = H * W * 2;
    int area = 0;
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
           area+=max(0, Mat[i][j]-Mat[i-1][j]);
           area+=max(0, Mat[i][j]-Mat[i+1][j]);
           area+=max(0, Mat[i][j]-Mat[i][j-1]);
           area+=max(0, Mat[i][j]-Mat[i][j+1]);
           //cout << i << " " << j << " " << area << endl;
        }
    }
    //cout << area + topdown << endl;
    return area + topdown;
}
int main()
{
    H = 3;
    W = 3;
    vector<vector<int>> vec{{1, 3, 4},
                            {2, 2, 3},
                            {1, 2, 4}};
    surfaceArea(vec);
}
