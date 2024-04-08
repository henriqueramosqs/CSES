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
int stToInt(string a,int k){
    int ans=0;
    rep(i,1,k+1){
        int pos = k-i;
        ans+=((a[pos]=='1')<<(i-1));
    }
    return ans;
}
int main(){
    sws
    int n,k;
    cin>>n>>k;
    vi v;
    rep(i,0,n){
        string a;
        cin>>a;
        v.pb(stToInt(a,k));
    }

    int ans = k;
    rep(i,0,n){
        rep(j,i+1,n){
         ans=min(ans,__builtin_popcount(v[i]^v[j]));
        }   
    }
    cout<<ans;
}
