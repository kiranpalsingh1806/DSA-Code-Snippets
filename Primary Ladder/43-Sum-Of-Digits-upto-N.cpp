#include<bits/stdc++.h>
using namespace std;

int sumofDigitsUtil(int n, int a[]) {
    if(n < 10) {
        return (n * (n + 1)/ 2);
    }

    int d = (int)(log10(n));
    int p = (int)(ceil(pow(10, d)));
    int msd = n / p;

    return (msd * a[d] + (msd * (msd - 1) / 2) * p + msd * (1 + n % p) + sumofDigitsUtil(n % p, a));
}

int sumOfDigits(int n) {
    int d = (int) (log10(n));
    int a[d + 1];

    a[0] = 0;
    a[1] = 45;

    for(int i = 2; i <= d; i++) {
        a[i] = a[i - 1] * 10 + 45 * (int)(ceil(pow(10, i - 1)));    
    }

    return sumofDigitsUtil(n, a);
}

int main() {
    for(int i = 10; i < 50; i += 10) {
        cout << "Sum of digits in numbers from 1 to " << i << " is " << sumOfDigits(i) << "\n";
    }
}