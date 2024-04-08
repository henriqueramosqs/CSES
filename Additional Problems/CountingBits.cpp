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
const int MAXN = 1e15;
vi pots;

void process(){
    pots.pb(1);
    int idx = 0;
    while(pots[idx]<=MAXN){
        pots.pb(pots[idx]<<1);
        idx++;
    }
}
int32_t main(){
    sws
    process();
    int n;cin>>n;
    n++;
    int ans=0;

    int i=1;

    int sz = pots.size();
    int lim = sz-1;
    for(int step=sz/2;step>=1;step/=2){
        while(lim-step>=0 && pots[lim-step]>=n)lim-=step;
    }   


    rep(i,1,lim+1){
        ans += pots[i-1]*(n/pots[i]) +max(0LL,(n%pots[i])-pots[i-1]);
    }

    cout<<ans;
}
