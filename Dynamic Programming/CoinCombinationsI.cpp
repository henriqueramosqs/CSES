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
#define int long long
#define pq xpriority_queue
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int MOD = 1e9 +7;
 
int32_t main(){
    int n,x;
    cin>>n>>x;
    int coins[n];
    vi dp(x+1,0);
    dp[0]=1;
 
    rep(i,0,n){
        cin>>coins[i];
    }
 
    rep(i,0,x+1){
        rep(j,0,n){
            if(i-coins[j]>=0){
                (dp[i]+=dp[i-coins[j]])%=MOD;
            }
        }
    }
    cout<<dp[x];
}