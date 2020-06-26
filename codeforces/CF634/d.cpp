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

int a[9][9];

void solve() {
	string s;
	for(int i=0;i<9;i++) {
		cin >> s;
		for(int j=0;j<9;j++) {
			a[i][j] = s[j]-'0';
			if (a[i][j] == 1) a[i][j] = 2;
		}
	}
	F0R(i,9) {
		F0R(j,9) cout << a[i][j];
		cout << endl;
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