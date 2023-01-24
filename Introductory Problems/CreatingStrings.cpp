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
#define int long long
#define ss second
#define pq priority_queue
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;


void getStringsAux(string s,int n,set<string> *st){
    if(n==1){
        st->insert(s);
        return;
    }

    for(int i=n-1;i>=0;i--){
        swap(s[i],s[n-1]);
        getStringsAux(s,n-1,st);
        swap(s[i],s[n-1]);
    }

}


void getStrings(string org){
    set<string>st;

    getStringsAux(org,org.size(),&st);

    cout<<st.size()<<"\n";

    vector<string>ans;

    for(string s:st){
        ans.pb(s);
    }
    sort(ans.begin(),ans.end());

    for(string s:ans){
        cout<<s<<"\n";
    }
}
int32_t main(){
    sws
    string s;
    cin>>s;
    sort(s.begin(),s.end()); // precisa?

    getStrings(s);


}