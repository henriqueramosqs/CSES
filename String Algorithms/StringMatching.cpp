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
    string s,pat;
    cin>>s>>pat;
    int n,m;
    n = s.size();
    m = pat.size();

    s = pat+'$'+s; 
    int sz = n+m+1;
    int z[sz];
    rep(i,0,sz)z[i]=0;
    z[0]=n+m;

    int l=0,r=0;
    int ans=0;
    rep(i,1,sz){
        if(i<r)z[i]=min(z[i-l],r-i);
        while(i+z[i]<sz && s[z[i]]==s[i+z[i]]) z[i]++;
    
        if(z[i]==m)ans++;

        if(i+z[i]>r){
            l=i;
            r = i + z[i];
        }
    }

    cout<<ans;
}
