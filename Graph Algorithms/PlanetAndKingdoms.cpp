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
#define ss second
#define pq priority_queue
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int MAXN = 1e5+1;
vi adj[MAXN];
vi rev[MAXN];
bool visited[MAXN];
int group[MAXN];
vi topSort;
int idx=1;

void dfs1(int v){
    visited[v]=true;
    for(auto c:adj[v]){
        if(!visited[c])dfs1(c);
    }
    topSort.pb(v);
}

void dfs2(int v){
    visited[v]=true;
    group[v]=idx;
    for(auto c:rev[v]){
        if(!visited[c])dfs2(c);
    }
}

int main(){
    sws
    int n,m;
    cin>>n>>m;

    memset(visited,false,sizeof(visited));

    while (m--){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        rev[b].pb(a);
    }


    rep(i,1,n+1){
        if(!visited[i])dfs1(i);
    }

    reverse(topSort.begin(),topSort.end());
    memset(visited,false,sizeof(visited));

    for(auto i: topSort){
        if(!visited[i]){
            dfs2(i);
            idx++;
        }
    }

   cout<<idx-1<<"\n";
   rep(i,1,n+1){
        cout<<group[i]<<" ";
   }

    
}
