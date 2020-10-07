#include <bits/stdc++.h>

/**
 * String itu valid kalo
 * 1. semua jenis char di string jumlahnya sama
 *      either 1 semua (abcd), 2 semua (aabbcc), etc
 * 2. tetep valid kalo bisa remove 1 char
 *      aabbccddd valid karena 1 d bisa di-remove
 *      abcdccc ga valid karena harus remove c 2 kali
**/

using namespace std;

// Complete the isValid function below.
bool isValid(string s) {
    vector<int> count(26, 0);

    //cek tiap char a-z munculnya berapa kali
    for (auto c : s) count[c - 97]++;

    //sort berdasarkan jumlah, terus buat angka penunjuk ke char pertama yang muncul setidaknya 1 kali
    sort(count.begin(), count.end());
    int i = 0;
    while(!count[i]) i++;

    int lowest = count[i], highest = count[25];
    //kalo lowest highest udah sama, itu auto valid karena ga ada perbedaan jumlah char
    if (lowest == highest) return true;
    else{
        //kalo bedanya cuma satu antara lowest highest dan cuma ada satu yang beda, bisa di remove jadi valid
        if(((highest - lowest == 1) && (highest > count[24])) ||
            (lowest == 1) && (count[i+1] == highest))
            return true;
    }
    return false;
}

int main() {
    string s;
    cin >> s;
    if (isValid(s)) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
