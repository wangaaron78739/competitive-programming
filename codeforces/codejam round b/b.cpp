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

ll a,b;
string result;
void send(ll x, ll y) {
	cout << x << " " << y "\n";
}
int read() {
	cin >> result;
		switch(result) {
		case "CENTER":
			return -1;
		case "HIT":
			break 1;
		case "MISS":
			break 0;
	}
}
ll t,d,l,r;
int tf,df,lf,rf;
void solve() {
	t = 1e9;
	d = -1e9;
	l = -1e9;
	r = 1e9;
	while(t != d || l != r) {
		send((3ll*l+r)/4,(t+d)/2);
		lf = read();
		if (lf == -1) return;
		send((l+3ll*r)/4,(t+d)/2);
		rf = read();
		if (rf == -1) return;
		send((l+r)/2,(3ll*t+d)/4);
		tf = read();
		if (tf == -1) return;
		send((l+r)/2,(t+3ll*d)/4);
		df = read();
		if (df == -1) return;
		if(!lf) l = 
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	cin >> T >> a >> b;
	for(int i=1;i<=T;i++) {
		// cout << "Case #"<< i << ": ";
		solve();
	}
	return 0;
}