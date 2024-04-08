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
set<int> adj[MAXN];
stack<pii> ans;
int counter=0;

void dfs(int v=1,int p=-1){

    // for(auto c:adj[v]){
    while(true){
        if(adj[v].empty())break;
        int c = *adj[v].begin();
        adj[v].erase(adj[v].begin());
        adj[c].erase(adj[c].find(v));
        dfs(c,v);
    }
 
    ans.push(mp(p,v));
}
int main(){
    sws
    int n,m;
    cin>>n>>m;
    rep(i,0,m){
        int a,b;cin>>a>>b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    dfs();

    bool poss = true;
    if(ans.size()-1!=m)poss=false;
 
    vi fin;
 
    pii last=mp(-1,-1);

        
    while(!ans.empty()){
        if(ans.top()==mp(last.ss,last.ff))poss=false;
        if(last.ss!=ans.top().ff)poss=false;
        fin.pb(ans.top().ss);
        last = ans.top();
        ans.pop();
    }
 
    if(fin[fin.size()-1]!=1)poss=false;

    if(poss){
        for(auto c:fin)cout<<c<<" ";
    }else{
        cout<<"IMPOSSIBLE";
    }
}