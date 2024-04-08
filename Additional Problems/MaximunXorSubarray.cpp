#include <bits/stdc++.h>
using namespace std;
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(msg,x) cout<<msg<<" "<<x<<endl;
#define output(x) for(auto c:x){cout<<c<<" ";}cout<<" ";
#define ll long long 
#define ff first
#define ss second
#define pq priority_queue
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int MAXN = 2*1e5+1;
int t[MAXN<<5][2];
int idx=1;

void add(int a){
    int pos=30;
    int aux = 1<<pos;
    int cur=0;

    while(pos>=0){
        int bit = ((aux&a)!=0);

        if(t[cur][bit]){
            cur = t[cur][bit];
        }else{
            cur = t[cur][bit]=idx++;
        }
        pos--;  
        aux>>=1;
    }
}

int get(int a){
    int pos=30;
    int aux = 1<<30;
    int cur=0;

    int ans=0;
    while(pos>=0){
        int bit = ((aux&a)!=0);

        if(t[cur][!bit]){
            cur = t[cur][!bit];
            if(!bit)ans+=(1<<pos);
        }else{
            cur = t[cur][bit];
            if(bit)ans+=(1<<pos);
        }
        pos--;  
        aux>>=1;
    }
    return ans;
}

int main(){
    sws
    int n;cin>>n;
    int a[n];
    int psum[n+1];psum[0]=0;

    rep(i,0,n){
       cin>>a[i];
       psum[i+1]=a[i]^psum[i];
    }

    int ans=0;
    add(0);
    rep(i,1,n+1){
        int aux = psum[i]^get(psum[i]);
        ans= max(aux,ans);
        add(psum[i]);
    }
    cout<<ans;
}
