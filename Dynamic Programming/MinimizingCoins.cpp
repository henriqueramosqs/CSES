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
const int MAXN = 1e6 +1;
const int INF = 0x3f3f3f3f;
int ans[MAXN];
 
int main(){
    sws
    int n,x;
    cin>>n>>x;  
    vi v;
 
    rep(i,0,n){
        int a;cin>>a;
        v.pb(a);
        ans[a]=1;
    }
 
    rep(i,1,x+1){
        if(ans[i]!=0)continue;
 
        int poss = INF;
 
        for(auto c:v){
            if( i-c >0 && ans[i-c]!=0){
                poss = min(poss,ans[i-c]+1);
            }
        }
        if(poss!=INF){
            ans[i]=poss;
        }
    }
    
    ans[x]==0? cout<<-1 : cout<<ans[x];
}