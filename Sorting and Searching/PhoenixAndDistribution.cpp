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
#define endl "\n"
#define pq priority_queue
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;

int32_t main(){
    sws
    int t;cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;
        string s;cin>>s;
        sort(s.begin(),s.end());
        pq<string,vector<string>,greater<string> >p;



        rep(i,0,k){
            p.push(string(1,s[i]));
        }

        rep(i,k,n){
            string aux = p.top();
            p.pop();
            // dbg("aux",aux)
            p.push(aux+s[i]);
        }

        string ans =p.top();

        while(!p.empty()){
            ans=max(ans,p.top());
            p.pop();
        }

        cout<<"ans:\n";
        cout<<ans<<endl;
    }
}
