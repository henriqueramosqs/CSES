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
typedef tuple<int,int,int> edge;
const int MAXN = 1e5+1;
 
struct DSU{
    vi sz;
    vi parents;
 
    DSU(int n):parents(n+1),sz(n+1,1){
        rep(i,1,n+1){
            parents[i]=i;
        }
    }
 
    int root(int a){
        if(a==parents[a])return a;
        return parents[a]=root(parents[a]);
    }
 
    void unite(int a,int b){
        a = root(a);
        b = root(b);
        if(a==b)return;
 
        if(sz[a]<sz[b])swap(a,b);
 
        parents[b]=a;
        sz[a]+=sz[b];
        sz[b]=0;
    }
 
    bool sameSet(int a,int b){
        return root(a)==root(b);
    }
 
};
 
struct Comp{
 
    bool operator()(edge a,edge b){
        return get<0>(a)>=get<0>(b);
    }
};
int32_t main(){
    sws
    int n,m;
    cin>>n>>m;
    pq<edge,vector<edge>,Comp> p;
 
    DSU dsu(n);
 
    rep(i,0,m){
        int a,b,c;
        cin>>a>>b>>c;
        p.push(mt(c,a,b));
    }
   
    int ans =0;
 
    while(!p.empty()){
        int a,b,c;
        tie(c,a,b) = p.top();
        p.pop();
        if(dsu.sameSet(a,b))continue;
        dsu.unite(a,b);
        ans+=c;
    }
 
    set<int>counter;
 
    rep(i,1,n+1){
        counter.insert(dsu.root(i));
    }
 
    if(counter.size()!=1){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    cout<<ans;
}