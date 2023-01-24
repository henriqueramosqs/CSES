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
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int MAXN =2*1e5+1;

vi adj[MAXN];
int ans[MAXN];

int  solve(int v){
    int counter=adj[v].size();
    for(auto c:adj[v]){
        counter+=solve(c);
    }
    ans[v]=counter;
    return ans[v];
}   


int main(){
    sws
    int n;
    cin>>n;

    rep(i,2,n+1){
        int a;
        cin>>a;
        adj[a].pb(i);
    }

    solve(1);

    rep(i,1,n+1){
        cout<<ans[i]<<" ";
    }
}
