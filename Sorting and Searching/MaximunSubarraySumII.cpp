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
const int MAXN = 2*1e5+2;
const int LINF = -2*1e15;
int t[MAXN<<2];

void build(int a[],int v,int tl,int tr){
    if(tl==tr){
        t[v]=a[tl];
        return;
    }

    int tm = (tl+tr)/2;

    build(a,v<<1,tl,tm);
    build(a,v<<1|1,tm+1,tr);
    t[v]=min(t[v<<1],t[v<<1|1]);
}

int get(int v,int tl,int tr,int l,int r){
    if(tl>r || tr<l)return __INT64_MAX__;
    if(tl==l && tr==r)return t[v];
    int tm = (tl+tr)/2;
    return min(get(v<<1,tl,tm,l,min(r,tm)),get(v<<1|1,tm+1,tr,max(l,tm+1),r));
}

int32_t main(){
    sws
    int n,a,b;
    cin>>n>>a>>b;
    int psum[n+1];   
    psum[0]=0;

    rep(i,1,n+1){
        int x;cin>>x;
        psum[i]=psum[i-1]+x;
    } 
    int ans  = LINF;
    build(psum,1,0,n);

    rep(i,a,n+1){
        int lim_a = max(i-b,0LL),lim_b=max(i-a,0LL);
        int pos = psum[i]-get(1,0,n,lim_a,lim_b);
        ans = max(pos,ans);
    }

    cout<<ans;
}
