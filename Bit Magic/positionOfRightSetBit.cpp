#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 32;

    cout << log2(n & -n) + 1 << "\n";
    return 0;
}