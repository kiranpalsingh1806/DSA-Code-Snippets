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
### Knight Moves in Chessboard

```cpp
int dirs[8][2] = {{-2,1}, {-1,2}, {1,2}, {2,1}, {2,-1}, {1,-2}, {-1,-2}, {-2,-1}};

for (auto &dir : dirs) {
    int a = x + dir[0], b = y + dir[1];
    // Here x and y is our current location.
}
```
### Binary Search - When middle goes out of range

```cpp
int M = (L + R) / 2;
// signed integer overflow: 1063376696 + 2126753390 cannot be represented in type 'int'

int M = L + (R - L) / 2
// This will prevent overflowing.
```
### Find element in vector and replace it
```cpp
auto it = find (V.begin(), V.end(), num);
// it - V.begin() will given index of given num [0-indexed]
V[it - V.begin()] = otherNum;
```
### Generating Random Numbers in Range
```cpp
mt19937 rng{random_device{}()};
uniform_real_distribution<double> uni{0, 1};
// It will generate the random numbers every time in given range
// cout << uni(rng) << "\n";
```
### Dummy Head Node and its pointer
```cpp
// Creates a dummy head node and a pointer tail which points to dummy initially.
ListNode dummy, *tail = &dummy;
tail->next = new ListNode(val);
tail = tail->next;

// dummy is not a pointer but a ListNode so we must use dummy.next.
return dummy.next;
```
### Rotate Array Left or right

```cpp
// Array - 1 2 3 4 5 6 7 8 9

// Rotate array to left by 3 positions.
// 4 5 6 7 8 9 1 2 3
rotate(vec1.begin(), vec1.begin() + 3, vec1.end());

// Rotate array to right by 3 positions.
// 7 8 9 1 2 3 4 5 6
rotate(vec1.begin(), vec1.begin() - 3, vec1.end());
```
### Longest Increasing Subsequence - LIS DP

```cpp
int LIS(vector<int> &a) {
    int n = a.size();
    vector<int> dp(n, 1e9);

    for(int i = 0; i < n; i++) {
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);
        *it = a[i];
    }

    return lower_bound(dp.begin(), dp.end(), 1e9) - dp.begin();
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
### Convert Vector to Unordered Set
```cpp
vector<string> V = {"One", "Two", "Three", "Four", "Five"};
unordered_set<string> S(V.begin(), V.end());

// Use Cases
// -> To find any particular element : S.count("word");
// -> To erase any particular element : S.erase("word");
```

### Number of set bits in number
```cpp
int setbitsCnt = __builtin_popcount(x);
long int setbitsCnt = __builtin_popcountl(x);
long long setbitsCnt = __builtin_popcountll(x);
```
### Lambda Function to Check if Vector is Permutation 
```cpp
int n = 6;
auto isPermutation = [&](const vector<int> &A)->bool{
    vector<int> vis(n + 1, false);
    for(auto x : A){
        if(x <= 0 || x > n || vis[x])
            return false;
        vis[x] = true;
    }
    return true;
};

vector<int> A = {1, 2, 3, 4, 5, 1};
vector<int> B = {3, 4, 5, 6, 1, 2};

