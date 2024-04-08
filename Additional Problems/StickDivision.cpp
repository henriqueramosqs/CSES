#include <bits/stdc++.h>
using namespace std;
// #pragma GCC target("popcnt")
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

int32_t main(){
    sws 
    int x,n;cin>>x>>n;
    pq<int,vi,greater<int> >p;
    rep(i,0,n){
        int x;cin>>x;
        p.push(x);
    }
    int ans=0;
    while(p.size()>1){
        int x = p.top();p.pop();
        int y = p.top();p.pop();
        ans+=(x+y);
        p.push(x+y);
    }
    cout<<ans;
}
