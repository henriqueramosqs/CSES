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
int up[4*MAXN];
int dwn[4*MAXN];


void build(int v,pii a[],int tl,int tr){
    if(tl==tr){
        up[v]=a[tl].ff+a[tl].ss;
        dwn[v]=a[tl].ff-a[tl].ss;
        return;
    }
    int tm= (tl+tr)/2;
    build(v<<1,a,tl,tm);
    build(v<<1|1,a,tm+1,tr);
    up[v]=min(up[v<<1],up[v<<1|1]);
    dwn[v]=min(dwn[v<<1],dwn[v<<1|1]);
}

void update(int v,int tl,int tr,pii a){
    if(tl==tr){
        up[v]=a.ff+a.ss;
        dwn[v]=a.ff-a.ss;
        return;
    }

    int tm= (tl+tr)/2;
    if(tm>=a.ss){
        update(v<<1,tl,tm,a);
    }else{
        update(v<<1|1,tm+1,tr,a);
    }
    up[v]=min(up[v<<1],up[v<<1|1]);
    dwn[v]=min(dwn[v<<1],dwn[v<<1|1]);
}

int minim_up(int v,int tl,int tr,int l,int r){
    if(tl>r || tr<l){
        return __INT64_MAX__;
    }  
    if(l==tl && tr==r){
        return up[v];
    }

    int tm = (tl+tr)/2;
    int ans_a = minim_up(v<<1,tl,tm,l,min(r,tm));
    int ans_b = minim_up(v<<1|1,tm+1,tr,max(l,tm+1),r);
    return min(ans_a,ans_b);
}

int minim_dwn(int v,int tl,int tr,int l,int r){
    if(tl>r || tr<l){
        return __INT64_MAX__;
    }  
    if(l==tl && tr==r){
        return dwn[v];
    }

    int tm = (tl+tr)/2;
    int ans_a = minim_dwn(v<<1,tl,tm,l,min(r,tm));
    int ans_b = minim_dwn(v<<1|1,tm+1,tr,max(l,tm+1),r);
    return min(ans_a,ans_b);
}
int32_t main(){
    sws
    int n,q;
    cin>>n>>q;
    pii a[n];

    rep(i,0,n){
        int x;cin>>x;
        a[i]=mp(x,i);
    }
    build(1,a,0,n-1);

    while(q--){
        int op;cin>>op;

        if(op==1){
            int pos,x;
            cin>>pos>>x;
            pos--;
            update(1,0,n-1,mp(x,pos));
        }else{  
            int a;cin>>a;a--;
            cout<<min(minim_dwn(1,0,n-1,0,a)+a,minim_up(1,0,n-1,a+1,n-1)-a)<<endl;
        }

    }
}