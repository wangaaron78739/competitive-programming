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
    int p,c;
    int _p = 0,_c=0;
    int yes = 1;
    F0R(i,n) {
        cin >> p >> c;
        if (p<_p||c<_c) {
            yes = 0;
        }
        else if (p==_p && c != _c) yes = 0;
        else if (p-_p < c-_c) yes = 0;
        
        _p = p;
        _c = c;
    }
    if (yes) {
        cout << "YES" << endl;
    }else {
        cout << "NO" << endl;
    }
}

int main() {
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
