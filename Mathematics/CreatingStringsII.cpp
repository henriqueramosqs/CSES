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
const int MOD=1e9+7;
int fact[MAXN];
int counter[26];

void process(){
    fact[0]=1;
    rep(i,1,MAXN){
        (fact[i]=i*fact[i-1])%=MOD;
    }
}

int binexp(int a,int b= MOD-2){
    if(b==0)return 1;
    if(b==1) return a;

    int aux = binexp(a,b/2)%MOD;
    (aux*=aux)%=MOD;    
    if(b%2==1)(aux*=a)%=MOD;    
    return aux;
}


int32_t main(){
    sws
    string s;
    cin>>s;
    int n = s.size();
    process();

    int ans = fact[n];


    rep(i,0,n)counter[s[i]-'a']++;
    rep(i,0,26)(ans*=binexp(fact[counter[i]]))%=MOD;

    cout<<ans;
}
