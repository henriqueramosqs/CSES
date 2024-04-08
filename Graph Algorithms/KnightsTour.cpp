#include <bits/stdc++.h>
using namespace std;
// #pragma GCC target("popcnt")
#define sws ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(x) cout<<#x<<" "<<x<<endl;
#define output(x) for(auto c:x){cout<<c<<" ";}cout<<" ";
#define int long long 
#define ff first
#define ld long double
#define ss second
#define endl "\n"
#define pq priority_queue
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pair<int,int> > vpp;
int mat[8][8];
int cur=1;
bool found =false;

int getCode(int line,int col){
    return line*8+col;
}
pii getCel(int code){
    int lin = code/8;
    int col =code%8;
    return mp(lin,col);
}

bool inGrid(int line,int col){
    if(line<0 || line>=8)return false;
    if(col<0 || col>=8)return false;
    return true;
}

int getDegree(int line,int col){
    int ans=0;
    if(inGrid(line+2,col+1) && mat[line+2][col+1]==0)ans++;
    if(inGrid(line+2,col-1) && mat[line+2][col-1]==0)ans++;
    if(inGrid(line-2,col+1) && mat[line-2][col+1]==0 )ans++;
    if(inGrid(line-2,col-1) && mat[line-2][col-1]==0  )ans++;
    if(inGrid(line+1,col+2) && mat[line+1][col+2]==0 )ans++;
    if(inGrid(line-1,col+2) && mat[line-1][col+2]==0  )ans++;
    if(inGrid(line+1,col-2) && mat[line+1][col-2]==0  )ans++;
    if(inGrid(line-1,col-2) && mat[line-1][col-2]==0 )ans++;
    return ans;
}
void dfs(int line,int col){
    mat[line][col]=cur++;
    if(cur==65){
        found = true;
        return;
    }
    pq<pii>p;

    if(inGrid(line+2,col+1) && mat[line+2][col+1]==0)p.push(mp(-getDegree(line+2,col+1),getCode(line+2,col+1)));
    if(inGrid(line+2,col-1) && mat[line+2][col-1]==0)p.push(mp(-getDegree(line+2,col-1),getCode(line+2,col-1)));
    if(inGrid(line-2,col+1) && mat[line-2][col+1]==0)p.push(mp(-getDegree(line-2,col+1),getCode(line-2,col+1)));
    if(inGrid(line-2,col-1) && mat[line-2][col-1]==0)p.push(mp(-getDegree(line-2,col-1),getCode(line-2,col-1)));
    if(inGrid(line+1,col+2) && mat[line+1][col+2]==0)p.push(mp(-getDegree(line+1,col+2),getCode(line+1,col+2)));
    if(inGrid(line-1,col+2) && mat[line-1][col+2]==0)p.push(mp(-getDegree(line-1,col+2),getCode(line-1,col+2)));
    if(inGrid(line+1,col-2) && mat[line+1][col-2]==0)p.push(mp(-getDegree(line+1,col-2),getCode(line+1,col-2)));
    if(inGrid(line-1,col-2) && mat[line-1][col-2]==0)p.push(mp(-getDegree(line-1,col-2),getCode(line-1,col-2)));

    while(!p.empty()){
        int cd = p.top().ss; pii lc = getCel(cd);
        p.pop();
        dfs(lc.ff,lc.ss);
        if(found)return;
    }
    mat[line][col]=0;
    cur--;

}

int32_t main(){
    sws 
    int x,y;
    cin>>x>>y;
    x--;y--;
    dfs(y,x);
    rep(i,0,8){
        rep(j,0,8)cout<<mat[i][j]<<" ";
        cout<<"\n";
    }
}
