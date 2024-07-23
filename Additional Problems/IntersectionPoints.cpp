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
typedef pair<pii, pii> ppii;
typedef vector<pair<int,int> > vpp;
const int MM =1e6;
const int MAXN = 2*1e6+1;
int t[MAXN<<2];


inline int conv(int x){
    return x+MM;
}
int get(int v,int tl,int tr,int l,int r){
    if(tl==l && tr==r)return t[v];
    if(tl>r || tr<l)return 0;
    int tm = (tl+tr)/2;
    return get(v<<1,tl,tm,l,min(tm,r))+get(v<<1|1,tm+1,tr,max(tm+1,l),r);
}

int get(int l,int r){
    return get(1,0,MAXN-1,l,r);
}

void update(int v,int tl,int tr,int pos,int val){
    if(tl==tr){
        t[v]+=val;
        return ;
    }
    int tm = (tl+tr)/2;
    if(pos<=tm){
        update(v<<1,tl,tm,pos,val);
    }else{
        update(v<<1|1,tm+1,tr,pos,val);
    }
    t[v]=t[v<<1]+t[v<<1|1];
}

void update(int pos,int val){
    update(1,0,MAXN-1,pos,val);
}

int32_t main(){

    int n;cin>>n;
    vector<ppii> v(n);
    vector<array<int,3> >events;
    rep(i,0,n){
        cin>>v[i].ff.ff>>v[i].ff.ss>>v[i].ss.ff>>v[i].ss.ss;
        if(v[i].ff.ff>v[i].ss.ff)swap(v[i].ff,v[i].ss);
        if(v[i].ff.ss==v[i].ss.ss){
            //horz
            events.pb({v[i].ff.ff,1,i});
            events.pb({v[i].ss.ff,3,i});
        }else{
            //vert
            events.pb({v[i].ff.ff,2,i});
        }
    }       
    // 1 entra, 2 vert, 3 tira

    sort(events.begin(),events.end());

    int ans=0;
    

    for(auto c:events){
        int x = c[0],type=c[1],idx = c[2];

        if(type==1){
            update(conv(v[idx].ff.ss),1);
        }

        if(type==2){
            int l = v[idx].ff.ss,r = v[idx].ss.ss;
            if(l>r)swap(l,r);
            ans+=get(conv(l),conv(r));
        }

        if(type==3){
            update(conv(v[idx].ff.ss),-1);
        }
    }

    cout<<ans;
}