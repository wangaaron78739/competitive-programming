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

ll n,p;
ll fact(ll x) {
    int total = 1;
    for(int i=1;i<=x;i++) {
       total = total*x;
       total %= p;
    }
    return total;
}

int main() {
    cin >> n >> p;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int mi = a[0];
    int ma = a[n-1];
    vector<int> ans1;
    vector<int> ans;
    for(int i=mi;i<=ma;i++){ 
        int num = upper_bound(a.begin(),a.end(),i)-a.begin();
        if (num >= p) break;
        int s = num;
        //deque<int> temp(a.begin(),a.begin()+num);
        int curr = i;
        int imposs = false;
        while(s) {
            //debug() << imie(temp);
            //temp.pop_front();
            s--;
            curr++;
            while(num < n && a[num]<=curr) {
                //temp.push_back(a[num++]);
                s++;
                num++;
            }
            //debug() << imie(temp);
            if (s>=p) {
                imposs = true;
                break;
            }
        }
        if (imposs) break;
        if (imposs == false && curr >= ma) ans.push_back(i);
        
    }
    if (ans.size() == 0) {
        cout << "0\n\n";
        return 0;
    }
    cout << ans.size() << endl;
    for(int x:ans) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;    
}
