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
#define pq xpriority_queue
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int MOD = 1e9 +7;
const int MAXN =1e6 +1;
 
int main(){
    sws
    int n,x;
    cin>>n>>x;
    vi coins;

    rep(i,0,n){
        int k;cin>>k;
        coins.pb(k);
    }
    
    sort(coins.begin(),coins.end());

    int dp[MAXN];
    rep(i,0,MAXN)dp[i]=0;
    dp[0]=1;

    for(int c:coins){
       for(int sum=0;sum<=x;sum++){
        
            if(sum+c>x)break;

            (dp[sum+c]+=dp[sum]);
            dp[sum+c]%=MOD;
        }
    }

    cout<<dp[x];
 
}
