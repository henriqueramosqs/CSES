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
#define int long long
#define pq priority_queue
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int INF = 1e15;

int32_t main(){
    sws
    int n,m,q;
    cin>>n>>m>>q;
    int adj[n+1][n+1];
    rep(i,1,n+1){
        rep(j,1,n+1)adj[i][j]=INF ;
    }

    while(m--){
        int a,b,w;
        cin>>a>>b>>w;
        adj[a][b]=min(w,adj[a][b]);
        adj[b][a]=min(w,adj[b][a]);
    }

    int distances[n+1][n+1];

    rep(i,1,n+1){
        rep(j,1,n+1){
            if(i==j)distances[i][j]=0;
            else if(adj[i][j]!=INF){distances[i][j]=adj[i][j];}
            else{distances[i][j]=INF;}
        }
    }

    rep(k,1,n+1){
        rep(i,1,n+1){
            rep(j,1,n+1){
                distances[i][j]=min(distances[i][j],distances[i][k]+distances[k][j]);
            }
        }
    }

    rep(i,0,q){
        int a,b;
        cin>>a>>b;
        if(distances[a][b]==INF){
            cout<<-1<<endl;
        }else{
            cout<<distances[a][b]<<endl;
        }
    }
}