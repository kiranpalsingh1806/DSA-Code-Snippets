#include<bits/stdc++.h>
using namespace std;

const int C = 3;

void zigzagMatrix(int arr[][C], int n, int m) {
    int row = 0, col = 0;
    bool rowInc = false;
    
    int mn = min(m, n);
    for(int len = 1; len <= mn; ++len) {
        for(int i = 0; i < len; ++i) {
            cout << arr[row][col] << " ";

            if(i + 1 == len) {
                break;
            }
            if(rowInc) {
                ++row;
                --col;
            } else {
                --row;
                ++col;
            }     
        }

        if(len == mn) {
            break;
        }

        if(rowInc) {
            ++row;
            rowInc = false;
        } else {
            ++col; 
            rowInc = true; 
        }    
    }

    if(row == 0) {
        if(col == m - 1) {
            ++row;
        } else {
            ++col;
        }
        rowInc = true;
    } else {
        if(row == n - 1) {
            ++col;
        } else {
            ++row;
        }
        rowInc = false;
    }

    int mx = max(m, n) - 1;
    for(int len, diag = mx; diag > 0; --diag) {
        if(diag > mn) {
            len = mn;
        } else {
            len = diag;
        }

        for(int i = 0; i < len; i++) {
            cout << arr[row][col] << " ";

            if(i + 1 == len) {
                break;
            }

            if(rowInc) {
                ++row;
                --col;
            } else {
                --row;
                ++col;
            }
        }
        
        if(row == 0 || col == m - 1) {
            if(col == m - 1) {
                ++row;
            } else {
                ++col;
            }
            rowInc = true;
        } else if(col == 0 || row == n - 1) {
            if(row == n - 1) {
                col++;
            } else {
                row++;
            }
            rowInc = false;
        }
    }
}

int main() {
    int matrix[][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    zigzagMatrix(matrix, 3, 3);
}