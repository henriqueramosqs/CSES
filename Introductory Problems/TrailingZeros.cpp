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
int pots[12];

void process(){
    pots[0]=5;

    rep(i,1,12){
        pots[i]=pots[i-1]*5;
    }
}
int main(){
    sws
    process();

    int n;cin>>n;

    int ans=0;

    rep(i,0,12){
        ans+=(n/pots[i]);
    }

    cout<<ans;
}