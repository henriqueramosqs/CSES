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
#define ld long double
#define ss second
#define endl "\n"
#define pq priority_queue
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int MAXN = 5*1e4+1;
bitset<50000>reach[MAXN];
bool visited[MAXN];
vi adj[MAXN];

void dfs(int v){
    visited[v]=true;
    reach[v][v]=true;
    for(auto c:adj[v]){
        if(!visited[c])dfs(c);
        reach[v]|=reach[c];
    }
}
int32_t main(){
    sws
    int n,m;cin>>n>>m;
    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
    }

    rep(i,1,n+1){
        if(!visited[i])dfs(i);
    }
    rep(i,1,n+1)cout<<reach[i].count()<<" ";
}
