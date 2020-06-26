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
	int U;
	cin >> U;
	string s;
	vector<unordered_map<char,int>> v(2);
	for(ll i=0;i<1e4;i++) {
		ll temp;
		cin >> temp;
		cin >> s;
		ll n = s.size();
		v[0][s[0]]++;
		v[1][s[1]]++;
		// for(ll j=0; j < 2;j++) {
		// 	v[n-1-j][s[n-1-j]]++;
		// }
	}

	vector<pair<char,int>> char_list;
	// cout << v[1].size();
	for(auto p:v[1]) {
		char_list.push_back({p.first,1e5});
	}
	for(auto p: v[0]) {
		for(int i=0;i<char_list.size();i++) {
			if (char_list[i].first == p.first) {
				char_list[i].second = p.second;
			}
		}
	}
	sort(char_list.begin(), char_list.end(), sortbysec);

	// assert(char_list.size() == 10);
	for(ll i=9;~i;i--) {
		cout << char_list[i].first;
	}
	cout << endl;
	// for(int i=0;i<U;i++) {
	// 	cout << imie(i);
	// 	for (auto p:v[i]) {
	// 		cout << p.first << " " << p.second << endl;
	// 	}
	// }

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("bin.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	cin >> T;
	for(int i=1;i<=T;i++) {
		cout << "Case #"<< i << ": ";
		solve();
	}
	return 0;
}