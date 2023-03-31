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
const int MAXN = 1e5;
const int MOD = 1e9+7;
int n,m;
int a[MAXN];
int dp[MAXN][102];

int solve(int pos,int val){

    if(val<=0 || val>m)return 0;
    if(a[pos]!=0 &&  val!=a[pos])return dp[pos][val]=0;
    if(pos==n-1)return dp[pos][val]= 1;
    if(dp[pos][val]!=-1)return dp[pos][val];

    
    int ans =0;
    (ans+=solve(pos+1,val+1))%=MOD;
    (ans+=solve(pos+1,val-1))%=MOD;
    (ans+=solve(pos+1,val))%=MOD;


    return dp[pos][val]=ans;

}
int main(){
    sws 
    cin>>n>>m;
    rep(i,0,n)cin>>a[i];

    memset(dp,-1,sizeof(dp));

   int fin_ans=0;

   rep(i,1,m+1){
        (fin_ans +=solve(0,i))%=MOD;
   }

   cout<<fin_ans;

}
