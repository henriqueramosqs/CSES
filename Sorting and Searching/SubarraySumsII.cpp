#include <bits/stdc++.h>
using namespace std;
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(msg,x) cout<<msg<<" "<<x<<endl;
#define output(x) for(auto c:x){cout<<c<<" ";}cout<<" ";
#define int long long 
#define ff first
#define ss second
#define pq priority_queue
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;

int32_t main(){
    sws
    int n,x;
    cin>>n>>x;
    int ans = 0;
    int psum[n+1];
    psum[0]=0;
    map<int,int>m;
    m[0]=1;

    rep(i,1,n+1){
        int k;cin>>k;
        psum[i]=psum[i-1]+k;
    }

    rep(i,1,n+1){
        int goal = psum[i]-x;   

        if(m.find(goal)!=m.end()){
            ans+=m[goal];
        }

        m[psum[i]]++;
    }   


    cout<<ans;

}
