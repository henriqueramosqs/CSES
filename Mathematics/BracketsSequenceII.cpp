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
const int MOD=1e9+7;
const int MAXN = 2* 1e6+1;
int fact[MAXN];

void process(){
    fact[0]=fact[1]=1;
    rep(i,2,MAXN)(fact[i]=fact[i-1]*i)%=MOD;
}

int binexp(int a,int b = MOD-2){
    if(b==0)return 1;
    if(b==1)return a;
    int ans = binexp(a,b/2);
    ans%=MOD;
    (ans*=ans)%=MOD;
    if(b%2==1)(ans*=a)%=MOD;
    return ans;
}


int comb(int a,int b){
    int ans = fact[a];
    (ans*=binexp(fact[b]))%=MOD;
    (ans*=binexp(fact[a-b]))%=MOD;
    return ans;
}

int32_t main(){
    sws
    int n;
    string s;
    cin>>n;
    cin>>s;

    if(n%2==1){
        cout<<0;
        return 0;
    }
    int counter_1=0,counter_2=0;

    for(auto c:s){
        if(c=='('){
            counter_1++;
        }else{
            counter_2++;
        }    
        if(counter_2>counter_1){
            cout<<0;
            return 0;
        }
    }



    if(s.size()==n){
        cout<<1;
        return 0 ;
    }

    process();
    n/=2;

    if(counter_1>n || counter_2>n){
        cout<<0;
        return 0;
    }

    int ans = fact[(n<<1) - counter_1 -counter_2 ];
    (ans*=binexp(fact[n-counter_1]))%=MOD;
    (ans*=binexp(fact[n-counter_2]))%=MOD;
    int dec = fact[(n<<1) - counter_1 -counter_2 ];
    (dec*=binexp(fact[n+1-counter_2]))%=MOD;
    (dec*=binexp(fact[n-1-counter_1]))%=MOD;
    ans-=dec;
    if(ans<0){
        ans+=MOD;
        ans%=MOD;
    }

    cout<<ans;   
}
