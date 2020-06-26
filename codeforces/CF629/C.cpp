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

const int maxn = 5e4+3;
char a[maxn], b[maxn];

void solve() {
	memset(a,'\0',sizeof(a));
	memset(b,'\0',sizeof(b));
	int n;
	cin >> n;
	char c;
	int first = 0;
	F0R(i,n) {
		cin >> c;
		switch(c-'0') {
			case 0:
			a[i] = '0';
			b[i] = '0';
			break;
			case 1:
			if (first) {
			a[i] = '0';
			b[i] = '1';
			}else {
							a[i] = '1';
			b[i] = '0';
				first = 1;
			}
			break;
			case 2:
			if (first) {
			a[i] = '0';
			b[i] = '2';
			}else {
							a[i] = '1';
			b[i] = '1';
			}
			break;
		}
	}
	cout << a << endl;
	cout << b << endl;
}

int main() {
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
