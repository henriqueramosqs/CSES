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
const int INF = 1e18;
const int MAXN = 501;
vi adj[MAXN];
// Find a way from the source to sink on a path with non-negative capacities
bool reachable (vvi &g,vi &parent,int n,int source,int sink){
    queue<int> q;
    q.push(source);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int son = 0; son < n; son++) {
            long long w = g[node][son];
            if (w <= 0 || parent[son] != -1) continue;
            parent[son] = node;
            q.push(son);
        }
    }
    return parent[sink] != -1;
};

long long max_flow(vvi &g, int n, int source, int sink) {
	long long flow = 0;
	vi parent(n, -1);


	// While there is a way from source to sink with non-negative capacities
	while (reachable(g,parent,n,source,sink)) {
		int node = sink;

		// The minimum capacity on the path from source to sink
		long long curr_flow = LLONG_MAX;
		while (node != source) {
			curr_flow = min(curr_flow, g[parent[node]][node]);
			node = parent[node];
		}
		node = sink;
		while (node != source) {
			// Subtract the capacity from capacity edges
			g[parent[node]][node] -= curr_flow;
			// Add the current flow to flow backedges
			g[node][parent[node]] += curr_flow;
			node = parent[node];
		}
		flow += curr_flow;
		fill(parent.begin(), parent.end(), -1);
	}

	return flow;
}

void dfs(vvi&gp,vb &vis,int v,int n,int p=-1){
    vis[v]=true;
    for(auto c:adj[v]){
        if(!vis[c] && gp[v][c]!=0){
            dfs(gp,vis,c,n,v);
        }
    }
}

int32_t main() {
	int n, m;
	cin >> n >> m;

	vvi capacity(n+1, vector<long long>(n+1, 0));
    vpp edges;
	for (int i = 0; i < m; i++) {
		int x, y, c=1;
		cin >> x >> y;
        edges.pb(mp(x,y));
        adj[x].pb(y);
        adj[y].pb(x);
		capacity[x][y] += c;
        capacity[y][x]+=c;
	}
    vb vis(n+1,false);

	cout << max_flow(capacity, n+1, 1, n ) << "\n";
    dfs(capacity,vis,1,n+1);
    for(auto c:edges){
        bool aux = vis[c.ff]^vis[c.ss];
        if(aux)cout<<c.ff<<" "<<c.ss<<"\n";
    }
    
}