#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")
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


int c(int x){
    return (x*(x-1))>>1;
}
int32_t main(){
    sws 
    int n;cin>>n;
    ld ans=0.0;
    vi v(n);
    rep(i,0,n)cin>>v[i];
    rep(i,0,n){
        rep(j,i+1,n){
            int ctr;
            if(v[i]<=v[j]){
                ctr=c(v[i]);
            }else{  
                ctr=c(v[j]);
                ctr+=((v[i]-v[j])*v[j]);
            }
            ans+=(ld)ctr/(v[i]*v[j]);
        }
    }   
  printf("%.6Lf\n", ans);
}