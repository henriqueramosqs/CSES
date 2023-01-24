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
    int n,x;
    cin>>n>>x;
    vi v;
    rep(i,0,n){
        int a;cin>>a;
        v.pb(a);
    }

    sort(v.begin(),v.end());

    int l=0,r=n-1,counter=0;

    while(l<r){
        if(v[l]+v[r]<=x){
            l++;r--;
        }else{
            r--;
        }
        counter++;
    }
    if(l==r){counter++;}

    cout<<counter;

}