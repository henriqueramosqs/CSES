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

struct Node{
    int sum;
    int pref;
    Node(){}

    Node(int val){
        sum = val;
        pref = max(0LL,val);
    }

    Node(int val_1,int val_2){
        sum = val_1;
        pref =val_2;
    }
};

Node t[4*MAXN];

Node combine(Node a,Node b){
    return Node(a.sum+b.sum,max(a.pref,a.sum+b.pref));
}

void build(int v,int a[],int tl,int tr){
    if(tl==tr){
        t[v]=Node(a[tl]);
        return;
    }

    int tm  = (tl+tr)/2;
    build(v<<1,a,tl,tm);
    build(v<<1|1,a,tm+1,tr);
    t[v]=combine(t[v<<1],t[v<<1|1]);
}

void update(int v,int tl,int tr,int pos,int val){
    if(tl==tr){
        t[v]=Node(val);
        return;
    }
    int tm = (tl+tr)/2;
    if(pos<=tm){
        update(v<<1,tl,tm,pos,val);
    }else{
        update(v<<1|1,tm+1,tr,pos,val);
    }
    t[v]=combine(t[v<<1],t[v<<1|1]);
}

Node get(int v ,int tl,int tr,int l,int r){
    if(tl>r || tr<l){
        return Node(0,0);
    }
    if(tl==l && tr==r){
        return t[v];
    }
    
    int tm = (tl+tr)/2;

    Node a = get(v<<1,tl,tm,l,min(r,tm));
    Node b = get(v<<1|1,tm+1,tr,max(l,tm+1),r);
    return combine(a,b);
}


int32_t main(){
    sws
 
    int n,q;
    cin>>n>>q;
    int a[n];
    rep(i,0,n)cin>>a[i];    

    build(1,a,0,n-1);

    while(q--){
        int op;cin>>op;
        if(op==1){
            int pos,val;
            cin>>pos>>val;
            pos--;
            update(1,0,n-1,pos,val);
        }else{
            int a,b;
            cin>>a>>b;
            a--;b--;
            cout<<get(1,0,n-1,a,b).pref<<endl;
        }
    }
}