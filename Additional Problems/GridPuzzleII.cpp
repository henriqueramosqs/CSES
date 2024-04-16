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
 
// Dinitz Min Cost {{{
const int INF = 0x3f3f3f3f3f3f3f3f;
 
struct Dinitz {
  struct Edge {
    int v, u, cap, flow=0, cost;
    Edge(int v, int u, int cap, int cost) : v(v), u(u), cap(cap), cost(cost) {}
  };
 
  int n, s, t;
  Dinitz(int n, int s, int t) : n(n), s(s), t(t) {
    adj.resize(n);
  }
 
  vector<Edge> edges;
  vvi adj;
  void add_edge(int v, int u, int cap, int cost) {
    edges.pb(Edge(v, u, cap, cost));
    adj[v].push_back(edges.size()-1);
    edges.pb(Edge(u, v, 0, -cost));
    adj[u].push_back(edges.size()-1);
  }
 
  vector<int> dist;
  bool spfa() {
    dist.assign(n, INF);
 
    queue<int> Q;
    vector<bool> inqueue(n, false);
 
    dist[s] = 0;
    Q.push(s);
    inqueue[s] = true;
 
    vector<int> cnt(n);
 
    while (!Q.empty()) {
      int v = Q.front(); Q.pop();
      inqueue[v] = false;
 
      for (auto eid : adj[v]) {
        auto const& e = edges[eid];
        if (e.cap - e.flow <= 0) continue;
        if (dist[e.u] > dist[e.v] + e.cost) {
          dist[e.u] = dist[e.v] + e.cost;
          if (!inqueue[e.u]) {
            Q.push(e.u);
            inqueue[e.u] = true;
          }
        }
      }
    }
 
    return dist[t] != INF;
  }
 
  int cost = 0;
  vector<int> ptr;
  int dfs(int v, int f) {
    if (v == t || f == 0) return f;
    for (auto &cid = ptr[v]; cid < adj[v].size();) {
      auto eid = adj[v][cid];
      auto &e = edges[eid];
      cid++;
      if (e.cap - e.flow <= 0) continue;
      if (dist[e.v] + e.cost != dist[e.u]) continue;
      int newf = dfs(e.u, min(f, e.cap-e.flow));
      if (newf == 0) continue;
      e.flow += newf;
      edges[eid^1].flow -= newf;
      cost += e.cost * newf;
      return newf;
    }
    return 0;
  }
 
  int total_flow = 0;
  int flow() {
    while (spfa()) {
      ptr.assign(n, 0);
      while (int newf = dfs(s, INF))
        total_flow += newf;
    }
    return total_flow;
  }
};
 
int32_t main(){
    sws
    int n;cin>>n;
    Dinitz d((n<<1)+2,0,2*n+1);
    int sum = 0;
    rep(i,1,n+1){
        int x;cin>>x;
        sum+=x;
        d.add_edge(0,i,x,0);
    }


    rep(i,n+1,(n<<1|1)){
        int x;cin>>x;
        sum+=x;
        d.add_edge(i,n<<1|1,x,0);
    }

    rep(i,1,n+1){
        rep(j,n+1,(n<<1|1)){
            int price;cin>>price;
            d.add_edge(i,j,1,-price);
        }
    }
    int aux = d.flow();
    if(2*aux !=sum){
        cout<<-1;
        return 0;
    }
    cout<<abs(d.cost)<<"\n";
    char ans[n][n];
    memset(ans,'.',sizeof(ans));
 
    for(auto c:d.edges){
        if(c.flow<=0)continue;
        if(c.v>=1 && c.v<=n && c.u>=n+1 && c.u<=2*n){
            ans[c.v-1][c.u-n-1]='X';
        }
    }

    rep(i,0,n){
        rep(j,0,n)cout<<ans[i][j];
        cout<<"\n";
    }
}
