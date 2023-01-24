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
#define int long long
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;

int32_t main(){
    sws
    int n,q;
    cin>>n>>q;
    int psum[n+1];
    psum[0]=1;

    rep(i,1,n+1){
        int a;cin>>a;
        psum[i]=psum[i-1]+a;
    }

    rep(i,0,q){
        int a,b;
        cin>>a>>b;
        cout<<psum[b]-psum[a-1]<<"\n";
    }
}