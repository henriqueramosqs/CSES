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
typedef vector<vpp> vvp;
typedef pair<pii,int >pp;
const int LOGN = 18;
// const int LOGN = 3;
const int INF = (1LL<<30);
int n,q;
vpp v ;

int getMovieIdx(int time){
    auto it = lower_bound(v.begin(),v.end(),mp(time,-1ll));
    return it-v.begin();
}
int32_t main(){
    sws 
    cin>>n>>q;
    v.resize(n);

    rep(i,0,n)cin>>v[i].ff>>v[i].ss;
    sort(v.begin(),v.end());
    vvp dp(n,vpp(LOGN,mp(INF,INF)));

    for(int i = n-1;i>=0;i--){
        dp[i][0]=mp(v[i].ss,getMovieIdx(v[i].ss));
        if(i+1<n)dp[i][0]=min(dp[i+1][0],dp[i][0]);
        rep(j,1,LOGN){
            if(i+1<n)dp[i][j]=dp[i+1][j];
            if(dp[i][j-1].ss<n)dp[i][j]=min(dp[i][j],dp[dp[i][j-1].ss][j-1]);
        }
    }


    while(q--){
        int l,r;
        cin>>l>>r;
        auto cur = getMovieIdx(l);
        int ans=0;

        for(int i = LOGN-1;i>=0;i--){
            if(cur>=n)break;
            if(dp[cur][i].ff<=r){
                ans+=(1ll<<i);
                cur = dp[cur][i].ss;
            }
        }

        cout<<ans<<"\n";
    }
}
