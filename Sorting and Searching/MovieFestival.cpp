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
#define pq xpriority_queue
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
int counter=0;

bool Comp(pii a,pii b){
    return (a.ss<=b.ss);

}

int main(){
    sws
    int n;
    cin>>n;   
    vpp v;

    rep(i,0,n){
        int a,b;cin>>a>>b;
        v.pb(mp(b,a));
    }

    
   sort(v.begin(),v.end());

    int ans=0;
    int cur=0;

    rep(i,0,n){
        if(v[i].ss>=cur){
            cur=v[i].ff;
            ans++;
        }
    }

    cout<<ans;
}