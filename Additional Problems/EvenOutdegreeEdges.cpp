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
#define pq priority_queue
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int MAXN = 2*1e5+1;
vpp adj[MAXN];
bool deg[MAXN];
bool vis[MAXN];
bool dir[MAXN];
int tin[MAXN];
vpp edges;
int timer =0;
 
void dfs(int v=1,int p = 0,int edgeidx=-1){
    vis[v]=true;
    tin[v]=timer++;
    for(auto c:adj[v]){
        if(c.ff==p)continue;
        if(vis[c.ff]){
            if(tin[c.ff]<tin[v])deg[c.ff]^=1;
            continue;
        }
        deg[v]^=1;
        dfs(c.ff,v,c.ss);
    }
    if(p==0)return;
    if(deg[v]==false)return;
    deg[v]^=1;deg[p]^=1;
    dir[edgeidx]=true;
}
 
 
int32_t main(){
    sws
    int n,m;cin>>n>>m;
 
    rep(i,0,m){
        int a,b;cin>>a>>b;
        adj[a].pb(mp(b,i));
        adj[b].pb(mp(a,i));
        edges.pb(mp(a,b));
    }
 

    rep(i,1,n+1){
        if(vis[i])continue;
        dfs(i);
        if(deg[i]){
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
    };
 
    

    rep(i,0,m){
        int a = edges[i].ff;
        int b = edges[i].ss;
        if(dir[i]){
            if(tin[a] < tin[b] ){
                cout<<b<<" "<<a<<"\n";
            }else{
                cout<<a<<" "<<b<<"\n";
            }
        }else{  
            if(tin[a] < tin[b] ){
                cout<<a<<" "<<b<<"\n";  
            }else{
                cout<<b<<" "<<a<<"\n";
            }
        }
    }
    
 
}   