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
const int MAXN =2*1e5+1;
vi adj[MAXN];
int sub[MAXN];
int n,ans;

void dfs_1(int v=1,int p=-1){
    sub[v]=1;
    for(int c:adj[v]){
        if(c==p)continue;
        dfs_1(c,v);
        sub[v]+=sub[c];
    }
}

int dfs_2(int v=1, int p=-1){

    for(int c:adj[v]){
        if(c==p)continue;
        if(sub[c]>(n/2))return dfs_2(c,v);
    }
    return v;
}

int main(){
    sws
    cin>>n;

    rep(i,1,n){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs_1();cout<<dfs_2();
}
