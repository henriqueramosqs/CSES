#include <bits/stdc++.h>
using namespace std;
// #pragma GCC target("popcnt")
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(x) cout<<#x<<" "<<x<<endl;
#define output(x) for(auto c:x){cout<<c<<" ";}cout<<" ";
#define int long long 
#define ff first
#define ld long double
#define ss second
#define endl "\n"
#define pq priority_queue
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
int n;

void zfunction(string &s){
    int l=0,r=0;
    vi z(n,0);
    rep(i,1,n){
        if(i<r){
            z[i]=min(r-i,z[i-l]);
        }
        while(i+z[i]<n && s[z[i]]==s[i+z[i]])z[i]++;
        if(i+z[i]>r){
            l=i;r=i+z[i];
        }
    }
    for(auto c:z)cout<<c<<" ";
    cout<<"\n";
}

void kmp(string &s){
    vi pi(n,0);
    rep(i,1,n){
        int j = pi[i-1];
        while(j>0 && s[i]!=s[j])j=pi[j-1];
        if(s[i]==s[j])j++;
        pi[i]=j;
    }

    for(auto c:pi)cout<<c<<" ";
    cout<<"\n";
}
int32_t main(){
    sws 
    string s;cin>>s;
    n = s.size();
    zfunction(s);
    kmp(s);
}
