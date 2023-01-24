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
    int n;
    cin>>n;
    bool b[n+1];
    rep(i,0,n+1)b[i]=false;
    rep(i,0,n-1){
        int a;cin>>a;
        b[a]=true;
    }

    rep(i,1,n+1){
        if(!b[i]){
            cout<<i;return 0;
        }
    }
}