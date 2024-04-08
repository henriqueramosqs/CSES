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
const int MAXN =200000;
int t[MAXN<<2];

bool Comp(pair<pii,int> a,pair<pii,int> b){
    if(a.ff.ss==b.ff.ss)return b.ss<a.ss;
    return a.ff.ss<b.ff.ss;
}

int get(int v,int tl,int tr,int l,int r){
    if(tl>r || tr<l)return 0 ;
    if(tl==l && r==tr)return t[v];
    
    int tm = (tl+tr)/2;

    return get(v<<1,tl,tm,l,min(r,tm))+get(v<<1|1,tm+1,tr,max(tm+1,l),r);
}   
void update(int v,int tl,int tr,int pos,int val){
    if(tl==tr){
        t[v]=val;
        return;
    }
    
    int tm = (tl+tr)/2;
    if(pos<=tm){
        update(v<<1,tl,tm,pos,val);
    }else{
        update(v<<1|1,tm+1,tr,pos,val);
    }
    t[v]=t[v<<1]+t[v<<1|1];
     
}
int main(){
    sws
    int n,m;
    cin>>n>> m;
    int a[n];
    rep(i,0,n)cin>>a[i];
    vector<pair<pii,int> > v;
    vi ans(m);

    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        a--;b--;
        v.pb(mp(mp(a,b),i));
    }

    map<int,int>lastIdx;
    sort(v.begin(),v.end(),Comp);


    int r=0;

    rep(i,0,m){
        while(r<=v[i].ff.ss){
            if(lastIdx.find(a[r])!=lastIdx.end()){
               update(1,0,n-1,lastIdx[a[r]],0);
            }
            lastIdx[a[r]]=r;
            update(1,0,n-1,r,1);
            r++;
        }

        ans[v[i].ss] = get(1,0,n-1,v[i].ff.ff,v[i].ff.ss);
    }   

    rep(i,0,m)cout<<ans[i]<<"\n";


}
