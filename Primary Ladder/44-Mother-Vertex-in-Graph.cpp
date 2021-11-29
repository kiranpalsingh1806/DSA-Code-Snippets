#include<bits/stdc++.h>
using namespace std;

const int V = 7;
list<int> adj[V];

void DFSUtil(int v, vector<bool> &visited) {
    visited[v] = true;

    for(auto i = adj[v].begin(); i != adj[v].end(); i++) {
        if(!visited[*i]) {
            DFSUtil(*i, visited);
        }
    }
}

int findMother() {
    vector<bool> visited(V, false);
    int v = 0;

    for(int i = 0; i < V; i++) {
        if(visited[i] == false) {
            DFSUtil(i, visited);
            v = i;
        }
    }

    fill(visited.begin(), visited.end(), false);
    DFSUtil(v, visited);

    for(int i = 0; i < V; i++) {
        if(visited[i] == false) {
            return -1;
        }
    }
    return v;
}

int main() {
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[4].push_back(1);
    adj[6].push_back(4);
    adj[5].push_back(6);
    adj[5].push_back(2);
    adj[6].push_back(0);

    cout << "The mother vertex is " << findMother() <<  "\n";
}