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
const int MAXN = 1e5+1;
vpp adj[MAXN];
bool vis[MAXN];
set<int>aux;


bool isIn(int x){
    return aux.find(x)!=aux.end();
}
void dfs(int v=1,int p=-1,bool down = true){
    vis[v]=true;
    for(auto x:adj[v]){
        int c =x.ff,idx=x.ss;
        if(idx==p)continue;
        if(vis[c]){
            if(!isIn(idx)){
                if(!down){
                    cout<<c<<" "<<v<<"\n";
                }else{
                    cout<<v<<" "<<c<<"\n";
                }
                aux.insert(idx);
            }
            continue;
        }
        if(down){
            if(!isIn(idx)){
                cout<<v<<" "<<c<<"\n";
                aux.insert(idx);
            }
        }else{
            if(!isIn(idx)){
                cout<<c<<" "<<v<<"\n";
                aux.insert(idx);
            }
        }
        dfs(c,idx,down^1);
    }
}
int32_t main(){
    sws
    int n,m;cin>>n>>m;
    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        adj[a].pb(mp(b,i));
        adj[b].pb(mp(a,i));
    }
    rep(i,1,n+1){
        if(!vis[i])dfs(i);
    }
}
