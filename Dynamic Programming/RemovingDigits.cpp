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
const int MAXN = 1e6;

int main(){
    sws
    int n;cin>>n;

    int dp[MAXN+1];
    dp[0]=0;

    rep(i,1,10)dp[i]=1;

    rep(i,10,n+1){
        int num=i;
        int ans=INT32_MAX;
        while(num>0){
            if(num%10!=0){
                ans=min(ans,dp[i-(num%10)]+1);
            }
            num/=10;
        }
        dp[i]=ans;
    }

   cout<<dp[n];
}