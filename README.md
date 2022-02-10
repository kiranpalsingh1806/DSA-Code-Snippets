Bit Manipulation
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

void solve()
{ 
	int N, M,s,t; cin >> N >> M >> s >> t;

	for (int i = 1; i <=M; ++i) {
	    int a, b;
	    cin >> a >> b;
	    G[a].push_back(b);
	}

	seen.assign(100, false);
	dfs(s);

	if (seen[t]) cout << "Yes" << endl;
    else cout << "No" << endl;
}
```
### Heading
```cpp
Code here
```