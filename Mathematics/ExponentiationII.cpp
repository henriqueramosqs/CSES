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
const int MOD = 1e9+7;


int binexp(int a,int b,int m){
    if(b==0)return 1;
    if(b==1)return a;

    int ans = binexp(a,b/2,m);
    (ans*=ans)%=m;
    if(b%2==1)(ans*=a)%=m;
    return ans;
}
int32_t main(){
    sws
    int q;cin>>q;

    while(q--){
        int a,b,c;
        cin>>a>>b>>c;
        cout<<binexp(a,binexp(b,c,MOD-1),MOD)<<endl;
    }

}

