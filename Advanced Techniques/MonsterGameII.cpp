#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(x) cout<<#x<<" "<<x<<endl;
#define output(x) for(auto c:x){cout<<c<<" ";}cout<<" ";
#define int long long 
#define ff first
#define ld long double
#define ss second
#define endl "\n"
#define all(x) x.begin(),x.end()
#define pq priority_queue
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int INF = __INT64_MAX__;
struct Line {
	mutable int a, b, p;
	bool operator<(const Line& o) const { return a < o.a; }
	bool operator<(int x) const { return p < x; }
};

struct dynamic_hull : multiset<Line, less<> > {
	int div(int a, int b) { 
		return a / b - ((a ^ b) < 0 and a % b);
	}
	
	void update(iterator x) {
		if (next(x) == end()) x->p = INF;
		else if (x->a == next(x)->a) x->p = x->b >= next(x)->b ? INF : -INF;
		else x->p = div(next(x)->b - x->b, x->a - next(x)->a);
	}

	bool overlap(iterator x) {
		update(x);
		if (next(x) == end()) return 0;
		if (x->a == next(x)->a) return x->b >= next(x)->b;
		return x->p >= next(x)->p;
	}
		
	void add(int a, int b) {
		auto x = insert({a, b, 0});
		while (overlap(x)) erase(next(x)), update(x);
		if (x != begin() and !overlap(prev(x))) x = prev(x), update(x);
		while (x != begin() and overlap(prev(x))) 
			x = prev(x), erase(next(x)), update(x);
	}
	
	int query(int x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.a * x + l.b;
	}
};
 
 
int32_t main(){
    int n,x;
    cin>>n>>x;
    vi s(n),f(n);
    rep(i,0,n)cin>>s[i];
    rep(i,0,n)cin>>f[i];
 

    dynamic_hull cht;
    for(int i =n-1;i>=0;i--){
        int dp = (i==n-1?0:cht.query(#include <bits/stdc++.h>
using namespace std;
// #pragma GCC target("popcnt")
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(x) cout<<#x<<" "<<x<<endl;
#define output(x) for(auto c:x){cout<<c<<" ";}cout<<" ";
#define int long long 
#define ff first
#define ld long double
#define ss second
#define endl "\n"
#define pq priority_queue
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
typedef pair<pii,int >pp;

int solve(int c1,int c2){

}
int32_t main(){
    sws
    int t;cin>>t;
    while(t--){
        set<pp>s;
        int n,d;cin>>n>>d;
        vector<pp>v(n);
        rep(i,0,n)cin>>v[i].ff.ss>>v[i].ff.ss>>v[i].ss;
        sort(v.begin(),vend());
        set<int> xcmenosyc,mcmaisyc;
        for(int i =n-1;i>=0;i--){
            xcmenosyc[v[i].ff.ff-v[i].ff.ss].insert(i);
            mcmaisyc[v[i].ff.ff+v[i].ff.ss].insert(i);
        }
        set<pii>pref;
        pref.insert(v[i].ff);
        rep(i,1,n-2){
            int goal = d-v[i].ff.ss+v[i].ff.ff;
            int c1 = v[i].ff.ff+v[i].ff.ss-d;
            for(auto c:xmenosyxc[goal]){
                int c2 = d-v[c].ff.ff+v[c].ff.ss;
                if((c2+c1)%2)continue;
                int xa = (c1-c2)/2, ya = (c1+c2)/2;
                if(pref.find(mp(xa,ya))){
                    
                }
            }
        }
        cout<<"0 0 0\n";
    }   


}
f[i]));
        cht.add(-s[i],dp);
    }
    cout<<-cht.query(x)<<"\n";
}