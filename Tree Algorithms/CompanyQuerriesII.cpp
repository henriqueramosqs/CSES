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
const int MAXN = 2*1e5 +3;
vi adj[MAXN];
int up[MAXN][19];
int tin[MAXN];
int tout[MAXN];
int t=0;

void process(int v=1,int p=1){
    up[v][0]=p;
    rep(i,1,19)up[v][i]=up[up[v][i-1]][i-1];
    
    tin[v]=t++;
    for(int c:adj[v])process(c,v);

    tout[v]=t++;
}

bool is_ancestor(int a,int b){
    return (tin[a]<=tin[b] && tout[a]>=tout[b]);
}

int lca(int a,int b){
    if(is_ancestor(a,b))return a;
    if(is_ancestor(b,a))return b;

    for(int i=18;i>=0;i--){
        if(!is_ancestor(up[a][i],b)){
            a=up[a][i];
        }
    }
    return up[a][0];
}

int main(){
    sws
    int n,q;
    cin>>n>>q;

    rep(i,2,n+1){
        int x;cin>>x;
        adj[x].pb(i);
    }

    process();

    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<lca(a,b)<<endl;
    }
}
