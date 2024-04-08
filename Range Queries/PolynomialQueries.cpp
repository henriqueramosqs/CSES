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
const int MAXN = 2*1e5+1;
int t[MAXN<<2];
pii lazy[MAXN<<2];
 
 
pii combine(pii a,pii b){
    return mp(a.ff+b.ff,a.ss+b.ss);
}
 
void push(int v,int tl,int tr){
    int ao=lazy[v].ff,q = lazy[v].ss;
    if(ao==0 && q==0)return;
    int tm = (tl+tr)/2;
    t[v<<1]+=(tm-tl+1)*(ao+ao+q*(tm-tl))/2;
    lazy[v<<1]=combine(lazy[v<<1],lazy[v]);
    int lo = ao+ (tm+1-tl)*q;
    t[v<<1|1]+=(tr-tm)*(lo+lo+q*(tr-tm-1))/2;
    lazy[v<<1|1]=combine(lazy[v<<1|1],mp(lo,q));
    lazy[v]=mp(0,0);
}
void build(int a[],int v,int tl,int tr){
    if(tl==tr){
        t[v]=a[tl];
        return;
    }
    int tm = (tl+tr)/2;
    build(a,v<<1,tl,tm);
    build(a,v<<1|1,tm+1,tr);
    t[v]=t[v<<1]+t[v<<1|1];
}
 
int get(int v,int tl,int tr,int l,int r){
    if(tl>r || tr<l)return 0 ;
    if(tl==l && tr==r){
        return t[v]; 
    }
    push(v,tl,tr);
    int tm = (tl+tr)/2;
    return get(v<<1,tl,tm,l,min(tm,r))+get(v<<1|1,tm+1,tr,max(l,tm+1),r);
}
 
 
void update(int v,int tl,int tr,int l,int r,int ao=1,int q=1){
    if(tl>r || tr<l)return;
    if(tl==l && tr==r){
        t[v]+=(tr-tl+1)*(ao+ao+q*(tr-tl))/2;
        lazy[v]=combine(lazy[v],mp(ao,q));
        return; 
    }
    push(v,tl,tr);
    int tm = (tl+tr)/2;
    update(v<<1,tl,tm,l,min(r,tm),ao,q);
    int no = ao;
    if(tm+1>l)no+=(tm+1-l);
    update(v<<1|1,tm+1,tr,max(l,tm+1),r,no,q);
    t[v]=t[v<<1]+t[v<<1|1]; 
}
 
 
int32_t main(){
    sws
    int n,q;cin>>n>>q;
    int a[n];
    rep(i,0,n)cin>>a[i];
 
    build(a,1,0,n-1);
 
    while(q--){
        int op,a,b;cin>>op>>a>>b;
        a--;b--;
        if(op==1){
            update(1,0,n-1,a,b);
        }else{
            cout<<get(1,0,n-1,a,b)<<endl;
        }
    }
}