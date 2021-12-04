#include<bits/stdc++.h>
using namespace std;

void sieveOfEratosthenes(int n) {
    bool comp[n + 1];
    memset(comp, false, sizeof comp);

    vector<int> primeVec;

    for(int i = 2; i <= n; i++) {
        if(!comp[i]) {
            primeVec.push_back(i);
            for(int j = 2 * i; j <= n; j += i) {
                comp[j] = true;
            }
        }
    }

    for(auto a: primeVec) {
        cout << a << " ";
    }
    cout << "\n";
}

int main() {
    int n = 100;
    cout << "The prime numbers smaller than or equal to " << n << " are : " << "\n";
    sieveOfEratosthenes(n);
}