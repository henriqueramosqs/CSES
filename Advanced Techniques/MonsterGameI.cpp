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
const int INF = (1LL<<30); 

struct Line{
    int a,b;
    mutable int x_inter;
    Line(int a,int b,int x=INF):a(a),b(b),x_inter(x){}
    bool operator <( int x) const {
        return x_inter < x;
    }
    const int eval(int x)const{
        return a*x+b;
    }
    bool operator <( const Line &o) const {
        return mp(a,b) < mp(o.a,o.b);
    };
};

void show(Line a){
    cout<<"("<<a.a<<")x + "<<a.b<<" x:"<<a.x_inter<<"\n";
}
int intersection(Line a, Line b){
    if(a.a==b.a)return -INF;
    return (a.b-b.b)/(b.a-a.a); 
}


int32_t main(){
    sws;    

    int n,x;
    cin>>n>>x;
    vi s(n),f(n);
    rep(i,0,n)cin>>s[i];
    rep(i,0,n)cin>>f[i];
    vector<Line>cht;

    for(int i =n-1;i>=0;i--){
        int dp=0;
        if(!cht.empty())dp=lower_bound(all(cht),f[i])->eval(f[i]);

        Line nn(s[i],dp);
        if(!cht.empty() && cht.back().a==nn.a)continue;

        while(cht.size()>=2){
            Line a = cht[cht.size()-2];
            Line b = cht[cht.size()-1];
            if(intersection(b,nn)<intersection(a,nn))cht.pop_back();
            else break;
        }
        if(!cht.empty())cht.back().x_inter=intersection(cht.back(),nn);
        cht.pb(nn);
        
    }  


    cout<<lower_bound(all(cht),x)->eval(x);;
}
