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
typedef pair<pii,int >pp;
const int MAXN = 1e5+5;
vpp t[MAXN<<2];
int n,m,q;


struct  DSU{
    vi parents;
    vi sz;
    vpp hist;
    vpp act;
    int comps;
    int tt;

    DSU(int n):tt(0),comps(n),parents(n+1),sz(n+1,1){
        rep(i,0,n+1)parents[i]=i;
    }

    DSU(){}

    int root(int x){
        return x==parents[x]?x:root(parents[x]);
    }

    void unite(int a,int b){
        int pasta=a;
        int pasb=b;
        a=root(a);
        b=root(b);
        if(a==b)return;
        comps--;
        if(sz[a]<sz[b])swap(a,b);
        parents[b]=a;
        sz[a]+=sz[b];
        hist.pb(mp(b,a));
        act.pb(mp(pasta,pasb));
        tt++;

    }

    void unite(pii a){
        unite(a.ff,a.ss);
    }

    void rollback(int ts){
        while(ts<tt){
            int b = hist.back().ff, a=hist.back().ss;
            comps++;
            parents[b]=b;
            sz[a]-=sz[b];
            hist.pop_back();
            act.pop_back();
            tt--;
        }
    }

};

DSU dsu;

void update(int v,int tl,int tr,int l,int r,pii val){
    if(tl==l && tr==r){
        t[v].pb(val);
        return;
    }
    if(tl>r || tr<l)return;
    int tm = (tl+tr)>>1;
    update(v<<1,tl,tm,l,min(tm,r),val);
    update(v<<1|1,tm+1,tr,max(tm+1,l),r,val);
}

void update(int l,int r,pii val){
    update(1,0,q,l,r,val);
}

void dfs(int v=1,int tl=0,int tr=q){

    int ts = dsu.tt;
    for(auto c:t[v])dsu.unite(c);
    if(tl==tr){
        cout<<dsu.comps<<" ";
        dsu.rollback(ts);
        return;
    }
    int tm = (tl+tr)>>1;
    dfs(v<<1,tl,tm);dfs(v<<1|1,tm+1,tr);
    dsu.rollback(ts);
}

int32_t main(){
    sws 
    cin>>n>>m>>q;
    dsu = DSU(n);
    map<pii,int>edg;
    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        if(a>b)swap(a,b);
        edg[mp(a,b)]=0;
    }


    rep(i,1,q+1){
        int op,a,b;
        cin>>op>>a>>b;
        if(a>b)swap(a,b);
        if(op==1){
            edg[mp(a,b)]=i;
        }else{
            update(edg[mp(a,b)],i-1,mp(a,b));
            edg.erase(edg.find(mp(a,b)));
        }

    }

    for(auto c:edg)update(c.ss,q,c.ff);

    dfs();
}
