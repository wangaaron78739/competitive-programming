	int a[9][9];
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

const int maxN = 2e5+3;
int v[maxN][201];

void solve() {
	int n;
	cin >> n;
	int curr = -1;
	int idx = 0;
	for(int i=0;i<201;i++) {
		v[0][i] = 0;
	}
	for(int i=1; i<n+1;i++) {
		int t;
		cin >> t;
		t--;
		if (t != curr || i == n) {
			idx++;
			F0R(j,201) {
				v[idx][j] = v[idx-1][j];
			}
			v[idx][t]++;
			curr = t;
		} else {
			v[idx][t]++;
		}
	}
	// cout << imie(idx) imie(v[3][2]);
 	int best = 0;
 	FOR(l,0,idx+1) {
 		FOR(r,l,idx+1) {
 			int m1 = 0,m2 = 0;
 			F0R(i,201) {
 				m1 = max(m1,min(v[l][i],v[idx][i]-v[r][i]));
 				m2 = max(m2,v[r][i]-v[l][i]);
 			}
 			// if (best <= m2+2*m1) {
 			// 	cout << imie(best) << m2+2*m1 << imie(l) imie(r);
 			// }
 			best = max(best,m2+2*m1);
 		}
 	}
 	cout << best << endl;
}

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}