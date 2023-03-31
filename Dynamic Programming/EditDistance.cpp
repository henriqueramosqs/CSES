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
    string a,b;
    cin>>a>>b;
    int n = a.size();
    int m = b.size();

    int dp[n+1][m+1];     
    rep(i,1,n+1){
        rep(j,1,m+1){
            dp[i][j]=1e9;
        }
    }
    rep(i,0,m+1)dp[0][i]=i;
    rep(i,0,n+1)dp[i][0]=i;

    rep(i,1,n+1){
        rep(j,1,m+1){
            dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
            dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
            dp[i][j]=min(dp[i][j],dp[i-1][j-1]+(a[i-1]!=b[j-1]));
        }
    }

    cout<<dp[n][m];
}

