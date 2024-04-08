#include <bits/stdc++.h>
using namespace std;
// #pragma GCC target("popcnt")
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(msg,x) cout<<msg<<" "<<x<<endl;
#define output(x) for(auto c:x){cout<<c<<" ";}cout<<" ";
#define int long long 
#define ff first
#define ld long double
#define ss second
#define endl "\n"
#define pq priority_queue
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int MOD1= 1e9+7;
const int MOD2= 999999937;
const int M1 = 29;
const int M2 = 31;

inline int getNum(char a){
    return a-'a'+1;
}

int binexp(int a,int b,int mod){
    if(b==0)return 1;
    if(b==1)return a%mod;
    int ans = binexp(a,b/2,mod);
    (ans*=ans)%=mod;
    // if(ans<0)ans+=mod;
    if(b%2)(ans*=a)%=mod;
    // if(ans<0)ans+=mod;
    return ans;
}

int inv(int x,int mod){
    return binexp(x,mod-2,mod);
}
inline int  pg(int a0,int q,int n,int mod){
    int ans = binexp(q,n,mod);
    ans--;
    (ans*=a0)%=mod;
    // if(ans<0)ans+=mod;
    (ans*=inv(q-1,mod))%=mod;
    // if(ans<0)ans+=mod;
    return ans;
}
struct HASH{
    vi psum1;
    // vi psum2;
    vi pot;
    int n;
    HASH(string s):psum1(s.size()),pot(s.size()+1){
        this->n = s.size();
        rep(i,0,n){
            psum1[i]=getNum(s[i]);
            pot[0]=1;
            // psum2[i]=getNum(s[i]);
            if(i>0){
                (psum1[i]+=((M1*psum1[i-1])%MOD1))%=MOD1;
                (pot[i]=M1*pot[i-1])%=MOD1;
                // (psum2[i]+=((M2*psum2[i-1])%MOD2))%=MOD2;
            }
            if(psum1[i]<0)psum1[i]+=MOD1;
            if(pot[i]<0)pot[i]+=MOD1;
            // if(psum2[i]<0)psum2[i]+=MOD2;
        }
        (pot[n]=M1*pot[n-1])%=MOD1;
        if(pot[n]<0)pot[n]+=MOD1;

    }

    bool check(int x){
        int k = n/(x+1);
        int ans =0;
        // pii ans = mp(0ll,0ll);
        if(n%(x+1)){
            // ans = mp(psum1[n%(x+1) -1 ],psum2[n%(x+1) -1]);
            ans = psum1[n%(x+1) -1 ];
        }
        (ans+=(psum1[x]*pg(pot[n%(x+1)],pot[x+1],k,MOD1))%MOD1)%=MOD1;
        // (ans.ss+=(psum2[x]*pg(binexp(M2,n%(x+1),MOD2),binexp(M2,x+1,MOD2),k,MOD2))%MOD2)%=MOD2;
        if(ans<0)ans+=MOD1;
        // if(ans.ss<0)ans.ss+=MOD2;
       return ans==psum1.back();
    }
};  
int32_t main(){
    sws
    string s;cin>>s;
    HASH hash(s);
    int n = s.size();

    rep(i,0,n){
        if(hash.check(i))cout<<i+1<<" ";
    }
}   