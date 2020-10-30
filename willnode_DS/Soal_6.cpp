#include <bits/stdc++.h>

/*  the main idea is to pair the letters of the abbreviation to the letters of the main string
*   when the letter is paired, search through the main string to search for the next abbreviation letter's pair
*   while doing so, keep track of the 'count' that should be under K at all times
*   if count happen to exceed K, give it another chance to pair up
*   -------------------------------------------------------------------------------------------------------------
*   how exactly?
*   when searching for next pair, keep track of another potential pair for the already paired letter
*   this method is crucial for test case HOLOGY 7 to be correct
*   the chance is given as long as the potential pair for the already paired letter,
*   has less than K letters in between to the previous paired letter (pusing ga, gw juga jelasinnya susah)
*   -------------------------------------------------------------------------------------------------------------
*   there are two fail states in here
*   bool broke means that the current attemp to find next pair doesn't work, so it'll attempt to move the curr pair location
*   bool permanentFail means it is hopeless, as changing the curr pair location will break it and the next pair is still out of reach as well
*   -------------------------------------------------------------------------------------------------------------
*   potential problem might arise as I didn't have any reference to work with, mostly because I can't find similar problems
*   but I hope I have tested this one extensively enough to make sure it should work
*   potential solution is unknown since I don't know what are the potential problem to begin with
*/

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
