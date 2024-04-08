#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")
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
const int MOD = 1e9+7;

int calc(int x){
    if(x==0)return 1;
    return (2*calc(x-1))%MOD;
}

struct DSU{
    int n; 
    vi sz;
    vi parent;

    void clear(){
        rep(i,0,n)sz[i]=1;
        rep(i,0,n)parent[i]=i;
    }

    DSU(int x):sz(x,1),parent(x){
        n = x;
        rep(i,0,x)parent[i]=i;
    }

    int root(int x){
        if(x==parent[x])return x;
        return parent[x]=root(parent[x]);
    }

    void unite(int a,int b){
        a=root(a);
        b=root(b);
        if(a==b)return;
        if(sz[a]<sz[b])swap(a,b);
        parent[b]=a;
        sz[a]+=sz[b];
    }

    bool sm(int a,int b){
        return root(a)==root(b);
    }

    int cnt(){
        set<int>s;
        int aux =0;
        rep(i,1,n){
            int r = root(i);
            if(s.find(r)!=s.end())continue;
            aux+=(sz[r]-1);
            s.insert(r);
        }
        return aux;
    }

};

int32_t main(){
    sws
    int n,m;
    cin>>n>>m;
    DSU dsu(n+1);
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        dsu.unite(x,y);
    }
    int bck = m-dsu.cnt();
    cout<<calc(bck);
}
