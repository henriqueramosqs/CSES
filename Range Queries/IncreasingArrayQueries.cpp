#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")
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
const int MAXN = 2*1e5+2;
const int LOGN = 30;
const int INF = __INT32_MAX__;
int t[MAXN<<2];
int up[MAXN][LOGN];
int sum[MAXN][LOGN];
 
void build(vi &a,int v,int tl,int tr){
    if(tl==tr){
        t[v]=a[tl];
        return;
    }
 
    int tm = (tl+tr)/2;
    build(a,v<<1,tl,tm);
    build(a,v<<1|1,tm+1,tr);
    t[v]=t[v<<1]+t[v<<1|1];
}
int gets(int v,int tl,int tr,int l,int r){
    if(tl>r || tr<l)return 0;
    if(tl==l && tr==r)return t[v];
    int tm = (tl+tr)/2;
    return gets(v<<1,tl,tm,l,min(tm,r))+gets(v<<1|1,tm+1,tr,max(l,tm+1),r);
}
 
int32_t main(){
    sws;
    int n,q;
    cin>>n>>q;
    vi a(n);
    rep(i,0,n)cin>>a[i];
    build(a,1,0,n-1);
    a.pb(INF);
    rep(i,0,LOGN){
        up[n][i]=n;
        sum[n][i]=0;
    }
    stack<pii>aux;
 
    aux.push(mp(a[n],n));
    for(int i = n-1;i>=0;i--){
        while(aux.top().ff<a[i])aux.pop();
        up[i][0]=aux.top().ss;
        sum[i][0]=(up[i][0]-i)*a[i];
        rep(j,1,30)up[i][j]=up[up[i][j-1]][j-1];
        rep(j,1,30)sum[i][j]=sum[i][j-1]+sum[up[i][j-1]][j-1];
        aux.push(mp(a[i],i));
    }
 
    while (q--){
        int l,r;
        cin>>l>>r;
        l--;r--;
        int ans = -gets(1,0,n-1,l,r);
        int v = l;
        while(true){
            bool could = false;
            for(int i = LOGN-1;i>=0;i--){
                if(up[v][i]<=r){
                    ans+=sum[v][i];
                    v = up[v][i];
                    could = true;
                    break;
                }
            }
            if(!could )break;
        }
        ans+=(r-v+1)*a[v];
        cout<<ans<<"\n";
    }
    
}   