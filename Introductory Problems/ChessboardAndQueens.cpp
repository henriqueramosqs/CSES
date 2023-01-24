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
char board[8][8];
int ans=0;

bool isSafe(int line,int col){

    for(int i = line+1;i<8;i++){
        if(board[i][col]=='Q')return false;
    }
    
    for(int i = line-1;i>=0;i--){
        if(board[i][col]=='Q')return false;
    }

    for(int i = col+1;i<8;i++){
        if(board[line][i]=='Q')return false;
    }
    
    for(int i = col-1;i>=0;i--){
        if(board[line][i]=='Q')return false;
    }

    for(int i =1;i<8;i++){
        if((line+i)==8)break;
        if((col+i)==8)break;
        if(board[line+i][col+i]=='Q')return false;
    }

    for(int i =1;i<8;i++){
        if((line-i)<0)break;
        if((col-i)<0)break;
        if(board[line-i][col-i]=='Q')return false;
    }

    for(int i =1;i<8;i++){
        if((line+i)==8)break;
        if((col-i)<0)break;
        if(board[line+i][col-i]=='Q')return false;
    }

    for(int i =1;i<8;i++){
        if((line-i)<0)break;
        if((col+i)==8)break;
        if(board[line-i][col+i]=='Q')return false;
    }
    
    return true;
}


void solve(int col=0){
    if(col==8){
        ans++;
        return;
    }

    //para cada linha
    rep(i,0,8){
       if(board[i][col]=='*')continue;
       if(!isSafe(i,col))continue;
       board[i][col]='Q';
       solve(col+1);
       board[i][col]='.';
    }

}
int main(){
    sws
    rep(i,0,8){
        rep(j,0,8)cin>>board[i][j];
    }

    solve();

    cout<<ans;
}
