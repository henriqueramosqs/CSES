#include <bits/stdc++.h>
using namespace std;
// #pragma GCC target("popcnt")
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(x) cout<<#x<<" "<<x<<endl;
#define output(x) for(auto c:x){cout<<c<<" ";}cout<<" ";
#define ff first
#define int long long
#define ld long double
#define ss second
#define endl "\n"
#define pq priority_queue
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
typedef pair<pii,int >pp;


int solve(int n,int k){
    if(n==1)return 1;
    if(k<=((n+1)/2)){
        int ans= (k<<1)%n;
        if(ans==0)ans=n;
        return ans;
    }
    int nsz = n-(n>>1);
    if(n%2)return 2*solve(n>>1,k-((n+1)>>1))+1;
    return 2*solve(n>>1,k-((n+1)>>1))-1;
}

int32_t main(){
    sws 
    int t;cin>>t;
    while (t--){
        int n,k;
        cin>>n>>k;
        cout<<solve(n,k)<<"\n";
    }
    
}

