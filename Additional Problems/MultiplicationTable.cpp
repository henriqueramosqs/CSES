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
int n;

int count(int x){
    int ans=0;
    rep(i,1,n+1)ans+=min(n,(x/i));
    return ans;
}

int32_t main(){
    sws 
    cin>>n;
    int k = (n*n)/2 +1;
    int ans =0;
    for(int step = (n*n)/2;step>=1;step/=2){
        while(ans+step<=n*n && count(ans+step)<k)ans+=step;
    }
    ans++;
    while(count(ans)==0)ans++;
    cout<<ans;
}
