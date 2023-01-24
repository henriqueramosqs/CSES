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
    int n,x;
    cin>>n>>x;
    int a[n];
    rep(i,0,n)cin>>a[i];
    int l =0,r=0;
    int s=a[0];
    int ans=0;
    while(r<n){
        if(s>=x){
            if(s==x)ans++;
            s-=a[l];
            l++;
        }else{
            r++;
            s+=a[r];
        }
    }

    cout<<ans;
}
