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
int temp=0,leaf_1,leaf_2,hMax=0;
vi adj[MAXN];
int up[MAXN][18];
int tin[MAXN],tout[MAXN],h[MAXN];
 
 
void dfs1(int v=1,int p=-1,int height=0){
    up[v][0]=p;
    if(p<0)up[v][0]=v;
    h[v]=height;
    if(height>hMax){
        leaf_1=v;
        hMax = height;
    }
    rep(i,1,18)up[v][i]= up[up[v][i-1]][i-1];
    tin[v]=temp++;
 
    for(int c:adj[v]){
        if(c==p)continue;
        dfs1(c,v,height+1);
    }
 
    tout[v]=temp++;
}
 
void getWidth(int v=leaf_1,int p =-1,int height=0){
    if(height>hMax){
        leaf_2=v;
        hMax = height;
    }
    for(auto c:adj[v]){
        if(c==p)continue;
        getWidth(c,v,height+1);
    }
}
 
int isAncestor(int a,int b){
    return (tin[a]<=tin[b] && tout[a]>=tout[b]);
}
 
int lca(int a,int b){
    if(isAncestor(a,b))return a;
    if(isAncestor(b,a))return b;
 
    rep(i,0,18){
        int val = 17-i;
        if(!isAncestor(up[a][val],b))a=up[a][val];
    }
    return up[a][0];
}
 
int getDist(int a,int b){
    return h[a]+h[b]-2*h[lca(a,b)];
}
 
int main(){
    sws
    int n;
    cin>>n;
    rep(i,0,n-1){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
 
    dfs1();hMax=0;
    getWidth();
    rep(i,1,n+1){
        cout<<max(getDist(i,leaf_1), getDist(i,leaf_2))<<" ";
    }
}