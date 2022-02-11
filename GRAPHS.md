### Print Euler Tour
```cpp

vector<int> adj[1000]; 
int vis[1000]; 
int Euler[2000]; 

void eulerTree(int u, int &indx)
{
    vis[u] = 1;
    Euler[indx++] = u;
    for (auto it : adj[u]) {
        if (!vis[it]) {
            eulerTree(it, indx);
            Euler[indx++] = u;
        }
    }
}
 
void printEulerTour(int root, int N)
{
    int index = 0;  
    eulerTree(root, index);
    for (int i = 0; i < (2*N-1); i++)
        cout << Euler[i] << " ";
}

void solve() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    printEulerTour(1, n);
}
```