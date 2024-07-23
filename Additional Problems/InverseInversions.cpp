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
typedef vector<pair<int,int> > vpp;
typedef pair<pii,int >pp;
const int MAXN = 1e6+1;
int t[MAXN<<2];
int qtd;

void update(int v,int tl,int tr,int pos,int val){
    if(tl==tr){
        t[v]=val;
        return;
    }
    int tm = (tl+tr)>>1;
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

int get(int v,int tl,int tr,int val){
    if(tl==tr)return tl;
    int tm = (tl+tr)>>1;
    if(t[v<<1]<=val)return get(v<<1|1,tm+1,tr,val-t[v<<1]);
    return get(v<<1,tl,tm,val);
}

int get(int val){
    return get(1,0,MAXN-1,val);
}

int32_t main(){
	sws
	int n,k;
	cin>>n>>k;
    qtd=n;
	rep(i,1,n+1)update(i,1);
	
	while(qtd){
	   int disc = min(k,qtd-1);
	   k-=disc;
       int pos = get(disc);
	   cout<<pos<<" ";
	   update(pos,0);qtd--;
	}
}
