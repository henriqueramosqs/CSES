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
int leaf_1,leaf_2,maxDist=0,ans_1=0,ans_2=0;
const int MAXN = 2*1e5+1;
vi adj[MAXN];
int dp[MAXN][2];
bool leaf[MAXN];


void dfs(int v=1,int p=-1){

    for(int c:adj[v]){
        if(c==p) continue;
        leaf[v]=false;
        dfs(c,v);
        dp[v][0]+=max(dp[c][1],dp[c][0]);
    }
    if(leaf[v])return;
    for(int c:adj[v]){
        if(c==p)continue;
        dp[v][1]=max(dp[v][1],dp[v][0]+1+dp[c][0]-max(dp[c][1],dp[c][0]));
    }
}
int main(){
    sws
    int n;cin>>n;
    memset(dp,0,sizeof(dp));
    memset(leaf,1,sizeof(leaf));

    rep(i,0,n-1){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs();
    cout<<max(dp[1][1],dp[1][0]);
}
