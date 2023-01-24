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
#define int long long
#define ss second
#define pq priority_queue
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;

int32_t main(){
    sws
    int n;cin>>n;
    int a[n];
    int ans=0;
    rep(i,0,n)cin>>a[i];

    rep(i,1,n){
        if(a[i]<a[i-1]){
            ans+= a[i-1]-a[i];
            a[i]=a[i-1];
        }
    }
    cout<<ans;
}
