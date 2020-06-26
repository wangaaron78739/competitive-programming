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

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n),b(n), c(n);
    F0R(i,n) cin >> a[i] >> b[i];
    c[0] = max(0ll,a[0]-b[n-1]);
    int maxidx = 0;
    int needed = c[0];
    FOR(i,1,n) {
        c[i] = max(0ll,a[i]-b[i-1]);
    }
    vector<ll> dp(n,1e12+1);
    vector<array<ll,2>> dp(n,{1e12+7,1e12+7});
    dp[0][0] = a[0];
    dp[0][1] = c[0];
    F0R(i.1,n) {
        dp[i][0] = a[i];
    }
    cout << needed << endl;
}



int main() {
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
