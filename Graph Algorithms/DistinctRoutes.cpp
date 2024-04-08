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
const int N = 700; 


struct Dinic {
    struct Edge { 
        int from, to, flow, cap;
        Edge(int a,int b,int c,int d){
            from =a;to=b;
            flow=c;cap=d;
        }
    };
    vector<Edge> edges;

    vector<int> g[N];
    int ne = 0, lvl[N], vis[N], pass;
    int qu[N], px[N], qt;

    int run(int s, int sink, int minE) {
        if (s == sink) return minE;
        int ans = 0;
        for(; px[s] < (int)g[s].size(); px[s]++){
            int e = g[s][ px[s] ];
            auto &v = edges[e], &rev = edges[e^1];
            if( lvl[v.to] != lvl[s]+1 || v.flow >= v.cap) continue;
            int tmp = run(v.to, sink, min(minE, v.cap - v.flow));
            v.flow += tmp, rev.flow -= tmp;
            ans += tmp, minE -= tmp;
            if (minE == 0) break;
        }
        return ans;
    }

    bool bfs(int source, int sink) {
        qt = 0;
        qu[qt++] = source;
        lvl[source] = 1;
        vis[source] = ++pass;
        for(int i=0; i<qt; i++) {
            int u = qu[i];
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

    int flow(int source, int sink) { // max_flow
        reset_flow();
        int ans = 0;
        while(bfs(source, sink))
            ans += run(source, sink, __INT64_MAX__);
        return ans;
    }

    void addEdge(int u, int v, int c, int rc = 0) { // c = capacity, rc = retro-capacity;
        Edge e(u, v, 0, c);
        edges.pb(e);
        g[u].pb(ne++);
        e = Edge(v, u, 0, rc);
        edges.pb(e);
        g[v].pb(ne++);
    }

    void reset_flow() {
        for (int i=0; i<ne; i++) edges[i].flow = 0;
        memset(lvl, 0, sizeof(lvl));
        memset(vis, 0, sizeof(vis));
        memset(qu, 0, sizeof(qu));
        memset(px, 0, sizeof(px));
        qt = 0; pass = 0;
    }
    vi get(int s,int t){
        vi ans;
        int cur = s;
        while(cur!=t){
            ans.pb(cur);
            for(auto& ed :g[cur]) {
                auto &v = edges[ed];
                if(v.flow>0){
                    cur = v.to;
                    v.flow--;
                    break;
                }
            }
        }
        ans.pb(cur);
        return ans;
    }
};

int32_t main(){
    sws
    int n,m;cin>>n>>m;
    Dinic d;
    rep(i,0,m){
        int a,b;cin>>a>>b;
        d.addEdge(a,b,1);
    }
    int ans = d.flow(1,n);
    cout<<ans<<"\n";

    rep(i,0,ans){
        vi aux=d.get(1,n);
        cout<<aux.size()<<"\n";
        for(auto c:aux)cout<<c<<" ";
        cout<<"\n";
    }
}

// sample 1 
// ans = 7
// 6 8
// 1 2 5
// 1 4 4
// 2 3 6
// 3 6 5 
// 3 5 8
// 4 5 1 
// 4 2 3
// 5 6 2
// 1 6

// sample 2
// ans = 10
// 6 9
// 1 2 7
// 1 3 4
// 2 4 5
// 2 5 3 
// 3 2 3
// 3 5 2 
// 5 6 5
// 4 6 8
// 5 4 3
// 1 6