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
const int MAXN = 1e6+1;
const int MOD = 1e9+7;
int fact[MAXN];
int inv[MAXN];



int binexp(int a,int b){
    if(b==0)return 1;

    int ans =  binexp(a,b/2);
    ans%=MOD;
    ans = ans*ans;
    ans%=MOD;
    if(b%2==1)(ans*=a)%=MOD;
    return ans;
}

void process(){
    fact[0]=1;
    rep(i,1,MAXN){
        (fact[i]=i*fact[i-1])%=MOD;
    }

    rep(i,0,MAXN){
        (inv[i]=binexp(fact[i],MOD-2))%=MOD;
    }
}

int32_t main(){
    sws
    int n,m;cin>>n>>m;
    process();
    int denomin = 1;
    int add = n+m-1;

    while(add>(n-1)){
        (denomin*=add)%=MOD;
        add--;
    }

    cout<<(denomin*inv[m])%MOD;
    
}
