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

int main() {
    int n;
    cin >> n;
    string s,t;
    cin >> s;
    cin >> t;
    int c = 0;
    string a = "";
    string b = "";
    for(int i=0;i<n;i++){
        if (s[i] == '1') c++;
        if (t[i] == '1') c--;
        if (s[i] != t[i]) {
            a += s[i];
            b += t[i];
        }
    }
    if (c != 0) {
        cout << "-1\n";
        return 0;
    }
    int m = 0;
    int curr = 0;
    int curr2 = 0;
    for(int i=0;i<a.size();i++) {
       if (a[i] == '1') curr++;
       else curr = max(0,curr-1);
       if (a[i] == '0') curr2++;
       else curr2 = max(0,curr2-1);
       m = max(m,curr);
       m = max(m,curr2);
       //debug() << imie(curr,curr2);
    }
    //curr = 0;
    //for(int i=0;i<b.size();i++) {
       //if (b[i] == '1') curr++;
       //else curr = 0;
       //m = max(m,curr);
    //}
    assert(a.size()%2 == 0);
    assert(a.size() == b.size());
    cout << m << endl;
    return 0;    
}
