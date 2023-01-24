#include <bits/stdc++.h>
using namespace std;
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(msg,x) cout<<msg<<" "<<x<<endl;
#define output(x) for(auto c:x){cout<<c<<" ";}cout<<" ";
#define ll long long 
#define ff first
#define ss second
#define pq xpriority_queue
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
const int MAXN=1000;
int n,m;
char mp[MAXN][MAXN];
bool visited[MAXN][MAXN];

void dfs(int i,int j){
    visited[i][j]=true;
    if(i>0 && mp[i-1][j]=='.'&& !visited[i-1][j]) dfs(i-1,j);
    if(j>0 &&  mp[i][j-1]=='.' && !visited[i][j-1]) dfs(i,j-1);
    if(i<(n-1) && mp[i+1][j]=='.' && !visited[i+1][j]) dfs(i+1,j); 
    if(j<(m-1) && mp[i][j+1]=='.' && !visited[i][j+1]) dfs(i,j+1); 
}

int main(){
    sws
    cin>>n>>m;

    rep(i,0,n){
        rep(j,0,m){
            cin>>mp[i][j];
        }
    }

    int counter=0;

    rep(i,0,n){
        rep(j,0,m){
            if(mp[i][j]=='.' && !visited[i][j]){
                dfs(i,j);
                counter++;
            }
        }
    }

    cout<<counter;

}