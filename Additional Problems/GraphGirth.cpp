#include <bits/stdc++.h>
using namespace std;
// #pragma GCC target("popcnt")
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
const int MAXN = 2500+1;
const int INF = __INT64_MAX__;
vvi dp(MAXN,vi(MAXN,INF));
vi adj[MAXN];
int ans= INF;

int32_t main(){
    sws
    int n,m;cin>>n>>m;
    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    rep(i,1,n+1){
        vi dist(n+1,INF);
        queue<int>p;
        p.push(i);
        dist[i]=0ll;
        while(!p.empty()){
            int v = p.front();
            p.pop();

            for(auto c:adj[v]){
                if(dist[c]==INF){
                    dist[c]=dist[v]+1;
                    p.push(c);
                }else{
                    if(dist[c]<dist[v])continue;
                    ans = min(ans,dist[c]+dist[v]+1);
                }
            }
        }


    }
    ans==INF?cout<<-1:cout<<ans;
}
