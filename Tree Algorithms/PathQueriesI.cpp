#include <bits/stdc++.h>
using namespace std;
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(msg,x) cout<<msg<<" "<<x<<endl;
#define output(x) for(auto c:x){cout<<c<<" ";}cout<<" ";
#define ll long long 
#define int long long 
#define ff first
#define ss second
#define pq priority_queue
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int MAXN = 2*1e5+1;
ll lazy[MAXN<<3];
vi adj[MAXN];
int tin[MAXN];
int tout[MAXN];
ll val[MAXN];
ll ans[MAXN];
vi euler;
int tme=0,n,q;
 
void dfs(int v,int p,ll carry=0LL){
    tin[v]=tme++;
    ans[v]=carry+val[v];
    euler.pb(v);
 
    for(auto c:adj[v]){
        if(c!=p)dfs(c,v,carry+val[v]);
    }
 
    tout[v]=tme++;
    euler.pb(0);
}
 
 
void update(int v,int tl,int tr,int l,int r,ll val){
    if(l>tr ||r<tl)return;
 
    if(tl==l && tr==r){
        lazy[v]+=val;
        return;
    }
 
    int tm = (tl+tr)/2;
 
    update(v<<1,tl,tm,l,min(r,tm),val);
    update(v<<1|1,tm+1,tr,max(tm+1,l),r,val);
 
}
 
ll get(int v,int tl,int tr,int goal){
    if(tl==tr){
        int ans =  lazy[v];
        lazy[v]=0LL;
        return ans;
    }
    lazy[v<<1]+=lazy[v];
    lazy[v<<1|1]+=lazy[v];
    lazy[v]=0LL;
 
    int tm = (tl+tr)/2;
 
    if(goal<=tm){
        return get(v<<1,tl,tm,goal);
    }
    return get(v<<1|1,tm+1,tr,goal);
}
int32_t main(){
    sws
    int n,q;
    cin>>n>>q;
    rep(i,0,n)cin>>val[i+1];
 
    rep(i,0,n-1){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
 
    dfs(1,-1);
 
    rep(i,0,(tme-1)<<2)lazy[i]=0;
 
    while(q--){
        int op;cin>>op;
 
        if(op==1){
            int nd,num;cin>>nd>>num;
            update(1,0,tme-1,tin[nd],tout[nd],num-val[nd]);
            val[nd]=num;
        }else{
            int nd;cin>>nd;
            int add = get(1,0,tme-1,tin[nd]);
            ans[nd]+=add;
            cout<<ans[nd]<<endl;
        }
    }
 
}