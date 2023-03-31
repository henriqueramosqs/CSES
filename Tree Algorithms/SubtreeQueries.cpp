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
const int MAXN =2*1e5+1;
int t[MAXN*8];
vi adj[MAXN];
int val[MAXN];
int tin[MAXN];
int tout[MAXN];
int tt=0;
int euler[MAXN<<1];


void build(int v,int tl,int tr){
    if(tl==tr){
        t[v]=euler[tl];
        return;
    }

    int tm = (tl+tr)/2;
    build(v<<1,tl,tm);
    build(v<<1|1,tm+1,tr);
    t[v]=t[v<<1]+t[v<<1|1];
}


void show(int v,int tl,int tr){
    if(tl==tr){
       cout<<t[v]<<" ";
       return;
    }
    
    int tm = (tl+tr)/2;
    show(v<<1,tl,tm);
    show(v<<1|1,tm+1,tr);
}

void update(int v,int tl,int tr,int pos,int dif){


    if(tl==tr){
        t[v]+=dif;
        return;
    }

    int tm = (tl+tr)/2;
    if(tm>=pos){
        update(v<<1,tl,tm,pos,dif);
    }else{
        update(v<<1|1,tm+1,tr,pos,dif);
    }
    t[v]=t[v<<1]+t[v<<1|1];
}

int get(int v,int tl,int tr,int l,int r){
    if(tr<l || tl>r){
        return 0LL;
    }

    if(tl==l && tr==r)return t[v];
    int tm = (tl+tr)/2;
    return get(v<<1,tl,tm,l,min(r,tm))+get(v<<1|1,tm+1,tr,max(tm+1,l),r);
    
}

void dfs(int v,int p){
    euler[tt]=val[v];
    tin[v]=tt++;
    for(auto c:adj[v]){
        if(c!=p)dfs(c,v);
    }
    euler[tt]=0;
    tout[v]=tt++;
}

int32_t main(){
    sws
    int n,q;
    cin>>n>>q;


    rep(i,1,n+1){
        int x;cin>>x;
        val[i]=x;
    }

    rep(i,0,n-1){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1,1);
    build(1,0,tt-1);
    while(q--){
        int op;cin>>op;
        if(op==1){
            int s,x;
            cin>>s>>x;
            update(1,0,tt-1,tin[s],x-val[s]);
            val[s]=x;
        }else{
            int s;cin >>s;
            cout<<get(1,0,tt-1,tin[s],tout[s])<<endl;
        }
    }

}
