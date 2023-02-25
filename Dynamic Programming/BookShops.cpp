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
const int MAXN = 1e5+1;

int main(){
    sws
    int n,x;
    cin>>n>>x;
    int c[n],p[n];
    rep(i,0,n)cin>>c[i];
    rep(i,0,n)cin>>p[i];
    int dp[n][MAXN];


    rep(amount,0,MAXN){
        if(amount>=c[0]){
            dp[0][amount]=p[0];
        }else{
            dp[0][amount]=0;
        }
    }

    rep(bk,1,n){
        rep(amount,0,MAXN){
            dp[bk][amount]=0;
            if(amount>0)dp[bk][amount]=max(dp[bk][amount-1],dp[bk-1][amount]);
            if(amount<c[bk])continue;
            dp[bk][amount] = max(dp[bk][amount],p[bk]+dp[bk-1][amount-c[bk]]);
        }
    }

    cout<<dp[n-1][x];

}   


