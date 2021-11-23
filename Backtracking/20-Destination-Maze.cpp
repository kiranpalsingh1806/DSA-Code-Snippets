#include<bits/stdc++.h>
using namespace std;

#define R 4
#define C 4

int countPaths(int maze[][C]) {
    if(maze[0][0] == -1) {
        return 0;
    }

    for(int i = 0; i < R; i++) {
        if(maze[i][0] == 0){
            maze[i][0] = 1;
        } else {
            break;
        }
    }

    for(int i = 1; i < C; i++) {
        if(maze[0][i] == 0) {
            maze[0][i] = 1;
        } else {
            break;
        }
    }

    for(int i = 1; i < R; i++) {
        for(int j = 1; j < C; j++) {
            if(maze[i][j] == -1) {
                continue;
            }

            if(maze[i - 1][j] > 0) {
                maze[i][j] = maze[i][j] + maze[i - 1][j];
            }

            if(maze[i][j - 1] > 0) {
                maze[i][j] = maze[i][j] + maze[i][j - 1];
            }
        }
    }
    if(maze[R - 1][C - 1] > 0) {
        return maze[R - 1][C - 1];
    } else {
        return 0;
    }
}

int main() {
    int maze[R][C]= 
    {{0, 0, 0, 0},
    {0, -1, 0, 0},
    {-1, 0, 0, 0},
    {0, 0, 0, 0}};

    cout << countPaths(maze) << "\n";
}

