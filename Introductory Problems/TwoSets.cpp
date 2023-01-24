#include <bits/stdc++.h>
using namespace std;
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(msg,x) cout<<msg<<" "<<x<<endl;
#define output(x) for(auto c:x){cout<<c<<" ";}cout<<"\n";
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
    ll n;cin>>n;

    if(n%4!=0 && (n+1)%4!=0){cout<<"NO\n";return 0;}

    cout<<"YES\n";

    vi v1,v2;

    ll goal;

    ll current=0;

    if(n%4==0){
        goal = (n/4)*(n+1);
    }else{
        goal = ((n+1)/4)*(n);
    }
    
    for(int i=n;i>=1;i--){
        if(current+i <= goal){
            v1.pb(i);
            current+=i;
        }else{
            v2.pb(i);
        }
    }

    cout<<v1.size()<<"\n";

    output(v1);

    cout<<v2.size()<<"\n";

    output(v2);
}