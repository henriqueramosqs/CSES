#include <bits/stdc++.h>
using namespace std;
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(msg,x) cout<<msg<<": "<<x<<endl;
#define output(x) for(auto c:x){cout<<c<<" ";}cout<<" ";
#define int long long 
#define ff first
#define ss second
#define pq priority_queue
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int MAXN = 2*1e14;
int maxVal=0;

bool check(vi &v,int val,int k){
    if(val<maxVal)return false;

    int sum=0;
    int counter=1;

    for(auto c:v){
        if(sum+c<=val)sum+=c;
        else{
            sum=c;
            counter++;
        }
    }   

    return counter<=k;

}

int32_t main(){
    sws
    int n,k;
    cin>>n>>k;
    vi a(n);
    rep(i,0,n){
        cin>>a[i];
        maxVal=max(a[i],maxVal);
    }

    int pos = MAXN;

    for(int step=MAXN/2;step>=1;step/=2){
        while(pos-step>=0 && check(a,pos-step,k))pos-=step;
    }

    cout<<pos;
}
