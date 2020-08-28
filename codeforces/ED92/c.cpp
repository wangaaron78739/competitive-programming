#include <bits/stdc++.h>
using namespace std;
template <class c> struct rge { c b, e; };
template <class c> rge<c> range(c i, c j) { return rge<c>{i, j}; }
template <class c> auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c> char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
template <class c> typename enable_if<sizeof dud<c>(0)!=1, debug&>::type operator<<(c i) {cerr << boolalpha << i; return * this; }
template <class c> typename enable_if<sizeof dud<c>(0)==1, debug&>::type operator<<(c i) {return * this << range(begin(i), end(i)); }
template <class c, class b> debug & operator <<(pair < b, c > d) {
  return * this << "(" << d.first << ", " << d.second << ")";
}
template <class c> debug & operator <<(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  return * this << "]";
}
#else
template <class c> debug & operator <<(const c&) { return * this; }
#endif
};
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

void solve() {
    string s;
    cin >> s;
    vector<int> f(10);
    int n = s.size();
    int ans = n;
    for(char c: s) {
        f[c-'0']++;
    }
    for(int i=0;i<=9;i++) ans = min(ans,n-f[i]);
    for(int i=0;i<=9;i++) {
        for(int j=0;j<=9;j++) {
            if (!f[i] || !f[j]) continue;
            if (i==j) continue;
            //int p1 = 0;
            //int p2 = 1;
            //int a = 0;
            //int b = 0;
            //for(int k=0;k<n;k++){
                //if (p1 == 0 && s[k] == i+'0') {
                    //a++;
                    //p1 = !p1;
                //}else if (p1 == 1 && s[k] == j+'0') {
                    //a++;
                    //p1 = !p1;
                //}
                //if (p2 == 0 && s[k] == i+'0') {
                    //b++;
                    //p2 = !p2;
                //}else if (p2 == 1 && s[k] == j+'0') {
                    //b++;
                    //p2 = !p2;
                //}
            //}
            int li = -1;
            int lj = -1;
            int ba = 0;
            int bb = 0;
            for(int k=0;k<n;k++){
                if (li != -1 && s[k] == j+'0') {
                    li = -1;
                    ba += 2;
                }
                if (lj != -1 && s[k] == i+'0') {
                    lj = -1;
                    bb += 2;
                }                
                if (li == -1 && s[k] == i+'0') li = k;
                if (lj == -1 && s[k] == j+'0') lj = k;

            }
            ans = min(ans, n-ba);
            ans = min(ans, n-bb);
        }
    }
    cout << max(ans,0) << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;    
}
