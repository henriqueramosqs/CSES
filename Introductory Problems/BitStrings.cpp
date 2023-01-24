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
const int MAXN= 1e6 +3;
const int MOD = 1e9 +7;
int ans[MAXN];

void process(){
    ans[0]=1;
    rep(i,1,MAXN){
        ans[i]=(ans[i-1]<<1)%MOD;
    }
}
int main(){
    sws
    process();
    int n;cin>>n;
    cout<<ans[n];
}