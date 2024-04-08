#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")
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
const int MAXN = 1223;

int32_t main(){
    sws
    int t;cin>>t;


    vi dp(MAXN,0);
    dp[0]=0;
    rep(i,2,MAXN){
        set<int> aux;
        rep(a,1,i){
            int b = i-a;
            if(b==a)continue;
            aux.insert(dp[a]^dp[b]);
        }
        int expc=0;
        bool any = false;
        for(auto c:aux){
            if(c==expc){
                expc++;
            }else{
                dp[i]=expc;
                any=true;
                break;
            }   
        }
        if(!any)dp[i]=expc;

    }

    while(t--){
        int x;cin>>x;
        if(x>=MAXN){
            cout<<"first\n";
        }else{
            (dp[x]!=0)?cout<<"first\n":cout<<"second\n";
        }
    }
}
