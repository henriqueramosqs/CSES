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
#define int long long
#define ss second
#define pq priority_queue
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int MAXN = 1e5+1;
const int  INF = 1e18;
 
vpp adj[MAXN];
int distances[MAXN];
bool visited[MAXN];
 
 
int32_t main(){
    sws
    int n,m;
    cin>>n>>m;
 
    rep(i,0,m){
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].pb(mp(b,w));
    }
   
    rep(i,0,n+1)distances[i]=INF;
    distances[1]=0;
    pq<pii>p;
    p.push(mp(0,1));
    
    while(!p.empty()){
        int v = p.top().ss;
        p.pop();
 
        if(visited[v])continue;
        visited[v]=true;
 
        for(auto c:adj[v]){
            int b = c.ff,w=c.ss;
            if(!visited[b] && distances[b]>distances[v]+w){
                distances[b]=distances[v]+w;    
                p.push(mp(-distances[b],b));
            }
        }
    }
 
    rep(i,1,n+1)cout<<distances[i]<<" ";
 
}