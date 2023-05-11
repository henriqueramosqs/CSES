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

int main(){
    sws
    int n,k;
    cin>>n>>k;
    vpp v;
    
    rep(i,0,n){
        int a,b;
        cin>>a>>b;
        v.pb(mp(b,a));
    }
    
    sort(v.begin(),v.end());

    set<pii>s;

    rep(i,0,k)s.insert(mp(0,i));
    int ans=0;
 
    rep(i,0,n){
        int start = v[i].ss, end=v[i].ff;
        auto it = s.upper_bound(mp(start,n+1));
        if(it==s.begin())continue;
        ans++;it--;
        int idx = it->ss;
        s.erase(it);
        s.insert(mp(end,idx));
    }
 
   cout<<ans;
}

