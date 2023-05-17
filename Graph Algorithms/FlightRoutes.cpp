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
const int MAXN = 1e5+1;
vpp adj[MAXN];
 
signed main(){
    sws
    int n,m,k;
    cin>>n>>m>>k;
 
    rep(i,0,m){
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].pb(mp(b,w));
    }
 
    pq<int,vi,greater<int> >distances[n+1];
    // distances[1].push(0);
 
    pq<pii,vpp, greater<pii> >p;
    p.push(mp(0,1));
 
    while(!p.empty()){
        int v = p.top().ss;
        int d = p.top().ff;
        p.pop();
        if(distances[v].size()==k)continue;
        distances[v].push(d);
 
        for(auto c:adj[v]){
            int b = c.ff,w=c.ss;
            if(distances[b].size()<(k)){
                p.push(mp(d+w,b));
            }
        }
    }
 
    int counter=0;
    while(counter!=k){
        cout<<distances[n].top()<<" ";
        distances[n].pop();
        counter++;
    }
}