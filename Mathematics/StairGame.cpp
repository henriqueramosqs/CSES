#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(x) cout<<#x<<" "<<x<<endl;
#define output(x) for(auto c:x){cout<<c<<" ";}cout<<" ";
#define int long long 
#define ff first
#define ld long double
#define ss second
#define endl "\n"
#define pq priority_queue
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;

int32_t main(){
    sws
    int t;cin>>t;
    while (t--){
        int n;cin>>n;
        int aux=0;
        rep(i,0,n){
            int x;cin>>x;
            if(i%2)aux^=x;
        }
        aux!=0?cout<<"first\n":cout<<"second\n";
    }
    
}