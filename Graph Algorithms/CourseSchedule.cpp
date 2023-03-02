#include <bits/stdc++.h>
using namespace std;
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define mt make_tuple
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
const int MAXN = 1e5+1;
vi adj[MAXN];
int colour[MAXN];
vi topSort;
bool poss = true;

void dfs(int v){
   colour[v]=1;
    for(auto c:adj[v]){
        if(colour[c]==1){
            poss = false;
            return ;
        }

        if(colour[c]==0)dfs(c);
    }
    topSort.pb(v);
    colour[v]=2;
}
int32_t main(){
    sws
    int n,m;
    cin>>n>>m;
    memset(colour,0LL,sizeof(colour));
    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
    }

    rep(i,1,n+1){
        if(colour[i]==0)dfs(i);
    }

    reverse(topSort.begin(),topSort.end());

    if(poss){output(topSort);}
    else{cout<<"IMPOSSIBLE";}

}