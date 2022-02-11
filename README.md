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
    int N, M,s,t;
    cin >> N >> M >> s >> t;

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
### Sorting Based on Another Vector
```cpp
int main() {
    int n = 7;
    vector<int> a = {4, 8, 1, 3, 2, 9, 11};
    
    vector<int> ind(n);
    iota(ind.begin(), ind.end(), 0);
    for(auto a: ind) {
        cout << a << " ";
    }
    cout << "\n";
    
    sort(ind.begin(), ind.end(), [&](int i, int j) {
        return a[i] > a[j];
    });

    for(auto a: ind) {
        cout << a << " ";
    }
    cout << "\n";
}
```
### Common Elements in Vector
```cpp
int main() {
	int countCommon = 0;
	int n = 6;
	vector<int> vec1 = {1, 3, 5, 7, 8, 9};
	int m = 7;
	vector<int> vec2 = {1, 2, 3, 7, 9, 4, 8};

	sort(vec1.begin(), vec1.end());
	sort(vec2.begin(), vec2.end());

	vector<int> v(vec1.size() + vec2.size());

	auto it = set_intersection(vec1.begin(), vec1.end(),vec2.begin(), vec2.end(),v.begin());

	cout << "Common Elements : " << it - v.begin() << "\n";
	cout << "The elements are : ";

	for ( auto st = v.begin(); st != it; ++st) {
		cout << *(st) << " ";
	}
}
```
### Union Find - Disjoint Set Union
```cpp
struct UnionFind{
    int num;
    vector<int> rs, parent;
    UnionFind(int n): num(n), rs(n, 1), parent(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        return (x == parent[x] ? x : parent[x] = find(parent[x]));
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    void unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return;
        if (rs[x] < rs[y]) swap(x, y);
        rs[x] += rs[y];
        parent[y] = x;
        num--;
    }

    int size(int x) {
        return rs[find(x)];
    }

    int countSets() const {
        return num;
    }
};
```
### Breadth First Search
```cpp
void bfs()
{
    int n, m;
    cin>> n >> m;
    vector<int> adj[n+1];
    memset(adj, 0, sizeof adj);

    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // Source Vertex
    int s = 1;
    
    queue<int> q;
    vector<bool> used(n+1);
    vector<int> d(n+1), p(n+1);

    q.push(s);
    used[s] = true;
    p[s] = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (!used[u]) {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }

    // Check if there is any path between source vertex and vertex u.
    int u = 4;

    if (!used[u]) {
        cout << "No path!";
    } else {
        vector<int> path;
        for (int v = u; v != -1; v = p[v])
            path.push_back(v);
        reverse(path.begin(), path.end());
        cout << "Path: ";
        for (int v : path)
            cout << v << " ";
    }
}
```
### DFS - First and Last Order
```cpp
vector<int> G[100];
vector<int> first_order;
vector<int> last_order;
vector<bool>seen;

void dfs(int v, int& first_ptr, int& last_ptr) {
    first_order[v] = first_ptr++;

    seen[v] = true; 
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue;
        dfs(next_v, first_ptr, last_ptr);
    }
    last_order[v] = last_ptr++;
}

void solve()
{ 
	int N, M; cin >> N >> M;

	for (int i = 1; i <=M; ++i) {
	    int a, b;
	    cin >> a >> b;
	    G[a].push_back(b);
	    G[b].push_back(a);
	}

	seen.assign(100, false);
	first_order.resize(100);
    last_order.resize(100);
	int first_ptr = 0, last_ptr = 0;
	dfs(0, first_ptr, last_ptr);

	for (int v = 0; v < N; ++v)
        cout << v << ": " << first_order[v] << ", " << last_order[v] << endl;
}
```
### Dijkstra's Algorithm
```cpp
const int N = 3e5 + 9;
int n, m;
vector<pair<int, int>> g[N];


// First parameter is source vertex and second is adjacency list
vector<long long> dijkstra(int s, vector<pair<int, int>> g[])
{
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    vector<long long> d(n + 1, 1e18); vector<bool> vis(n + 1, 0);
    q.push({0, s});
    d[s] = 0;
    while(!q.empty()){
        auto x = q.top(); q.pop();
        int u = x.second;
        if(vis[u]) continue; vis[u] = 1;
        for(auto y: g[u]){
            int v = y.first; long long w = y.second;
            if(d[u] + w < d[v]){
                d[v] = d[u] + w; q.push({d[v], v});
            }
        }
    }
    return d;
}

 
int u[N], v[N], w[N];
void solve()
{
	cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> u[i] >> v[i] >> w[i];
        g[u[i]].push_back({v[i], w[i]});
        g[v[i]].push_back({u[i], w[i]});
    }

    auto d1 = dijkstra(1, g);
    auto d2 = dijkstra(5, g);
    auto d3 = dijkstra(8, g);

    for(int i = 1; i <= n; i++) {
    	cout << d1[i] << " ";
    }
    cout << "\n";
    for(int i = 1; i <= n; i++) {
    	cout << d2[i] << " ";
    }
    cout << "\n";
    for(int i = 1; i <= n; i++) {
    	cout << d3[i] << " ";
    }
    cout << "\n";
}

// Input
// 8 13
// 1 2 2
// 1 3 9
// 2 3 7
// 2 4 8
// 3 5 3
// 4 5 2
// 5 6 1
// 1 7 3
// 7 8 2
// 8 5 3
// 7 6 6
// 8 3 2
// 1 8 8

// Output
// 0 2 7 10 8 9 3 5 
// 8 10 3 2 0 1 5 3 
// 5 7 2 5 3 4 2 0 
```
### Lowest Common Ancestor
```cpp
const int maxN = 2e5 + 1;
const int logN = 20;

int p[maxN][logN];
int timer, in[maxN], out[maxN];
vector<int> G[maxN];

void dfs(int u = 1, int par = 1) {
	in[u] = ++timer;
	p[u][0] = par;
	for(int i = 1; i < logN; i++) {
		p[u][i] = p[p[u][i-1]][i - 1];
	}
	for(int v: G[u]) {
		if(v != par) {
			dfs(v, u);
		}
	}
	out[u] = ++timer;
}

bool ancestor(int u, int v) {
	return in[u] <= in[v] && out[u] >= out[v];
}

int lca(int u, int v) {
	if(ancestor(u, v)) return u;
	if(ancestor(v, u)) return v;

	for(int i = logN - 1; i >= 0; i--) {
		if(!ancestor(p[u][i] , v)) {
			u = p[u][i];
		}
	}
	return p[u][0];
}

void solve()
{
	int N, M, Q, x, y, a, b;
	cin >> N >> M >> Q;
	for(int i = 2; i <= N; i++) {
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}

	dfs();

	for(int q = 0; q < Q; q++) {
		cin >> a >> b;
		cout << lca(a, b) << "\n";
	}
}

// Input
// 11 10 4
// 1 2
// 2 3
// 3 4
// 3 5
// 4 6
// 4 7
// 5 9
// 2 8
// 8 10
// 8 11
// 11 6
// 7 9
// 4 9
// 6 7

// Output
// 2
// 3
// 3
// 4
```
### Number of Connected Components
```cpp
vector<int> G[100];

vector<bool> seen;
void dfs(int v) {
    seen[v] = true;
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue;
        dfs(next_v); 
    }
}


void solve()
{ 
    int N, M; cin >> N >> M;

    for (int i = 1; i <=M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int count = 0;
    seen.assign(100, false);
    for (int v = 1; v <=N; ++v) {
        if (seen[v]) continue; // Through if v has been searched
        dfs(v); // If v is unsearched, perform DFS starting from v
        ++count;
    }
    cout << count << endl;
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
### Heading
```cpp
Code here
```
### Heading
```cpp
Code here
```
### Heading
```cpp
Code here
```
### Heading
```cpp
Code here
```
### Heading
```cpp
Code here
```