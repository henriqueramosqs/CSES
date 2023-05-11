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
const int INV = 500000004;

int32_t main(){
    sws
    int n;cin>>n;   
    int ans=0LL;
 
    int i =n;
 
    while(i>=1LL){
        int mul = n/i;
        int nxt = i;
        for(int step = (i)/2LL;step>=1LL;step/=2LL){
            while(nxt-step>=1 && (n/(nxt-step))==mul)nxt-=step;
        }
        nxt--;
        int qtd = (i-nxt)%MOD;
        int pat = (nxt+1LL+i)%MOD;
        (pat*=INV)%=MOD;
        (pat*=qtd)%=MOD;
        (pat*=mul)%=MOD;
        (ans+= pat)%=MOD;   
        i=nxt; 
    }
 
    cout<<ans;
}