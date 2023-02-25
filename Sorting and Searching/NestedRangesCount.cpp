
#include <iostream>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <class T> using oset =  tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
  
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
const int INF = 1e9;

bool Comp(pair<pii,int> a1,pair<pii,int> b1){
    pii a = a1.ff;
    pii b = b1.ff;
    if(a.ff<b.ff)return true;
    if(a.ff>b.ff)return false;
    return a.ss>b.ss;
}

int main(){
    sws
    
    int n;cin>>n;
    vector<pair<pii,int> > v;

    rep(i,0,n){
        int a,b;
        cin>>a>>b;
        v.pb(mp(mp(a,b),i));
    }

    sort(v.begin(),v.end(),Comp);

    int ans1[n],ans2[n];
    oset<pii> ans1set;
    oset<pii> ans2set;
    
    for(int i = (n-1);i>=0;i--){
        int idx = v[i].ss;
        int bound = v[i].ff.ss;
        int k = ans1set.order_of_key(mp(bound+1,0));
        ans1[idx]=k;
        ans1set.insert(mp(bound,idx));
    }

    for(int i =0;i<n;i++){
        int idx = v[i].ss;
        
        int bound = v[i].ff.ss;
        int k = ans2set.size()-ans2set.order_of_key(mp(bound,-1));
        
        ans2[idx]=k;
        ans2set.insert(mp(bound,idx)); 
    }
    
    rep(i,0,n){
        cout<<ans1[i]<<" ";
    }

    cout<<endl;

    rep(i,0,n){
        cout<<ans2[i]<<" ";
    }
}
