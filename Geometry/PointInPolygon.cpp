#include <bits/stdc++.h>
using namespace std;
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(x) cout<<#x<<" "<<x<<endl;
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
    ld id;
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
		return os << "(" << p.x << "," << p.y << ")"; }
};
int n,m;
vector<point> v;


bool border(point pt){
    rep(i,0,n){
        int nx = (i+1)%n;
        if(pt.y>max(v[i].y,v[nx].y))continue;
        if(pt.x>max(v[i].x,v[nx].x))continue;
        if(pt.y<min(v[i].y,v[nx].y))continue;
        if(pt.x<min(v[i].x,v[nx].x))continue;
        if( ((v[nx]-v[i])^(pt-v[i]))==0)return true;
    }
    return false;
}

bool inside(point pt){
    bool ans=false;
    
    rep(i,0,n){
        int nx = (i+1)%n;
        if(v[i].x <= pt.x && pt.x < v[nx].x && pt.x>=v[i].x && ((v[i]-pt)^(v[nx]-pt))<0){
            ans^=1;
        }
      
        if( v[nx].x <= pt.x && pt.x < v[i].x && ((v[nx]-pt)^(v[i]-pt)) < 0){
                ans^=1;
            }
        
    } 
    return ans;
}


signed main(){
    sws
    cin>>n>>m;
    v.resize(n);
    rep(i,0,n){
        int x,y;
        cin>>x>>y;
        v[i]=point(x,y);
    }
    while(m--){
        int x,y;
        cin>>x>>y;
        point pt(x,y);
        if(border(pt)){
            cout<<"BOUNDARY\n";
            continue;
        }

        if(inside(pt)){
            cout<<"INSIDE\n";
            continue;
        }

        cout<<"OUTSIDE\n";
    }
}