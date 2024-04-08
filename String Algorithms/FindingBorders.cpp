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
    string s;cin>>s;
    int n=s.size();
    set<int>st;
    int z[n];rep(i,0,n)z[i]=0;
    z[0]=n;
    int l=0,r=0;

    rep(i,1,n){

        if(i<r){
            z[i]=min(r-i,z[i-l]);
        }
        while(s[z[i]]==s[i+z[i]])z[i]++;

        if(i>r){
            l=i;
            r=i+z[i];
        }
        if(z[i]!=0 && i+z[i]==n)st.insert(z[i]);
    }

    for(int c:st){
        if(c!=0)cout<<c<<" ";
    }
}