if(isPermutation(A)) {
    cout << "Vector A is permutation" << "\n";
}
if(isPermutation(B)) {
    cout << "Vector B is permutation" << "\n";
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
        int , v;
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

class UnionFind {
    private:
        vector<int> id, rank;
        int cnt;
    public:
        UnionFind(int cnt) : cnt(cnt) {
            id = vector<int>(cnt);
            rank = vector<int>(cnt, 0);
            for (int i = 0; i < cnt; ++i) id[i] = i;
        }
        int find(int p) {
            if (id[p] == p) return p;
            return id[p] = find(id[p]);
        }
        int getCount() { 
            return cnt; 
        }
        bool connected(int p, int q) { 
            return find(p) == find(q); 
        }
        void connect(int p, int q) {
            int i = find(p), j = find(q);
            if (i == j) return;
            if (rank[i] < rank[j]) {
                id[i] = j;  
            } else {
                id[j] = i;
                if (rank[i] == rank[j]) rank[j]++;
            }
            --cnt;
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
### Euler Phi Function
```cpp
vector< int > euler_phi_table(int n) {
  vector< int > euler(n + 1);
  for(int i = 0; i <= n; i++) {
    euler[i] = i;
  }
  for(int i = 2; i <= n; i++) {
    if(euler[i] == i) {
      for(int j = i; j <= n; j += i) {
        euler[j] = euler[j] / i * (i - 1);
      }
    }
  }
  return euler;
}

template< typename T >
T euler_phi(T n) {
  T ret = n;
  for(T i = 2; i * i <= n; i++) {
    if(n % i == 0) {
      ret -= ret / i;
      while(n % i == 0) n /= i;
    }
  }
  if(n > 1) ret -= ret / n;
  return ret;
}

void EulerPhiDemo(int n) {
  int countPhi = 0;
  vector<int> whichNum;
  for(int i = 0; i <= n; i++) {
    if(gcd(i, n) == 1) {
      whichNum.push_back(i);
      countPhi++;
    }
  }
  cout << "Euler Phi of " << n << " : " << countPhi << "\n";
  cout << "The numbers are : ";
  for(auto &a: whichNum){
    cout << a << " ";
  }
  cout << "\n";
}

void solve()
{
	auto eulerTable = euler_phi_table(100);
	for(auto &a: eulerTable) {
		cout << a << " ";
	}
	cout << "\n";

	auto eulerNumber = euler_phi(20);
	cout << eulerNumber << "\n";

  EulerPhiDemo(5);
  EulerPhiDemo(11);
  EulerPhiDemo(20);
}

// Output
// Euler Phi Table
// 0 1 1 2 2 4 2 6 4 6 4 10 4 12 6 8 8
// 16 6 18 8 12 10 22 8 20 12 18 12 28
// 8 30 16 20 16 24 12 36 18 24 16 40
// 12 42 20 24 22 46 16 42 20 32 24 
// 52 18 40 24 36 28 58 16 60 30 36
// 32 48 20 66 32 44 24 70 24 72 36
// 40 36 60 24 78 32 54 40 82 24 64
// 42 56 40 88 24 72 44 60 46 72 32
// 96 42 60 40 

// Euler Phi Number
// 8

// Euler Phi Demo
// Euler Phi of 5 : 4
// The numbers are : 1 2 3 4 
// Euler Phi of 11 : 10
// The numbers are : 1 2 3 4 5 6 7 8 9 10 
// Euler Phi of 20 : 8
// The numbers are : 1 3 7 9 11 13 17 19 
```
### Point Structure - Geometry
```cpp
typedef double T;
struct pt {
	T x, y;
	pt operator+ (pt p) {
		return {x + p.x, y + p.y};
	}

	pt operator- (pt p) {
		return {x - p.x, y - p.y};
	}

	pt operator* (T d) {
		return { x * d, y * d};
	}

	pt operator/ (T d) {
		return {x/d, y/d};
	}
};

bool operator==(pt a, pt b) {
	return a.x == b.x && a.y == b.y;
}

bool operator!= (pt a, pt b) {
	return !(a == b);
}

T sq(pt p) {
	return p.x * p.x + p.y * p.y;
}

double abs(pt p) {
	return sqrt(sq(p));
}

ostream& operator<< (ostream& os, pt p) {
	return os << "(" << p.x << "," << p.y << ")";
}

void solve()
{
    pt a, b;
    cin >> a.x >> a.y >> b.x >> b.y;
    cout << a+b << " " << a-b << "\n"; 
    cout << a*-1 << " " << b/2 << "\n"; 

    pt c;
    cin >> c.x >> c.y;
    cout << abs(c) << "\n";
}

// Input
// 3 4
// 2 -1
// -5 -10

// Output
// (5,3) (1,5)
// (-3,-4) (1,-0.5)
// 11.1803

```

### Finding if element inserted in set or not
```cpp
set<int> S;
int N = 6;
for(int i = 0; i < N; i++) {
    int x; cin >> x;
    if(S.insert(x).second) {
        cout << "New Element is inserted :)" << "\n";
    } else {
        cout << "Element already exists  :(" << "\n";
    }
}

// Input = 1 2 3 4 2 5
// Output: 
// New Element is inserted :)
// New Element is inserted :)
// New Element is inserted :)
// New Element is inserted :)
// Element already exists  :(
// New Element is inserted :)
```

### Adding numbers in string
```cpp
string addStr(const string& a, const string& b) {
	int as = (int)a.size() - 1;
	int bs = (int)b.size() - 1;
	string res;
	int carry = 0;
	for (int i = 0;; ++i) {
		int v = carry;
		carry = 0;
		if (i <= as) v += a[as-i] - '0';
		if (i <= bs) v += b[bs-i] - '0';
		if (v >= 10) {
			v -= 10;
			carry = 1;
		}
		if (i > as && i > bs && v == 0) break;
		res.push_back(v + '0');
	}
	reverse(res.begin(), res.end());
	return res;
}


void solve()
{
	string a, b;
	cin >> a >> b;

	string ans = addStr(a, b);
	cout << ans << "\n";
}

// Input
// 5555
// 4444

// Output
// 9999
```
### Longest Prefix Suffix
```cpp
// Longest prefix which is also suffix
// The prefix and suffix should not overlap
vector<int> computeLPS(string t) {
	int m = t.length();
    vector<int> lps(m);
 
    int i = 1, len = 0;
    lps[0] = 0;
 
    while (i < m) {
        if (t[i] == t[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

void solve()
{
	string a, b;
    cin >> a >> b;  

    auto A = computeLPS(a);
    auto B = computeLPS(b);

    for(auto &a: A) {
        cout << a << " ";
    }
    cout << "\n";

    for(auto &b: B) {
        cout << b << " ";
    }
    cout << "\n";
}

// Input
// abcdabcdabcd
// abcdefabcdefabcdef
// Output
// 0 0 0 0 1 2 3 4 5 6 7 8 
// 0 0 0 0 0 0 1 2 3 4 5 6 7 8 9 10 11 12 

```
### Sorting String based on number of ones
```cpp
void solve()
{
	int n;
	cin >> n;
	vector<string> s(n);

	for(int i = 0; i < n; i++) {
		cin >> s[i];
	}
	sort(s.begin(), s.end(), [&](string x, string y) {
        return count(x.begin(), x.end(), '1') < count(y.begin(), y.end(), '1');
    });

    for(int i = 0; i < n; i++) {
    	cout << s[i] << "\n";
    }
}

// Input
// 5
// 10101
// 10000000
// 010101
// 00111111
// 11000000000

// Output
// 10000000
// 11000000000
// 10101
// 010101
// 00111111
```
### Rabin Karp Algorithm
```cpp
string s,t;
//t -> text s-> pattern

vector<int> rabin_karp(string const& s, string const& t) {
    const int p = 31; 
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(T + 1, 0); 
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 
    long long h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 

    vector<int> occurences;
    for (int i = 0; i + S - 1 < T; i++) { 
        long long cur_h = (h[i+S] + m - h[i]) % m; 
        if (cur_h == h_s * p_pow[i] % m)
            occurences.push_back(i);
    }
    return occurences;
}

void solve()
{
    cin >> t >> s;
    ll n = s.length();

    // Prints the vector of indices where pattern is matched in text.
    auto a = rabin_karp(s, t);
    for(auto &ele: a) {
        cout << ele << " ";
    }
    cout << "\n";
}

//Input
// abcdeaabcfgabc abc
// Output
// 0 6 11
```
### Z Function - Prefix Function
```cpp
vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
```
### Kadane Algorithm
```cpp
ll maxSumSubarray (vector<ll> A) {
	ll n = A.size();
	ll local_max = 0;
	ll global_max = -inf;
	for (ll i=0; i<n; i++) {
			local_max = max(A[i], A[i] + local_max);

			if (local_max > global_max){
				global_max = local_max;
			}	
	}
	return global_max;
}


void solve()
{ 
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	ll mx = maxSumSubArray(a);
	cout << mx << "\n";
}
```
### Sorting by Comparator Function
```cpp
bool cmp(const pair<string, long> &p1, const pair<string, long> &p2)
{
    if(p1.second!=p2.second)
        return p1.second < p2.second;
    return p1.first < p2.first;
}

sort(vect.begin(), vect.end(), cmp);
```
### Structure Sorting Comparator
```cpp
struct city {
	string name;
	int score, index;
};

int n;

bool comp(const city a, const city b) {
	if(a.name != b.name) {
		return a.name < b.name;
	}
	return a.score > b.score;
}

void solve() {
	cin >> n;
	vector<city> cities(n);
	for(int i = 0; i < n; i++) {
		cin >> cities[i].name >> cities[i].score;
		cities[i].index = i + 1;
	}	

	sort(cities.begin(), cities.end(), comp);

	for(int i = 0; i < n; i++) {
		cout << cities[i].index << "\n";
	}
}

// Input
// 6
// khabarovsk 20
// moscow 10
// kazan 50
// kazan 35
// moscow 60
// khabarovsk 40

// Output
// 3
// 4
// 6
// 1
// 5
// 2

```
### Max Heap and Min Heap
```cpp
// Minimum heap and Maximum heap
void solve()
{
	priority_queue<int, vector<int>, greater<int> > minHeap;
	priority_queue<int, vector<int> > maxHeap;

	int n, x;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x;
		minHeap.push(x);
		maxHeap.push(x);
	}

	auto a = minHeap;
	while(!a.empty()) {
		cout << a.top() << " ";
		a.pop();
	}
	cout << "\n";

	auto b = maxHeap;
	while(!b.empty()) {
		cout << b.top() << " ";
		b.pop();
	}
	cout << "\n";
}

// Input
// 8
// 1 5 2 19 23 9 7 33
// Output
// 1 2 5 7 9 19 23 33 
// 33 23 19 9 7 5 2 1 
```
### Next Permutation
```cpp
void solve()
{
	string s;
	cin >> s;
	sort(s.begin(), s.end());

	do {
		cout << s << "\n";
	} while(next_permutation(s.begin(), s.end()));
}

// Input
// abcd

// Ouput
// abcd
// abdc
// acbd
// acdb
// adbc
// adcb
// bacd
// badc
// bcad
// bcda
// bdac
// bdca
// cabd
// cadb
// cbad
// cbda
// cdab
// cdba
// dabc
// dacb
// dbac
// dbca
// dcab
// dcba
```
### Chicken McNugget Theorem
```cpp
/* The Chicken McNugget Theorem states that for any two relatively prime positive
integers m and n, the greatest integer that cannot that cannot be written
in the form a*m + b *n for non-negative integers a, b is mn - m - n.  */

bool chickenMcNuggetTheorem(int m, int n, int number) {
	for(int i = 0; i <= 10; i++) {
		int y = number - i * n;
		if(y >= 0 && y % m == 0) {
			return true;
		}	
	}
	return false;
}

bool chickenMcNuggetTheoremModified(int m, int n, int number) {
	if(number >= n * (number % m)) {
		return true;
	} else {
		return false;
	}
}

void solve()
{
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		if(chickenMcNuggetTheoremModified(11, 111, n)) {
			cout << "YES" << "\n";
		} else {
			cout << "NO" << "\n";
		}
	}
}

// Input
// 3
// 33
// 144
// 69

// Output
// YES
// YES
// NO

```
### Sum of Two Numbers with Given Base
```cpp
// Returns sum of two numbers a and b with given base 
int sumWithBase(string a, string b, int base)
{
    int len_a, len_b;
 
    len_a = a.size(); len_b = b.size();
 
    string sum, s;
    s = "";
    sum = "";
 
    int diff;
    diff = abs(len_a - len_b);
 
    for (int i = 1; i <= diff; i++) s += "0";
 
    if (len_a < len_b) a = s + a;
    else b = s + b;
 
    int curr, carry = 0;
 
    for (int i = max(len_a, len_b) - 1; i > -1; i--) 
    {
        curr = carry + (a[i] - '0') + (b[i] - '0');
        carry = curr / base;
        curr = curr % base;
        sum = (char)(curr + '0') + sum;
    }

    if (carry > 0) sum = (char)(carry + '0') + sum;
    
    int ans = stoi(sum);
    return ans;
}

void solve()
{
    string a, b;
    cin >> a >> b;
    cout << sumABwithBase(a, b, 10);
}

// Input
// 11 12
// Output
// 23
```
### Prime Numbers in Range
```cpp
const ll MAXN = 1e7;
bool comp[MAXN + 10];
vector<ll> primeVec;

void sieveOfEratosthenes()
{
   for(int i = 2; i <= MAXN; i++){
        if(comp[i]) continue;
        primeVec.pb(i);        
        for(int j = 2 * i; j <= MAXN; j += i){
            comp[j] = true;
        }
    }
}

int L,R;

void solve()
{
    // Implementation
    sieveOfEratosthenes();
    cin >> L >> R;
    // For finding prime numbers in range L,R
    ll rangeAns = (upper_bound(primeVec.begin(), primeVec.end(), R)
                 - upper_bound(primeVec.begin(), primeVec.end(), L));

    cout << rangeAns;
}

// Input - > 1 100
// Output -> 25 (25 Prime numbers between 2 and 100 inclusive)
```
### Convert To Decimal From Base K
```cpp

int convertToDecimal(string s, int k) {
  int ans = 0;
  for(char x: s) {
    ans *= k;
    ans += x - '0';
  } return ans;
}

int main(){
    int k;
    string a,b;
    cin >> k >> a >> b;
    int A = convertToDecimal(a, k);
    int B = convertToDecimal(b, k);
    cout << A*B << endl;
    return 0;
}
```
### Maximum GCD in range [L, R]
```cpp
// Finding maximum gcd of two numbers a and b in range [L, R]
// in O(n) time instead of O(n ^ 2) time.
	// cin >> L >> R;
int maxGCD = -1e9;
int operations = 0;

for(int i = L; i <= R; i++) {
	for(int j = i + 1; j <= R; j++) {
		maxGCD = max(maxGCD, int(gcd(i, j)));
		operations++;
	}
}

cout << maxGCD << "\n";
int modifiedOperations = 0;

for(int c = R; c > 0; c--) {
	modifiedOperations++;
	if((L + c - 1) / c < R / c) {
		cout << c << "\n";
		goto end;
	}
}
end:;

cout << operations << "\n";
cout << modifiedOperations << "\n";

// Input
// 100 279
// Output
// 139
// 139
// 16110
// 141
```
### Prefix Sum 2D
```cpp
#include<bits/stdc++.h>
using namespace std;

constexpr int MAX_SIDE = 1000;
int prefixSum2D[MAX_SIDE + 1][MAX_SIDE + 1];
int array2D[MAX_SIDE + 1][MAX_SIDE + 1];

void solve()
{
	int N;
	int Q;
	cin >> N >> Q;
	// read the 2D array
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> array2D[i][j];
		}
	}

	// build the prefix sum array
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			prefixSum2D[i][j] = array2D[i][j]
						+ prefixSum2D[i - 1][j]
						+ prefixSum2D[i][j - 1]
						- prefixSum2D[i - 1][j - 1];
		}
	}

	for (int q = 0; q < Q; q++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << prefixSum2D[x2][y2]
				- prefixSum2D[x1-1][y2]
				- prefixSum2D[x2][y1-1]
				+ prefixSum2D[x1-1][y1-1] << '\n';
	}

}

int main(void) {
	solve();
}
```
### Numeric Limits
```cpp
long long a = numeric_limits<long long>::max();
int b = numeric_limits<int>::max();
```
### Count frequency of each character in string
```cpp
int cnt[26] = {0};
for (char c : s) {
  cnt[c - 'a']++;  
} 

```
### Erase Duplicates in Vector
```cpp
unorder_set<int> s;
for(int i : vec) {
    s.insert(i);
}

vec.assign(s.begin(), s.end());
sort(vec.begin(), vec.end());

Another Method: Slower than the above method

sort(vec.begin(), vec.end());
vec.erase(unique(vec.begin(), vec.end()), vec.end());
```