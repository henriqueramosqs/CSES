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
    int t;
    cin>>t;

    while(t--){
        int a,b;
        cin>>a>>b;
        int n1 = 2*a-b;
        int n2 = 2*b-a;

        if(n1<0 || n2<0){
            cout<<"NO\n";
            continue;
        }

        bool c1 = (n1%3==0);
        bool c2 = (n1%3==0);

        if(c1 && c2){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}