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
const int MAXN = 1e5+1;

struct DSU{
    vi sz;
    vi parents;
    int numComp;
    int maxComp;

    DSU(int n):parents(n+1),sz(n+1,1){
        rep(i,1,n+1){
            parents[i]=i;
        }

        numComp=n;
        maxComp =1;
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
        numComp--;
        maxComp=max(maxComp,sz[a]);
    }
    void pt(){
        cout<<numComp<<" "<<maxComp<<"\n";
    }
};

int32_t main (){
    sws;
    int n,m;
    cin>>n>>m;
    DSU dsu(n);

    while(m--){
        int a,b;
        cin>>a>>b;
        dsu.unite(a,b);
        dsu.pt();
    }
}