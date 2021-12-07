#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1000000007;

struct modint {
	ll n;
	modint() :n(0) { ; }
	modint(ll m) :n(m) {
		if (n >= mod)n %= mod;
		else if (n < 0)n = (n % mod + mod) % mod;
	}
	operator int() { return n; }
};

bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint& a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint& a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint& a, modint b) { a.n = ((ll)a.n * b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, ll n) {
	if (n == 0)return modint(1);
	modint res = (a * a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}
 
ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
modint operator/=(modint& a, modint b) { a = a / b; return a; }

const int max_n = 1 << 10;
modint fact[max_n], factinv[max_n];

void init_factorial() {
	fact[0] = modint(1);
	for (ll i = 0; i < max_n - 1; i++) {
		fact[i + 1] = fact[i] * modint(i + 1);
	}
	factinv[max_n - 1] = modint(1) / fact[max_n - 1];
	for (ll i = max_n - 2; i >= 0; i--) {
		factinv[i] = factinv[i + 1] * modint(i + 1);
	}
}

modint nCr(ll a, ll b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[b] * factinv[a - b];
}

modint nPr(ll a, ll b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[a - b];
}
 
 
istream& operator >>(istream &is, modint &ope){
	ll t; is >> t, ope.n = t;
	return is;
}
ostream& operator <<(ostream &os, modint &ope){return os << ope.n;}
ostream& operator <<(ostream &os, const modint &ope){return os << ope.n;}

int main() {
    int a = 10, b = 3;
    init_factorial();
    cout << "nCr(" << a << "," << b << ") = " << nCr(a, b) << "\n";
    cout << "nPr(" << a << "," << b << ") = " << nPr(a, b) << "\n";
    return 0;
}

