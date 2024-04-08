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
const int MAXN= 1e5+1;
vi adj[MAXN];
int tin[MAXN];
int low[MAXN];
bool visited[MAXN];
int tempo=0;
vpp ans;
void dfs(int v=1,int p=-1){
    tin[v]=low[v]=tempo++;
    visited[v]=true;

    for(int c:adj[v]){
        if(c==p)continue;
        if(visited[c]){
            low[v]=min(low[v],tin[c]);
        }else{
            dfs(c,v);
            low[v]=min(low[v],low[c]);
            if(low[c]>tin[v])ans.pb(mp(v,c));
 
        }


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
    dfs();
    cout<<ans.size()<<endl;
    for(auto c:ans){
        cout<<c.ff<<" "<<c.ss<<endl;
    }
}
