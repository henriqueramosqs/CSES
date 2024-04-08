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

};


int32_t main(){
    sws
    int n,m,q;
    cin>>n>>m>>q;
    DSU dsu(n+1);
    vpp edges(m);
    vpp queries(q);
    vpp ints(q,mp(0,m));

    rep(i,0,m)cin>>edges[i].ff>>edges[i].ss;
    rep(i,0,q)cin>>queries[i].ff>>queries[i].ss;
        
    int rd=0;
    
    while(true){
        dsu.clear();
        vpp meds;

        rep(i,0,q){
            if(ints[i].ff==ints[i].ss)continue;
            int med = (ints[i].ff+ints[i].ss)/2;
            meds.pb(mp(med,i));
        }
        if(meds.empty())break;
        sort(meds.begin(),meds.end());

        int cur =-1;
        for(auto x:meds){
            int pt = x.ff,idx=x.ss;
  
            while(cur+1<pt){
                cur++;
                dsu.unite(edges[cur].ff,edges[cur].ss);
            }
            if( dsu.sm(queries[idx].ff,queries[idx].ss) ){
                ints[idx].ss=pt;
            }else{
                ints[idx].ff=pt+1;
            }

            
        }

    }

    for(auto c:edges)dsu.unite(c.ff,c.ss);

    rep(qq,0,q){
        if(!dsu.sm(queries[qq].ff, queries[qq].ss)){
            cout<<-1<<"\n";
        }else{
            cout<<ints[qq].ff<<"\n";
        }
    }

}
