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
typedef pair<pii,int >pp;
const int MOD = 1E9+7;
const int MAXIM = 249501;
vvi dp(2,vi(MAXIM,0));
vvi psum(2,vi(MAXIM,0));

int maxim(int sz){
    return sz*(sz-1)/2;
}

int get(int idx,int l,int r){
    l = max(0ll,l);
    r = min(r, MAXIM - 1);
    int ans = psum[idx][r];
    if(l>0)(ans-=psum[idx][l-1])%=MOD;
    if(ans<0)ans+=MOD;
    return ans;
}

int32_t main(){
	sws
    int n,k;
    cin>>n>>k;

    dp[1][0]=1;psum[1][0]=1;
    rep(i,1,MAXIM)psum[1][i]=dp[1][i]+psum[1][i-1];

    rep(i,2,n+1){
        int md = (i%2);
        int ot = (i+1)%2;
        rep(j,0,MAXIM){
           dp[md][j]=get(ot,j-(i-1),j); 
           psum[md][j]=dp[md][j];
           if(j>0)(psum[md][j]+=psum[md][j-1])%=MOD;
           if(psum[md][j]<0)psum[md][j]+=MOD;
        }
    }

    cout<<dp[n%2][k];
}
