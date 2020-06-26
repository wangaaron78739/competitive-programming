#include <bits/stdc++.h>
using namespace std;

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

bool sortbysec(const pair<char,ll> &a, 
              const pair<char,ll> &b) 
{ 
    return (a.second < b.second); 
} 
#define sz(x) (ll)x.size()
#define all(x) begin(x), end(x)
#define rsz resize

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }


void solve() {
	int n,d;
	cin >> n >> d;
	vector<ll> a(n);
	unordered_map<ll,int> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
		m[a[i]]++;
	}
	sort(a.begin(),a.end());
	pair<ll,int> maxp({0,0});
	for(auto p:m) {
		if (maxp.first< p.first) {
			maxp = p;
		}
	}
	auto it = a.find(maxp.first);
	while()
	int have = maxp.second;
	while(have < n) {

	}
	cout << n - maxp.second +  << end;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	cin >> T;
	for(int i=1;i<=T;i++) {
		cout << "Case #"<< i << ": ";
		solve();
	}
	return 0;
}