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
#define int long long
#define ss second
#define pq priority_queue
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;

int32_t main(){
    sws
    int n,totalSum=0;
    cin>>n;
    vi v;

    rep(i,0,n){
        int p;cin>>p;
        v.pb(p);
        totalSum+=p;
    }

    int maxComparator =(1<<(n+1));
    int minDif = 1e10;
    int i = 11;
    for(int i=1;i<maxComparator;i++){
        int localSum=0;
        for(int el = 0;el<n;el++){
            int pos = (1<<el);
            if( (i&pos)!=0 ){ 
                localSum+=v[el];
            }
        }

        int localDif = abs(localSum - (totalSum-localSum));
        minDif = min(minDif,localDif);
    }

    cout<<minDif;
}
