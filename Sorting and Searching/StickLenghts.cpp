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

int32_t main(){
    sws

    int n;cin>>n;
    int m1,m2,s=0;
    vi a(n);

    rep(i,0,n)cin>>a[i];

    sort(a.begin(),a.end());

    m1 = a[n/2];

    int ans1=0,ans2=0;

    rep(i,0,n){
        ans1+=abs(a[i]-m1);
    }

    if(n%2==1){
        cout<<ans1;
        return 0;
    }

    m2 = a[n/2-1];

    rep(i,0,n){
        ans2+=abs(a[i]-m2);
    }

    cout<<min(ans1,ans2);

}