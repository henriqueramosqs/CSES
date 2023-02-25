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
const int MAXN = 5000;
int n;
vi a;

int dpmax[MAXN][MAXN];  
int dpmin[MAXN][MAXN];

int minimize(int l,int r);

int maximize(int l,int r){
    if(dpmax[l][r])return dpmax[l][r];
    if(l>r)return 0;
    if(l==r) return dpmax[l][r] = a[l];
    return dpmax[l][r] =  max(a[l] + minimize(l+1,r), a[r] +minimize(l,r-1));
}

int minimize(int l,int r){
    if(l>r || l==r){
        return 0;
    }
    return dpmax[l][r] =  min(maximize(l+1,r),maximize(l,r-1));
}

int32_t main(){
    sws
    memset(dpmax,0LL,sizeof(dpmax));
    memset(dpmin,0LL,sizeof(dpmin));

    int n;cin>>n;   
    a.resize(n);
    rep(i,0,n)cin>>a[i];

    cout<<maximize(0,n-1);
 

}   
