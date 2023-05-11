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
#define pq priority_queue
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int MAXN = 1e6+1;
const int MOD = 1e9+7;
int dp[MAXN];

void process(){
    dp[0]=1;
    dp[1]=0;
    rep(i,2,MAXN){
        dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
        dp[i]%=MOD;
    }
}

int32_t main(){
    sws
    process();
    int n;
    cin>>n;
    cout<<dp[n];
}
