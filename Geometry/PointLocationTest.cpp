#include <bits/stdc++.h>
using namespace std;
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(msg,x) cout<<msg<<" "<<x<<endl;
#define output(x) for(auto c:x){cout<<c<<" ";}cout<<" ";
#define ll long long 
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

int main(){
    sws
    int t;cin>>t;

    while(t--){
        int x1,y1,x2,y2,x3,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;

        point p1(x1,y1);
        point p2(x2,y2);
        point p3(x3,y3);
        p3 = p3-p1;

        point dif = p2-p1;\
        auto aux = dif^p3;

        if(aux<0){
            cout<<"RIGHT\n";
            continue;
        }

        if(aux> 0){
            cout<<"LEFT\n";
            continue;
        }
        cout<<"TOUCH\n";
    }
}
