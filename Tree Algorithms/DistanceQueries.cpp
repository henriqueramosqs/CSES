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
const int MAXN = 2*1e5+1;
vi adj[MAXN];
int tin[MAXN];
int tout[MAXN];
vector<vi> up;
int h[MAXN];
int counter=0;
int lim;

void dfs(int v,int p,int he){
    h[v]=he;
    tin[v]=counter++;

    if(p==-1){
        rep(i,0,lim+1)up[v][i]=1;
    }else{
        up[v][0]=p;
        rep(i,1,lim+1)up[v][i]=up[up[v][i-1]][i-1];
    }

    for(int c:adj[v]){
        if(c!=p)dfs(c,v,he+1);
    }
    tout[v]=counter++;
}


bool isAncestor(int a,int b){
    return (tin[a]<=tout[b] && tout[a]>=tout[b]);
}

int lca(int a,int b){
    for(int i =lim;i>=0;i--){
        if(isAncestor(up[a][i],b)==false){
            a=up[a][i];
        }
    }
    return up[a][0];
}

int getDist(int a,int b){
    if(isAncestor(a,b))return h[b]-h[a];
    if(isAncestor(b,a))return h[a]-h[b];
    return h[a]+h[b]-2*h[lca(a,b)];
}

int main(){
    sws;
    int n,q;
    cin>>n>>q;

    rep(i,0,n-1){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    lim = (int)(ceil(log2(n)));
    up.assign(n+1,vi(lim+1));
    dfs(1,1,0);

    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<getDist(a,b)<<endl;
    }
}   