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
#define pq xpriority_queue
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int MAXN = 2*1e5+1;
vi adj[MAXN];
bool visited[MAXN];
bool poss = true;
unsigned short int ans[MAXN];

void dfs(int v,int p,int cur){
    visited[v]=true;
    ans[v]=cur;
    int nxt = cur^3;

    for(int c:adj[v]){
        if(!visited[c] && c!=p)dfs(c,v,nxt);
        if(ans[c]==cur)poss=false;
    }

}

int main(){
    sws
    int n,m;
    cin>>n>>m;

    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }   

    rep(i,1,n+1){
        if(visited[i])continue;
        dfs(i,-1,1);
    }

    if(!poss){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    rep(i,1,n+1){
        cout<<ans[i]<<" ";
    }

}