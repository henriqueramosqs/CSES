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
typedef pair<int,pii > dt;


struct comp{
    bool operator()(dt a,dt b){
        return a.ff<=b.ff;
    }
};

int main(){
    sws
    int x,n;
    cin>>x>>n;
    set<int>s;
    s.insert(0);
    s.insert(x);
    pq<dt,vector<dt>,comp>p;
    p.push(mp(x,mp(0,x)));

    rep(i,0,n){
        int k;cin>>k;
        s.insert(k);
        set<int>::iterator it = s.upper_bound(k);
        p.push(mp(*it-k,mp(k,*it)));
        it--;
        it--;
        p.push(mp(k-*it,mp(*it,k)));
        while(*s.upper_bound(p.top().ss.ff) !=p.top().ss.ss)p.pop();

        cout<<p.top().ff<<endl;
    }
}
