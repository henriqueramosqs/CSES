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
typedef vector<long double> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;

int32_t main(){
    sws
    int n,a,b;
    cin>>n>>a>>b;

    vvi dp(101,vi(601,0));

    rep(amount,1,601){
        dp[1][amount]+=dp[1][amount-1];
        if(amount<=6)dp[1][amount]+=(1.0/6.0);
    }

    rep(day,2,101){
        rep(amount,1,601){
            dp[day][amount]+=dp[day][amount-1];

            dp[day][amount]+=(1.0/6.0)*(dp[day-1][amount-1]);
            if(amount>=7)dp[day][amount]-=(1.0/6.0)*dp[day-1][amount-7];
        
            dp[day][amount]=min((long double)1.0,dp[day][amount]);
        }
    }


    long double ans = dp[n][b]-dp[n][a-1];

    printf("%.6Lf",ans);

}
