#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 32;
    cout << "The position of right set bit is " << log2(n & -n) + 1 << "\n";
    return 0;
}

