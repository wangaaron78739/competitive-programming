#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
	enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
		sim > struct rge { c b, e;  };
		sim > rge<c> range(c i, c j) { return rge<c>{i, j};  }
		sim > auto dud(c* x) -> decltype(cerr << *x, 0);
		sim > char dud(...);
		struct debug {
#ifdef LOCAL
			~debug() { cerr << endl;  }
			eni(!=) cerr << boolalpha << i; ris; 
		}
		eni(==) ris << range(begin(i), end(i)); 
	}
sim, class b dor(pair < b, c > d) {
	  ris << "(" << d.first << ", " << d.second << ")";
	  
}
sim dor(rge<c> d) {
	  *this << "[";
	    for (auto it = d.b; it != d.e; ++it)
			    *this << ", " + 2 * (it == d.b) << *it;
		  ris << "]";
		  
}
#else
sim dor(const c&) { ris;  }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using ll = long long;

int main() {
	int sum = 0;
	for(int i=265275;i<=781584;i++) {
		string s = to_string(i);
		bool a = true;
		bool b = false;
		for(int j=1;j<6;j++) {
			if (s[j]<s[j-1]) a = false;
		}
		if ((s[0]==s[1])&&(s[1]!=s[2])) b |= true;
		if ((s[0]!=s[1])&&(s[1]==s[2])&&(s[2]!=s[3])) b |= true;
		if ((s[1]!=s[2])&&(s[2]==s[3])&&(s[3]!=s[4])) b |= true;
		if ((s[2]!=s[3])&&(s[3]==s[4])&&(s[4]!=s[5])) b |= true;
		if ((s[3]!=s[4])&&(s[4]==s[5])&&(s[5]!=s[6])) b |= true;
		if ((s[4]!=s[5])&&(s[5]==s[6])) b |= true;
		if (a && b) sum ++;
	}
	cout << sum << endl;
	return 0;
}
