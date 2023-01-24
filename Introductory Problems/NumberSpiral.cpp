#include <bits/stdc++.h>
using namespace std;
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(msg,x) cout<<msg<<" "<<x<<endl;
#define output(x) for(auto c:x){cout<<c<<" ";}cout<<" ";
#define int unsigned long long 
#define ff first
#define ss second
#define pq priority_queue
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;

signed main(){
    sws
    int t;cin>>t;
    while(t--){
        int y,x;
        cin>>y>>x;
        int square = max(x,y);
        
        if(square%2==1){
            if(x==square){
                cout<<square*square-(y-1)<<endl;
            }else{
                int leftmosts = (square-1)*(square-1) + 1; 
                cout<<leftmosts +(x-1)<<endl;
            }
        }else{
           if(y==square){
                cout<<square*square-(x-1)<<endl;
           }else{
                int topmost = (square-1)*(square-1) + 1; 
                cout<<topmost +(y-1)<<endl;
           }
        }
    }
}
