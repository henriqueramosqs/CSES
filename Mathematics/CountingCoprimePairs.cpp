#include <bits/stdc++.h>
using namespace std;
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(x) cout<<#x<<" "<<x<<endl;
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
const int MAXN = 1e6+1;
int a[MAXN];
int dp[MAXN];
vi primes;

void sieve(){
    for(int i =2;i*i<=MAXN;i++){
        if(a[i])continue;
        primes.pb(i);
        for(int q=2;q*q*i*i<=MAXN;q++){
            a[q*i]=true;
        }
    }   

}

int32_t main(){
    sws
    sieve();

    int n;cin>>n;   
    vi v(n);
    rep(i,0,n)cin>>v[i];

    int pz = primes.size();

    int discount=0;

    rep(i,0,n){
        vi pf;

        for(auto c:primes){
            if(v[i]==1)break;
            if(v[i]%c!=0)continue;
            pf.pb(c);
            while(v[i]%c==0)v[i]/=c;
        }

        if(v[i]!=1)pf.pb(v[i]);

        int cur=0;
 

        rep(msk,1,(1<<pf.size())){
            int mul=1;
            rep(i,0,pf.size()){
                if((1<<i)&msk ){
                    mul*=pf[i];
                }
            }
            if(__builtin_popcount(msk)%2==1){
                discount+=dp[mul];
            }else{  
                discount-=dp[mul];
            }
            dp[mul]++;
        }
    }

    cout<<(n*(n-1)/2) -discount;
}
