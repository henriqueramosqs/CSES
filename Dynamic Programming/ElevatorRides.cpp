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

int32_t main(){
    sws
    int n,x;
    cin>>n>>x;
    int a[n];
    rep(i,0,n)cin>>a[i];

    int lim = (1<<n);
    pii dp[lim];
    dp[0]=mp(1,0);

    rep(bm,1,lim){
        pii best = mp(__INT64_MAX__,__INT64_MAX__);

        rep(pp,0,n){
            if(!((1<<pp)&bm))continue;
            int lk = (1<<pp)^bm;
            pii pos;
            if(dp[lk].ss + a[pp]>x){
                pos = mp(dp[lk].ff+1,a[pp]);
            }else{
                pos = mp(dp[lk].ff,dp[lk].ss+a[pp]);
            }

            best = min(pos,best);
        }
        dp[bm]=best;
    }
    
    cout<<dp[lim-1].ff;

}
