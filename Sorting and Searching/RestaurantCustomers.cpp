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
const int MAXN = 1e5+2;


bool Compara(pii a,pii b){
    if(a.ff<b.ff){
        return true;
    }
    if(a.ff==b.ff){
        return (a.ss>=b.ss);
    }
    return false;
}
int main(){
    sws 
    int n;cin>>n;
    vpp v;

    rep(i,0,n){
        int a,b;
        cin>>a>>b;
        v.pb(mp(a,1));
        v.pb(mp(b,-1));
    }

    sort(v.begin(),v.end(),Compara);

    int ans=0;
    int cur=0;

    rep(i,0,2*n){ 
        cur+=v[i].ss;
        ans=max(ans,cur);
    }

    cout<<ans;
}