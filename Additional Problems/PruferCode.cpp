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
const int MAXN  = 2*1e5+1;
vi lastAparition(MAXN,-1);
vi adj[MAXN];
set<int>s;

void dfs(int v=1,int p=-1){
    for(auto c:adj[v]){
        if(c==p)continue;
        cout<<v<<" "<<c<<"\n";
        dfs(c,v);
    }
}

int32_t main(){
    sws 
    int n;cin>>n;

    vi v(n-2);
    rep(i,0,n-2){
        cin>>v[i];
        lastAparition[v[i]]=i;
    }
    rep(i,1,n+1)if(lastAparition[i]<0)s.insert(i);

    rep(i,0,n-2){       
        auto it = s.begin();
        adj[*it].pb(v[i]);
        adj[v[i]].pb(*it);
        s.erase(it);
        if(i==lastAparition[v[i]])s.insert(v[i]);
    }

    adj[*s.begin()].pb(*next(s.begin()));
    adj[*next(s.begin())].pb(*s.begin());
    dfs();

}
