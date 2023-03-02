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
const int MAXN = 1e5+1;
int idx=0;
int curPoints=0;
int maxPoints=0;
int points[MAXN];
bool visited[MAXN];
vi adj[MAXN];
vi rev[MAXN];
vi scc[MAXN];
int dp[MAXN];
int belongs[MAXN];
int groupPoints[MAXN];

vi topSort;

void dfs1(int v){
    visited[v]=true;

    for(auto c:adj[v]){
        if(!visited[c])dfs1(c);
    }
    topSort.pb(v);
}

void dfs2(int v){
    visited[v]=true;
    curPoints+=points[v];
    belongs[v]=idx;
    
    for(auto c:rev[v]){
        if(!visited[c])dfs2(c);
    }
}

void dfs3(int v){
    visited[v]=true;
    
    for(auto c:adj[v]){
        if(belongs[c]!=belongs[v])scc[belongs[v]].pb(belongs[c]);
        if(visited[c])continue;
        if(!visited[c])dfs3(c);
    }
}


void dfs4(int v){
    dp[v]=groupPoints[v];
    visited[v]=true;
    for(auto c:scc[v]){
        if(!visited[c])dfs4(c);
        dp[v]=max(dp[v],groupPoints[v]+dp[c]);
    }

    maxPoints= max(dp[v],maxPoints);
}

int32_t main(){
    sws
    int n,m;
    cin>>n>>m;

    memset(visited,false,sizeof(visited));
    memset(dp,-1LL,sizeof(dp));

    rep(i,1,n+1)cin>>points[i];

    while(m--){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        rev[b].pb(a);
    }

    rep(i,1,n+1){
        if(!visited[i])dfs1(i);
    }
    
    reverse(topSort.begin(),topSort.end());
    
    memset(visited,false,sizeof(visited));

    for(auto i:topSort){
        if(!visited[i]){
            dfs2(i);
            groupPoints[idx]=curPoints;
            idx++;
            curPoints=0;
        }
    
    }

    memset(visited,false,sizeof(visited));

    rep(i,1,n+1){
        if(!visited[i])dfs3(i);
    }

    memset(visited,false,sizeof(visited));

    rep(i,0,idx){
        if(!visited[i]){
            dfs4(i);
        }
    }
    cout<<maxPoints;

}
