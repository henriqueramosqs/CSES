#include <bits/stdc++.h>
using namespace std;
// #pragma GCC target("popcnt")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
const int MAXN = 1e5+1;

struct Line{
    int a,b;
    mutable int x_inter;
    Line(int a,int b,int x=-INF):a(a),b(b),x_inter(x){}
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
 


vector<Line>cht;

void show(Line a){
    cout<<"("<<a.a<<")x + "<<a.b<<" x:"<<a.x_inter<<"\n";
}
int teto(int a,int b){
    return (a+b-1)/b;
}
int intersection(Line a, Line b){
    if(a.a==b.a)return -INF;
    return teto(a.b-b.b,b.a-a.a); 
}
 
void clear(){cht.clear();}
 
int getpsum(vi&psum,int l,int r){
    int ans=psum[r];
    if(l>0)ans-=psum[l-1];
    return ans;
}
 

void add(int a,int b){
    Line nn(a,b);
    if(!cht.empty() && cht.back().a==nn.a && cht.back().b<nn.b)return;
 
    while(cht.size()>=2){
        Line a = cht[cht.size()-2];
        Line b = cht[cht.size()-1];
        if(intersection(b,nn)>intersection(a,b))cht.pop_back();
        else break;
    }
    if(!cht.empty())cht.back().x_inter=intersection(cht.back(),nn);
    if(cht.empty() || cht.back().x_inter>0)cht.pb(nn);
}

int get(int x){
    if(cht.empty())return 0;
    int sz= cht.size();
    int pos=sz-1;
    for(int step = sz;step>=1;step>>=1){
        while(pos-step>=0 && cht[pos-step].x_inter<=x)pos-=step;
    }
    return cht[pos].eval(x);
}

int32_t main(){
    sws
    int n,k;
    cin>>n>>k;
    vi v(n);
    rep(i,0,n)cin>>v[i];
    vi psum(n);
    rep(i,0,n){
        psum[i]=v[i];
        if(i>0)psum[i]+=psum[i-1];
    }  
    vvi dp(n+1,vi(k+1,0));
    rep(i,0,n){
        dp[i][1]=getpsum(psum,i,n-1);
        dp[i][1]*=dp[i][1];
    }
 
    rep(ki,2,k+1){
        clear();
        for(int i = n-1;i>=0;i--){
            if(n-i<ki)continue;
 
            int pj = psum[i];
            add(-2*pj,pj*pj+dp[i+1][ki-1]);
            int disc = (i==0?0:psum[i-1]); 
            dp[i][ki]=disc*disc+get(disc);
        }
    } 
    cout<<dp[0][k];
}