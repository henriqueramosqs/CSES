#include <bits/stdc++.h>
using namespace std;
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define endl "\n";
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
const int MAXN = 1e5+1;
int n,m;
vi adj[MAXN];
int bp;
vpp aux;

void dfs(int v=1,int p=-1){  

    while (!adj[v].empty()){
        int c = adj[v].back();
        adj[v].pop_back();
        dfs(c,v);
    }
    aux.pb(mp(p,v));
    if(p==n && v ==1){bp=aux.size()-1;}
    
}

int main(){
    sws 
    cin>>n>>m;

    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
    }
    adj[n].pb(1);
    dfs();

    vpp ans;

    ans.pb(mp(-1,1));

    for(int i = bp-1;i>=0;i--){
        ans.pb(aux[i]);
    }


    for(int i = aux.size()-2;i>bp;i--){
        ans.pb(aux[i]);
    }

   if(ans.size()<m || ans[ans.size()-1].ss !=n){
        cout<<"IMPOSSIBLE";
        return 0;
   }

   int last = ans[0].ss;

   for(int i = 1;i<ans.size();i++){
        if(ans[i].ff!=last){
            cout<<"IMPOSSIBLE";
            return 0;
        }
        last = ans[i].ss;
   }

   for(auto c:ans){
      cout<<c.ss<<" ";
   }
}
