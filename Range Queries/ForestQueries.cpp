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
    int n,q;
    cin>>n>>q;
    int a[n][n];

    rep(i,0,n){
        rep(j,0,n){
            char k;cin>>k;
            int val = (k=='*');

            if(i>0)val+=a[i-1][j];

            if(j>0)val+=a[i][j-1];

            if(i>0 && j>0) val-=a[i-1][j-1];

            a[i][j]=val;
            
        }
    }

    rep(i,0,q){
        int y1,x1,y2,x2;
        cin>>y1>>x1>>y2>>x2;
        y1--;
        x1--;
        x2--;
        y2--;
        int ans =a[y2][x2];
        if(x1>0)ans-=a[y2][x1-1];
        if(y1>0)ans-=a[y1-1][x2];
        if(x1>0 && y1>0)ans+=a[y1-1][x1-1];
        cout<<ans<<"\n";
    }
}