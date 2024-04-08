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
    int ans=binexp(a,b/2);
    (ans*=ans)%=MOD;
    if(ans<0)(ans+=MOD)%=MOD;
    if(b%2==1)(ans*=a)%=MOD;
    if(ans<0)(ans+=MOD)%=MOD;
    return ans;
}


int inv(int a){
    return binexp(a,MOD-2);    
}



int calc_x1(int n){
    int ans;
    if(n%2==0){
        ans=n*n/4;
    }else{
        ans=((n-1)*(n+1)/4) + 1;
    }
    return ans;
}  


int calc_x2(int n){
    int ans=0;
    int k = n;
    while (true){
        int cur = 2*k-2;
        if(k>2){
            ans+=cur;
        }else{
            ans+=k;
        }
        if(cur<=0)break;
        // dbg("k",k)
        k-=2;
    }
    return ans;
}   

int32_t main(){
    sws
    int n;
    cin>>n;
    int ans=0;
    (ans+=binexp(2,n*n))%=MOD;
    
    if(ans<0)(ans+=MOD)%=MOD;

    (ans+=binexp(2,calc_x1(n)+1))%=MOD;

   
    if(ans<0)(ans+=MOD)%=MOD;

    (ans+=binexp(2,calc_x2(n)))%=MOD;

    if(ans<0)(ans+=MOD)%=MOD;

    (ans*=inv(4))%=MOD;

    cout<<ans;
    

}
