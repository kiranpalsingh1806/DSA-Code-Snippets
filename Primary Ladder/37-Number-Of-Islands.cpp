#include<bits/stdc++.h>
using namespace std;

const int N = 5;
const int M = 5;

int isSafe(int adj[][M], int row, int col, bool vis[][M]) {
    return (row >= 0) && (row < N) &&
    (col >= 0) && (col < M) && (adj[row][col] && !vis[row][col]);
}

void dfs(int adj[][M], int row, int col, bool vis[][M]) {
    static int X[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int Y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    vis[row][col] = true;

    for(int k = 0; k < 8; k++) {
        if(isSafe(adj, row + X[k], col + Y[k], vis)) {
            dfs(adj, row + X[k], col + Y[k], vis);
        }
    }
}

int countIslands(int adj[][M]) {
    bool vis[N][M];
    memset(vis, 0, sizeof vis);

    int count = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(adj[i][j] && !vis[i][j]) {
                dfs(adj, i, j, vis);    
                ++count;
            }
        }
    }
    return count;
}

int main() {
    int adj[][M] = {
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1}
    };

    cout << "Number of islands is : " << countIslands(adj);

    return 0;
}