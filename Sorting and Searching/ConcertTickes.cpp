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
    int n,m;
    cin>>n>>m;
    multiset<int>prices;
    rep(i,0,n){
        int x; cin>>x;
        prices.insert(x);
    }

    rep(i,0,m){
        int t;cin>>t;
        auto it = prices.lower_bound(t);   

        if(*it==t){
            cout<<t<<endl;
            prices.erase(it);
            continue;
        }

        if(it==prices.begin()){
            cout<<-1<<endl;
        }else{
            it--;
            cout<<*it<<endl;
            prices.erase(it);
        }
    }
}