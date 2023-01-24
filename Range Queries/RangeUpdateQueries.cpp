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
#define int long long
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int MAXN= 2*1e5 +1;
int t[4*MAXN];
int lazy[4*MAXN];

void build(int a[],int v,int tl,int tr){
    if(tl==tr){
        t[v]=a[tl];
        return;
    }

    int tm= (tl+tr)/2;
    build(a,v<<1,tl,tm);
    build(a,v<<1|1,tm+1,tr);
    t[v]=0;
}

int get(int v, int tl,int tr,int pos){
    if(lazy[v]){
        t[v]+=lazy[v];
        if(tl!=tr){
            lazy[v<<1]+=lazy[v];
            lazy[v<<1|1]+=lazy[v];
        }

        lazy[v]=0;

    }
    if(tl==pos && tr==pos){
        return t[v];
    }
    int tm= (tl+tr)/2;
    if(pos<=tm){
        return get(v<<1,tl,tm,pos);
    }else{
        return get(v<<1|1,tm+1,tr,pos);
    }
}

void update(int v,int tl,int tr,int l,int r,int u){
    if(tl>r || l>tr){
        return;
    }

    if(tl==l && tr==r){
        lazy[v]+=u;
        return;
    }

    int tm= (tl+tr)/2;
    update(v<<1,tl,tm,l,min(r,tm),u);
    update(v<<1|1,tm+1,tr,max(l,tm+1),r,u);
}

int32_t main(){
    sws
    int n,q;
    cin>>n>>q;
    int a[n];
    rep(i,0,n)cin>>a[i];

    build(a,1,0,n-1);   

    rep(i,0,q){
        int op;
        cin>>op;
        if(op==1){
            int a,b,val;
            cin>>a>>b>>val;
            update(1,0,n-1,a-1,b-1,val);
        }else{
            int pos;cin>>pos;
            cout<<get(1,0,n-1,pos-1)<<endl;
        }
    }
    
}