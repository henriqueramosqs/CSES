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
#define int long long
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int MOD = 1E9+7;

int32_t main(){
    sws
    int n;cin>>n;
    char grid[n][n];
    int a[n][n];

    rep(i,0,n*n) cin>>grid[i/n][i%n];

    a[0][0]= (grid[0][0]=='.');

    rep(i,1,n*n){
       if(grid[i/n][i%n]=='*'){
            a[i/n][i%n]=0;
       }else{
           int ans=0;
           if((i/n -1)>=0)(ans+=a[i/n -1][i%n]);
           if((i%n -1)>=0)(ans+=a[i/n][(i%n) -1]);
           a[i/n][i%n]=(ans%MOD);
       }
    }

    cout<<a[n-1][n-1];
}
