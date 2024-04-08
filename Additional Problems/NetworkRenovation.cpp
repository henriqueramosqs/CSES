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
vi adj[MAXN];
int deg[MAXN];
vpp ans;
vi leafs;

void dfs(int v,int p=-1){
    for(auto c:adj[v]){
        if(c==p)continue;
        dfs(c,v);
    }
    if(adj[v].size()==1)leafs.pb(v);
}
int32_t main(){
    sws
    int n;cin>>n;
    rep(i,0,n-1){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
        deg[a]++;deg[b]++;
    }
    rep(i,1,n+1){
        if(deg[i]>1){
            dfs(i);
            int l = 0,r=leafs.size()/2;
            if(leafs.size()%2)r++;
            while(r<leafs.size()){
                ans.pb(mp(leafs[l],leafs[r]));
                l++;r++;
            }
            if(leafs.size()%2)ans.pb(mp(leafs[l],leafs.back()));
            break;
        }
    }

    cout<<ans.size()<<"\n";
    for(auto c:ans){
        cout<<c.ff<<" "<<c.ss<<"\n";
    }
}
