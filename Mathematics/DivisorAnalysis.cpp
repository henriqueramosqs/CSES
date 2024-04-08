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

int binexp(int a,int b){
    if(b==0)return 1;
    if(b==1)return a;
    int ans = binexp(a,b/2);
    (ans*=ans)%=MOD;   
    if(b%2==1)(ans*=a)%=MOD;
    return ans;
}


int inv(int a){
    return binexp(a,MOD-2);
}


int32_t main(){
    sws
    int n;
    cin>>n;
    vpp v;

    int qtdDiv=1;
    int num=1;

    bool special=true;

    int aux=1;
    int divPos=-1;

    rep(i,0,n){
        int a,b;
        cin>>a>>b;
        if(b%2==1){
            special = false;
            divPos=i;
        }
        
        v.pb(mp(a,b));
        (qtdDiv*=(b+1))%=MOD; 
        (num*=binexp(a,b))%=MOD;
    }
    int sdiv=1;

    rep(i,0,n){
        (sdiv*=(binexp(v[i].ff,v[i].ss+1)-1))%=MOD;
        (sdiv*=( inv(v[i].ff-1) ))%=MOD; 
    }


   int pdiv=1;

    rep(i,0,n){
        if(i==divPos){
            (aux*=(v[i].ss+1)/2)%=(MOD-1);
        }else{
            (aux*=(v[i].ss+1))%=(MOD-1);
        }
    }


   if(!special){
        pdiv = binexp(num,aux);
   }else{
    
        rep(i,0,n){
            int ax= v[i].ss/2;
            (ax*=aux)%=(MOD-1);
            (pdiv*=binexp(v[i].ff,ax))%=MOD;
        }

   }

   cout<<qtdDiv<<" "<<sdiv<<" "<<pdiv;
}
