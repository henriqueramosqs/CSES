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
const int MAXN = 2<<15;
vi adj[MAXN];


void dfs(int v=0){

    while(!adj[v].empty()){
        int c = adj[v].back();
        cout<<(c&1);
        adj[v].pop_back();
        dfs(c);
    }
}
int main(){
    sws 
    int n;cin>>n;

    if(n==1){cout<<10;return 0;}
    int mask = (1<<(n-1))-1;
    
    rep(i,0,(1<<(n-1))){
        int aux = i<<1;
        adj[i].pb(aux&mask);
        adj[i].pb(1 + aux&mask);
    }

    rep(i,0,n-1)cout<<0;
    dfs();

}
