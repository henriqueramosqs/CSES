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
vi a,psum;

int dpmax[MAXN][MAXN];  

int32_t main(){
    sws
    memset(dpmax,0LL,sizeof(dpmax));

    int n;cin>>n;   
    a.resize(n);
    psum.resize(n+1);
    psum[0]=0;
    rep(i,0,n){
        cin>>a[i]; 
        psum[i+1]=psum[i]+a[i];
    }

    for(int l=n-1;l>=0;l--){
       rep(r,l,n){
           if(l==r){
                dpmax[l][r]=a[l];
                continue;
           }
           dpmax[l][r] =  psum[r+1]-psum[l] -min(dpmax[l+1][r],dpmax[l][r-1]);
        }
    }

    cout<<dpmax[0][n-1];
 

}   
