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
	int k;
	cin >> k;
	vector<int> b(k);
	F0R(i,k) cin >> b[i];
	int same = 1;
	int idx = -1;
	F0R(i,k) {
		if(i==k-1) {
			if (b[0]!=b[k-1]) same = 0;
			else if (idx==-1) idx = i;
		}
		else {
			if (b[i]!=b[i+1]) same = 0;
			else if (idx==-1) idx = i;
		} 
	}
	if (same) {
		cout << "1" << endl;
		F0R(i,k) {
			cout << '1';
			if (i != k-1) cout << ' ';
		}
		cout << endl;
		return;
	}
	if (k%2==0) {
		cout << "2" << endl;
		F0R(i,k) {
			if (i %2)
				cout << '1';
			else
				cout << '2';
			if (i != k-1) cout << ' ';
		}
		cout << endl;
		return;
	}
	// cout << imie(idx) imie(~idx)<< endl;
	if (idx==-1) {
		cout << "3" << endl;
		F0R(i,k) {
			if (i == k-1) {
				if(k%3==0) cout << "3";
				if(k%3==1) cout << "2";
				if(k%3==2) cout << "2";
			}else {
				if(i%3==0) cout << "1 ";
				if(i%3==1) cout << "2 ";
				if(i%3==2) cout << "3 ";
			}
		}
		cout << endl;
		return;
	}
	cout << "2" << endl;
	F0R(i,idx+1) {
		if (i %2)
			cout << '1';
		else
			cout << '2';
		if (i != k-1) cout << ' ';
	}
	FOR(i,idx+1,k){
		if (i %2)
			cout << '2';
		else
			cout << '1';
		if (i != k-1) cout << ' ';
	}
	cout << endl;
}

int main() {
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
