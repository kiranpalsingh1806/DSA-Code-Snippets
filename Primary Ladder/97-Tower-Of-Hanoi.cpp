#include<bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if(n == 1) {
        cout << "Move Disk 1 from rod " << from_rod << " to " << to_rod << "\n";
        return;
    }

    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    cout << "Move Disk " << n << " from rod " << from_rod << " to " << to_rod << "\n";
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod); 
}

int main() {
    int n = 4;
    towerOfHanoi(n, 'A', 'C', 'B');
}

