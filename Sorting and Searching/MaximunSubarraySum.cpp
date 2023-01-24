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
#define int long long
#define pq priority_queue
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;

int32_t main(){
    sws
    int n;cin>>n;
    int a[n];
    rep(i,0,n)cin>>a[i];
    int sum=0;
    int maxSum=0;
    int maxVal=INT64_MIN;

    rep(i,0,n){
        sum = max(sum+a[i],a[i]);
        maxSum= max(sum,maxSum);
        maxVal=max(maxVal,a[i]);
    }

    if(maxSum==0)maxSum = maxVal;
    cout<<maxSum;
  
    
}