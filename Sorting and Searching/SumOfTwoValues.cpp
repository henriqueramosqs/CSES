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
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;

int32_t main(){
    sws
    int n,x;
    cin>>n>>x;
    vpp v(n);

    rep(i,0,n){
        int a;cin>>a;
        v[i]=mp(a,i+1);
    }

    sort(v.begin(),v.end());

    int l=0,r=n-1;

    while(l<r){
        int sum = v[l].ff+v[r].ff;
        if(sum>x){
            r--;
            continue;
        }
        if(sum<x){
            l++;
            continue;
        }
        if(sum==x){
            cout<<v[l].ss<<" "<<v[r].ss<<"\n";
            return 0;
        }
    }

    cout<<"IMPOSSIBLE";
}