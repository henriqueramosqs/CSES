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
const int MAXN = 100000+1;
int ans[MAXN];
int distances[MAXN];
bool visited[MAXN];
vi adj[MAXN];
int n,m;

int main(){
    sws
    cin>>n>>m;

    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    pq<pair<pii,int> >p;
    p.push(mp(mp(0,1),-1));
    ans[1]=-1;
    bool found =false;

    rep(i,1,n+1){
        distances[i]=INT32_MAX;
        visited[i]=false;
    }
    distances[1]=0;
    
    while(!p.empty()){
        int v = p.top().ff.ss;
        int hT = p.top().ss;
        p.pop();

        if(visited[v])continue;
        ans[v]=hT;

        if(v==n){
            found=true;
            break;
        }

        visited[v]=true;

        for(auto c:adj[v]){
            if(!visited[c] && distances[c]>distances[v]+1){
                distances[c]=distances[v]+1;
                p.push(mp(mp(-distances[c],c),v));
            }
        }
    }

    if(!found){
        cout<<"IMPOSSIBLE";
        return 0;
    }

    stack<int>fil;
    int cur = n;

    while(ans[cur]!=-1){
        int hT = ans[cur];
        fil.push(hT);
        cur = ans[cur];
    }

    cout<<fil.size()+1<<"\n";

    while(!fil.empty()){
        cout<<fil.top()<<" ";
        fil.pop();
    }
    cout<<n;
   
}