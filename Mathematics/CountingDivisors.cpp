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

int count(int a){
    int ans=0;
    for(int i=1;i<=sqrt(a);i++){
        if(a%i==0){
            ans++;
            ans+=(i != a/i);
        }
    }
    return ans;
}
int main(){
    sws
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        cout<<count(n)<<endl;
    }
}