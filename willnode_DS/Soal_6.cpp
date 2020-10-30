#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, K;
    string abv, real;

    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        cin >> abv >> K;
        getchar();
        getline(cin, real);

        int lenABV = abv.size(), \
        lenReal = real.size();

        int r = 0, prevPair = INT_MIN, iters = 0;
        bool permanentFail = false;

        for (int a = 0; a < lenABV; a++) {
            if (permanentFail) break;
            if (iters > lenReal) {
                permanentFail = true;
                break;
            }

            bool broke = false;
            if (tolower(abv[a]) == tolower(real[r])) {
                r++;

                int count = 0, currA, \
                    pairedAt = r - 1, potentialPair;

                if (a + 1 != lenABV) currA = a + 1;
                else currA = a;

                while(tolower(abv[currA]) != tolower(real[r]) && r != lenReal) {
                    if (count > K) {
                        broke = true;
                        break;
                    }
                    if (tolower(abv[a]) == tolower(real[r])) {
                        potentialPair = r;
                    }
                    r++;
                    count++;
                }
                if (broke) {
                    if (potentialPair - prevPair <= K && a != 0) {
                        a--;
                        r = potentialPair;
                    }
                    else permanentFail = true;
                }
                else if (pairedAt - prevPair > K) {
                    permanentFail = true;
                }
                else {
                    prevPair = pairedAt;
                }

            }
            iters++;
        }

        if (permanentFail) {
            cout << "Case #" << i + 1 << ": tidak valid"<< endl;
        }
        else cout << "Case #" << i + 1 << ": valid"<< endl;
    }
    
    return 0;
}