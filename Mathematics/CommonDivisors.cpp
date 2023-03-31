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
const int MAXN = 1e6+1;

int main(){
    sws
    int n;
    cin>>n;
    vi a(n);
    rep(i,0,n)cin>>a[i];
    int divs[MAXN];
    rep(i,0,MAXN)divs[i]=0;
    int ans=0;

    for(auto c:a){
        for(int i=1;i*i<=c;i++){
            if(c%i==0){
                int k = c/i;
                if(++divs[i]>=2)ans=max(i,ans);
                if(k!=i && ++divs[k]>=2)ans=max(k,ans);
            }
        }
    }

    cout<<ans;

}
