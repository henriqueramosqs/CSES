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
 
void binSearch(vi &v,int x){
    int n = v.size();
    int pos =n-1;
    if(n==0){
        v.pb(x);
        return;
    }
 
    //eu quero o primeiro que seja maior ou igual
 
    for(int step = (n/2);step>=1;step/=2){
        while(pos-step>=0 && v[pos-step]>=x)pos-=step;
    }
 
    if(v[pos]<x){
        v.pb(x);
        return;
    }
 
    v[pos]=x;
 
}
 
int main(){
    sws
    int n;
    cin>>n;
    int a[n];rep(i,0,n)cin>>a[i];
 
    vi ans;
 
    rep(i,0,n){
        binSearch(ans,a[i]);
    }
 
    cout<<ans.size();
}