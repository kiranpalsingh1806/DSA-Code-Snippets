#include<bits/stdc++.h>
using namespace std;

#define N 8

int knightTourUtil(int x, int y, int moveI, int sol[N][N], int xMove[], int yMove[]);

int isSafe(int x, int y, int sol[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

int knightTour() {
    int sol[N][N];

    for(int x = 0; x < N; x++) {
        for(int y = 0; y < N; y++) {
            sol[x][y] = -1;
        }
    }

    int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    sol[0][0] = 0;

    if(knightTourUtil(0, 0, 1, sol, xMove, yMove) == 0) {
        cout << "Solution does not exist" << "\n";
    } else {
        for(int x = 0; x < N; x++) {
            for(int y = 0; y < N; y++) {
                cout << " " << setw(2) << sol[x][y] << " ";
            }
            cout << "\n";
        }
    }

    return 1;
}

int knightTourUtil(int x, int y, int moveI, int sol[N][N], int xMove[8], int yMove[8]) {
    int k, next_x, next_y;
    if(moveI == N * N) {
        return 1;
    }

    for(int k = 0; k < 8; k++) {
        next_x = x + xMove[k];
        next_y = y + yMove[k];

        if(isSafe(next_x, next_y, sol)) {
            sol[next_x][next_y] = moveI;
            if(knightTourUtil(next_x, next_y, moveI + 1, sol, xMove, yMove) == 1) {
                return 1;
            } else {
                sol[next_x][next_y] = -1;
            }
        }
    }
    return 0;
}

int main() {
    knightTour();
    return 0;
}