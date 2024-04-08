#include <bits/stdc++.h>
using namespace std;
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(msg,x) cout<<msg<<" "<<x<<endl;
#define output(x) for(auto c:x){cout<<c<<" ";}cout<<" ";
#define int long long 
#define ff first
#define ss second
#define endl "\n"
#define pq priority_queue
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;

int32_t main(){
    sws
    int n,k;
    cin>>n>>k;
    vi p(k);
    rep(i,0,k)cin>>p[i];
    sort(p.begin(),p.end());
    bool dp[n+1];
    memset(dp,true,sizeof(dp));
    dp[0]=false;

    rep(i,1,n+1){
        rep(j,0,k){
            if(i-p[j]>=0){
                dp[i]&=dp[i-p[j]];
            }
        }
        dp[i]^=1;
    }

    rep(i,1,n+1){
       dp[i]? cout<<"W":cout<<"L";
    }
}
 