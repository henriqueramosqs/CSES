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
const int MAXN = 1e5+1;
int main(){
    sws
    int n;
    cin>>n;
    int c[n];
    rep(i,0,n)cin>>c[i];
    set<int>s;

    bool dp[n][MAXN];

    memset(dp,false,sizeof(dp));

    rep(coin,0,n){
        rep(amount,0,MAXN){
            if(amount==c[coin]){
                s.insert(amount);
                dp[coin][amount]=1;
                continue;
            }

            if(coin==0)continue;
            
            if(dp[coin-1][amount]){
                dp[coin][amount]=1;
                continue;
            }

            if(amount>=c[coin] && dp[coin-1][amount - c[coin]]){
                dp[coin][amount]=1;
                s.insert(amount);
            }
        }
    }
    

    cout<<s.size()<<"\n";
    for(auto c
    :s){
        cout<<c<<" ";
    }

}
