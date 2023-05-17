#include <bits/stdc++.h>
using namespace std;
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
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
const int MAXN = 2*1e5+1;
const int INF = 2*1e14+1;
const int MOD = 1e9+7;
vpp adj[MAXN];
vi aux_1[MAXN];
int n,m;

int calc(int pos,vi &dp){
    if(dp[pos]!=-1){
        return dp[pos];
    }
    int aux=0;
    for(int c:aux_1[pos]){
        (aux+=calc(c,dp))%=MOD;
    }
    return dp[pos]=aux;
}

int calc_2(int pos,vi &dp){
    if(dp[pos]!=-1){
        return dp[pos];
    }
    int aux=0;
    for(int c:aux_1[pos]){
        aux = max(aux,calc_2(c,dp));
    }
    return dp[pos]=aux+1;
}

int calc_3(int pos,vi &dp){
    if(dp[pos]!=INF){
        return dp[pos];
    }
    int aux=INF;
    for(int c:aux_1[pos]){
        aux = min(aux,calc_3(c,dp));
    }
    return dp[pos]=aux+1;
}



struct Step{
    int node;
    int org;
    int dist;
    Step(int v,int dd,int d=-1){
        node = v;
        dist = dd;
        org = d;
    }
};


struct  Comp{
    bool operator()(Step a,Step b){
        return a.dist>=b.dist;
    }
};

int32_t main(){
    sws
    cin>>n>>m;
    rep(i,0,m){
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].pb(mp(b,w));
    }

    int distances[n+1];
    bool visited[n+1];
    memset(visited,false,sizeof(visited));

    rep(i,0,n+1)distances[i]=INF;
    distances[1]=0;

    pq<Step,vector<Step>,Comp >p;
    p.push(Step(1,0));

    vi dp(n+1,-1);
    dp[1]=1;

    while(!p.empty()){
        int v = p.top().node;
        int org = p.top().org;
        int dist = p.top().dist;
        if((!visited[v] || distances[v]==dist) && org!=-1)aux_1[v].pb(org);
        p.pop();
        if(visited[v])continue;
        visited[v]=true;
        for(auto x: adj[v]){
            int c = x.ff,w =x.ss;
            if(visited[c])continue;
            if(distances[v]+w<=distances[c]){
                distances[c]=distances[v]+w;
                p.push(Step(c,distances[c],v));
            }
        } 
    }

    calc(n,dp);
    cout<<distances[n]<<" "<<dp[n]<<" ";

    rep(i,0,n+1)dp[i]=INF;
    dp[1]=0;
    calc_3(n,dp);
    cout<<dp[n]<<" ";

    rep(i,0,n+1)dp[i]=-1;
    dp[1]=0;
    calc_2(n,dp);
    cout<<dp[n];


}
