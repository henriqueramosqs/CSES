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
const int MAXN = 2*1e5+1;
int up[MAXN];
int ans[MAXN];
int tin[MAXN];
bool visited[MAXN];
int temp = 0;
int cz=0;
int add=0;
int mark =0;

void dfs(int v){
    visited[v]=true;
    tin[v]=temp++;

    if(visited[up[v]]){
        if(ans[up[v]]==0){
            cz =tin[v]-tin[up[v]]+1;
            mark = up[v];
        }else{
            cz=ans[up[v]];
            add=1;
        }
    }else{
        dfs(up[v]);
    }
    ans[v]=cz+add;

    if(add!=0 || v==mark)add++;

}

int main(){
    sws
    memset(visited,false,sizeof(visited));
    memset(ans,0,sizeof(ans));
    int n;
    cin>>n;

    int c[n+1];
    rep(i,1,n+1){
        cin>>up[i];
        c[up[i]]++;
    }
    pq<pii>p;
    rep(i,1,n+1){
        p.push(mp(-c[i],i));
    }

    while(!p.empty()){
        int i = p.top().ss;
        p.pop();
        if(visited[i])continue;
        cz=mark=add=0;
        dfs(i);
    }

    rep(i,1,n+1)cout<<ans[i]<<" ";

}
