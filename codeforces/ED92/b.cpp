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

void solve() {
    int n,k,z;
    cin >> n >> k >> z;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    vector<vector<vector<int>>> dp(z+1,vector<vector<int>>(k+1,vector<int>(2,0)));
    vector<int> sum(k);
    vector<int> m(n);
    for(int i=0;i<z;i++) dp[i][0][0] = a[0];
    for(int j=0;j<z;j++){
        for(int i=0;i<k;i++) {
            dp[j][i+1][0] = max(dp[j][i][0]+a[i+1], dp[j][i+1][0]);
            dp[j][i+1][0] = max(dp[j][i][1]+a[i+1], dp[j][i+1][0]);
            if(i) dp[j+1][i-1][1] = max(dp[j][i][0] + a[i-1], dp[j+1][i+1][1]);
        }
    }
    int best = 0;
    for(int i=0;i<=z;i++)for(int j=0;j<=k;j++) {
        for(auto x :{0,1}) {
            best = max(dp[i][j][x], best);
        }
    }
    //m[0] = 0;
    //for(int i=0;i<=k;i++){
        //if (i) sum[i] += sum[i-1];
       //sum[i] += a[i];
       //if (i) {
           //if (a[m[i]]+a[m[i]+1] < a[i]+a[i]+1) {
               //m[i] = i;
           //}
       //}
    //}
    ////int currmax = sum;

    //for(int i=0;i<2*z;i++) {
        //int temp = 0;
        ////if (k-z*2 < 0) break;
        //temp = sum[k-i];
        //temp += (a[m[k-i]]+a[m[k-i]+1])*(i/2);
        //if (i%2) {
            //if (m[k-i] >= k-i-2) { 
                //temp += max(a[m[k-1]],a[k-i]);
            //}
        //}
        //if (i%2 == 0) {
        //} else {
            
            //temp += (a[m[k-1]]+a[m[k-1]])
        //}
        //if (i%2) {
            //temp += ()
        //}
        //temp = sum[k-2*z] + (a[m[k-2*z]])*i + 
        //if (k-2*z)
            //(a[m[k-2*z]+1])*(i);
        
        //currmax = max(currmax, temp);
    //}
    //while(z != 0) {

        //if (k>=0) sum -= a[k--];
        //if (k>=1) currmax = max(currmax,sum + a[k-1]);
        //if (k>=0) sum -= a[k--];
        //if (k>=1) sum += m[k-1];
        //currmax = max(currmax, sum);
        //z--;
    //}
    cout << best << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;    
}
