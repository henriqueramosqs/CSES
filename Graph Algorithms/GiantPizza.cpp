
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
const int MAXN = 2*1e5+5;
vi adj[MAXN];
vi rev[MAXN];
int deg[MAXN];
int gp[MAXN];
bool vis[MAXN];
bool ans[MAXN];
int idx=0;
vi topSort;
int n,m;

int getOp(int x){
    if(x>=m)return x-m;
    return x+m;
}

void dfs1(int v=1){
    vis[v]=true;

    for(auto c:adj[v]){
        if(vis[c])continue;
        dfs1(c);
    }

    topSort.pb(v);

}

void dfs2(int v){
    vis[v]=true;
    gp[v]=idx;
    for(auto c:rev[v]){
        if(vis[c])continue;
        dfs2(c);
    }
}


void dfs3(int v,int gg){
    vis[v]=vis[getOp(v)]=true;
    if(v>=m){
        ans[v%m]=false;
    }else{
        ans[v%m]=true;
    }
    for(auto c:adj[v]){
        if(vis[c] || gp[v]!=gp[c])continue;
        dfs3(c,gg);
    }
}

int32_t main(){
    sws;
    cin>>n>>m;
    rep(i,0,n){
        char a1,a2;
        int b1,b2;
        cin>>a1>>b1>>a2>>b2;
        b1--;b2--;
        if(a1=='-')b1=getOp(b1);
        if(a2=='-')b2=getOp(b2);
        adj[getOp(b1)].pb(b2);
        adj[getOp(b2)].pb(b1);
        deg[b2]++;deg[b1]++;
        rev[b2].pb(getOp(b1));
        rev[b1].pb(getOp(b2));
    }
    rep(i,0,(m<<1)){
        if(!vis[i])dfs1(i);
    }
    memset(vis,false,sizeof(vis));
    reverse(topSort.begin(),topSort.end());
    for(auto c:topSort){
        if(vis[c])continue;
        dfs2(c);
        idx++;
    }
    rep(i,0,m){
        if(gp[i]==gp[getOp(i)]){
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
    }

    memset(vis,false,sizeof(vis));
    pq<pii>aux;
    rep(i,0,(m<<1))aux.push(mp(gp[i],i));
    while(!aux.empty()){
        int v = aux.top().ss;
        aux.pop();
        if(!vis[v]){
            dfs3(v,gp[v]);
        }
    }

    rep(i,0,m){
        if(ans[i]){
            cout<<"+ ";
        }else{
            cout<<"- ";
        }
    }


}   
