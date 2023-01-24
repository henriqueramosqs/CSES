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
const int MAXN = 2*1e5+1;

int32_t main(){
    sws
    int n;cin>>n;
    
    vi v;

    rep(i,0,n){
        int a;cin>>a;
        v.pb(a);
    }  

    sort(v.begin(),v.end());

    pii foc=mp(0,0);

    rep(i,0,n){
        pii nw =mp(foc.ff+v[i],foc.ss+v[i]);

        if(nw.ff<=(foc.ss+1)){
            foc = mp(0,nw.ss);
        }else{
            cout<<foc.ss+1;
            return 0;
        }
    }


    cout<<foc.ss+1;
}