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
const int INF = (1ll<<50);
vi v,psum;

int get(int l,int r){
    int ans = psum[r];
    if(l>0)ans-=psum[l-1];
    return ans;
}

int32_t main(){
    sws 
    int n,x;cin>>n;
    rep(i,0,n){
        cin>>x;
        psum.pb(x+(psum.empty()?0:psum.back()));
    }
    vvi dp(n,vi(n,INF));
    vvi opt(n,vi(n,INF));

    for(int l=n-1;l>=0;l--){
        dp[l][l]=0;opt[l][l]=l;
        rep(r,l+1,n){
            for(int m=opt[l][r-1];m<=min(r-1,opt[l+1][r]);m++){
                int qtd = dp[l][m]+dp[m+1][r]+get(l,r);
                if(qtd<dp[l][r]){
                    dp[l][r]=qtd;opt[l][r]=m;
                }
            }
        }
    }

    cout<<dp[0][n-1];
}
