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
const int MAXN = 2* 1e5;
int t[MAXN<<2];
pii lazy[MAXN<<2];

pii combineLz(pii a,pii b){
    if(b.ff==0)return a;
    if(a.ff==2)return a;
    if(b.ff==1 && a.ff==1)return mp(1,a.ss+b.ss);     
    return mp(2,a.ss+b.ss);
}

void push(int v,int tl,int tr){
    if(lazy[v].ff==0LL)return;
    lazy[v<<1]=combineLz(lazy[v],lazy[v<<1]);
    lazy[v<<1|1]=combineLz(lazy[v],lazy[v<<1|1]);
    int tm = (tl+tr)/2;

    if(lazy[v].ff==1){
        t[v<<1]+=((tm-tl+1)*lazy[v].ss);
        t[v<<1|1]+=((tr-tm)*lazy[v].ss);
    }else{
        t[v<<1]=(tm-tl+1)*lazy[v].ss;
        t[v<<1|1]=((tr-tm)*lazy[v].ss);
    }

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

void update(int v,int tl,int tr,int l,int r,int op,int val){
    if(tr<l || tl>r)return;

    if(tl==l && tr==r){
        int aux =((tr-tl+1)*val);
       if(op==1){
            t[v]+= aux;
       }else{
            t[v]=aux;
       }
       lazy[v]=combineLz(mp(op,val),lazy[v]);
       return;
    }

    push(v,tl,tr);
    int tm = (tl+tr)/2;
    update(v<<1,tl,tm,l,min(tm,r),op,val);
    update(v<<1|1,tm+1,tr,max(l,tm+1),r,op,val);
    t[v]=t[v<<1]+t[v<<1|1];
   
}

int get(int v,int tl,int tr,int l,int r){

    if(tr<l || tl>r){
        return 0 ;
    }

    if(tl==l && tr==r){
        return t[v];
    }

    push(v,tl,tr);
    int tm = (tl+tr)/2;
    return get (v<<1,tl,tm,l,min(tm,r))+get(v<<1|1,tm+1,tr,max(l,tm+1),r);
}

int32_t main(){
    sws
    int n,q;
    cin>>n>>q;

    int a[n];rep(i,0,n)cin>>a[i];

    build(a,1,0,n-1);

    while(q--){
        int op,l,r,val;
        cin>>op>>l>>r;
        l--;r--;
        if(op==3){
            cout<<get(1,0,n-1,l,r)<<endl;
        }else{
            cin>>val;
            update(1,0,n-1,l,r,op,val);
        }

    }
}
