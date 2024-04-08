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
#define endl "\n"
#define pq priority_queue
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int MAXN = 2*1e5+1;
vi adj[MAXN];
int up[MAXN][19];
int head[MAXN];
vi heavy(MAXN,-1);
int st[MAXN];
int id[MAXN];
int t[MAXN<<2];
int h[MAXN];
int val[MAXN];
int tin[MAXN];
int tout[MAXN];
int n,q;
int cur=0;
int temp=0;
 
int get(int a, int b) {
    a += n; b += n;
    int s = 0;
    while (a <= b) {
        if (a%2 == 1) s = max(s,t[a++]);
        if (b%2 == 0) s = max(s,t[b--]);
        a /= 2; b /= 2;
    }   
    return s; 
}

void update(int k, int x) {
    k += n;
    t[k] = x;
    for (k /= 2; k >= 1; k /= 2) {
        t[k] = max(t[2*k],t[2*k+1]);
    }
}

 
int dfs_sz(int v=1,int p=1,int he=0){
    // dbg("v_a",v)
    h[v]=he;
    up[v][0]=p;
    rep(i,1,19)up[v][i]=up[up[v][i-1]][i-1];
    int heavy_c=-1;
    int heavy_sz=0;
    tin[v]=temp++;
    st[v]=1;
    for(auto c:adj[v]){
        if(c==p)continue;
        int aux = dfs_sz(c,v,he+1);
        st[v]+=aux;
        if(aux>heavy_sz){
            heavy_sz=aux;
            heavy_c=c;
        }
    }
    heavy[v]=heavy_c;
    tout[v]=temp++;
    return st[v];
}
 
 
void dfs_hld(int v=1,int p=1,int hd=1){
    // dbg("v_h",v)
    id[v]=cur++;
    update(id[v],val[v]);
    head[v]=hd;
    if(heavy[v]!=-1){
        dfs_hld(heavy[v],v,hd);
    }
 
    for(auto c:adj[v]){
        if(c==p || c==heavy[v])continue;
        dfs_hld(c,v,c);
    }
}
 
void process(){
    dfs_sz();
    dfs_hld();
}
 
 
int query(int a,int b){
    int res=0;
    // heads diferentes
    for(;head[a]!=head[b];b=up[head[b]][0]){
        if(h[head[a]]>h[head[b]])swap(a,b);
        int aux = get(id[head[b]],id[b]);
        res=max(aux,res);
    }
    //heads iguais
    if(h[a]>h[b])swap(a,b);
    int aux=get(id[a],id[b]);
    res=max(res,aux);
    return res;
}
 
bool isAncestor(int a,int b){
    return tin[a]<=tin[b] && tout[a]>=tout[b];
}
 
int lca(int a,int b){
    if(isAncestor(a,b))return a;
    if(isAncestor(b,a))return b;
    rep(j,0,19){
        int i = 18-j;
        if(!isAncestor(up[a][i],b))a=up[a][i];
    }
    return up[a][0];
}
int32_t main(){
    sws
    cin>>n>>q;
    rep(i,1,n+1)cin>>val[i];
    rep(i,1,n){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
 
    process();
 
    while(q--){
        int op;cin>>op;
        if(op==1){
            int v,x;
            cin>>v>>x;
            update(id[v],x);
        }else{
            int a,b;
            cin>>a>>b;
            int l = lca(a,b);
            cout<<max(query(l,a),query(l,b))<<" ";
        }
    }
}