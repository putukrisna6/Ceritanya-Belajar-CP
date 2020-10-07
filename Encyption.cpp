#include <bits/stdc++.h> 

using namespace std;

int main() {
    string input;
    cin >> input;

    int length = input.length(), track = 0;
    double root= sqrt(length);
    int row = floor(root), columns = ceil(root);
    if (row * columns < length) row = ceil(root);

    char encrypt[row][columns] = {'1'};

    for (int i = 0; i < row; i++) {
        
        for (int j = 0; j < columns; j++) {
            if (track >= length) {
                encrypt[i][j] = '1';
            }
            else {
                encrypt[i][j] = input[track];
                track++;
            }
        }
    }
   
    for (int j = 0; j < columns; j++) {
        for (int i = 0; i < row; i++) {
            if (encrypt[i][j] != '1') cout << encrypt[i][j];
        }
        if (j != columns - 1) cout << ' ';
    }
    cout << endl;

    return 0;
}
