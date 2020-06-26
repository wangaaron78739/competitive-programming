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



void solve() {
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int chan = 0;

    for(int i=0;i<(k+1)/2;i++) {
        // cout << imie(i) << endl;
        vector<int> count(26,0);
        for(int num = 0; num < (n/k); num++) {
            // cout << imie(num*k+i) imie(s[num*k+i]) << endl;
            // assert(s[num*k+i]-'a'>=0);
           count[s[num*k+i]-'a']++; 
           if ((k%2)==0 || i<(k+1)/2-1) count[s[num*k+k-i-1]-'a']++; 
        }

        int maxC = 0;
        for(int j=0;j<26;j++) maxC = max(maxC,count[j]);
        int res = (n/k)-maxC;
        // cout << imie(res) ;
        if ((k%2)==0 || i<(k+1)/2-1) res+=(n/k);
        // cout << imie(res) << endl;
        chan += res;
        // cout << imie(chan) << endl;
        }
    cout << chan << endl;

}

int main() {
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
