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
int dp[MAXN];
int path[MAXN];
bool visited[MAXN];


int calc(int v){
    if(dp[v]!=-1){
        return dp[v];
    }
    
    int curAns=-1;
    int curpPt=-1;

    for(int c:rev[v]){
       int tp = calc(c); 
       if(tp<0)continue;
       if(tp>curAns){
            curAns= tp;
            curpPt=c;
       }
    }

    path[v]=curpPt;
    return dp[v]=curAns+1;
}

void dfs(int v=1){
    visited[v]=true;
    for(int c:adj[v]){
        if(!visited[c])dfs(c);
    }
}
int main(){
    sws
    memset(dp,-1,sizeof(dp));
    memset(visited,false,sizeof(visited));

    dp[1]=0;
    path[1]=-1;
    int n,m;
    cin>>n>>m;

    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);   
        rev[b].pb(a);
    }
    dfs();
    rep(i,1,n+1){
        if(!visited[i])dp[i]=(-2*MAXN);
    }

    if(!visited[n]){
        cout<<"IMPOSSIBLE";
        return 0;
    }

    stack<int>pt;
    calc(n);
    
    int cur = n;

    while(cur!=-1){
        // dbg("cur",cur)
        pt.push(cur);
        cur = path[cur];
    }

    cout<<pt.size()<<endl;
    while(!pt.empty()){
        cout<<pt.top()<<" ";
        pt.pop();
    }
}
