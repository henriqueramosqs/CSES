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
typedef pair<pii,int >pp;
const int MAXN = 1e5+1;
vi rev[MAXN];
int outdeg[MAXN];

int32_t main(){
    sws 
    pq<int>p;
    int n,m;cin>>n>>m;
    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        rev[b].pb(a);
        outdeg[a]++;
    }
    rep(i,1,n+1)if(outdeg[i]==0)p.push(i);
    vi ans;
    while(!p.empty()){
        int v = p.top();p.pop();
        ans.pb(v);
        for(auto c:rev[v]){
            if((--outdeg[c])==0)p.push(c);
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto c:ans)cout<<c<<" ";
}
