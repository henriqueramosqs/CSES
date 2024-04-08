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
    int n,x;cin>>n>>x;
    int a[n];
    rep(i,0,n)cin>>a[i];
    vi v1,v2;
    int num_1 = n/2;
    int num_2 = n-num_1;
 
    rep(i,0,(1<<num_1)){
        int pos=0,eval=1;
        int sum=0;
 
        while (eval<=i){
           if(eval&i)sum+=a[pos];
           eval<<=1;
           pos++;
        }
        v1.pb(sum);
        
    }
 
    rep(i,0,(1<<num_2)){
 
        int pos=0,eval=1;
        int sum=0;
 
        while (eval<=i){
           if(eval&i)sum+=a[num_1+pos];
           eval<<=1;
           pos++;
        }
        v2.pb(sum);
    }
    
    int ans=0;

    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
 
    for(auto c:v1){
        // int c=0;
        auto lit = lower_bound(v2.begin(),v2.end(),x-c);
        auto rit = upper_bound(v2.begin(),v2.end(),x-c);
        int r = rit-v2.begin();
        int l =lit-v2.begin();
        ans+=(r-l);
    }
 
    cout<<ans;
 
}