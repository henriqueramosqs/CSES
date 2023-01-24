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
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int MAXN = 2*1e5;
const int IDENT =  0x7fffffff;
int t[4*MAXN];

void build(int a[],int v,int tl,int tr){
    if(tl==tr){
        t[v]=a[tl];
        return;
    }

    int tm= (tl+tr)/2;
    build(a,v<<1,tl,tm);
    build(a,v<<1|1,tm+1,tr);

    t[v]=(t[v<<1]^t[v<<1|1]);
}


int get(int v,int tl,int tr,int l,int r){

    if(tl>r || tr<l){
        return 0;
    }

    if(tl==l && r==tr){
        return t[v];
    }
    int tm = (tl+tr)/2;

    int ans =(get(v<<1,tl,tm,l,min(tm,r))^get(v<<1|1,tm+1,tr,max(l,tm+1),r));

    return ans;


}
int main(){
    sws
    int n,q;
    cin>>n>>q;
    int a[n];
    rep(i,0,n){
        cin>>a[i];
    }

    build(a,1,0,n-1);

    rep(i,0,q){
        int a,b;
        cin>>a>>b;
        cout<<get(1,0,n-1,a-1,b-1)<<endl;
    }
}