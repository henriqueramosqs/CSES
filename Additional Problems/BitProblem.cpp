#include <bits/stdc++.h>
using namespace std;
// #pragma GCC target("popcnt")
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(x) cout<<#x<<" "<<x<<endl;
#define output(x) for(auto c:x){cout<<c<<" ";}cout<<" ";
#define ff first
#define int long long
#define ld long double
#define ss second
#define endl "\n"
#define pq priority_queue
#define all(x) x.begin(),x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
typedef pair<pii,int >pp;
const int LOGN = 20;
const int OPMSK = (1LL<<LOGN)-1;

inline bool isOn(int bit,int num){
    return ((1ll<<bit)&num)!=0;
}


int getOp(int x){
    return  x^OPMSK;
}
int32_t main(){
    sws 
    int n;cin>>n;
    vi v(n);
    rep(i,0,n)cin>>v[i];
    vi dp((1ll<<LOGN),0);
    vi dp2((1ll<<LOGN),0);
    rep(i,0,n)dp[v[i]]++;
    rep(i,0,n)dp2[v[i]]++;

    for(int i = 0;i < LOGN; ++i) {
        for(int mask = 0; mask < (1<<LOGN); ++mask){
            if(isOn(i,mask)){
                dp[mask] += dp[mask^(1<<i)];
            }else{
                dp2[mask]+=dp2[mask^(1<<i)];
            }
        }
    }


    rep(i,0,n){
        cout<<dp[v[i]]<<" "<<dp2[v[i]]<<" "<<(n-dp[getOp(v[i])])<<"\n";
        
    }
}
