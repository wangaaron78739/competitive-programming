#include <bits/stdc++.h>
using namespace std;

#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;


#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound


#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }


vector<vector<int> > adj;
vector<vector<int> > seen;
vector<int> pare;
vector<int> currpath;
vector<bool> asdf;
	int n,m;

void dfs(int par) {
	asdf[par] = true;
	// 	if (seen[par].empty()) {
	// 	seen[par] = currpath;
	// 	if (par != 0) seen[par].pop_back();
	// }
	for(int v:adj[par]) {
		if (asdf[v]) continue;
		pare[v] = par;
		currpath.push_back(v);
		dfs(v);
		currpath.pop_back();
	}
}
vector<int> currlong, fdsa;

int check() {
	if (currlong.size() >= fdsa.size()) {
		for(int i=0;i<fdsa.size();i++) {
			if (currlong[i] != fdsa[i]) return 0;
		}
		return 1;
	}
	for(int i=0;i<currlong.size();i++) {
		if (currlong[i] != fdsa[i]) return 0;
	}
	currlong = fdsa;
	return 1;
}

void solve() {
	int k; cin >> k;
	int can = 1;
	int next;
	currlong.clear();
	fdsa.clear();
	F0R(i,k) {
		cin >> next;next--;
		// cout << imie(next);
		// trav(a,currlong) cout << a << ' ';
		// cout << endl;
		// trav(a,fdsa) cout << a << ' ';
		// cout << endl;
		if (!can) continue;
		int curr = next;
		fdsa.clear();
		while(~curr) {
			curr = pare[curr];
			fdsa.push_back(curr);
		}
		// cout << imie(next);
		// trav(a,fdsa) cout << a << ' ';
		// cout << endl;
		fdsa.pop_back();
		reverse(fdsa.begin(),fdsa.end());
		if (currlong.empty()) {
			currlong = fdsa;
			continue;
		}
	

		if (check()) {
			continue;
		}
		can = 0;
	}
	if (can) {
		cout << "YES" << endl;
	}else {
		cout << "NO" << endl;
	}
}

int main() {
	cin >> n >> m;
	adj.resize(n);
	seen.resize(n);
	asdf.resize(n);
	pare.resize(n);
	F0R(i,n-1) {
		int u,v;
		cin >> u >> v;
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	// currpath.push_back(0);
	pare[0] = -1;
	dfs(0);
	// F0R(i,n) {
	// 	cout << imie(i)<<endl;
	// 	trav(a,seen[i]) cout << a << ' ';
	// 	cout << endl;
	// }
	while(m--) solve();
	return 0;
}
