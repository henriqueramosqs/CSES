#include <bits/stdc++.h>
using namespace std;
#define sws ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#pragma GCC target("popcnt")
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(msg,x) cout<<msg<<" "<<x<<endl;
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
    int n;cin>>n;
    int ans = 0;
    bitset<3000> row[3000];
    rep(i,0,n)cin>>row[i];
    
    rep(i,0,n){
        rep(j,i+1,n){
            int aux = (row[i]&row[j]).count();
            ans+= (aux*(aux-1));
        }
    }


    cout<<(ans>>1)<<"\n";
    
}
