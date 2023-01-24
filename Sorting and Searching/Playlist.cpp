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
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pii> vpp;
const int MAXN = 2*1e5 +3;


int nxt(pii a,  vpp &v){
    int pos =0;
    int max_pos = v.size();

    for(int step = (max_pos)/2;step>=1;step/=2){
        while(step+pos<max_pos && a>=v[pos+step]){
            pos+=step;
        }
    }
    

    if(pos == max_pos-1 )return MAXN;

    if(v[pos+1].ff==a.ff){
        return v[pos+1].ss;
    }
    
    return MAXN;

}


int main(){
    sws
    int n;cin>>n;
    int a[n];
    vpp v;
    rep(i,0,n){
        cin>>a[i];
        v.pb(mp(a[i],i));
    }

    sort(v.begin(),v.end());

    int ans=0;
    int l=0,r=-1;
    priority_queue<pii, vector<pii>, greater<pii> > p;

    while(r<(n-1)){
        r++;
        pii arg =mp(a[r],r);
        int local_lim = nxt(arg,v);
        p.push(mp(local_lim,r));
        while(l>p.top().ss)p.pop();
        int limit = p.top().ff;
        int org = p.top().ss;
        if(r==limit){
            l=org+1;
            p.pop();
        }

        ans = max(ans,r-l+1);
    }

    cout<<ans;
}
