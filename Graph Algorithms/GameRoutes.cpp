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
const int MAXN = 1e5+1;
const int MOD = 1e9 +7;
int dp[MAXN];
vi rev[MAXN];

void dfs(int v){
    if(v==1)return;
    dp[v]=0;
    for(auto c:rev[v]){
        if(dp[c]==-1)dfs(c);
        (dp[v]+=dp[c])%=MOD;
    }
}
int main(){
    sws;
    int n,m;
    cin>>n>>m;
    memset(dp,-1,sizeof(dp));
    dp[1]=1;

    while(m--){
        int a,b;
        cin>>a>>b;
        rev[b].pb(a);
    }

    dfs(n);


    cout<<dp[n];
    

}
