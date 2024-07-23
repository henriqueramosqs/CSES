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
		return os << "(" << p.x << "," << p.y << ")"; }
};

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int32_t main(){
    sws
    int n;cin>>n;
    vp v(n);
    rep(i,0,n){
        int x,y;
        cin>>x>>y;
        v[i]=point(x,y);
    }

    int s=0;
    int bans=0;

    rep(i,0,n){
        int nx = (i+1)%n;
        s+=(v[i]^v[nx]);
        int a = v[nx].y-v[i].y;
        int b = v[nx].x-v[i].x;
        int g = gcd(a,b);
        if(b==0){
            bans+=(1+abs(a));
            continue;
        }
        bans+=(1+abs(b)/abs(b/g));
    }
    bans-=n;
    s=abs(s);
    int a = (s+2-bans)>>1;
    cout<<a<<" "<<bans<<"\n";
}