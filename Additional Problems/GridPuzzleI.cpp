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
#define ll long long
#define ff first
#define ld long double
#define ss second
#define endl "\n"
#define pq priority_queue
typedef vector<int> vi;
typedef vector<vector<char> > vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const ll N = 700; 


struct Dinic {
    struct Edge { 
        ll from, to, flow, cap;
        Edge(ll a,ll b,ll c,ll d){
            from =a;to=b;
            flow=c;cap=d;
        }
    };
    vector<Edge> edges;

    vector<ll> g[N];
    ll ne = 0, lvl[N], vis[N], pass;
    ll qu[N], px[N], qt;

    ll run(ll s, ll sink, ll minE) {
        if (s == sink) return minE;
        ll ans = 0;
        for(; px[s] < (int)g[s].size(); px[s]++){
            ll e = g[s][ px[s] ];
            auto &v = edges[e], &rev = edges[e^1];
            if( lvl[v.to] != lvl[s]+1 || v.flow >= v.cap) continue;
            ll tmp = run(v.to, sink, min(minE, v.cap - v.flow));
            v.flow += tmp, rev.flow -= tmp;
            ans += tmp, minE -= tmp;
            if (minE == 0) break;
        }
        return ans;
    }

    bool bfs(ll source, ll sink) {
        qt = 0;
        qu[qt++] = source;
        lvl[source] = 1;
        vis[source] = ++pass;
        for(ll i=0; i<qt; i++) {
            ll u = qu[i];
            px[u] = 0;
            if (u == sink) return 1;
            for(auto& ed :g[u]) {
                auto v = edges[ed];
                if (v.flow >= v.cap || vis[v.to] == pass) continue;
                vis[v.to] = pass;
                lvl[v.to] = lvl[u]+1;
                qu[qt++] = v.to;
            }
        }
        return false;
    }

    ll flow(ll source, ll sink) { // max_flow
        reset_flow();
        ll ans = 0;
        while(bfs(source, sink))
            ans += run(source, sink, __INT64_MAX__);
        return ans;
    }

    void addEdge(ll u, ll v, ll c, ll rc = 0) { // c = capacity, rc = retro-capacity;
        Edge e(u, v, 0, c);
        edges.pb(e);
        g[u].pb(ne++);
        e = Edge(v, u, 0, rc);
        edges.pb(e);
        g[v].pb(ne++);
    }

    void reset_flow() {
        for (ll i=0; i<ne; i++) edges[i].flow = 0;
        memset(lvl, 0, sizeof(lvl));
        memset(vis, 0, sizeof(vis));
        memset(qu, 0, sizeof(qu));
        memset(px, 0, sizeof(px));
        qt = 0; pass = 0;
    }

};

int32_t main(){
    sws
    int n;cin>>n;
    Dinic d;
    char ans[n][n];
    memset(ans,'.',sizeof(ans));
    int sum =0;
    int lin[n];
    int col[n];
    rep(i,1,n+1){
      int x;cin>>x;
      d.addEdge(0,i,x);
      lin[i-1]=x;
    }


    rep(i,n +1,(n<<1)+1){
      int x;cin>>x;
      d.addEdge(i,2*n+1,x);
      col[i-n-1]=x;
    }


    rep(i,1,n+1){
      rep(j,n+1,2*n+1){
        d.addEdge(i,j,1);
      }
    }

    int xx = d.flow(0,2*n+1);
   
    for(auto c:d.edges){
        if(c.flow<=0)continue;
        int i = c.from,j = c.to;
        if(i>=1 && i<=n && j>=n+1 && j<=2*n){
            lin[i-1]--;
            col[j-n-1]--;
            ans[i-1][j-n-1]='X';
        }
    }
    rep(i,0,n){
        if(lin[i]!=0 || col[i]!=0){
            cout<<-1;
            return 0;
        }
    }

    rep(i,0,n){
      rep(j,0,n)cout<<ans[i][j];
      cout<<"\n";
    }
}