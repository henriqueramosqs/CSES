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
const int LIM = 6;
const int MAXN= (LIM+1)*(LIM+1);
bool visited[7][7];
string s;
int ans=0;


void solve(int x,int y,int sPos,int visCount,char last){
    visited[x][y]=true;

    if(x==0 && y==LIM){
        if(visCount==MAXN)ans++;
        visited[x][y]=false;
        return;

    }
    
    // checa caso de bater no canto esquerdo
    if(x==0 || (visited[x-1][y]) && last!='R'){
        int count=0;
        if(y>0 && !visited[x][y-1])count++;
        if(y<LIM && !visited[x][y+1])count++;
        if(count==2){
            visited[x][y]=false;
            return;
        }
    }
    
    // checa caso de bater no canto direito
    if(x==6 || (visited[x+1][y] && last!='L')){
        int count=0;
        if(y>0 && !visited[x][y-1])count++;
        if(y<LIM && !visited[x][y+1])count++;
        if(count==2){
            visited[x][y]=false;
            return;
        }
    }

    // checa caso de bater no topo
    if(y==0 || (visited[x][y-1] && last!= 'D')){
        int count=0;
        if(x>0 && !visited[x-1][y])count++;
        if(x<LIM && !visited[x+1][y])count++;
        if(count==2){
            visited[x][y]=false;
            return;
        }
    }
    
    // checa caso de bater embaixo
    if(y==6 || (visited[x][y+1] && last!='U')){
        int count=0;
        if(x>0 && !visited[x-1][y])count++;
        if(x<LIM && !visited[x+1][y])count++;
        if(count==2){
            visited[x][y]=false;
            return;
        }
    }

    switch (s[sPos]){
        case '?':
            if(x<LIM && !visited[x+1][y])solve(x+1,y,sPos+1,visCount+1,'R');
            if(x>0 && !visited[x-1][y])solve(x-1,y,sPos+1,visCount+1,'L');
            if(y<LIM && !visited[x][y+1])solve(x,y+1,sPos+1,visCount+1,'D');
            if(y>0 && !visited[x][y-1])solve(x,y-1,sPos+1,visCount+1,'U');     
            break;
        case 'D':
            if(y<LIM && !visited[x][y+1])solve(x,y+1,sPos+1,visCount+1,'D');
            break;
        case 'U':
            if(y>0 && !visited[x][y-1])solve(x,y-1,sPos+1,visCount+1,'U');     
            break;
        case 'L':
              if(x>0 && !visited[x-1][y])solve(x-1,y,sPos+1,visCount+1,'L');
            break;
        case 'R':
             if(x<LIM && !visited[x+1][y])solve(x+1,y,sPos+1,visCount+1,'R');
            break;
        default:
            break;
    }
    visited[x][y]=false;



}

void solve(){
    solve(0,0,0,1,'x');
    cout<<ans;
}

int main(){
    sws
    cin>>s;
    memset(visited,false,sizeof(visited));
    solve();
}
