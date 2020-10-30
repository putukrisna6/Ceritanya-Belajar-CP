#include<bits/stdc++.h>
using namespace std;

// fungsi untuk menentukan nomor urutan bebek setelah dilakukan pengurutan
int solution(vector<string> &duck) {
    int j = duck.size() - 1;
    while(j > 0 && duck[j].compare(duck[j - 1]) < 0) {
        swap(duck[j], duck[j - 1]);
        j--;
    }
    return j + 1;
}

int main() {
    vector<string> duck;    // vector untuk menyimpan semua nama bebek
    string name;
    int n;
    cin >> n;               // input jumlah bebek
    for(int i = 0; i < n; i++) {
        cin >> name;                        // input nama bebek
        duck.push_back(name);               // masukkan nama bebek ke vector
        cout << solution(duck) << endl;     // cetak nomor urutan bebek
    }
}
