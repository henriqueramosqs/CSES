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

int getMod(int x,int n){
    int ans = x%n;

    if(ans<0)ans+=n;
    return ans;
}

int32_t main(){
    sws
    int n;
    cin>>n;
    int psum[n+1];
    psum[0]=0;
    int mods[n];
    rep(i,0,n)mods[i]=0LL;

    rep(i,1,n+1){
        int x;
        cin>>x;
        psum[i]=psum[i-1]+x;
        psum[i]=getMod(psum[i],n);
    }

    int ans = 0;

    rep(i,0,n+1){   
        ans+=mods[psum[i]];
        mods[psum[i]]++;
    }

    cout<<ans;
}
