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
struct pair_hash
{
		template <class T1, class T2>
				std::size_t operator () (std::pair<T1, T2> const &pair) const
				{
							std::size_t h1 = std::hash<T1>()(pair.first);
									std::size_t h2 = std::hash<T2>()(pair.second);

											return h1 ^ h2;
												
				}
		
};
template <typename Out>
void split(const std::string &s, char delim, Out result) {
	    std::istringstream iss(s);
		    std::string item;
			while (std::getline(iss, item, delim)) {
				        *result++ = item;
						    }
			}


int main() {
	string a;
	string b;
	cin >> a;
	cin >> b;
	unordered_map<pair<int,int>,int,pair_hash> s;
	vector<string> as;
	vector<string> bs;
	split(a,',',back_inserter(as));
	split(b,',',back_inserter(bs));
	vector<pair<char,int>> a1(as.size());
	vector<pair<char,int>> b1(bs.size());
	int count = 0;
	for(int i=0;i<as.size();i++){
		a1[i] = {as[i][0],stoi(as[i].substr(1))};
	}
	for(int i=0;i<bs.size();i++){
		b1[i] = {bs[i][0],stoi(bs[i].substr(1))};
	}
	int cx=0,cy=0;
	for(auto p:a1) {
		int * dir = &cx;
		int mul = 1;
		switch(p.first){
			case 'L':
				mul = -1;
				break;
			case 'R':
				break;
			case 'D':
				dir = &cy;
				mul = -1;
				break;
			case 'U':
				dir = &cy;
				break;
		}
		for(int i=0;i<p.second;i++) {
			*dir += mul;
			count++;
			//s.insert({cx,cy});
			s[{cx,cy}] = count;
		}
	}
	int currBest = 1e9;
	cx = 0;
	cy = 0;
	count = 0;
	for(auto p:b1) {
		int * dir = &cx;
		int mul = 1;
		switch(p.first){
			case 'L':
				mul = -1;
				break;
			case 'R':
				break;
			case 'D':
				dir = &cy;
				mul = -1;
				break;
			case 'U':
				dir = &cy;
				break;
		}
		for(int i=0;i<p.second;i++) {
			*dir += mul;
			count++;
			if (s[{cx,cy}]!=0){
				currBest = min(currBest,count+s[{cx,cy}]);
			}
		}
	}
	//for(int i=0;i<as.size();i++) cout << as[i] << ' ' ;
	int asum = 0;
	int bsum = 0;
	for(int i=0;i<as.size();i++) asum += a1[i].second;
	for(int i=0;i<bs.size();i++) bsum += b1[i].second;
	cout << asum << " " << bsum << endl;
	cout << currBest << endl;
	return 0;
}
