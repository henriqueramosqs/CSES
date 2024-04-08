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
const int MAXN = 2*1e5;
int t[MAXN<<2];
int n;

void build(int a[],int v,int tl,int tr){
    if(tl==tr){
        t[v]=a[tl];
        return;
    }
    int tm = (tl+tr)/2;
    build(a,v<<1,tl,tm);
    build(a,v<<1|1,tm+1,tr);
    t[v]=min(t[v<<1],t[v<<1|1]);
}


int get_l(int v,int tl,int tr,int l,int r,int goal){

    if(tl>r || tr<l || t[v]>=goal){
        return -1;

    }
    if(tl==tr){
        return tl;
    }
    int tm = (tl+tr)/2;
    int ans = get_l(v<<1|1,tm+1,tr,max(l,tm+1),r,goal);
    if(ans!=-1)return ans;
    return get_l(v<<1,tl,tm,l,min(tm,r),goal);
}

int get_r(int v,int tl,int tr,int l,int r,int goal){

    if(tl>r || tr<l || t[v]>=goal){

        return n;
    }

    if(tl==tr){
        return tl;
    }
    int tm = (tl+tr)/2;

    int ans = get_r(v<<1,tl,tm,l,min(tm,r),goal);
    if(ans!=n)return ans;
    return get_r(v<<1|1,tm+1,tr,max(l,tm+1),r,goal);
   
}

int32_t main(){
    sws
    cin>>n;
    int a[n];rep(i,0,n)cin>>a[i];

    build(a,1,0,n-1);
    int ans=0;

    rep(i,0,n){
        int l = get_l(1,0,n-1,0,i-1,a[i]);
        int r = get_r(1,0,n-1,i+1,n-1,a[i]);
        l++;r--;
        ans=max(ans,(r-l+1)*a[i]);
    }

    cout<<ans;
}

