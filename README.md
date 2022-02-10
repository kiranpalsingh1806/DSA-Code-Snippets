# DSA Code Snippets

### Check if ith bit is on
```cpp
for(int i = 0; i < 32; i++) {
    if(x & (1 << i)) {
        // True if ith bit of x is set
    }
}
```
### Moving in four directions in grid

```cpp
int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

for (auto &dir : dirs) {
    int a = x + dir[0], b = y + dir[1];
    // Here x and y is our current location.
}
```

### Can We Go From Source To Destination
```cpp
vector<int> G[100];
vector<bool>seen;

void dfs(int v) {
    seen[v] = true;
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue;
        dfs(next_v);
    }
}

void solve() { 
    int N, M,s,t; cin >> N >> M >> s >> t;

    for (int i = 1; i <=M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    seen.assign(100, false);
    dfs(s);

    if (seen[t]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}
```
### Maximum Digit in Number
```cpp
int maxDigitInNumber(int n) {
    if(n < 10) return n;
    return max( maxDigitInNumber(n / 10), n % 10);
}
```
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
### Heading
```cpp
Code here
```
### Heading
```cpp
Code here
```