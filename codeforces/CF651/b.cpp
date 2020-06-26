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

void solve(){
    int n;
    cin >> n;
    vector<int> odd;
    vector<int> even;
    for(int i=1;i<=2*n;i++) {
        int x;
        cin >> x;
        //cout << imie(x) << endl;
        if (x%2) odd.push_back(i);
        else even.push_back(i);
    }
    if (odd.size() % 2 == 1) {
        even.pop_back();
        odd.pop_back();
    } else {
        if (odd.size() >= 2) {
        odd.pop_back();
        odd.pop_back();

        } else {
            even.pop_back();
            even.pop_back();
        }
    }
    //cout << even.size() << odd.size() << "asdf "<< endl;
    for(int i=0;i+1<even.size();i += 2) {
        cout << even[i] << " " << even[i+1] << endl;
    }
    for(int i=0;i+1<odd.size();i+= 2) {
        cout << odd[i] << " " << odd[i+1] << endl;
    }
}
int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;    
}
