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
typedef pair<pii,int >pp;

const int INF = (1ll<<30);

struct Dinitz {
  struct Edge {
    int v, u, cap, flow=0;
    Edge (int v, int u, int cap) : v(v), u(u), cap(cap) {}
  };

  vector<Edge> edges;
  vector<vector<int>> adj;
  vb vis;
  int n, s, t;
  Dinitz(int n, int s, int t) : vis(n,false),n(n), s(s), t(t) {
    adj.resize(n);
  }

  void add_edge(int v, int u, int cap) {
    edges.emplace_back(v, u, cap);
    adj[v].push_back(edges.size()-1);
    edges.emplace_back(u, v, 0);
    adj[u].push_back(edges.size()-1);
  }

  vector<int> level;
  bool bfs() {
    queue<int> Q;
    level.assign(n, -1);
    level[s] = 0;
    Q.push(s);
    while (!Q.empty()) {
      int v = Q.front(); Q.pop();
      for (auto eid : adj[v]) {
        auto e = edges[eid];
        if (e.cap - e.flow <= 0) continue;
        if (level[e.u] != -1) continue;
        level[e.u] = level[v] + 1;
        Q.push(e.u);
      }
    }
    return level[t] != -1;
  }

  vector<int> ptr;
  int dfs(int v, int f) {
    if (f == 0 || v == t) return f;
    for (int &cid = ptr[v]; cid < adj[v].size(); cid++) {
      int eid = adj[v][cid];
      auto &e = edges[eid];
      if (e.cap - e.flow <= 0) continue;
      if (level[e.u] != level[e.v] + 1) continue;
      int newf = dfs(e.u, min(f, e.cap-e.flow));
      if (newf == 0) continue;
      e.flow += newf;
      edges[eid^1].flow -= newf;
      return newf;
    }
    return 0;
  }

  int flow() {
    int f = 0;
    while (bfs()) {
      ptr.assign(n, 0);
      while (int newf = dfs(s, INF))
        f += newf;
    }
    return f;
  }

  vi getRows(){
    vi ans;
    for(auto c:edges){
        if(c.v==s && c.flow>0){
            ans.pb(c.u);
        }
    }
    return ans;
  }

  void dfs(int v){
    vis[v]=true;
    for(auto eid:adj[v]){
        auto e = edges[eid];
        if(!vis[e.u] && e.cap-e.flow!=0)dfs(e.u);
    }
  }
}; //}}}

int32_t main(){
    sws 
    int n;cin>>n;
    // [0,n-1] = linhas, [n,2*n-1] =colunas
    // 2*n = org, 2*n+1 = dest
    Dinitz d((n+1)<<2,n<<1, n<<1|1);
    rep(i,0,n)d.add_edge(n<<1,i,1);
    rep(i,n,n<<1)d.add_edge(i,n<<1|1,1);
    rep(i,0,n){
        rep(j,0,n){
            char ch;cin>>ch;
            if(ch=='o')d.add_edge(i,j+n,1);
        }
    }

    cout<<d.flow()<<"\n";
    d.dfs(n<<1);
    
    rep(i,0,n){
        if(!d.vis[i])cout<<1<<" "<<i+1<<"\n";
    }
    
    rep(j,0,n){
         if(d.vis[j+n])cout<<2<<" "<<j+1<<"\n";
    }

}   
