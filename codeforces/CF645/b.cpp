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


#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }
const int maxn = 2e5+2;
int freq[maxn];

void solve() {
	int n;
	cin >> n;
	memset(freq,0,sizeof(freq));
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		freq[t]++;
	}
	for(int i=1;i<2e5;i++) 
		freq[i] += freq[i-1];
	int l = 1, r = 2e5;
	while(l<r) {
		int mid = (l+r+1)/2;
		if (freq[i]<i) {
			l 
		}
	}
	int curr = 0;
	for(int i=1;i<=2e5;i++) {
		int next = curr+freq[i];
		if (freq[i]) {
			if (i > next) {
				cout << curr+1 << endl;
				return;
			}
		}
	}
	cout << curr << endl;

}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}