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
const int MAXN = 2*1e5;

int main(){
    sws
    int n;cin>>n;
    set<pii>s;
    pq<int,vi,greater<int> >rooms;
    pq<pii,vpp,greater<pii> >occupied;

    int ans[n];
    int maxRoom = 0;

    rep(i,0,MAXN){
        rooms.push((i+1));
    }

    vector<pair<pii,int> >v;

    rep(i,0,n){
        int a,b;
        cin>>a>>b;  
        v.pb(mp(mp(a,b),i));
    }   

    sort(v.begin(),v.end());

    for(auto c:v){
        int arriveDay = c.ff.ff;
        int leaveDay = c.ff.ss;
        int idx = c.ss;

        while(occupied.size()!=0 && occupied.top().ff<arriveDay){
            rooms.push(occupied.top().ss);
            occupied.pop();
        }

        int room = rooms.top();
        rooms.pop();
        maxRoom = max(room,maxRoom);
        ans[idx]=room;
        occupied.push(mp(leaveDay,room));
    }   
    
    cout<<maxRoom<<endl;
    rep(i,0,n){
        cout<<ans[i]<<" ";
    }
}
