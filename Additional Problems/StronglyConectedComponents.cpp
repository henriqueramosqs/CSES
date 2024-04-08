#include <bits/stdc++.h>
using namespace std;
#define sws ios_base::sync_with_stdio(NULL);cout.tie(NULL);cin.tie(NULL);
#define int long long
#define rep(i,a,b) for(int i = a;i<b;i++)
#define mp make_pair
#define pb push_back
#define ff first
#define dbg(x) cout<<#x<<" "<<x<<"\n";
#define ss second
#define endl '\n'
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpp;

const int MAXN = 2*1E5+5;
vpp adj[MAXN];
vi rev[MAXN];
vi gp[MAXN];
bool dir[MAXN];
bool vis[MAXN];
vpp edges;
int tin[MAXN];
vi topSort;
int idx=0;
int timer=0;


void dfs(int v=1,int p=-1){
    vis[v]=true;
    tin[v]=timer++;
    for(auto c:adj[v]){
        if(c.ff==p)continue;
        if(vis[c.ff]){
            dir[c.ss]=1;
            continue;
        }
        dfs(c.ff,v);
    }
}
void dfs1(int v){
    vis[v]=true;
    // dbg(v)
    for(auto c:gp[v]){
        if(!vis[c])dfs1(c);
    }
    topSort.pb(v);
}

void dfs2(int v){
    vis[v]=true;

    for(auto c:rev[v]){
        if(!vis[c])dfs2(c);
    }
}

void printGp(int v=1,int p=-1){
    if(p>0){
        cout<<p<<" "<<v<<"\n";
    }
    if(vis[v])return;
    vis[v]=true;

    for(auto c:gp[v]){
        if(c==p)break;
        printGp(c,v);
    }
}

int32_t main() { 
    sws
    int n,m;
    cin>>n>>m;

    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        adj[a].pb(mp(b,i));
        adj[b].pb(mp(a,i));
        edges.pb(mp(a,b));
    }

    rep(i,1,n+1){
        if(!vis[i])dfs(i);
    }

    rep(i,0,m){
        int a = edges[i].ff,b = edges[i].ss;
        if(dir[i]){
            if(tin[a]<tin[b]){
                gp[b].pb(a);
                rev[a].pb(b);
            }else{
                gp[a].pb(b);
                rev[b].pb(a);
            }
        }else{
            if(tin[a]<tin[b]){
                gp[a].pb(b);
                rev[b].pb(a);
            }else{
                gp[b].pb(a);
                rev[a].pb(b);
            }
        }
    }
    rep(i,1,n+1)vis[i]=false;

    rep(i,1,n+1){
        if(!vis[i])dfs1(i);
    }

    reverse(topSort.begin(),topSort.end());

    rep(i,1,n+1)vis[i]=false;

    for(auto c:topSort){
        if(!vis[c]){
            dfs2(c);
            idx++;
        }
    }


    if(idx!=1){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    

    rep(i,1,n+1)vis[i]=false;

    printGp();


}