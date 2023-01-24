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
vi adj[MAXN];

void leaf(int v,int p,int dist,int *a,int *maxDist){
    if(dist>*maxDist){
        *a=v;
        *maxDist=dist;
    }

    for(int c:adj[v]){
        if(c!=p){
            leaf(c,v,dist+1,a,maxDist);
        }
    }
}

void width(int v,int p,int *w,int carry){
    *w = max(*w,carry);
    for(int c:adj[v]){
        if(c!=p){
            width(c,v,w,carry+1);
        }
    }
}

int width(){
    int ans=0;
    int l;
    int maxDist=0;
    leaf(1,0,0,&l,&maxDist);
    width(l,0,&ans,0);
    return ans;
}
int main(){
    sws
    int n;
    cin>>n;
    rep(i,0,n-1){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    if(n==1){cout<<"0";return 0;}
    cout<<width();
}