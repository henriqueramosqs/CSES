#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(msg,x) cout<<msg<<" "<<x<<endl;
#define output(x) for(auto c:x){cout<<c<<" ";}cout<<" ";
#define ll long long 
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
const int MAXN = 50001 ;
vi adj[MAXN];
vvi scc;
vi rev[MAXN];
int gp[MAXN];
int idx=0;
bool vis[MAXN];
vi topSort;
vector< bitset<50001> >reach;

void dfs(int v){
    vis[v]=true;
    for(auto c:adj[v]){
        if(!vis[c])dfs(c);
    }
    topSort.pb(v);
}

void dfs2(int v){
    vis[v]=true;
    gp[v]=idx;
    for(auto c:rev[v]){
        if(!vis[c])dfs2(c);
    }
}


void dfs3(int v){
    vis[v]=true;
    for(auto c:adj[v]){
        if(gp[c]!=gp[v])scc[gp[v]].pb(gp[c]);
        if(!vis[c])dfs3(c);
    }
}

void dfs4(int v){
    vis[v]=1;
    reach[v][v]=1;

    for(auto c:scc[v]){
        if(!vis[c])dfs4(c);
        reach[v]|=reach[c];
    }
}



int32_t main(){
    sws
    int n,m,q;
    cin>>n>>m>>q;

    
    while(m--){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        rev[b].pb(a);
    }

    rep(i,1,n+1){
        if(!vis[i])dfs(i);
    }

    reverse(topSort.begin(),topSort.end());

    memset(vis,false,sizeof(bool)*(n+1));

    rep(i,0,n){
        if(!vis[topSort[i]]){
            dfs2(topSort[i]);
            idx++;
            scc.pb(vi());
            reach.pb(bitset<50001>().reset());
        }
    }

    memset(vis,false,sizeof(bool)*(n+1));

    rep(i,1,n+1){
        if(!vis[i])dfs3(i);
    }
    memset(vis,false,sizeof(bool)*(idx+1));

    rep(i,0,idx){
        if(!vis[i]){
            dfs4(i);
        }
    }

    while(q--){
        int a,b;
        cin>>a>>b;
        reach[gp[a]][gp[b]]? cout<<"YES\n":cout<<"NO\n";
    }
}   