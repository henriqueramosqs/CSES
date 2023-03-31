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
const int MAXN = 501;
const int MAX_SUM=62626;
const int MOD = 1e9+7;
vector<vi> dp(MAX_SUM,vi(MAXN,0));


int getMod(int a,int md){
    int ans = a%md;
    if(ans<0)ans+=md;
    return ans;
}

int32_t main(){
    sws
    int n;cin>>n;
    int sum = n*(n+1)/2;

    if(sum%2==1){
        cout<<0;
        return 0;
    }

    int goal = sum/2;

    rep(val,0,goal+1){
        rep(num,0,n+1){
            
            // printf("(%d, %d)\n",val,num);
            if(val==0){
                dp[val][num]=1;
                // cout<<"Hr\n";
                continue;
            }

            if(num==0){
                dp[val][num]=0;
                continue;
            }


            dp[val][num]=dp[val][num-1];
            if(val-num<0)continue;
            (dp[val][num]+=dp[val-num][num-1])%=MOD; 
        }
    }

    cout<<dp[goal-n][n-1];
}