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


#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define F0R(i, a) for (ll i = 0; i < (a); i++)
#define FORd(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (ll i = (a)-1; i >= 0; i--)
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
    ll n,l,r;
    cin >> n >> l >> r;
    //1 x, 2(n-1), 2(n-2), 2(n-3), 1
    ll x = 1;
    ll a = 0;
    while(x < n && l > a+2ll*(n-x)) {
        a = a+2ll*(n-x);
        x++;
        // cout << imie(a) << endl;
    }
    ll y = x+1+(l-a)/2;
    // cout << imie(l) imie(r) imie(x) imie(y) << endl;
    FOR(i,l,r) {
        if (i%2) {
            cout << x << ' ';
        }
        else {
            cout << y << ' ';
            y++;
            if (y == n+1) {
                y = 1;
                x++;
            }
        }
    }
    if (r == n*(n-1ll)+1) cout << 1 << endl;
    else cout << n << endl;
}



int main() {
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
