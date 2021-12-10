#include<bits/stdc++.h>
using namespace std;

const int R = 4;
const int C = 5;

int kadane(int* arr, int* start, int* finish, int n) {
    int sum = 0, maxSum = INT_MIN;
    *finish = -1;
    int localStart = 0;

    for(int i = 0; i < n; i++) {
        sum += arr[i];
        if(sum < 0) {
            sum = 0;
            localStart = i + 1;
        } else if(sum > maxSum) {
            maxSum = sum;
            *start = localStart;
            *finish = i;
        }
    }

    if(*finish != -1) {
        return maxSum;
    } 

    maxSum = arr[0];
    *start = *finish = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] > maxSum) {
            maxSum = arr[i];
            *start = *finish = i;
        }
    }
    return maxSum;
}

void findMaxSum(int M[][C]) {
    int maxSum = INT_MIN;
    int finalLeft, finalRight, finalTop, finalBottom;

    int temp[R], sum, start, finish;

    for(int left = 0; left < C; left++) {
        memset(temp, 0, sizeof temp);
        for(int right = left; right < C; right++) {
            for(int i = 0; i < R; i++) {
                temp[i] += M[i][right];
            }

            sum = kadane(temp, &start, &finish, R);

            if(sum > maxSum) {
                maxSum = sum;
                finalLeft = left, finalRight = right;
                finalTop = start, finalBottom = finish;
            }
        }
    }

    cout << "(Top, Left) ( " << finalTop << ", " << finalLeft << " )" << "\n";
    cout << "(Bottom, Right) ( " << finalBottom << ", " << finalRight << " )" << "\n";
    cout << "Maximum Sum is : " << maxSum << "\n";
}



int main() {
    int M[R][C] = {
        {1, 2, -1, -4, -20},
        {-8, -3, 4, 2, 1},
        {3, 8, 10, 1, 3},
        {-4, -1, 1, 7, -6}
    };

    findMaxSum(M);
}