#include <bits/stdc++.h>
using namespace std;
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define mt make_tuple
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
typedef tuple<int,int,int> project;

struct Comp{
    
    bool operator()(project a,project b){ 
        if(get<1>(a)<get<1>(b)){
            return true;   
        }
        if(get<1>(a)>get<1>(b)){
            return false;   
        }
        if(get<2>(a)<get<2>(b)){
            return false;   
        }
    }  
};

int32_t main(){
    sws
    int n;
    cin>>n;
    int dp[n];
    vector<project>v;
    
    rep(i,0,n){
        int a,b,c;
        cin>>a>>b>>c;
        v.pb(mt(a,b,c));
    }
    sort(v.begin(),v.end(),Comp());
    
    dp[0]=get<2>(v[0]);
    
    rep(i,1,n){
        dp[i]=dp[i-1];
        
        int limit = get<0>(v[i]);
        
        int pos = -1;
        for(int step = max(1LL,i/2);step>=1;step/=2){
            while(pos+step<i && get<1>(v[pos+step])<limit)pos+=step;
        }
        
        
        int cur = get<2>(v[i]);
        if(pos!=-1)cur+=dp[pos];
        
        dp[i]=max(dp[i],cur);
    }
    
    
    cout<<dp[n-1];
    
}
