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
const int MAXN = 2501;
const int INF = 1e14;
vi adj[MAXN];
vi rev[MAXN];
bool marked[MAXN];

int32_t main(){
    sws
    int n,m;
    cin>>n>>m;
    vector<tuple<int,int,int> >edjes;
    memset(marked,false,sizeof(marked));
    
    rep(i,0,m){
        int a,b,w;
        cin>>a>>b>>w;
        edjes.pb(mt(a,b,w));
        adj[a].pb(b);
        rev[b].pb(a);
    }

    int dist[n+1];
    rep(i,0,n+1)dist[i]=-INF;
    dist[1]=0;


    rep(i,0,n-1){
        for(auto e:edjes){
            int a,b,w;
            tie(a,b,w) =e;
            dist[b]=max(dist[b],dist[a]+w);
        }
    }
    
     bool any = false;
    
    for(auto e:edjes){
        int a,b,w;
        tie(a,b,w) =e;
        if(dist[b]<dist[a] +w){
            any = true;
            marked[b]=true;
        }
    }

    if(!any){
        cout<<dist[n];
        return 0;
    }

    bool visited_by_one[n+1];
    memset(visited_by_one,false,sizeof(visited_by_one));
    stack<int>s;
    s.push(1);

    while(!s.empty()){
        int v = s.top();
        s.pop();
        visited_by_one[v]=true;

        for(auto c:adj[v]){
            if(!visited_by_one[c])s.push(c);
        }
    }

    bool visited_by_n[n+1];
    memset(visited_by_n,false,sizeof(visited_by_n));
    s.push(n);

    while(!s.empty()){
        int v = s.top();
        s.pop();
        if(marked[v] && visited_by_one[v]){
            cout<<-1;
            return 0;
        }
        visited_by_n[v]=true;

        for(auto c:rev[v]){
            if(!visited_by_n[c])s.push(c);
        }
    }

    cout<<dist[n];
  

}
