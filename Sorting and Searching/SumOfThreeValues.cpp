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
        int x;cin>>x;
        v.pb(mp(x,i+1));
    }

    sort(v.begin(),v.end());
    
    if(n<3){cout<<"IMPOSSIBLE";return 0;}

    rep(i,0,n-2){
        int cur = v[i].ff;

        if(cur>k){cout<<"IMPOSSIBLE";return 0;}

        int l=i+1,r=n-1;
        while(l<r){
            int val =cur + v[l].ff + v[r].ff;

            if(val<k){
                l++;
                continue;
            }

            if(val>k){
                r--;
                continue;
            }

            cout<<v[i].ss<<" "<<v[l].ss<<" "<<v[r].ss<<"\n";
            return 0;
    
        }

    }

    cout<<"IMPOSSIBLE";return 0;


}