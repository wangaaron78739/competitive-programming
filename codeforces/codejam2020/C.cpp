#include <bits/stdc++.h>

using namespace std;

#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define ar array

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
// #define s second
#define lb lower_bound
#define ub upper_bound


#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

void solve(int ca) {
    int n;
    cin >> n;
    vector<ar<int,3>> time(n);
    F0R(i,n) {
        cin >> time[i][0] >> time[i][1];
        time[i][2] = i;
    }
    sort(all(time));
    ar<int,3> c = {-1,-1};
    ar<int,3> j = {-1,-1};
    vector<char> sch(n+1); 
    trav(interval, time) {
        if (c[0] == -1) {
            c = interval;
            sch[interval[2]] = 'C';
            continue;
        } else if (j[0] == -1) {
            j = interval;
            sch[interval[2]] = 'J';
        }else {
            if (c[1]<j[1]) {
                if (c[1] > interval[0]) {
                   printf("Case #%d: IMPOSSIBLE\n", ca);
                   return;
                }
                c = interval;
                sch[interval[2]] = 'C';
            }else {
                if (j[1] > interval[0]) {
                   printf("Case #%d: IMPOSSIBLE\n", ca);
                   return;
                }
                j = interval;
                sch[interval[2]] = 'J';
            }
        }
    }
    string temp = string(sch.begin(),sch.end());
    printf("Case #%d: %s\n", ca, temp.c_str());
}

int main() {
	int T;
	cin >> T;
	F0R(i,T) solve(i+1);
	return 0;
}
