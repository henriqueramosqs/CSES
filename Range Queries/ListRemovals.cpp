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
#define pq xpriority_queue
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int MAXN = 2*1e5;
pii t[4*(MAXN+3)];


pii combine(pii a,pii b){
    return mp(max(a.ff,b.ff),a.ss+b.ss);
}

void build(int a[],int v,int tl,int tr){
    if(tl==tr){
        t[v]=mp(a[tl],1);
        return;
    }

    int tm = (tl+tr)/2;

    build(a,v<<1,tl,tm);
    build(a,v<<1|1,tm+1,tr);
    t[v]=combine(t[v<<1],t[v<<1|1]);
}

void get(int v,int tl,int tr,int pos,int carry){
    
    if(tl==tr){
        cout<<t[v].ff<<" ";
        t[v].ss=0;
        return;
    }

    int tm = (tl+tr)/2;

    if(pos<=(t[v<<1].ss+carry)){
        get(v<<1,tl,tm,pos,carry);
    }else{
        get(v<<1|1,tm+1,tr,pos,carry+t[v<<1].ss);
    }

    t[v]=combine(t[v<<1],t[v<<1|1]);

}
int main(){
    sws
    int n;cin>>n;
    int a[n];
    rep(i,0,n)cin>>a[i];

    build(a,1,0,n-1);

    rep(i,0,n){
        int x;
        cin>>x;
        get(1,0,n-1,x,0);
    }
}