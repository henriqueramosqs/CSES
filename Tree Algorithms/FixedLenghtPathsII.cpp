#include <bits/stdc++.h>
using namespace std;
// #pragma GCC target("popcnt")
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define pf push_front
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(x) cout<<#x<<" "<<x<<endl;
#define output(x) for(int c:x){cout<<c<<" ";}cout<<" ";
#define int long long 
#define ff first
#define ld long double
#define ss second
#define endl "\n"
#define pq priority_queue
typedef vector<int> vi;
typedef deque<int> di;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int MAXN = 2*1e5+5;
vi adj[MAXN];
int n,k1,k2;
int finans=0ll;


int get(di &a,int idx){
    if(idx<=0)return a[0];
    if(idx>=a.size())return 0ll;
    return a[idx];
}
int get(di &a,int l,int r){
    return get(a,l)-get(a,r+1);
}

void comb(di &a,di &b){
    int  n= a.size(), m = b.size();
    if(n<m){
        swap(a,b);
        swap(n,m);
    }

    rep(i,0,m){
        int cur = get(b,i,i);
        finans+=(cur*get(a,k1-i,k2-i));
    }
    rep(i,0,m)a[i]+=b[i];
    
}




di dfs(int v=1,int p=-1){
    di d;
    d.pf(1);
    for(auto c:adj[v]){
        if(c==p)continue;
        di aux = dfs(c,v);
        aux.pf(aux.front());
        comb(d,aux);
    }
    return d;
}

int32_t main(){
    sws
    cin>>n>>k1>>k2;
    rep(i,0,n-1){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs();
    cout<<finans;
}
