#include <bits/stdc++.h>
using namespace std;
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(msg,x) cout<<msg<<" "<<x<<endl;
#define output(x) for(auto c:x){cout<<c<<" ";}cout<<" ";
#define int long long 
#define ff first
#define ss second
#define pq priority_queue
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int MAXN = 1e18;
int cur =1;
vpp v;
vi pots;

void process(){
    while(v[cur-1].ss<=MAXN){
        pots.pb(10*pots[cur-1]);
        v.pb(mp(v[cur-1].ss+1,9*(cur+1)*pots[cur] + v[cur-1].ss));
        cur++;
    }

}
int splitNum(int a,int pos){
    vi ans;
    while(a!=0){
        ans.pb(a%10);
        a/=10;
    }
    return ans[ans.size()-1-pos];
}
int32_t main(){
    sws
    int q;cin>>q;
    pots.pb(1);
    v.pb(mp(1,9));

    process();

    int sz = v.size();
    while(q--){
        int k;cin>>k;

        int pos =0;

        for(int step=(sz/2);step>=1;step/=2){
            while(pos+step<sz &&v[pos+step].ff<=k)pos+=step;
        }

        int num = pots[pos];
        int position = k-v[pos].ff;
        num+=(position/(pos+1));
        cout<<splitNum(num,position%(pos+1))<<endl;;

    }
}
