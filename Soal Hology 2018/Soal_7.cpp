#include<bits/stdc++.h>
using namespace std;

double calculate(double eq[], int n, double x) { //function to calculate f(x)
    double y = 0;
    for(int i = 0; i < n + 1; i++) {
        y += eq[i] * pow(x, n - i);
//        cout << eq[i] * pow(x, n - i) << endl;
    }
    return y;
}

int solve(double eq[], int n, double x1, double x2) { //function to calculate the root of f(x) located in [x1, x2] using regula falsi method
    double x3, y1, y2, y3, prevY3, ee = 1, i = 0;

    while(ee > 0.00001) { //loop until estimated error <= 10^-5
        if(i == 0) {
            y1 = calculate(eq, n, x1);
            y2 = calculate(eq, n, x2);
            x3 = (x1 * y2 - x2 * y1) / (y2 - y1);
            y3 = calculate(eq, n, x3);
//            cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
        }
        else if(i > 0) {
            prevY3 = y3;
            y1 = calculate(eq, n, x1);
            y2 = calculate(eq, n, x2);
            x3 = (x1 * y2 - x2 * y1) / (y2 - y1);
            y3 = calculate(eq, n, x3);
            ee = abs(y3 - prevY3) / y3;
//            cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << ee << endl;
        }
        if(y1 * y3 < 0)
            x2 = x3;
        else if(y1 * y3 > 0)
            x1 = x3;
        else
            return (int) round(x3);
        i++;
    }
    return (int) round(x3);
}

int main() {
    int t, n; //variables to store input
    double eq[41], x1, x2; //array to store coefficient(s) and variables to store x1, and x2 respectively
    cin >> t; //get t
    while(t--) {
        cin >> n; //get n (highest degree of polynomial f(x))
        for(int i = 0; i < n + 1; i++) //input all f(x) coefficients starting from the highest degree, n + 1 times because the lowest degree is 0
            cin >> eq[i];
        cin >> x1 >> x2; //get x1 and x2
        cout << solve(eq, n, x1, x2) << endl; //get the root of the polynomial f(x) located in [x1, x2]
    }
}
