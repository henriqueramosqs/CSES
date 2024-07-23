#include <bits/stdc++.h>
using namespace std;
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(msg,x) cout<<msg<<" "<<x<<endl;
#define output(x) for(auto c:x){cout<<c<<" ";}cout<<" ";
#define int long long 
#define ff first
#define ss second
#define pq priority_queue
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
 
#define vp vector<point>
#define ld long double
const ld EPS = 1e-6;
const ld PI = acos(-1);
 
typedef int T;
bool eq(T a, T b){ return abs(a - b) <= EPS; }
 
struct point{
    T x, y;
    int id;
    point(T x=0, T y=0): x(x), y(y){}
 
    point operator+(const point &o) const{ return point(x + o.x, y + o.y); }
    point operator-(const point &o) const{ return point(x - o.x, y - o.y); }
    point operator*(T t) const{ return point(x * t, y * t); }
    point operator/(T t) const{ return point(x / t, y / t); }
    T operator*(const point &o) const{ return x * o.x + y * o.y; }
    T operator^(const point &o) const{ return x * o.y - y * o.x; }
    bool operator<(const point &o) const{
        return (eq(x, o.x) ? y < o.y : x < o.x);
    }
    bool operator==(const point &o) const{
        return eq(x, o.x) and eq(y, o.y);
    }
	friend ostream& operator<<(ostream& os, point p) {
		return os << "(" << p.x << "," << p.y << ")\n"; }
};
 
bool left(point a,point b,point c){ 
    return ((b-a)^(c-a))>0;
}
 
vector<point> hull(vector<point>&v){
    vector<point>ans;
 
    for(auto pt:v){
        while(ans.size()>1 && left(ans[ans.size()-2],ans.back(),pt))ans.pop_back();    
        ans.pb(pt); 
    }   
    return ans;
}
 
 
int32_t main(){
    sws
    int n;cin>>n;
    vector<point>ans;
    vector<point>v;
 
    rep(i,0,n){
        int x,y;
        cin>>x>>y;
        v.pb(point(x,y));
    }
 
    sort(v.begin(), v.end());

    vector<point> v1  = hull(v);
    
    reverse(v.begin(),v.end());
 
    vector<point> v2  = hull(v);
 
    rep(i,1,v2.size()-1){
        v1.pb(v2[i]);
    }
 
    cout<<v1.size()<<"\n";
    for(auto c:v1){
        cout<<c.x<<" "<<c.y<<"\n";
    }
}