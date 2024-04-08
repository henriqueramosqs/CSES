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
 
typedef ld T;
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
 
ld orient(point p1,point p2,point p3){
    return (point(p1^p2))*p3;
}

bool t1(point p1,point p2,point p3,point p4){
    if(p1.x==p2.x){
        if(p3.x!=p4.x)return false;
        return p1.x==p3.x;
    }
    if(p1.x>p2.x)swap(p1,p2);
    if(p3.x>p4.x)swap(p3,p4);
    T a1 = (p2.y-p1.y)/(p2.x-p1.x);
    T b1 = p1.y-a1*p1.x;

    T a2 = (p4.y-p3.y)/(p4.x-p3.x);
    T b2 =  p3.y-a2*p3.x;

    return eq(a1,a2) && eq(b1,b2);
}

bool contains(int l,int r,int tl,int tr){
    return tl>=l && tr<=r;
}
int32_t main(){
    sws
    int t;cin>>t;
    while(t--){
        int x1,y1,x2,y2,x3,y3,x4,y4;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        point p1(x1,y1);point p2(x2,y2);
        point p3(x3,y3);point p4(x4,y4);
        vector<point> v;
        v.pb(p1);v.pb(p2);v.pb(p3);v.pb(p4);
        point aux1 = (p2-p1);
        point aux2 = (p4-p3);
 
        if(p1 == p3 || p1 ==p4 || p2 == p3 || p2==p4){
            cout<<"YES\n";
            continue;
        }
 
    
        if(t1(p1,p2,p3,p4)){
            if(p1.x>p2.x)swap(p1,p2);
            if(p3.x>p4.x)swap(p3,p4);
            if(p1.x==p2.x && p3.x==p4.x){
                if(p1.y>p2.y)swap(p1,p2);
                if(p3.y>p4.y)swap(p3,p4);
                if( (p3.y>= p1.y &&  p3.y<=p2.y)  || (p4.y>= p1.y && p4.y<=p2.y) || 
                    contains(p1.y,p2.y,p3.y,p4.y) || contains(p3.y,p4.y,p1.y,p2.y) ){
                    cout<<"YES\n";
                } else{
                    cout<<"NO\n";
                }
                continue;
            }
            if( (p3.x>= p1.x &&  p3.x<=p2.x)  || (p4.x>= p1.x && p4.x<=p2.x) || 
                contains(p1.x,p2.x,p3.x,p4.x) || contains(p3.x,p4.x,p1.x,p2.x)){
                cout<<"YES\n";
            } else{
                cout<<"NO\n";
            }
            continue;
        }
 
        if( ((aux1^(p3-p1))*(aux1^(p4-p1)))<=0 && ((aux2^(p1-p3))*(aux2^(p2-p3)))<=0 ){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
 
    }
}