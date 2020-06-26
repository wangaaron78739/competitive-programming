#include <bits/stdc++.h>
using namespace std;

#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

typedef long long ll;
typedef long double ld;

#define ar array

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
// const int MAXN = 2e5+7;
// int a[MAXN];
void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	unordered_map<int,int> m;
	int MAX = 0;
	F0R(i,n) {
		int c;
		cin >> c;
		a[i] = c;
		m[c]++;
		MAX = max(MAX, m[c]);
	}
	int dist = m.size();
	if (dist == MAX) {
		cout << MAX-1 << endl;
	} else {
		cout << min(MAX,dist) << endl;
	}
}

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}