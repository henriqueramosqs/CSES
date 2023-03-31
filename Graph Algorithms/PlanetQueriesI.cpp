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

int main(){
    sws
    int n,q;
    cin>>n>>q;
    int lim = 31;
    int dp[n+1][lim];
    rep(i,1,n+1)cin>>dp[i][0];
    
    rep(up,1,lim){
        rep(v,1,n+1){
            dp[v][up]=dp[dp[v][up-1]][up-1];
        }
    }

    while(q--){
        int v, k;
        cin>>v>>k;
        int ans = v;
        int pos = 0;
        int ck = 1;

        while(pos<lim && ck<=k){
            if(ck&k){
                ans=dp[ans][pos];
            }
            pos+=1;
            ck<<=1;
        }
        cout<<ans<<"\n";
    }
}
