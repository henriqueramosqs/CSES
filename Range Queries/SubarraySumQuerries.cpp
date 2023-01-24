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
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int MAXN = 200002 ;

struct Node{
    ll pref,suf,sum,ans;
};

Node t[4*MAXN];

Node combine(Node l,Node r){
    Node res;
    res.pref = max(l.pref,l.sum+r.pref);
    res.suf = max(r.suf,r.sum+l.suf);
    res.sum = l.sum+r.sum;
    res.ans = max(max(l.ans,r.ans),l.suf+r.pref);

    return res;
}


Node make_data(ll a){
    Node res;
    res.suf = res.pref = res.ans = max(0LL,a);
    res.sum=a;
    return res;
}

void build(ll a[],int v,int tl,int tr){
    if(tl==tr){
        t[v] = make_data(a[tl]);
        return;
    }
    int tm= (tl+tr)/2;
    build(a,v<<1,tl,tm);
    build(a,v<<1|1,tm+1,tr);

    t[v]=combine(t[v<<1],t[v<<1|1]);

}

void update(int v,int tl,int tr,int index,int new_value ){
    if(tl==tr){
        t[v]=make_data(new_value);
        return;
    } 
    int tm= (tl+tr)/2;
    if(index<=tm){
        update(v<<1,tl,tm,index,new_value);
    }else{
        update(v<<1|1,tm+1,tr,index,new_value);
    }
    t[v]=combine(t[v<<1],t[v<<1|1]);

}

int main(){
    sws
    int n,m;
    cin>>n>>m;
    ll a[n];

    rep(i,0,n){
        cin>>a[i];
    }
    
    build(a,1,0,n-1);

    rep(i,0,m){
        int x,k;
        cin>>x>>k;
        x--;
        update(1,0,n-1,x,k);
        cout<<t[1].ans<<endl;;
    }

    
}