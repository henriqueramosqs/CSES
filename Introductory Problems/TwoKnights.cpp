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


int calc(int x){
    int ans = x*x;
    ans = (ans*(ans-1))/2;

    ans-=(4*(x-4)*(x-4) +20*x -56);
    return ans;
}
int32_t main(){
    sws
    int n;
    cin>>n;

    rep(i,1,n+1){
        int ans;
        switch (i){
            case 1:
                ans=0;
                break;
            case 2:
                ans=6;
                break;
            case 3:
                ans=28;
                break;
            case 4:
                ans=96;
                break;            
            default:
                ans = calc(i);
                break;
        }
        cout<<ans<<endl;
    }
}
