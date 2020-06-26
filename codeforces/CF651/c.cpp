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

void win(int i) {
    if (i%2) {
        cout << "FastestFinger\n";
    }
    else {
        cout << "Ashishgup\n";
    }
}

bool isPrime(int x) {
    for (int d = 3; d * d <= x; d+=2) {
        if (x % d == 0)
            return false;
    }
    return true;
}
void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        win(1);
        return;
    }
    if (n == 2) {
        win(0);
        return;
    }
    if (n % 2) {
       win(0); 
       return;
    }
    int count = 0;
    while(n%2 == 0) {
        count++;
        n /= 2;
    }
    if (n == 1) {
        win(1);
        //debug() << "test" ;
        return;
    }
    if (count == 1) {
        //win(1);
        //int cnt = 0;
        //for(int i=3;i <=n;i+= 2) {
            //while(n%i == 0) {
                //cnt++;
                //n = n/i;
            //}
            //if (n == 1) break;
        //}
        //debug() << cnt;
        if (isPrime(n)) win(1);
        else win(0);
        return;
    }
    win(0);
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;    
}
