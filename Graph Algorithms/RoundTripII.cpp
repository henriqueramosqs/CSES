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
typedef vector< bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int MAXN = 2*1e5+1;
vi adj[MAXN];
int path[MAXN];
int color[MAXN];
int n,m;
bool poss = false;

void dfs(int v){
    color[v]=1;

    for(int c:adj[v]){

        if(color[c]==0){
            path[c]=v;
            dfs(c);
        }

        if(color[c]==2)continue;
        if(color[c]==1){
            if(poss)continue;
            poss =true;
            int cyc =c;
            stack<int>s;
            s.push(c);
            int cur = v;

            while(cur!=c){
                s.push(cur);
                cur = path[cur];
            }
            s.push(c);


            cout<<s.size()<<"\n";
            while(!s.empty()){
                cout<<s.top()<<" ";
                s.pop();
            }
        }
    }
    color[v]=2;
}

int32_t main(){
    sws 
    memset(color,0LL,sizeof(color));

    cin>>n>>m;
    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
    }


    rep(i,1,n+1){
        if(color[i]==0)dfs(i);
    }

    if(!poss)cout<<"IMPOSSIBLE";

}
