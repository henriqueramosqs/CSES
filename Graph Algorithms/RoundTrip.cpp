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
const int MAXN = 1e5+1;

int closing = -1;
vi adj[MAXN];
bool visited[MAXN];
int fat[MAXN];

void dfs(int v,int p){
    fat[v]=p;

    if(visited[v]){
        closing=v;
        return;
    }

    visited[v]=true;

    for(int c:adj[v]){  
        if(c!=p && closing==-1)dfs(c,v);
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
        dfs(i,-1);
        if(closing!=-1)break; 
    }

    if(closing == -1){
        cout<<"IMPOSSIBLE";
        return 0;
    }

    stack<int>path;
    
    int cur = closing;
    bool nxt = true;

    while(cur!=closing || nxt){
        path.push(cur);
        cur = fat[cur];
        nxt = false;
    }
    path.push(cur);

    cout<<path.size()<<endl;
    while(!path.empty()){
        cout<<path.top()<<" ";
        path.pop();
    }
}