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
    int a,b,c,d;
    int x,y,x1,y1,x2,y2;
    cin >> a >> b >> c >> d;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    int lr = b-a;
    int ud = d-c;
    bool can = true;
    if (lr>0 && x+lr>x2) { 
        can = false;
    }
    if (lr < 0 && x+lr<x1) {
        can = false;
    }
    if (lr == 0 && (x1 == x && x2 == x) && (b||a)) {
        can = false;
    }
    if (ud>0 && y+ud>y2) {
        can = false;
    }
    if (ud < 0 && y+ud<y1) {
        can = false;
    }
    if (ud == 0 && (y1 == y && y2 == y) &&(c||d)) {
        can = false;
    }
    if (can) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
