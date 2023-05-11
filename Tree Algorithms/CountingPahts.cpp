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
int n,m,tempo=0;
const int MAXN = 2*1e5+1;
int up[MAXN][18];
vi adj[MAXN];
int tin[MAXN];
int tout[MAXN];
int add[MAXN];
int fin[MAXN];
int ans[MAXN];
 
void dfs(int v=1,int p=-1){
    up[v][0]=p;
    if(p==-1)up[v][0]=1;
    rep(i,1,18)up[v][i]= up[up[v][i-1]][i-1];
    tin[v]=tempo++;add[v]=0;
 
    for(int c:adj[v]){
        if(c==p)continue;
        dfs(c,v);
    }
 
    tout[v]=tempo++;
}
 
int dfs2(int v=1,int p=-1){
    for(int c:adj[v]){
        if(c==p)continue;
        ans[v]+=dfs2(c,v);
    }
    
    ans[v]+=add[v];
    ans[v]-=fin[v];
    return ans[v]-fin[v];
 
}
 
bool isAncestor(int a,int b){
    return (tin[a]<=tin[b] &&  tout[a]>=tout[b]);
}
 
int lca(int a,int b){
    if(isAncestor(a,b))return a;
    if(isAncestor(b,a))return b;
 
    rep(i,0,18){
        if(!isAncestor(up[a][17-i],b))a=up[a][17-i];
    }
 
    return up[a][0];
}
 
int main(){
    sws
    cin>>n>>m;
 
    rep(i,0,n-1){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
 
 
    dfs();
 
    while(m--){
        int a,b;
        cin>>a>>b;
        add[a]++;
        add[b]++;
        fin[lca(a,b)]++;
    }
 
    dfs2();
 
    rep(i,1,n+1)cout<<ans[i]<<" ";
}