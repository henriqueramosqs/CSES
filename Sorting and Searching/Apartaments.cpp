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
    int n,m,k;
    cin>>n>>m>>k;
    vi a,b;
    rep(i,0,n){int x;cin>>x;a.pb(x);}
    rep(i,0,m){int x;cin>>x;b.pb(x);}

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int ap=0;
    int bp=0;
    int counter=0;

    while(ap<n && bp<m){
        if(abs(a[ap]-b[bp])<=k){
            counter++;
            bp++;
            ap++;
            continue;
        }
        if(a[ap]>b[bp]){
            bp++;
            continue;
        }
        ap++;
    }

    cout<<counter;
}