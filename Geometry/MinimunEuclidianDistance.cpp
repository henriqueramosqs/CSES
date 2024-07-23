#include <bits/stdc++.h>
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
#define ld long double
const int INF = 9*1E18;
struct point{
    int x, y;
    point(int x=0, int y=0): x(x), y(y){}
    bool operator<(const point &o) const{
        return (x == o.x) ? y < o.y : x < o.x;
    }
    friend ostream& operator<<(ostream& os, point p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

set<pii>py;
set<pii>px;
vector<point>v;

void erase(int idx){
    int x = v[idx].x,y=v[idx].y;
    auto itx = px.find(mp(x,idx));
    if(itx!=px.end())px.erase(itx);
    auto ity = py.find(mp(y,idx));
    if(ity!=py.end())py.erase(ity);
}

void insert(int idx){
    int x = v[idx].x,y=v[idx].y;
    px.insert(mp(x,idx));
    py.insert(mp(y,idx));
}

int lbound(int x,int ans){
    ans= ceil(sqrt(ans));
    int lim = -__INT64_MAX__;
    if(lim+ans>=x)return lim;
    return x-ans;
}

int ubound(int x,int ans){
    ans= ceil(sqrt(ans));
    int lim = __INT64_MAX__;
    if(lim-ans<=x)return lim;
    return x+ans;
}


inline int dist(point &a,point &b){
    int da = abs(a.x-b.x);
    int db = abs(a.y-b.y);
    return da*da + db*db;
}

int32_t main(){
    sws
    int n;cin>>n;
    v.resize(n);

    rep(i,0,n){
        int x,y;
        cin>>x>>y;
        v[i]=point(x,y);
    }

    sort(v.begin(),v.end());
    int ans = INF;

    rep(i,0,n){
        int x = v[i].x,y = v[i].y;

        while(!px.empty() && (px.begin()->ff) < lbound(x,ans) ){
            erase((px.begin()->ss));
        }
        
        auto it = py.upper_bound(mp(lbound(y,ans),-1));
        while(it!=py.end() && (it->ff) <= ubound(y,ans) ){
            ans=min(ans,dist(v[i],v[it->ss])); it++; 
        }
        insert(i);
    }

    cout<<ans;
}