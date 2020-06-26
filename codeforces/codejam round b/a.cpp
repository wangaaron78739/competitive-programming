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

bitset<32> xb,yb;
int xr,yr;
void output() {
	for(int i=0;i<n-1;i++) {
		if (xb[32-i-1]) {

		}else if(yb[32-i-1]){

		}
	}
	if (xb[32-n-1]) {

	}else if(yb[32-n-1]) {

	}
}

void solve() {
	ll x,y;
	xr=0;yr=0;
	cin >> x >> y;
	int n = 1;
	if (x<0) x= -x, xr = 1;
	if (y<0) y= -y, yr = 1;
	while (1<<n <=x) n++;
	while (1<<n <=y) n++;
	xb = bitset<32>(x);
	yb = bitset<32>(y);
	int flag = 1;
	for(int i=0;i<n-1;i++) {
		if (xb[32-i-1] == yb[32-i-1]) flag = 0;
	}
	if (flag == 1) {
		output();
		return;
	}
	xr = !xr;
	xb.flip();
	flag = 1;
	for(int i=0;i<n;i++) {
		if (xb[32-i-1] == yb[32-i-1]) flag = 0;
	}
	if (flag == 1) {
		output();
		return;
	}
	xr = !xr;
	xb.flip();
	xr = !xr;
	yb.flip();
	flag = 1;
	for(int i=0;i<n;i++) {
		if (xb[32-i-1] == yb[32-i-1]) flag = 0;
	}
	if (flag == 1) {
		output();
		return;
	}
	cout << "IMPOSSIBLE\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	cin >> T;
	for(int i=1;i<=T;i++) {
		cout << "Case #"<< i << ": ";
		solve();
	}
	return 0;
}