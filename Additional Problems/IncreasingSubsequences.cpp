#include <bits/stdc++.h>
using namespace std;
// #pragma GCC target("popcnt")
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(x) cout<<#x<<" "<<x<<endl;
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
const int MAXN= 2*1e5+1;
const int MOD = 1e9+7;
int n;
int t[MAXN<<2];

void update(int v,int tl,int tr,int pos,int val){
    if(tl==tr){
        (t[v]+=val)%=MOD;
        while(t[v]<0)t[v]+=MOD;
        return;
    }
    int tm = (tl+tr)/2;

    if(pos<=tm){
        update(v<<1,tl,tm,pos,val);
    }else{
        update(v<<1|1,tm+1,tr,pos,val);
    }

    (t[v]=t[v<<1]+t[v<<1|1])%=MOD;
    while(t[v]<0)t[v]+=MOD;
}

void update(int pos,int val){
    update(1,0,n-1,pos,val);
}

int get(int v,int tl,int tr,int l,int r){
    if(tl>r || tr<l)return 0ll;
    if(tl==l && tr==r){
        return t[v];
    }
    int tm = (tl+tr)/2;

    int ans = get(v<<1,tl,tm,l,min(tm,r))+get(v<<1|1,tm+1,tr,max(l,tm+1),r);
    ans%=MOD;
    while(ans<0)ans+=MOD;
    return ans;
}

int get(int l,int r){
    return get(1,0,n-1,l,r);
}

int32_t main(){
    sws
    cin>>n;
    vi v(n);    
    map<int,int>m;
    rep(i,0,n)cin>>v[i];

    vi aux = v;
    sort(aux.begin(),aux.end());
    int idx=0;
    rep(i,0,n){
        if(i==0 || aux[i]!=aux[i-1])idx++;
        m[aux[i]]=idx;
    }
    for(auto &c:v)c=m[c];
    update(0,1);

    int ans=0;
    rep(i,0,n){
        int aux = get(0,v[i]-1);
        (ans+=aux)%=MOD;
        update(v[i],aux);
        while(ans<0)ans+=MOD;
    }

    cout<<ans;

}
