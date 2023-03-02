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
int t[MAXN<<2];

void build(int a[],int v,int tl,int tr){
    if(tl==tr){
        t[v]=a[tl];
        return;
    }

    int tm = (tl+tr)/2;

    build(a,v<<1,tl,tm);
    build(a,v<<1|1,tm+1,tr);
    t[v]= min(t[v<<1],t[v<<1|1]);
}


int get(int v,int tl,int tr,int maxPos,int maxVal){
    if(t[v]>=maxVal)return -1;
    if(tl>=maxPos)return -1;
    if(tl==tr)return tl;

    int tm = (tl+tr)/2;
    int ans = get(v<<1|1,tm+1,tr,maxPos,maxVal);
    if(ans!=-1)return ans;
    return get(v<<1,tl,tm,maxPos,maxVal);
}

int main(){
    sws
    int n;
    cin>>n;
    int a[n];
    rep(i,0,n)cin>>a[i];
    build(a,1,0,n-1);

    rep(i,0,n){
        cout<<get(1,0,n-1,i,a[i])+1<<" ";
    }

}