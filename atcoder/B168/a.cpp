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

const ll MOD = 1e9+7;

void add_self(ll&a, ll b) {
	a = (a+b)%MOD;
}

const ll mod2 = (MOD-(MOD/2ll))%MOD;

ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

int main() {
	int n;
	cin >> n;
	map<pair<ll,ll>,ll> m;
	for(int i=0;i<n;i++) {
		ll a, b;
		cin >> a >> b;
		ll c = gcd(abs(a),abs(b));
		a /= c;
		b /= c;
		m[{a,b}]++;
	}
	ll sum = 0ll;
	vector<array<ll,2>> dir{{1ll,-1ll},{-1ll,1ll}};
	for(auto p:m) {
		pair<ll,ll> v = p.first;
		ll freq = p.second;
		//debug() << imie(v)  ;
		for(auto v2: dir) {
            debug() <<imie(freq) imie(m[{v.first*v2[0],v.second*v2[1]}]);	
		    debug() <<imie(m);	
			add_self(sum,freq*m[{v.second*v2[0],v.first*v2[1]}]);
		}
	}
	//debug() << vector<pair<pair<ll,ll>,ll>>(m.begin(),m.end()) << endl;
	//debug() << dir;
	sum *= mod2;
	sum %= MOD;
	
	cout << sum << endl;
    return 0;    
}
