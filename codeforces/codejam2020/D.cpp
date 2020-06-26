#include <bits/stdc++.h>

using namespace std;

#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define ar array

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
// #define s second
#define lb lower_bound
#define ub upper_bound


#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }
int b;

void solve(int ca) {
    int bit;
    vector<int> v(b,-1);
    bool rev = false;
    bool comp = false;
    int idx = -1;
    for(int i=0;i<5;i++) {
        cout << 1+i;
        cin >> v[i];
        cout << b-i;
        cin >> v[b-1-i];
        if (v[1+i] != v[b-i]) idx = i;
    }
    cout << 1;
    cin >> bit;
    if (bit != v[0]) {
        if (idx == -1) comp = true;

    }
    cout << b;
    cin >> bit;
    
    if (~idx) {

    }


    if (v[1]==v[b]) {

    }
    for(int que=0;que<150;que++) {
        if (que) {
            cout << 0;
            cin >> bit;
            v[0] = bit;
        }
        else if (que%10 == 0) {
            cin >> bit;

        }
    }
}

int main() {
	int T;
	cin >> T >> b;
	F0R(i,T) solve(i+1);
	return 0;
}
