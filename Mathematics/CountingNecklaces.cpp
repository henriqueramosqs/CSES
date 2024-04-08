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
#define endl "\n"
#define pq priority_queue
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int MOD = 1e9+7;

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}


int binexp(int a,int b){
    if(b==0)return 1;
    int ans=binexp(a,b/2);
    (ans*=ans)%=MOD;
    if(b%2==1)(ans*=a)%=MOD;
    return ans;
}


int inv(int a){
    return binexp(a,MOD-2);    
}

int32_t main(){
    sws
    int n,m;
    cin>>n>>m;
    
    int ans=0;
    rep(i,0,n){
        (ans+=binexp(m,gcd(n,i)))%=MOD;
    }
    (ans*=inv(n))%=MOD;

    cout<<ans;
}
