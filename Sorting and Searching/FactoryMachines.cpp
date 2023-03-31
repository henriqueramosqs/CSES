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
 
bool check( vi &v,int x,int goal){
    int ans = 0;
    for(auto c:v){
        ans+=(x/c);
        if(ans>=goal)return true;
    }

    return ans>=goal;
}

int32_t main(){
    sws
    int n,t;
    cin>>n>>t;
    vi v(n);
    int tmax=1e18;

    rep(i,0,n){
        cin>>v[i];
    }


    int pos = tmax;
    for(int step = tmax/2;step>=1;step/=2){
        while(pos-step>=0 && check(v,pos-step,t))pos-=step;
    }

    cout<<pos;

}