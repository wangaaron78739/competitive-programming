// #include <iostream>
// #include <vector>
// #include <numeric>
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


int out[3][3];

void solve() {
    int k;
    cin >> k;
    out[0][0] = out[2][0] = out[2][1] = (1<<18)-1;
    out[0][2] = 0;
    out[1][0] = (1<<17);
    out[0][1] = out[1][1] = out[2][2] = (1<<17)-1;
    out[1][2] = (1<<17)-k;
    cout << 3 << 3 << endl;
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            cout << out[i][j];
            if (j!=2) cout << ' ';
            else cout << endl;
        }
    }
    cout << (out[0][0]& out[0][1]& out[1][1]&out[2][1]&out[2][2]) - (out[1][1]&out[1][2]&out[2][2]);
    }

int main() {
    int k;
    cin >> k;
    out[0][0] = out[2][0] = out[2][1] = (1<<18)-1;
    out[0][2] = 0;
    out[1][0] = (1<<17);
    out[0][1] = out[1][1] = out[2][2] = (1<<17)-1;
    out[1][2] = (1<<17)-1-k;
    cout << 3 << ' ' << 3 << endl;
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            cout << out[i][j];
            if (j!=2) cout << ' ';
            else cout << endl;
        }
    }
    // cout << (out[0][0]& out[0][1]& out[1][1]&out[2][1]&out[2][2]) - (out[1][1]&out[1][2]&out[2][2]);
	return 0;
}
