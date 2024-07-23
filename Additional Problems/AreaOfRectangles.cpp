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
const int MAXN = 2*1e6+1;
const int MM = 1e6;
const pii NIL = mp((1ll<<30),(1ll<<30));
int lazy[MAXN<<2];
pii t[MAXN<<2];

pii add(pii a,pii b){
    return mp(a.ff+b.ff,a.ss+b.ss);
}

inline int conv(int x){
    return x+MM;
}

pii comb(pii a,pii b){
    if(a.ff<b.ff)return a;
    if(b.ff<a.ff)return b;
    return mp(a.ff,b.ss+a.ss);
}

void push(int v,int tl,int tr){
    lazy[v<<1]+=lazy[v];
    lazy[v<<1|1]+=lazy[v];
    t[v<<1].ff+=lazy[v];
    t[v<<1|1].ff+=lazy[v];
    lazy[v]=0ll;
}   

void build(int v,int tl,int tr){
    if(tl==tr){
        t[v]=mp(0,1);
        return;
    }
    int tm = (tl+tr)/2;
    build(v<<1,tl,tm);
    build(v<<1|1,tm+1,tr);
    t[v]=comb(t[v<<1],t[v<<1|1]);
}

void build(){
    build(1,0,MAXN-1);
}
pii get(int v,int tl,int tr,int l,int r){
    if(tl>r || tr<l)return NIL;
    if(tl==l && tr==r)return t[v];
    push(v,tl,tr);
    int tm = (tl+tr)/2;
    return comb(get(v<<1,tl,tm,l,min(tm,r)), get(v<<1|1,tm+1,tr,max(tm+1,l),r));
}
int get(){
    pii aux  = get(1,0,MAXN-1,0,MAXN-1);
    int ans = MAXN;
    if(aux.ff==0)ans-=aux.ss;
    return ans;
}

void update(int v,int tl,int tr,int l,int r,int val){
    if(tl>r || tr<l)return;
    if(tl==l && tr==r){
        t[v].ff+=val;
        lazy[v]+=val;
        return;
    }
    push(v,tl,tr);
    int tm = (tl+tr)/2;
    update(v<<1,tl,tm,l,min(tm,r),val);
    update(v<<1|1,tm+1,tr,max(tm+1,l),r,val);
    t[v]=comb(t[v<<1],t[v<<1|1]);

}
void update(int l,int r,int val){
    update(1,0,MAXN-1,l,r,val);
}

int32_t main(){
    sws
    build();
    int n;cin>>n;
    vpp rect(n);
    vector<array<int,3> >v;

    rep(i,0,n){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        rect[i]=mp(conv(min(y1,y2)),conv(max(y1,y2)));
        v.pb({min(x1,x2),1,i});
        v.pb({max(x1,x2),2,i});
    }

    sort(v.begin(),v.end());

    int last = -(1ll<<30);
    int ans=0;

    for(auto c:v){
        int x =c[0],type=c[1],idx = c[2];

        ans+=(x-last)*get();

        if(type==1){
            update(rect[idx].ff,rect[idx].ss-1,1);
        }else{
            update(rect[idx].ff,rect[idx].ss-1,-1);
        }
        last=x;
    }

    cout<<ans<<"\n";
}