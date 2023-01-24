#include <bits/stdc++.h>
using namespace std;
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(msg,x) cout<<msg<<" "<<x<<endl;
#define output(x) for(auto c:x){cout<<c<<" ";}cout<<" ";
#define int unsigned long long 
#define ff first
#define ss second
#define pq priority_queue
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int MOD = 1e9 + 7;

int exp(int a,int b){
    if(b==1){return a;}
    if(b==0){return 1;}
    if(a==0)return 0;
    int aux = exp(a,b/2)%MOD;
    int ans = (aux*aux)%MOD;
    if(b%2==1){
        (ans*=a)%=MOD;
    }
    return ans;
}

int32_t main(){
    sws
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        cout<<exp(a,b)<<endl;
    }
}
