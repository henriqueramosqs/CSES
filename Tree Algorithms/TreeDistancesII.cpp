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
#define ss second
#define pq priority_queue
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
int n;
const int MAXN =2*1e5 +1;
vi adj[MAXN];
int st[MAXN];
int ans[MAXN];

void dfs_1(int v=1,int p=-1,int h=0){

    ans[v]=0;
    st[v]=1;

    for(int c:adj[v]){
        if(c==p)continue;
        dfs_1(c,v,h+1);
        st[v]+=st[c];
    }

    ans[1]+=h;

}
void dfs_2(int v=1,int p=-1){
    if(v!=1){
        ans[v]=ans[p];
        ans[v]-=(st[v]-1);
        ans[v]+=(n-st[v]-1);
    }

    for(int c:adj[v]){
        if(c==p)continue;
        dfs_2(c,v);
    }

}


int32_t main(){
    sws
    cin>>n;

    rep(i,0,n-1){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs_1();

    dfs_2();

    rep(i,1,n+1)cout<<ans[i]<<" ";
}
