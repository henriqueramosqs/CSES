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
const int MAXN = 2*1e5+2;
int colors[MAXN];
vi adj[MAXN];
set<int> s[MAXN];
int ans[MAXN];

void dfs(int v,int p=-1){
    for(int c:adj[v]){
        if(c==p)continue;
        dfs(c,v);
        if(s[c].size()>s[v].size())swap(s[v],s[c]);
        for(int x:s[c])s[v].insert(x);
    }
    s[v].insert(colors[v]);
    ans[v]=s[v].size();
}
int main(){
    sws
    int n;cin>>n;
    rep(i,1,n+1)cin>>colors[i];

    rep(i,0,n-1){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1);

    rep(i,1,n+1)cout<<ans[i]<<" ";
}
