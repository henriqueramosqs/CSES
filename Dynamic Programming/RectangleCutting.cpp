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
const int INF = 1e9;
int dp[501][501];

int main(){
    sws 
    int n,m;
    cin>>n>>m;

    rep(i,1,501){
        rep(j,1,501){

            if(i==1){
                dp[i][j]=j-1;
                continue;
            }
            if(j==1){
                dp[i][j]=i-1;
                continue;
            }
            if(i==j){
                dp[i][j]=0;
                continue;
            }

            int ans =INF;
            for(int l=1;l<=(i/2);l++){
                ans= min(ans,dp[l][j]+dp[i-l][j]);
            }

            for(int l=1;l<=(j/2);l++){
                ans= min(ans,dp[i][l]+dp[i][j-l]);
            }
            dp[i][j]= ans +1;

        }
    }

    cout<<dp[n][m];
}
