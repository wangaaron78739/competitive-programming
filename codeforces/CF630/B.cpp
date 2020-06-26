// #include <iostream>
// #include <vector>
// #include <numeric>
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

int a[1000];
int o[1000];
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};

void solve() {
    int n;
    cin >> n;
    F0R(i,n) cin >> a[i];
	memset(o,0,4*n);
	int currNum = 1;
	for(int x: primes) {
		int has = 0;
		int stillNeed = 0;
		F0R(i,n) stillNeed |= o[i] == 0;
		if (!stillNeed) break;
		F0R(i,n) {
			if(o[i] == 0 && (a[i]%x)==0) {
				has = 1;
				o[i] = currNum;
			}
		}
		if (has) {
			currNum++;
			if (currNum==13) goto out;
		}
	}
out:

    // int first = 0;

 
    // FOR(c,1,12) {
	// 	int first = -1;
    //     F0R(i,n) {
	// 		// cout << imie(first) imie(i) imie(o[i]) imie(o[i]);
    //         if (~first) {
    //             if (!o[i] && gcd(a[first],a[i])>1) o[i] = c;
    //         }else {
    //             if (!o[i]) {
	// 				o[i] = c; first = i;
	// 			}
    //         }
    //     }
	// 	cout << imie(first) << endl;
	// 	F0R(i,n) cout << imie(o[i]);
	// 	cout << endl;
    // }

	cout << currNum-1 << endl;
    F0R(i,n) {
        cout << o[i];
        if (i != n-1) cout << ' ';
        else cout << endl;
    }
}

int main() {
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
