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
#define int long long
#define ss second
#define pq priority_queue
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int MOD=1e9+7;
const int MAXN = 1e6+1;
int dp[MAXN][7];
int getMod(int a){
    a%=MOD;
    if(a<0)a+=MOD;
    return a;
}
int32_t main(){ 
    sws;
    rep(i,0,6)dp[1][i]=1;
    dp[1][6]=6;

    rep(h,2,MAXN){
        dp[h][3]=dp[h][1]=dp[h][2]=dp[h][0]=getMod(dp[h-1][6]-dp[h-1][4]);
        dp[h][5]=dp[h][4]=getMod(dp[h-1][6]-dp[h-1][0]-dp[h-1][1]-dp[h-1][3]);
        rep(i,0,6){
            (dp[h][6]+=dp[h][i])%=MOD;
        }
    }

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        cout<<getMod(dp[n][2]+dp[n][5])<<endl;
    }
    
}
